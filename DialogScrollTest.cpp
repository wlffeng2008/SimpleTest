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
}

DialogScrollTest::~DialogScrollTest()
{
    delete ui;
}
