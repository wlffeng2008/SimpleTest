#ifndef DIALOGSCROLLTEST_H
#define DIALOGSCROLLTEST_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class DialogScrollTest;
}

class DialogScrollTest : public QDialog
{
    Q_OBJECT

public:
    explicit DialogScrollTest(QWidget *parent = nullptr);
    ~DialogScrollTest();

private:
    Ui::DialogScrollTest *ui;
    QList<QLabel*>m_flags;
};

#endif // DIALOGSCROLLTEST_H
