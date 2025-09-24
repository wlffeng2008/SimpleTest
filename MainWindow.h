#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <windows.h>
#include <dbt.h>
#include <QMainWindow>
#include <QPaintEvent>

#include <QDebug>
#include <QTimer>
#include <QWidget>
#include <QApplication>
#include <QCoreApplication>
#include <QAbstractNativeEventFilter>
#include <QMessageBox>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStyledItemDelegate>
#include <QSpinBox>
#include <QComboBox>
#include <QSlider>
#include <QProgressBar>
#include <QPainter>
#include <QLineEdit>
#include <QProxyStyle>

class USBNotifier : public QObject, public QAbstractNativeEventFilter
{
    Q_OBJECT
public:
    explicit USBNotifier(QObject *parent = nullptr) : QObject(parent) {  }

signals:
    void devicePluggedIn();
    void deviceUnplugged();

protected:
    bool nativeEventFilter(const QByteArray &eventType, void *message, qintptr *result) override
    {
        Q_UNUSED(eventType)
        Q_UNUSED(result)

        MSG* msg = reinterpret_cast<MSG*>(message);
        if (msg->message == WM_DEVICECHANGE)
        {
            if(msg->wParam == DBT_DEVICEARRIVAL       )  emit devicePluggedIn();
            if(msg->wParam == DBT_DEVICEREMOVECOMPLETE)  emit deviceUnplugged();

        }
        return false ;
    }
};

class QStandardItemEx : public QStandardItem
{
public:
    QStandardItemEx(){};
    explicit QStandardItemEx(const QString &text):QStandardItem(text){}
    QStandardItemEx(const QIcon &icon, const QString &text):QStandardItem(icon,text){}
    explicit QStandardItemEx(int rows, int columns = 1):QStandardItem(rows,columns){};
    virtual ~QStandardItemEx(){};

    void setChecked(bool checked=true){ QStandardItem::setCheckState(checked ? Qt::Checked : Qt::Unchecked); }
    bool isChecked(){ return (QStandardItem::checkState() == Qt::Checked); }

    void setInt(quint32 value=0,int base=10,int width=2){
        QString strText = QString("%1").arg(value,width,base,QLatin1Char('0')) ;
        QStandardItem::setText(strText) ;
    } ;
    quint32 toInt(int base=10){
        quint32 value = QStandardItem::text().toInt(nullptr,base) ;
        return value ;
    } ;
};

class SpinBoxDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    SpinBoxDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}
    void setHexMode(bool bHexMode=true){ m_bHexMode = bHexMode ;}

private:
    bool m_bHexMode = false ;

protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_UNUSED(option)
        Q_UNUSED(index)
        QSpinBox *editor = new QSpinBox(parent);
        editor->setRange(0,100) ;
        editor->setSingleStep(1);
        if(m_bHexMode)
            editor->setDisplayIntegerBase(16) ;
        return editor;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        QString strValue = index.model()->data(index, Qt::EditRole).toString();
        int value = m_bHexMode ? strValue.toInt(nullptr,16) : strValue.toInt();
        spinBox->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();

        if(m_bHexMode)
        {
            QString value = spinBox->text().toUpper() ;
            model->setData(index, value, Qt::EditRole);
        }
        else
        {
            int value = spinBox->value();
            model->setData(index, value, Qt::EditRole);
        }
    }
};

class ValueSlider : public QSlider {
    Q_OBJECT
public:
    explicit ValueSlider(QWidget *parent = nullptr):QSlider(parent){}
    explicit ValueSlider(Qt::Orientation orientation,QWidget *parent = nullptr):QSlider(orientation,parent){}
    void setHexMode(bool bHexMode=true){ m_bHexMode = bHexMode; }

private:
    bool m_bHexMode = true ;

protected:
    void paintEvent(QPaintEvent *event) override {
        QSlider::paintEvent(event);

        QPainter painter(this);
        painter.drawText(rect(), Qt::AlignCenter,m_bHexMode ? QString("%1").arg(value(),2,16,QLatin1Char('0')) : QString::number(value()));
    }
};

class SliderDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    SliderDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void setRange(int nMin,int nMax){ _nMin = nMin ; _nMax = nMax; }
    void setHexMode(bool bHexMode=true){m_bHexMode = bHexMode; }

private:
    int _nMin = 0;
    int _nMax = 100 ;
    bool m_bHexMode = true ;

protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const override {
        Q_UNUSED(option)
        Q_UNUSED(index)
        ValueSlider *slider = new ValueSlider(Qt::Horizontal,parent);
        slider->setMinimum(_nMin);
        slider->setMaximum(_nMax);
        slider->setSingleStep(1);
        slider->setHexMode(m_bHexMode) ;
        return slider;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        QSlider *slider = static_cast<QSlider*>(editor);
        int value = index.model()->data(index, Qt::EditRole).toInt();
        if(m_bHexMode)
        {
            QString strValue = index.model()->data(index, Qt::EditRole).toString();
            value = strValue.toInt(nullptr,16);
        }
        slider->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QSlider *slider = static_cast<QSlider*>(editor);
        int value = slider->value();
        if(m_bHexMode)
        {
            QString strValue = QString("%1").arg(value,2,16,QLatin1Char('0')).toUpper() ;
            model->setData(index, strValue, Qt::EditRole);
        }
        else
        {
            model->setData(index, value, Qt::EditRole);
        }
    }
};



class ProgressDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    ProgressDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent)
    {
        connect(this,&ProgressDelegate::onValueChanged,this,[=](int nIndex,int nValue)
        {
            setValue(nIndex,nValue) ;
        }) ;
    }
    void initValue(int index,int value){ nValues[index] = value ;};

    void setValue(int nRow,int nValue){
        nValues[nRow] = nValue;
        QWidget *pWidget = static_cast<QWidget *>(parent()) ;
        pWidget->update() ;
    }

signals:
    void onValueChanged(int nIndex,int nValue) const ;

private:
    QMap<int,int> nValues ;

public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        painter->save() ;
        QRect rect = option.rect ;
        //painter->drawRect(rect) ;
        rect.adjust(4,4,-4,-4) ;

        QPen pen(Qt::green) ;
        pen.setWidthF(2) ;
        painter->setPen(pen) ;
        painter->setBrush(QBrush( Qt::blue )) ;
        painter->drawRoundedRect(rect,6,6);

        pen.setColor( nValues[index.row()]>50 ? Qt::white:Qt::darkGray );
        painter->setPen(pen) ;
        painter->drawText(rect,Qt::AlignCenter, QString::number(nValues[index.row()]));
        painter->restore() ;
    }

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {        
        Q_UNUSED(option)
        Q_UNUSED(index)
        QProgressBar *progressBar = new QProgressBar(parent);
        progressBar->setMinimum(0);      // 设置最小值
        progressBar->setMaximum(100);    // 设置最大值

        return progressBar;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QProgressBar *progressBar = static_cast<QProgressBar*>(editor);
        progressBar->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QProgressBar *progressBar = static_cast<QProgressBar*>(editor);
        int value = progressBar->value();
        emit onValueChanged(index.row(),value) ;
        model->setData(index, value, Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        Q_UNUSED(option)
        Q_UNUSED(index)
        QRect rc = option.rect ;
        rc.adjust(0,4,0,-4) ;
        editor->setGeometry(rc);
    }
};

class CustomComboBox : public QComboBox {
    Q_OBJECT
public:
    explicit CustomComboBox(QWidget *parent = nullptr):QComboBox(parent){}

protected:
    void hidePopup() override {
        QComboBox::hidePopup();
        QTimer::singleShot(20,this,[=]{ hide() ;}) ;
    }
};


class ComboBoxDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    ComboBoxDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {
        connect(this,&ComboBoxDelegate::onCreateComboBox,this,[=](CustomComboBox *comboBox){
            _comboBox = comboBox;
        }) ;
    }

    void setItems(const QString&strItems){ _items = strItems .split(',');}
    void setItems(const QStringList&strItems){ _items = strItems;}
    void setTableView( QTableView *pView ){ m_pTableView = pView;}

private:
    QStringList _items = QString("中国,上海,北京,深圳,广州,东莞,惠州,中山,江门,珠海,香港,澳门,重庆").split(',') ;
    CustomComboBox *_comboBox = nullptr ;
    QTableView *m_pTableView = nullptr ;

signals:
    void onCreateComboBox(CustomComboBox *pComBox) const;

protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_UNUSED(option)
        Q_UNUSED(index)
        CustomComboBox *comboBox = new CustomComboBox(parent);
        comboBox->setStyleSheet("QComboBox{ min-width:0px; }") ;
        comboBox->addItems(_items);
        comboBox->setMaxVisibleItems(20) ;
        comboBox->setEditable(true) ;

        emit onCreateComboBox(comboBox) ;

        QTimer::singleShot(50,this,[=](){ comboBox->showPopup(); }) ;
        return comboBox;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        QString value = index.model()->data(index, Qt::EditRole).toString();
        QComboBox *comboBox = static_cast<QComboBox*>(editor);
        comboBox->setMaxVisibleItems(20) ;
        int select = comboBox->findText(value) ;
        if(select != -1)
            comboBox->setCurrentIndex(select);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QComboBox *comboBox = static_cast<QComboBox*>(editor);
        comboBox->setMaxVisibleItems(20) ;
        QString value = comboBox->currentText();
        model->setData(index, value, Qt::EditRole);
    }

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override
    {
        if(event->type() == QEvent::MouseButtonRelease)
        {
            if(m_pTableView) m_pTableView->edit(index) ;
        }


        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        Q_UNUSED(option)
        Q_UNUSED(index)
        editor->setGeometry(option.rect);
    }
};

class ButtonDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    ButtonDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) { }
    void setValue(int nRow,int nValue){ nClicked[nRow] = nValue ;  _texts[nRow] = m_strText ; }
    void setText(int nRow,const QString&text){ _texts[nRow] = text ; } ;
    void setText(const QString&text){ m_strText = text ; } ;
    void setTableView(QTableView *pView){ m_pView = pView ;} ;

protected:
    QMap<int,int> nClicked ;
    QMap<int,QString> _texts ;
    QString m_strText = "恭喜发财" ;

    bool m_bLeftPressed=true ;
    int m_nHitRow = -1 ;
    int m_nHitCol = -1 ;
    int m_nHoverRow = -1 ;
    int m_nHoverCol = -1 ;
    QTimer *m_pAuto = nullptr;
    QTimer *m_pTM = nullptr;
    QRect  m_rc ;
    QTableView *m_pView = nullptr ;

signals:
    void onButtonClicked(int row,int col);

protected:

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyledItemDelegate::paint(painter,option,index) ;
        painter->save() ;
        QRect rect = option.rect ;
        rect.adjust(4,4,-4,-4) ;

        QPen pen(Qt::green) ;
        pen.setWidthF(2) ;
        painter->setPen(pen) ;
        painter->setBrush(QBrush( (m_nHitRow == index.row() && m_nHitCol == index.column()) ? Qt::red : Qt::blue )) ;
        painter->drawRoundedRect(rect,6,6);

        int nValue = nClicked[index.row()];
        pen.setColor( nValue>0 ? Qt::white:Qt::darkGray);
        painter->setPen(pen) ;
        painter->drawText(rect,Qt::AlignCenter,_texts[index.row()] + QString("%1").arg(nValue,6,10));
        painter->restore() ;
    }

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *pMEvt = static_cast<QMouseEvent *>(event) ;
            m_bLeftPressed = (pMEvt->button() == Qt::LeftButton) ;

            m_nHitRow = index.row() ;
            m_nHitCol = index.column() ;

            if(!m_pAuto)
            {
                m_pAuto = new QTimer(this) ;
                connect(m_pAuto,&QTimer::timeout,this,[=]{
                    if(m_bLeftPressed)
                        nClicked[m_nHitRow] ++ ;
                    else
                        nClicked[m_nHitRow] -- ;
                    QWidget *pWidget = static_cast<QWidget *>(parent()) ;
                    pWidget->update() ;
                });
            }
            m_pAuto->start(50) ;
        }

        if(event->type() == QEvent::MouseButtonRelease)
        {
            if(m_pAuto)
                m_pAuto->stop();
            m_nHitRow = -1 ;
            m_nHitCol = -1 ;

            QWidget *pWidget = static_cast<QWidget *>(parent()) ;
            pWidget->update() ;
            emit onButtonClicked(index.row(),index.column());
        }

        if(event->type() == QEvent::MouseMove)
        {
            QApplication::setOverrideCursor(Qt::PointingHandCursor) ;

            m_nHoverRow = index.row() ;
            m_nHoverCol = index.column() ;
            m_rc = option.rect ;
            if(!m_pTM)
            {
                m_pTM = new QTimer(this) ;
                connect(m_pTM,&QTimer::timeout,this,[=]
                {
                    QPoint pos = m_pView->mapFromGlobal(QCursor::pos());
                    QSize hs = m_pView->horizontalHeader()->sizeHint() ;
                    QSize vs = m_pView->verticalHeader()->sizeHint() ;
                    int row = m_pView->rowAt(pos.y() - hs.height()) ;
                    int col = m_pView->columnAt(pos.x() - vs.width());
                    if(m_nHoverRow != row || m_nHoverCol != col)
                    {
                        if(m_pAuto) m_pAuto->stop() ;
                        m_pTM->stop();

                        QApplication::setOverrideCursor(Qt::ArrowCursor) ;
                    }
                });
            }
            m_pTM->stop();
            m_pTM->start(30) ;
        }
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }
};


class SideValueDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    SideValueDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {
        connect(this,&SideValueDelegate::onSaveOldText,this,[=](int nRow,const QString&text){
            setText(nRow,text);
        }) ;
    }
    void setText(int nRow,const QString&text){ _texts[nRow] = text ; } ;
    void setTableView(QTableView *pView){ tableView = pView ;} ;
    void setHexMode(bool set=true){ m_bHexMode = set ;}

protected:
    QMap<int,QString> _texts ;
    QTableView *tableView = nullptr ;
    bool m_bHexMode = false ;

signals:
    void onButtonClicked(int row,int col);
    void onSaveOldText(int nRow,const QString&text) const ;

protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_UNUSED(option)
        Q_UNUSED(index)

        QStandardItemModel *pModel = (QStandardItemModel *)index.model() ;
        QString strText = pModel->item(index.row(),index.column())->text() ;
        emit onSaveOldText(index.row(),strText);

        QSpinBox *pBox = new QSpinBox(parent) ;
        pBox->setRange(-1000000,1000000);
        if(m_bHexMode)pBox->setDisplayIntegerBase(16) ;
        return pBox;
    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyledItemDelegate::paint(painter,option,index) ;

        painter->save() ;

        QStandardItemModel *pModel = (QStandardItemModel *)index.model() ;
        QStandardItem *item = pModel->item(index.row(),index.column()) ;
        QString strText = item->text() ;

        QRect rect = option.rect ;
        rect.adjust(4,4,-4,-4) ;

        QPen pen(Qt::darkGray) ;
        painter->setPen(pen) ;
        painter->drawText(rect,Qt::AlignRight|Qt::AlignVCenter,_texts[index.row()]);

        painter->restore() ;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        QString strValue = index.model()->data(index, Qt::EditRole).toString();
        int value = m_bHexMode ? strValue.toInt(nullptr,16) : strValue.toInt();
        spinBox->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();

        if(m_bHexMode)
        {
            QString value = spinBox->text().toUpper() ;
            model->setData(index, value, Qt::EditRole);
        }
        else
        {
            int value = spinBox->value();
            model->setData(index, value, Qt::EditRole);
        }
    }

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override
    {
        if(event->type() == QEvent::MouseButtonRelease && tableView)
        {
            QRect cellRect = tableView->visualRect(index);

            QPoint clp = tableView->viewport()->mapFromGlobal(QCursor::pos())  ;

            int nx = clp.x() ;
            int ny = clp.y() ;

            for(int i=0; i<index.column(); i++)
                nx -= tableView->columnWidth(i) ;
            for(int i=0; i<index.row(); i++)
                ny -= tableView->rowHeight(i) ;
            if(nx * 10 / cellRect.width() > 6)
            {
                QStandardItemModel *pModel = (QStandardItemModel *)index.model() ;
                QStandardItem *item = pModel->item(index.row(),index.column()) ;
                if(item && !_texts[index.row()].isEmpty()) item->setText(_texts[index.row()]) ;
            }
        }
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    }

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option ;
        opt.rect.adjust(0,0,opt.rect.width()/2 * -1 + 20 ,0);
        QStyledItemDelegate::updateEditorGeometry(editor,opt,index);
    }
};


class CustomStyle : public QProxyStyle {
public:
    void drawControl(ControlElement element, const QStyleOption* option,
                     QPainter* painter, const QWidget* widget) const override {
        if (element == CE_CheckBox)
        {
            painter->save();

            QPen pen = painter->pen();
            pen.setWidth(1);  // 加粗边框
            painter->setPen(pen);

            // 绘制加大的复选框
            QRect rect = option->rect;
            rect.setWidth(20);  // 加大宽度
            rect.setHeight(20); // 加大高度

            painter->setBrush(option->palette.base());
            painter->drawRect(rect);

            if (option->state & State_On)
            {
                QPen checkPen(pen.color(), pen.width(), Qt::SolidLine, Qt::RoundCap);  // 加粗勾选标记
                painter->setPen(checkPen);

                QPointF points[3] = {
                    QPointF(rect.left() + 5, rect.center().y()),
                    QPointF(rect.center().x(), rect.bottom() - 5),
                    QPointF(rect.right() - 5, rect.top() + 5)
                };
                painter->drawPolyline(points, 3);
            }

            painter->restore();
        } else {
            QProxyStyle::drawControl(element, option, painter, widget);
        }
    }
};


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event) override ;
    bool eventFilter(QObject *editor, QEvent *event) override;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonSavePng_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
