#include "CheckBoxHeaderView.h"
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QDebug>
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QApplication>

CheckBoxHeaderView::CheckBoxHeaderView(Qt::Orientation orientation, QWidget *parent):
    QHeaderView(orientation,parent)
{
    m_pView = static_cast<QTableView *>(parent);

    setChckcImage(":/images/BoxChecked.png",":/images/BoxUncheck.png") ;

    setMouseTracking(true);
    installEventFilter(this);

    connect(this,&CheckBoxHeaderView::checkRectChanged,this,[=](int index,const QRect&rect){
        m_checkRects[index] = rect;
    });
}

void CheckBoxHeaderView::setChckcImage(const QString&checked,const QString&unChecked)
{
    m_checkedImage   = checked ;
    m_uncheckedImage = unChecked;
}

void CheckBoxHeaderView::paintSection(QPainter *painter, const QRect &rect, int nCol) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, nCol);
    painter->restore();

    QStandardItemModel *pModel = (QStandardItemModel *)this->model() ;
    if (m_CheckCols.contains(nCol))
    {
        QStyleOptionButton option;
        option.rect = rect.adjusted(-2,-2,-2,-2);
        option.state = QStyle::State_Enabled | QStyle::State_Active;
        option.state |= m_checkStates.value(nCol, false) ? QStyle::State_On : QStyle::State_Off;

        QString strText= pModel->headerData(nCol,Qt::Horizontal).toString() ;

        painter->setRenderHint(QPainter::SmoothPixmapTransform);

        QRect rcBox = rect.adjusted(2,2,-2,-2);
        rcBox.setRight(rcBox.left() + 18);
        rcBox.setBottom(rcBox.top() + 18);
        painter->drawImage(rcBox,QImage(m_checkStates[nCol] ? m_checkedImage : m_uncheckedImage));

        emit checkRectChanged(nCol,rcBox);
    }
}

void CheckBoxHeaderView::setClickIndecator(bool click)
{
    m_clickIndecator = click;
}

void CheckBoxHeaderView::mousePressEvent(QMouseEvent *event)
{
    QPoint pos(event->pos()) ;
    int nCol = logicalIndexAt(pos);
    if (m_CheckCols.contains(nCol))
    {
        const QRect &rcCol = m_checkRects[nCol];
        if(rcCol.contains((pos)) || m_clickIndecator)
        {
            setChecked(nCol,!m_checkStates[nCol]);
            updateSection(nCol);
        }
    }
    QHeaderView::mousePressEvent(event);
}

bool CheckBoxHeaderView::eventFilter(QObject *editor, QEvent *event)
{
    if (event->type() == QEvent::HoverEnter || event->type() == QEvent::MouseMove)
    {
        QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
        return true;
    }
    QApplication::restoreOverrideCursor();

    return QHeaderView::eventFilter(editor, event);
}

bool CheckBoxHeaderView::isChecked(int nCol) const
{
    return m_checkStates.value(nCol, false);
}

void CheckBoxHeaderView::setChecked(int nCol,bool checked)
{
    m_checkStates[nCol] = checked;
    emit checkStateChanged(nCol, checked);
    if(!m_pView)
        return ;

    QStandardItemModel *pModel = static_cast<QStandardItemModel *>(m_pView->model());
    int nCount = pModel->rowCount();
    for(int i=0; i<nCount; i++)
        pModel->item(i,nCol)->setCheckState(checked?Qt::Checked:Qt::Unchecked);
}

void CheckBoxHeaderView::setCheckCol(int nCol)
{
    if(!m_CheckCols.contains(nCol))
        m_CheckCols.append(nCol);
}
