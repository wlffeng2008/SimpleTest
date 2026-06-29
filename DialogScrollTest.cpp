#include "DialogScrollTest.h"
#include "ui_DialogScrollTest.h"

#include <QPushButton>
#include <QMessageBox>

DialogScrollTest::DialogScrollTest(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogScrollTest)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::WindowMinMaxButtonsHint) ;

    for(int i=0; i<30; i++)
    {
        QPushButton *button = new QPushButton(QString("Button %1").arg(i+1),this) ;
        button->setMaximumWidth(80) ;
        button->setMinimumHeight(30) ;
        ui->scrollAreaWidgetContents->layout()->addWidget(button) ;
    }

    ui->tabWidget->clear() ;
    for(int i=0; i<250; i++)
    {
        if(i%8 == 0)
        {
            QLabel *flag = new QLabel(QString("哇哈哈%1").arg(i),this) ;
            ui->scrollAreaWidgetContents_2->layout()->addWidget(flag) ;
            m_flags.push_back(flag) ;
            ui->tabWidget->addTab(new QFrame(this),QString("Tab%1").arg(i));
        }
        QPushButton *button = new QPushButton(QString("Button %1").arg(i+1),this) ;
        button->setMaximumWidth(150) ;
        button->setMinimumHeight(40) ;
        ui->scrollAreaWidgetContents_2->layout()->addWidget(button) ;
    }

    QImage svgImg = QImage("D:\\fa-349.svg") ;

    qDebug() << svgImg;
    ui->label3333->setPixmap(QPixmap::fromImage(svgImg));

    connect(ui->pushButtonGo1,&QPushButton::clicked,this,[=]{ui->scrollArea_2->ensureWidgetVisible(m_flags[0]);}) ;
    connect(ui->pushButtonGo2,&QPushButton::clicked,this,[=]{ui->scrollArea_2->ensureWidgetVisible(m_flags[1]);}) ;
    connect(ui->pushButtonGo3,&QPushButton::clicked,this,[=]{ui->scrollArea_2->ensureWidgetVisible(m_flags[2]);}) ;
    connect(ui->pushButtonGo4,&QPushButton::clicked,this,[=]{ui->scrollArea_2->ensureWidgetVisible(m_flags[3]);}) ;

    connect(ui->tabWidget,&QTabWidget::currentChanged,this,[=](int index){ ui->scrollArea_2->ensureWidgetVisible(m_flags[index]); }) ;

    QString strSpinBoxStyle(R"(

QAbstractSpinBox {
    background: #f8f9fa;
    border: 1px solid #dee2e6;
    border-radius: 6px;
    padding: 4px 4px 4px 4px;
    font-size: 14px;
    color: #333;
}

QAbstractSpinBox:focus {
    border-color: #409eff;
    outline: none;
}

QAbstractSpinBox::up-button{
    subcontrol-origin: border;
    subcontrol-position: right;
    background: red;
    width:16px;
    height:16px;
    border:none;
    margin-right:22px;

    border-top-left-radius: 6px;
    border-bottom-left-radius: 6px;
}

QAbstractSpinBox::down-button{
    subcontrol-origin: border;
    subcontrol-position: right;
    background: gray;
    width:16px;
    height:16px;
    border:none;
    margin-right: 4px;

    border-top-right-radius: 6px;
    border-bottom-right-radius: 6px;
}

QAbstractSpinBox::up-button:hover {
    background: green;
    border-top-left-radius: 6px;
    border-bottom-left-radius: 6px;
}

QAbstractSpinBox::down-button:hover {
    background: blue;
    border-top-right-radius: 6px;
    border-bottom-right-radius: 6px;
}

QAbstractSpinBox::up-button:pressed,
QAbstractSpinBox::down-button:pressed {
    opacity: 0.8;
}

/*QAbstractSpinBox::down-button{
    subcontrol-origin: border;
    subcontrol-position: left;
    background: #f5f7fa;
    width:40px;
    height:38px;
    border:none;
    border-top-left-radius: 6px;
    border-bottom-left-radius: 6px;
    margin-left:1px;
    border-right: 1px solid #dee2e6;
}
QAbstractSpinBox::up-button{
    subcontrol-origin: border;
    subcontrol-position: right;
    background: #f5f7fa;
    width:40px;
    height:38px;
    border:none;
    border-top-right-radius: 6px;
    border-bottom-right-radius: 6px;
    margin-right: 1px;
    border-left: 1px solid #dee2e6
}

QAbstractSpinBox::up-arrow {
    image: url(:/images/7.png);
}
QAbstractSpinBox::up-arrow:hover {
    image: url(:/images/8.png);
}
QAbstractSpinBox::down-arrow {
    image: url(:/images/9.png);
}
QAbstractSpinBox::down-arrow:hover {
    image: url(:/images/10.png);
}*/

)");
    //setStyleSheet(strSpinBoxStyle);

    ui->spinBoxTest->setStyleSheet(R"(
QSpinBox {
    padding-left: 10px;
    padding-right: 10px;
    background-color:white;
    border:1px solid #a1a1a1;
    text-align:center;
}
QSpinBox::up-button {
    subcontrol-position: right;
    right: 5px; /* 向左偏移（实验性，效果有限）*/

    width: 18px;
    height: 18px;
    subcontrol-origin: border;        /* ✅ 必须设，否则尺寸无效 */

    background-color:green;
}
QSpinBox::down-button {
    subcontrol-position: left;
    left: 5px;
    width: 18px;
    height: 18px;
    subcontrol-origin: border;        /* ✅ 必须设，否则尺寸无效 */

    background-color:red;
}

)");

    m_downloader =new Downloader(this);

    connect(m_downloader, &Downloader::progressChanged, this, [=](int percent){

        ui->progressBar->setValue(percent);
    });
    connect(m_downloader, &Downloader::finished, this, [=]{

    });
    connect(m_downloader, &Downloader::errorOccurred, this, [=](const QString &err){
        qDebug() << err;
    });
}

DialogScrollTest::~DialogScrollTest()
{
    delete ui;
}

void DialogScrollTest::on_pushButtonDownload_clicked()
{

    QString url = ui->lineEditUrl->text().trimmed();
    QString savePath = ui->lineEditFile->text().trimmed();
    if (url.isEmpty() || savePath.isEmpty())
    {
        QMessageBox::warning(this, "提示", "请填写下载地址和保存路径");
        return;
    }
    m_downloader->startDownload(url, savePath);
}

