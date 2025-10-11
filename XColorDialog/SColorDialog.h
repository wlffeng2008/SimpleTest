#ifndef SCOLORDIALOG_H
#define SCOLORDIALOG_H

#include <QDialog>
#include "XColorPreview.hpp"
#include "SColorSquare.h"
#include "XGradientSlider.hpp"
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>
#include <QList>
#include "colorconfig.h"
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>

class SColorDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SColorDialog(QWidget *parent = 0);

    QColor  color() const;

protected:
    bool event(QEvent *event) override {
    if (event->type() == QEvent::ActivationChange)
        {
            if(QApplication::activeWindow() != this)
            {
                this->hide();
            }
        }
        return QWidget::event(event);
    }

private:
    ColorConfig colorConfig;
    enum CheckedColor
    {
        H,S,V,R,G,B
    }checkedColor;

    QVBoxLayout*        vLayout;
    SColorSquare*       colorSquare;
    XGradientSlider*    sliderHue;

    QHBoxLayout* hLayoutComboxType;
    QComboBox* comboxColorType;
    QHBoxLayout* hLayoutLineEdit;
    QLineEdit* lineeditHex;
    QLineEdit* lineeditColorFirst;
    QLineEdit* lineeditColorSecond;
    QLineEdit* lineeditColorThird;

    QComboBox* comboxColorHistory;
    QList<QLabel*>  lstColorRecommend;

    QIntValidator *intValidator255;
    QIntValidator *intValidator359;

    QWidget* m_wdgOwner;
private:
    void    SetupUI();
    void    SetConnect();

    void color2Text();
    void text2Color();

signals:
    void    colorChanged(QColor);
    void    checkedChanged(char);
    void    colorSelected(QColor);

public slots:
    void    UpdateWidgets();
    void    UpdateColor();
    void    SetHSV();

    void    SetColor(QColor color);
    void    comboxChanged(int index);
    void    comboxColorChanged(int index);

    void    ClickedOkButton();
    void    ClickedCloseButton();
    void    clickLabel(QString csText);
    void setOwner(QWidget* pOwner){m_wdgOwner = pOwner;}
    QWidget* owner(){return  m_wdgOwner;}
};

#endif // SCOLORDIALOG_H
