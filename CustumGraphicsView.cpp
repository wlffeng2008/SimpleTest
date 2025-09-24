#include "CustumGraphicsView.h"

#include <QDebug>
#include <QMouseEvent>
#include <QScrollBar>

CustumGraphicsView::CustumGraphicsView(QWidget *parent):QGraphicsView(parent) {

    m_sence = new QGraphicsScene(parent) ;
    setScene(m_sence) ;

    setDragMode(QGraphicsView::ScrollHandDrag);  // 支持拖拽平移
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);  // 缩放以鼠标为中心
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //setMouseTracking(true) ;
    //setAcceptDrops(true) ;
}

void CustumGraphicsView::setImage(const QString&strImage)
{
    m_img = QImage(strImage) ;
    reset() ;
}

void CustumGraphicsView::zoomIn()
{
    if(m_fScale>10)
        return ;
    m_fScale *= 1.1 ;
    scale(1.1,1.1) ;
}

void CustumGraphicsView::zoomOut()
{
    m_fScale *= 0.9 ;
    scale(0.9,0.9) ;
}

void CustumGraphicsView::reset()
{
    m_sence->clear() ;
    QPixmap pixmap = QPixmap::fromImage(m_img);
    if (!pixmap.isNull())
    {
        m_sence->addPixmap(pixmap);
        m_rcOrg = pixmap.rect();

        m_sence->setSceneRect(QRect(1,1,2,2));
        m_sence->setSceneRect(m_rcOrg);
    }
    m_fScale = 1 ;
}

QRgb CustumGraphicsView::rgb(int x,int y)
{
    QRgb value = m_img.pixel(x,y) ;
    return value ;
}

int CustumGraphicsView::R(int x,int y) { return qRed(m_img.pixel(x,y)) ;}
int CustumGraphicsView::G(int x,int y) { return qGreen(m_img.pixel(x,y)) ;}
int CustumGraphicsView::B(int x,int y) { return qBlue(m_img.pixel(x,y)) ;}

void CustumGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    // qDebug() << event->localPos() << mapToScene(event->localPos().toPoint());
    QGraphicsView::mouseMoveEvent(event);
}

void CustumGraphicsView::wheelEvent(QWheelEvent *event)
{
    if(m_bCtrlPressed)
    {
        if(event->inverted())
            zoomIn() ;
        else
            zoomOut() ;
        return ;
    }

    QGraphicsView::wheelEvent(event);
}


void CustumGraphicsView::keyPressEvent(QKeyEvent *event)
{
    int nKey = event->key();
    //qDebug() << Qt::hex << event->key();
    if(nKey == Qt::Key_Control)
    {
        m_bCtrlPressed = true ;
        qDebug() <<  "Key_Control Pressed" ;
    }
    if(nKey == Qt::Key_Shift)
    {
        m_bShfitPressed = true ;
        qDebug() <<  "Key_Shift Pressed" ;
    }
    if(nKey == Qt::Key_Alt)
    {
        m_bAltPressed = true ;
        qDebug() <<  "Key_Alt Pressed" ;
    }
    switch(nKey)
    {
    case Qt::Key_Plus:
    case Qt::Key_Equal:
        zoomIn() ;
        break;

    case Qt::Key_Minus:
    case Qt::Key_Underscore:
        zoomOut() ;
        break;

    case Qt::Key_Enter:
    case Qt::Key_Return:
    {
        reset() ;
    }
        break;
    }

    QGraphicsView::keyPressEvent(event);
}

void CustumGraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    int nKey = event->key();
    if(nKey == Qt::Key_Control)
    {
        m_bCtrlPressed = false ;
        qDebug() <<  "Key_Control Released" ;
    }
    if(nKey == Qt::Key_Shift)
    {
        m_bShfitPressed = false ;
        qDebug() <<  "Key_Shift Released" ;
    }
    if(nKey == Qt::Key_Alt)
    {
        m_bAltPressed = false ;
        qDebug() <<  "Key_Alt Released" ;
    }
    QGraphicsView::keyReleaseEvent(event);
}
