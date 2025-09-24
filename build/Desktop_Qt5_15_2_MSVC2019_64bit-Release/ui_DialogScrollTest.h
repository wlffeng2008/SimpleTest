/********************************************************************************
** Form generated from reading UI file 'DialogScrollTest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSCROLLTEST_H
#define UI_DIALOGSCROLLTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogScrollTest
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QDialog *DialogScrollTest)
    {
        if (DialogScrollTest->objectName().isEmpty())
            DialogScrollTest->setObjectName(QString::fromUtf8("DialogScrollTest"));
        DialogScrollTest->resize(811, 586);
        verticalLayout = new QVBoxLayout(DialogScrollTest);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(DialogScrollTest);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 80));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 791, 78));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(DialogScrollTest);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 791, 480));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea_2);


        retranslateUi(DialogScrollTest);

        QMetaObject::connectSlotsByName(DialogScrollTest);
    } // setupUi

    void retranslateUi(QDialog *DialogScrollTest)
    {
        DialogScrollTest->setWindowTitle(QCoreApplication::translate("DialogScrollTest", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogScrollTest", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogScrollTest: public Ui_DialogScrollTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSCROLLTEST_H
