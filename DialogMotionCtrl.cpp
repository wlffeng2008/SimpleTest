#include "DialogMotionCtrl.h"
#include "ui_DialogMotionCtrl.h"

#include "sldmv.h"

DialogMotionCtrl::DialogMotionCtrl(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogMotionCtrl)
{
    ui->setupUi(this);
}

DialogMotionCtrl::~DialogMotionCtrl()
{
    delete ui;
}
