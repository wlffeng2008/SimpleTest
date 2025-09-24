/********************************************************************************
** Form generated from reading UI file 'DialogChart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHART_H
#define UI_DIALOGCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogChart
{
public:
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QDialog *DialogChart)
    {
        if (DialogChart->objectName().isEmpty())
            DialogChart->setObjectName(QString::fromUtf8("DialogChart"));
        DialogChart->resize(1114, 741);
        lineEdit = new QLineEdit(DialogChart);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 0, 501, 21));
        textEdit = new QTextEdit(DialogChart);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 30, 501, 71));

        retranslateUi(DialogChart);

        QMetaObject::connectSlotsByName(DialogChart);
    } // setupUi

    void retranslateUi(QDialog *DialogChart)
    {
        DialogChart->setWindowTitle(QCoreApplication::translate("DialogChart", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogChart: public Ui_DialogChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHART_H
