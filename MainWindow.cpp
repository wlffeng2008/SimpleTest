#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "DialogScrollTest.h"
#include "CheckBoxHeaderView.h"
#include "DialogChart.h"

#include "sldmv.h"

#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QFont>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QStandardItemModel>
#include <QCoreApplication>
#include <QApplication>
#include <QSettings>

int GenMessageBox(QWidget *parent,const QString&strTitle,const QString&strMsg)
{
    static bool set=false ;
    static QMessageBox msgBox(parent);
    msgBox.setParent(parent) ;
    if(!set)
    {
        set = true ;
        QLabel *labelIcon = msgBox.findChild<QLabel*>("qt_msgboxex_icon_label");
        labelIcon->setFixedSize(40,40) ;

        QTimer::singleShot(50, &msgBox, [&]() {
            msgBox.setMinimumWidth(400) ;
            msgBox.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
            QLabel *label = msgBox.findChild<QLabel*>("qt_msgbox_label");
            label->setFixedSize(300,240);
            label->setMinimumSize(300,240) ;
            label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
            label->setAlignment(Qt::AlignTop|Qt::AlignLeft) ;
            label->setWordWrap(true);
            label->adjustSize();
        });
    }

    msgBox.setText(strMsg);
    msgBox.setWindowTitle(strTitle) ;
    msgBox.setIcon(QMessageBox::Question) ;
    return msgBox.exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->setStyle(new CustomStyle);

    {
        QCoreApplication::setOrganizationName("MyCompany");
        QCoreApplication::setApplicationName("MyApp");

        // 写入注册表
        QSettings settings;
        settings.beginGroup("Preferences");
        settings.setValue("DarkMode", true);
        settings.setValue("FontSize", 12);
        settings.endGroup();


        settings.beginGroup("Preferences/q1/123");
        settings.setValue("DarkMode", true);
        settings.setValue("FontSize", 15);
        settings.endGroup();

        // 读取注册表
        settings.beginGroup("Preferences");
        bool darkMode = settings.value("DarkMode", false).toBool();
        int fontSize = settings.value("FontSize", 10).toInt();
        settings.endGroup();
        qDebug() << "DarkMode:" << darkMode << "FontSize:" << fontSize;

        QSettings set("d:/jtest.ini",QSettings::IniFormat);
        set.beginGroup("Preferences");
        set.setValue("DarkMode", true);
        set.setValue("FontSize", 12);
        set.endGroup();

        set.beginGroup("Preferences/q1/123");
        set.setValue("DarkMode", true);
        set.setValue("FontSize", 15);
        set.endGroup();
    }
    {
        unsigned long type= 0 ;
        SLDM_GetPtMoveP(0,0,&type) ;
    }

    static USBNotifier *pUsb = new USBNotifier(this);
    connect(pUsb, &USBNotifier::devicePluggedIn, []() {
        qDebug() << "USB device plugged in";
    });

    connect(pUsb, &USBNotifier::deviceUnplugged, []() {
        qDebug() << "USB device unplugged";
    });

    connect(ui->pushButtonMsg1,&QPushButton::clicked,this,[=](){
        GenMessageBox(this,"中央","<h1>中央人民政府中央人 民政府中央人民政府<br>中央人民政府中央人民政府</h1><br>国家主席") ;
    }) ;

    connect(ui->pushButtonMsg2,&QPushButton::clicked,this,[=](){
        GenMessageBox(this,"提示","确定要退出吗1？确定要退出吗2？确定要退出吗3？确定要退出吗4？确定要退出吗5？\n确定要退出吗6？\n确定要退出吗7？\n确定要退出吗8？\n确定要退出吗？\n确定要退出吗？\n确定要退出吗？\n确定要退出吗？\n确定要退出吗？\n") ;
    }) ;

    QImage image(1024, 600, QImage::Format_ARGB32);
    image.fill(Qt::transparent);  // 填充完全透明背景

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);  // 抗锯齿（平滑边缘）[1](@ref)
    painter.setBrush(Qt::transparent);              // 完全透明画刷[1,7](@ref)
    painter.setPen(Qt::NoPen);                      // 无边框线

    QColor bgColor(0, 200, 0, 0);  // 黑色完全透明（Alpha=0）
    // 或半透明效果（Alpha范围0-255）
    bgColor.setAlpha(100);       // 半透明（如Alpha=100）[3,6](@ref)
    painter.setBrush(bgColor);

    painter.setPen(Qt::red);

    QFont font = this->font() ;
    font.setPointSize(200) ;
    font.setFamily("仿宋");
    font.setBold(true) ;
    //font.setItalic(true) ;
    painter.setFont(font) ;

    painter.drawText(image.rect(),Qt::AlignHCenter|Qt::AlignVCenter,"中央人民政府") ;

    image.save("D:\\123456.png") ;
    this->grab().save("D:\\test.png") ;

    {
        QPixmap pixmap(1366,768);
        pixmap.fill(Qt::transparent);  // 关键步骤：预填充透明背景
        QPainter painter(&pixmap);
        QFont font = this->font() ;
        font.setPointSize(120) ;
        font.setFamily("楷体");
        font.setBold(true) ;
        painter.setFont(font) ;
        painter.setPen(QPen(QColor(Qt::blue))) ;
        painter.drawText(pixmap.rect(),Qt::AlignHCenter|Qt::AlignVCenter,"中央人民广播电台") ;

        QStyleOptionButton option;
        option.rect = QRect( 5, 5, 50, 50);
        option.state = QStyle::State_Enabled | QStyle::State_Active;
        option.state |= QStyle::State_On ;

        painter.setPen(QPen(QBrush(QColor(Qt::blue)),3)) ;
        style()->drawControl(QStyle::CE_CheckBox, &option, &painter);
        pixmap.save("D:\\justTest.png");
    }

    QString strStyle=R"(
        QPushButton {
                background-color: #6CEF6C;
                border-radius: 10px;
                color: white;
                border: 2px solid blue;
                padding: 4px 4px;
                min-width:80px;
                min-height:16px;
            }
        QLabel{
                padding: 4px 4px;
                min-width:120px;
                min-height:16px;
                font: bold 16px 微软雅黑;
            }

        QPushButton:hover { background-color: #87ceeb; }
        QPushButton:pressed { background-color: #1e90ff;}
        QPushButton:checked { background-color: #1e90ff;}
        QPushButton:disabled { background-color: gray; color: #cccccc;}

    )";

    setStyleSheet(R"(
        QProgress:horizontal{max-height: 20px;}
        QSlider::groove:horizontal { height: 10px; background: #DCDCDC; border-radius: 4px;}
        QSlider::sub-page:horizontal { background: #3EA8FF;  border-radius: 4px;}
        QSlider::handle:horizontal {
            width: 16px;
            height: 16px;
            margin: -6px 0;
            background: white;
            border: 2px solid #3EA8FF;
            border-radius: 10px; }

        QSlider::groove:vertical { width: 8px; background: #3EA8FF;  border-radius: 4px; }
        QSlider::sub-page:vertical { background: #DCDCDC;  border-radius: 4px; }
        QSlider::handle:vertical {
            width: 16px;
            height: 16px;
            margin: 0 -6px;
            background: white;
            border: 2px solid #3EA8FF;
            border-radius: 9px; }

        QSlider::handle:hover { background: #F0F0F0;}
        QSlider::handle:pressed { background: #E0E0E0; border-color: #2D7FD1; }
        /*QComboBox{ font: bold 24px 微软雅黑; min-width:200px; }*/
        QHeaderView{ background-color:skyblue;}

        QHeaderView::section:vertical{ min-width:32px; border: none; padding:3px;}
        QHeaderView::section{ background-color:skyblue; border: 1px solid gray; text-align: left;}

        QTableView{ background-color: rgb(226, 249, 255);}
        QTableView::Item{ border: 1px solid gray;}
        QTableView::Item::selected{ background-color: #a0bb9e ; color: white;}
        QTableView QTableCornerButton::section {background-color: skyblue; }
 /*
        QTableView::indicator {
            position: relative;
            right: -120%;
            margin-right: 8px;
        }
*/
QTableView::item::indicator {
    /* 将复选框靠右对齐 */
    position: right;
    /* 可以添加一些右边距来调整位置 */
}

QTableView QHeaderView::section {
    qproperty-alignment: AlignRight;
}

        //CheckBox::indicator{ width: 20px; height: 20px;}
    )") ;

    qApp->setStyleSheet(strStyle) ;

    QVBoxLayout *pLay0 = new QVBoxLayout(ui->groupBox) ;
    pLay0->setAlignment(Qt::AlignTop) ;
    pLay0->setSpacing(0) ;

    for(int i=0; i<30; i++)
    {
        QFrame *pSub = new QFrame(this) ;
        QHBoxLayout *pLay = new QHBoxLayout(pSub) ;
        if(pLay)
        {
            pLay->setAlignment(Qt::AlignLeft) ;
            pLay->setSpacing(0) ;
            QLabel *pNewFlag = new QLabel(QString("Frame: ")+QString::number(i+1) ,pSub) ;
            pLay->addWidget(pNewFlag) ;
            pLay->setSpacing(10) ;
            for(int j=0; j<9; j++)
            {
                QPushButton *btn = new QPushButton(QString("你好%1-%2").arg(i+1).arg(j+1),pSub);
                pLay->addWidget(btn) ;
                btn->setFocusPolicy(Qt::NoFocus);
                btn->setCursor(Qt::PointingHandCursor) ;
            }
        }
        pSub->setFixedHeight(45) ;
        pSub->setStyleSheet("QFrame{background-color: skyblue; } QPushButton{font: bold 14px 微软雅黑;} "+ strStyle) ;

        pLay0->addWidget(pSub) ;
    }

    ui->comboBox->setFixedWidth(200);
    ui->comboBox->addItems(QString("中国,美国,日本").split(',')) ;

    for(int i=0; i<200; i++)
    {
        QFrame *pSub = new QFrame(this) ;
        QHBoxLayout *pLay = new QHBoxLayout(pSub) ;
        if(pLay)
        {
            pLay->setAlignment(Qt::AlignLeft) ;
            pLay->setSpacing(10) ;
            QLabel *pNewFlag = new QLabel(QString("Frame: ")+QString::number(i+1) ,pSub) ;
            pLay->addWidget(pNewFlag) ;
            pLay->addWidget(new QPushButton("你好1",pSub)) ;
            pLay->addWidget(new QPushButton("你好2",pSub)) ;
            pLay->addWidget(new QPushButton("你好3",pSub)) ;
            pLay->addWidget(new QPushButton("你好4",pSub)) ;
            pLay->addWidget(new QPushButton("你好5",pSub)) ;
            pLay->addWidget(new QPushButton("你好6",pSub)) ;
            pLay->addWidget(new QPushButton("你好7",pSub)) ;
            pLay->addWidget(new QPushButton("你好8",pSub)) ;
        }
        pSub->setFixedHeight(60) ;
        pSub->setStyleSheet("QFrame{background-color: pink; } QPushButton{font: bold 14px 微软雅黑;} " + strStyle) ;

        ui->scrollAreaWidgetContents->layout()->addWidget(pSub) ;
        ui->scrollArea->ensureWidgetVisible(pSub) ;
    }

    qDebug() << ui->scrollAreaWidgetContents->size()  <<  ui->scrollArea->size() << ui->scrollAreaWidgetContents->rect() ;

    //pwidget->render(&pixmap);

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setFocusPolicy(Qt::NoFocus) ;

    ui->tableView->setShowGrid(false) ;
    QStandardItemModel *m_pModel = new QStandardItemModel(6,5,this) ;
    m_pModel->setHorizontalHeaderLabels({"Name","Age","Height","Action","Thinking"}) ;
    ui->tableView->setModel(m_pModel) ;
    ui->tableView->setMouseTracking(true) ;

    ComboBoxDelegate *delegate0 = new ComboBoxDelegate(this);
    ui->tableView->setItemDelegateForColumn(0, delegate0);
    delegate0->setTableView(ui->tableView);

    SpinBoxDelegate *delegate1 = new SpinBoxDelegate(this);
    SliderDelegate *delegate2 = new SliderDelegate(this);
    ButtonDelegate *delegate3 = new ButtonDelegate(this);
    ProgressDelegate *delegate4 = new ProgressDelegate(this);
    ButtonDelegate *delegate5 = new ButtonDelegate(this);
    SideValueDelegate *delegate6 = new SideValueDelegate(this);
    delegate3->setTableView( ui->tableView );
    delegate5->setTableView( ui->tableView );
    delegate6->setTableView( ui->tableView );
    delegate5->setText("打强");
    delegate2->setRange(50, 300) ;
    delegate2->setHexMode( false );
    ui->tableView->setItemDelegateForColumn(1, delegate1);
    ui->tableView->setItemDelegateForColumn(2, delegate6);
    ui->tableView->setItemDelegateForColumn(3, delegate3);
    ui->tableView->setItemDelegateForColumn(4, delegate5);

    delegate3->installEventFilter(this) ;
    srand(time(nullptr)) ;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<5; j++)
        {
            QStandardItemEx *item = new QStandardItemEx("") ;

            if(j==1 || j==2)
                item->setCheckable(true) ;

            if(j==0)
            {
                item->setText("中央人民政府");
                item->setBackground(QBrush(Qt::red)) ;
            }

            if(j==1)
                item->setInt((20+rand()%60)) ;

            if(j==2)
                item->setText(QString::number(120+rand()%100)) ;

            if(j==3)
            {
                item->setText("你好") ;
                item->setEditable(false) ;
                int nValue = 500 + rand()%1000 ;
                delegate3->setValue(i,nValue) ;
            }

            if(j==4)
            {
                item->setEditable(false) ;
                int nValue = 20 + rand()%100 ;
                delegate4->initValue(i,nValue) ;
                delegate5->setValue(i,nValue) ;
                item->setInt((nValue)) ;
                item->setBackground(QBrush(QColor("skyblue"))) ;
            }

            m_pModel->setItem(i,j,item) ;
        }
        ui->tableView->setRowHeight(i,30) ;
    }

    // QHotKey hotkey(QKeySequence("Shift+Space"), true); // true表示全局生效
    // connect(&hotkey, &QHotKey::activated, []() {
    //     qDebug() << "全局Shift+Space触发";
    // });

    //ui->graphicsView->setImage("D:/bg.png") ;
    ui->graphicsView->hide() ;
    ui->textEdit->hide() ;

    CheckBoxHeaderView *pNH = new CheckBoxHeaderView(Qt::Horizontal,ui->tableView) ;
    pNH->setCheckCol(1) ;
    pNH->setCheckCol(2) ;
    ui->tableView->setHorizontalHeader(pNH) ;

    QHeaderView *header = ui->tableView->horizontalHeader() ;
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setSectionResizeMode(0,QHeaderView::Fixed);
    header->resizeSection(0,150) ;
    header->setSectionResizeMode(1,QHeaderView::Fixed);
    header->resizeSection(1,150) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *editor, QEvent *event)
{
    if(event->type() == QEvent::Enter)
    {
        qDebug() << "QEvent::Enter" ;
        QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
        return true ;
    }

    if(event->type() == QEvent::Leave)
    {
        QApplication::restoreOverrideCursor();
        return true ;
    }

    return QMainWindow::eventFilter(editor, event);
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this) ;

    painter.drawImage(20,20,QImage("D:\\123456.png")) ;
    QMainWindow::paintEvent(event);
}

void MainWindow::on_pushButton_clicked()
{
    DialogScrollTest dlg(this) ;
    dlg.exec() ;
}


void MainWindow::on_pushButton_2_clicked()
{
    DialogChart dlg(this) ;
    dlg.exec() ;
}


void MainWindow::on_pushButtonSavePng_clicked()
{
    QPixmap Png(size()) ;
    this->render(&Png) ;

    Png.save("d:/mainwindow.png") ;
}

