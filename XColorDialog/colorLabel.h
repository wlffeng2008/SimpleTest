#ifndef COLORLABEL_H
#define COLORLABEL_H
 
#include <QLabel>
 
class ColorLabel : public QLabel
{
    Q_OBJECT
public:
    ColorLabel( QWidget* parent = 0){}
    void mousePressEvent(QMouseEvent *e){
      Q_UNUSED(e);
      emit clicked(objectName());
    }
 
signals:
    void clicked(QString);//点击信号
};
 
#endif // CLICKEDLABEL_H
