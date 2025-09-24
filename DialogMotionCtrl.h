#ifndef DIALOGMOTIONCTRL_H
#define DIALOGMOTIONCTRL_H

#include <QDialog>

namespace Ui {
class DialogMotionCtrl;
}

class DialogMotionCtrl : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMotionCtrl(QWidget *parent = nullptr);
    ~DialogMotionCtrl();

private:
    Ui::DialogMotionCtrl *ui;
};

#endif // DIALOGMOTIONCTRL_H
