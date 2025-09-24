/********************************************************************************
** Form generated from reading UI file 'DialogMotionCtrl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMOTIONCTRL_H
#define UI_DIALOGMOTIONCTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DialogMotionCtrl
{
public:

    void setupUi(QDialog *DialogMotionCtrl)
    {
        if (DialogMotionCtrl->objectName().isEmpty())
            DialogMotionCtrl->setObjectName(QString::fromUtf8("DialogMotionCtrl"));
        DialogMotionCtrl->resize(968, 580);

        retranslateUi(DialogMotionCtrl);

        QMetaObject::connectSlotsByName(DialogMotionCtrl);
    } // setupUi

    void retranslateUi(QDialog *DialogMotionCtrl)
    {
        DialogMotionCtrl->setWindowTitle(QCoreApplication::translate("DialogMotionCtrl", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogMotionCtrl: public Ui_DialogMotionCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMOTIONCTRL_H
