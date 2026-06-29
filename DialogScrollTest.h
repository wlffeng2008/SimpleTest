#ifndef DIALOGSCROLLTEST_H
#define DIALOGSCROLLTEST_H

#include <QDialog>
#include <QLabel>
#include "Downloader.h"

namespace Ui {
class DialogScrollTest;
}

class DialogScrollTest : public QDialog
{
    Q_OBJECT

public:
    explicit DialogScrollTest(QWidget *parent = nullptr);
    ~DialogScrollTest();

private slots:
    void on_pushButtonDownload_clicked();

private:
    Ui::DialogScrollTest *ui;
    QList<QLabel*>m_flags;
    Downloader *m_downloader;
};

#endif // DIALOGSCROLLTEST_H
