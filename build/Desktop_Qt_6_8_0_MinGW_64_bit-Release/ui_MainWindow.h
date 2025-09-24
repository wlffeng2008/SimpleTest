/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "custumgraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    CustumGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QPushButton *pushButtonMsg1;
    QPushButton *pushButtonMsg2;
    QPushButton *pushButtonSavePng;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1201, 730);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMinimumSize(QSize(0, 200));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1164, 1527));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 0, 0, 0);
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 1500));

        verticalLayout_2->addWidget(groupBox);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName("comboBox");

        verticalLayout_2->addWidget(comboBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 10, -1, -1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setWordWrap(true);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        horizontalLayout->addWidget(textEdit);

        graphicsView = new CustumGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 10, -1, 10);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setMinimumSize(QSize(0, 100));

        verticalLayout->addWidget(checkBox);

        pushButtonMsg1 = new QPushButton(centralwidget);
        pushButtonMsg1->setObjectName("pushButtonMsg1");

        verticalLayout->addWidget(pushButtonMsg1);

        pushButtonMsg2 = new QPushButton(centralwidget);
        pushButtonMsg2->setObjectName("pushButtonMsg2");

        verticalLayout->addWidget(pushButtonMsg2);

        pushButtonSavePng = new QPushButton(centralwidget);
        pushButtonSavePng->setObjectName("pushButtonSavePng");

        verticalLayout->addWidget(pushButtonSavePng);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        tableView->setFont(font);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setHighlightSections(false);

        horizontalLayout->addWidget(tableView);


        verticalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1201, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\234\260\345\235\200\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232\350\246\201\351\200\200\345\207\272\345\220\2271\357\274\237\347\241\256\345\256\232\350\246\201\351\200\200\345\207\272\345\220\2272\357\274\237\347\241\256\345\256\232\350\246\201\351\200\200\345\207\272\345\220\2273\357\274\237\347\241\256\345\256\232\350\246\201\351\200\200\345\207\272\345\220\227\357\274\237\347\241\256\345\256\232\350\246\201\351\200\200\345\207\272\345\220\227\357\274\237\n"
"\347\241\256\345\256\232\350\246\201\351\200\200\345\207\272\345\220\227\357\274\237\n"
"\347\241\256\345\256\232\350\246\201\351\200\200\345\207\272\345\220\227\357\274\237", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\346\210\221\345\220\214\346\204\217\346\211\200\346\234\211\345\220\210\345\220\214", nullptr));
        pushButtonMsg1->setText(QCoreApplication::translate("MainWindow", "MessageBox1", nullptr));
        pushButtonMsg2->setText(QCoreApplication::translate("MainWindow", "MessageBox2", nullptr));
        pushButtonSavePng->setText(QCoreApplication::translate("MainWindow", "Save PNG", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "QChart", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Scroll Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
