#include "keyboardbutton.h"
#include <QPainter>
#include <QPainterPath>

KeyboardButton::KeyboardButton(QWidget *parent):QPushButton(parent)
{
    m_mtFlag = ":/images/mt0.png" ;
}

void KeyboardButton::setMtFlag(const QString&flag)
{
    m_mtFlag = flag;
}

void KeyboardButton::showMtFlag(bool show)
{
    m_showMtFlag=show;
}

void KeyboardButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event) ;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(m_showMtFlag)
        painter.drawImage(0,0,QImage(m_mtFlag));
}
