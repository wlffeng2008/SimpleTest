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

void CapsuleSlider::mousePressEvent(QMouseEvent *event)
{
    QSlider::mousePressEvent(event);
    if(event->button() == Qt::LeftButton)
    {
        if(orientation() == Qt::Horizontal)
        {
            int w = width();
            setValue(event->pos().x()*(maximum() - minimum()) / w + minimum());
        }
        else
        {
            int h = height();
            setValue((h-event->pos().y())*(maximum() - minimum()) / h + minimum());
        }
    }
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

    if(orientation() == Qt::Horizontal)
    {
        p.drawRoundedRect(groove.adjusted(0,6,0,-6), 6, 6);
        int hW = handleRect.width();
        int w = width() - hW;

        QRect progress = groove;
        int nPW = (value()-minimum())*w/(maximum() - minimum()) + hW/2;
        progress.setWidth(nPW);
        p.setBrush(QColor("#409EFF"));


        QLinearGradient lg(0, 0, 1, 0);
        lg.setCoordinateMode(QGradient::ObjectBoundingMode);
        lg.setColorAt(0, QColor("#E0E0FF"));
        lg.setColorAt(1, QColor("#409EFF"));
        p.setBrush(QBrush(lg));
        p.drawRoundedRect(progress.adjusted(0,6,0,-6), 6, 6);

        handleRect.setLeft(progress.width()-hW/2);
        handleRect.setRight(progress.width()+hW/2);
        int radius = handleRect.height() / 2;
        p.setBrush(QColor("#FFFFFF"));
        p.setPen(QPen(QColor("#409EFF"), 2));
        p.drawRoundedRect(handleRect.adjusted(1,1,-1,-1), radius, radius);
    }
    else
    {
        p.drawRoundedRect(groove.adjusted(6,0,-6,0), 6, 6);
        int hH = handleRect.height();
        int h = height() - hH;

        QRect progress = groove;
        int nPH = (value()-minimum())*h/(maximum() - minimum()) + hH/2;
        progress.setBottom(groove.bottom());
        progress.setTop(height() - nPH);
        p.setBrush(QColor("#409EFF"));
        p.drawRoundedRect(progress.adjusted(6,0,-6,0), 6, 6);

        handleRect.setTop(progress.top()-hH/2);
        handleRect.setBottom(progress.top()+hH/2);
        int radius = handleRect.width() / 2;
        p.setBrush(QColor("#FFFFFF"));
        p.setPen(QPen(QColor("#409EFF"), 2));
        p.drawRoundedRect(handleRect.adjusted(1,1,-1,-1), radius, radius);
    }
}
