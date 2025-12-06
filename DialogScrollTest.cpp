#include "DialogScrollTest.h"
#include "ui_DialogScrollTest.h"

#include <QPushButton>

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
    setStyleSheet(strSpinBoxStyle);
}

DialogScrollTest::~DialogScrollTest()
{
    delete ui;
}
