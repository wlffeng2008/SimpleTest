#include "CapsuleSlider.h"
#include <QPainter>
#include <QStyleOptionSlider>
#include <QMouseEvent>

CapsuleSlider::CapsuleSlider(QWidget *parent)
    : QSlider(parent)
{
    setMinimum(0);
    setMaximum(100);
    setValue(50);
}

CapsuleSlider::CapsuleSlider(Qt::Orientation orientation, QWidget *parent)
    : QSlider(orientation, parent)
{
    setMinimum(0);
    setMaximum(100);
    setValue(50);
}

void CapsuleSlider::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QStyleOptionSlider opt;
    opt.initFrom(this);
    opt.minimum = minimum();
    opt.maximum = maximum();
    opt.sliderPosition = sliderPosition();
    opt.orientation = orientation();

    QRect handleRect =
        style()->subControlRect(
            QStyle::CC_Slider,
            &opt,
            QStyle::SC_SliderHandle,
            this
            );

    QRect groove = rect();
    p.setBrush(QColor("#D0D0D0"));
    p.setPen(Qt::NoPen);
    p.drawRoundedRect(groove, 6, 6);

    if(orientation() == Qt::Horizontal)
    {
        int hW = handleRect.width();
        int w = width() - hW;

        QRect progress = groove;
        int nPW = (value()-minimum())*w/(maximum() - minimum()) + hW/2;
        progress.setWidth(nPW);
        p.setBrush(QColor("#409EFF"));
        p.drawRoundedRect(progress, 6, 6);

        handleRect.setLeft(progress.width()-hW/2);
        handleRect.setRight(progress.width()+hW/2);
        int radius = handleRect.height() / 2;
        p.setBrush(QColor("#FFFFFF"));
        p.setPen(QPen(QColor("#409EFF"), 2));
        p.drawRoundedRect(handleRect, radius, radius);
    }
    else
    {
        int hH = handleRect.height();
        int h = height() - hH;

        QRect progress = groove;
        int nPH = (value()-minimum())*h/(maximum() - minimum()) + hH/2;
        progress.setBottom(groove.bottom());
        progress.setTop(height() - nPH);
        p.setBrush(QColor("#409EFF"));
        p.drawRoundedRect(progress, 6, 6);

        handleRect.setTop(progress.top()-hH/2);
        handleRect.setBottom(progress.top()+hH/2);
        int radius = handleRect.width() / 2;
        p.setBrush(QColor("#FFFFFF"));
        p.setPen(QPen(QColor("#409EFF"), 2));
        p.drawRoundedRect(handleRect, radius, radius);
    }
}
