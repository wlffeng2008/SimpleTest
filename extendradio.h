#ifndef EXTENDRADIO_H
#define EXTENDRADIO_H

#include <QRadioButton>

class ExtendRadio : public QRadioButton
{
    Q_OBJECT
public:
    ExtendRadio(QWidget *parent=nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // EXTENDRADIO_H
