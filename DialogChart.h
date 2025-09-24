#ifndef DIALOGCHART_H
#define DIALOGCHART_H

#include <QDialog>

namespace Ui {
class DialogChart;
}

class DialogChart : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChart(QWidget *parent = nullptr);
    ~DialogChart();

protected:
    void mouseMoveEvent(QMouseEvent *event) override  ;
    void mousePressEvent(QMouseEvent *event) override ;
    void mouseReleaseEvent(QMouseEvent *event) override ;


private:
    Ui::DialogChart *ui;
    bool m_bDraging = false ;
    QPoint m_dragStartPos;
};

#endif // DIALOGCHART_H
