#include "framedragset.h"
#include "ui_framedragset.h"

#include <QPainter>
#include <QPaintEvent>
#include <QCursor>

FrameDragset::FrameDragset(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::FrameDragset)
{
    ui->setupUi(this);
}

FrameDragset::~FrameDragset()
{
    delete ui;
}

void FrameDragset::setCursorShape(bool bSet)
{
    static  bool  bHand = false;

    if(bHand && bSet)
        return;
    bHand = bSet;
    if(bSet)
    {
        QApplication::setOverrideCursor(Qt::PointingHandCursor) ;
    }
    else
    {
        QApplication::restoreOverrideCursor() ;
    }
}

int m_rectHW = 24;

void FrameDragset::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::darkCyan);
    painter.drawRoundedRect(rect().adjusted(0,0,-1,-1),10,10);

    for(int i=3; i>=0; i--)
    {
        painter.setBrush(m_values[i]?Qt::red:Qt::blue);
        painter.drawRoundedRect(m_rects[i],m_rectHW/2,m_rectHW/2);
    }
}

void FrameDragset::mousePressEvent(QMouseEvent *event)
{
    m_pressed = true;

    m_clickPt = event->pos();
    if(m_hit != -1)
        m_clickpadding = m_rects[m_hit].width();
    qDebug() << m_clickPt;

    QFrame::mousePressEvent(event);
}

void FrameDragset::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_hit != -1)
    {
        if(!m_draging)
        {
            m_values[m_hit] = !m_values[m_hit] ;
            qDebug() << m_values[m_hit];
            m_rects[m_hit].setWidth(m_rectHW);
        }
        else
        {
            int nW = event->pos().x() - m_clickPt.x() + m_clickpadding;

            if(m_hit  == 0)
            {
                if(m_clickpadding>2*m_step)
                {
                    m_values[1] = 0;
                    m_values[2] = 0;
                    m_rects[1].setWidth(m_rectHW);
                    m_rects[2].setWidth(m_rectHW);
                }

                if(m_clickpadding>m_step)
                {
                    m_values[1] = 0;
                    m_rects[1].setWidth(m_rectHW);
                }

                if(m_clickpadding <= m_rectHW)
                {
                    m_values[0] = 1;
                    m_rects[0].setWidth(m_rectHW);
                }

                if(nW>m_step*2)
                {
                    m_values[0] = 3 ; // b 11
                    m_values[1] = 3 ; // b 11
                    m_values[2] = 2 ; // b 10
                    nW = m_step*3;
                }
                else if(nW>m_step)
                {
                    m_values[0] = 3 ; // b 11
                    m_values[1] = 2 ; // b 10
                    nW = m_step*2;
                }
                else if(nW>m_rectHW)
                {
                    m_values[0] = 2 ; // b 10
                    nW = m_step;
                }
                else{
                    m_values[0] = 1;
                }
            }

            if(m_hit  == 1)
            {
                if(m_clickpadding<=m_rectHW)
                {
                    m_values[1] = 1;
                    m_rects[1].setWidth(m_rectHW);
                }
                if(nW>m_step)
                {
                    m_values[1] = 3 ; // b 11
                    m_values[2] = 2 ; // b 10
                    nW = m_step*2;
                }
                else if(nW>m_rectHW)
                {
                    m_values[1] = 2 ; // b 10
                    nW = m_step;
                }
                else
                {
                    m_values[1] = 1;
                }
            }

            if(m_hit  == 2)
            {
                if(nW>m_rectHW)
                {
                    m_values[2] = 2 ; // b 10
                    nW = m_step;
                }
                else
                {
                    m_values[2] = 1;
                    m_rects[2].setWidth(m_rectHW);
                }
            }

            if(nW<m_rectHW) nW = m_rectHW;

            m_rects[m_hit].setWidth(nW);

        }
        quint8 value = ((m_values[3] << 6) | ( m_values[2] << 4) | ( m_values[1] << 2) | ( m_values[0]));

        qDebug() << QString::asprintf("0x%02X",value);

    }
    update();
    m_draging = false;
    m_pressed = false;

    QFrame::mouseReleaseEvent(event);
}

void FrameDragset::mouseMoveEvent(QMouseEvent *event)
{
    int move = event->pos().x() - m_clickPt.x();
    if(m_draging)
    {
        int nW = move + m_clickpadding;
        if(nW<m_rectHW) nW = m_rectHW;

        if(m_hit  == 0)
            if(nW>m_step*3) nW = m_step*3;
        if(m_hit  == 1)
            if(nW>m_step*2) nW = m_step*2;
        if(m_hit  == 2)
            if(nW>m_step)   nW = m_step;

        m_rects[m_hit].setWidth(nW);
        update();
    }
    else
    {
        m_hit = -1;
        bool set = false;
        for(int i=0; i<4; i++)
        {
            if(m_rects[i].contains(event->pos()))
            {
                m_hit = i ;
                set = true;
                break;
            }
        }

        setCursorShape(set);
    }

    if(m_pressed && abs(move)>10)
    {
        if(m_hit != -1 && m_hit != 3 && m_values[m_hit])
            m_draging = true;
    }

    QFrame::mouseMoveEvent(event);
}

void FrameDragset::resizeEvent(QResizeEvent*event)
{
    qDebug() << "resizeEvent:" << rect();
    int step = (rect().width() - m_rectHW - 20) / 3 ;
    m_step = step;
    for(int i=0; i<4; i++)
    {
        m_rects[i].setSize(QSize(m_rectHW,m_rectHW));
        m_rects[i].setX(step*i + 10);
        m_rects[i].setY(8);
    }

    QFrame::resizeEvent(event);
}