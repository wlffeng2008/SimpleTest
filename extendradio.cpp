#include "extendradio.h"

#include <QPainter>

#include <QPaintEvent>

ExtendRadio::ExtendRadio(QWidget *parent):QRadioButton(parent) {}

void ExtendRadio::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QRect rc = this->rect().adjusted(1,1,-1,-1);
    int iconSize = rc.height();
    QRect iconRect(1, 1, iconSize, iconSize);

    QColor ringColor("#6329B6");
    QColor innerColor("#6329B6");
    int borderWidth = 2;

    painter.save();
    QPen pen(ringColor, borderWidth);
    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(iconRect.adjusted(1, 1, -1, -1));

    if (isChecked())
    {
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(innerColor));

        QRect temp = rc ;
        temp.setWidth(rc.height());
        painter.drawEllipse(temp.adjusted(6, 6, -6, -6));
    }
    painter.restore();

    QRect textRect = rc.adjusted(iconSize + 10, 0, 0, 0);
    QTextOption opt;
    opt.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    painter.drawText(textRect, text(), opt);

    event->accept();
}