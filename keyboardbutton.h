#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QLabel>

class KeyboardButton : public QPushButton
{
    Q_OBJECT
public:
    KeyboardButton(QWidget *parent);
    void setMtFlag(const QString&flag);
    void showMtFlag(bool show=true);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString m_mtFlag;
    bool m_showMtFlag=true;
};

#endif // KEYBOARDBUTTON_H
