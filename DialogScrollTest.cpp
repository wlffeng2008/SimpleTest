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

    for(int i=0; i<50; i++)
    {
        QPushButton *button = new QPushButton(QString("Button %1").arg(i+1),this) ;
        button->setMaximumWidth(150) ;
        button->setMinimumHeight(40) ;
        ui->scrollAreaWidgetContents_2->layout()->addWidget(button) ;
    }
}

DialogScrollTest::~DialogScrollTest()
{
    delete ui;
}
