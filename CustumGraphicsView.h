#ifndef CUSTUMGRAPHICSVIEW_H
#define CUSTUMGRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRgb>

class CustumGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    CustumGraphicsView(QWidget *parent=nullptr);

    void setImage(const QString&strImage) ;

    void zoomIn() ;
    void zoomOut() ;
    void reset() ;

    QRgb rgb(int x,int y) ;
    int R(int x,int y) ;
    int G(int x,int y) ;
    int B(int x,int y) ;

protected:
    void mouseMoveEvent(QMouseEvent *event) override ;

    void keyPressEvent(QKeyEvent *event) override ;
    void keyReleaseEvent(QKeyEvent *event) override ;
    void wheelEvent(QWheelEvent *event) override;

private:
     QGraphicsScene *m_sence = nullptr ;

    qreal  m_fScale = 1.0;
    QImage m_img ;
    QRect  m_rcOrg ;

    bool m_bCtrlPressed = false ;
    bool m_bShfitPressed = false ;
    bool m_bAltPressed = false ;
} ;

#endif // CUSTUMGRAPHICSVIEW_H
