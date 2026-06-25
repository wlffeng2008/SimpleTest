#ifndef CAPSULESLIDER_H
#define CAPSULESLIDER_H

#include <QObject>
#include <QSlider>

class CapsuleSlider : public QSlider
{
    Q_OBJECT
public:
    explicit CapsuleSlider(QWidget *parent = nullptr);
    explicit CapsuleSlider(Qt::Orientation orientation, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
};

#endif // CAPSULESLIDER_H
