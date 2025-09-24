/********************************************************************************
** Form generated from reading UI file 'DialogChart.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHART_H
#define UI_DIALOGCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DialogChart
{
public:

    void setupUi(QDialog *DialogChart)
    {
        if (DialogChart->objectName().isEmpty())
            DialogChart->setObjectName("DialogChart");
        DialogChart->resize(791, 563);

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
