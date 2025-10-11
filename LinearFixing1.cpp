#include "LinearFixing1.h"

#include <QScreen>
#include <QPainter>
#include <QStyleOption>
#include <QApplication>

LinearFixing1::LinearFixing1(const QString& title,const QString& content, QWidget *parent)
    : QDialog(parent)
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::MSWindowsFixedSizeDialogHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setModal(true);

    setStyleSheet("background-color: rgba(0, 0, 0, 0.5);"); // 黑色半透明

    QWidget* pContentWidget = new QWidget(this);
    pContentWidget->setStyleSheet(R"(
        QWidget {
            background-color: white;
            border-radius: 32px;
            padding: 10px;
        }
    )");

    QLabel *pLabTitle = new QLabel("行程校准操作指南", pContentWidget);
    pLabTitle->setStyleSheet("font-size: 16px; color: #333; text-align: center;");
    pLabTitle->setWordWrap(true);
    pLabTitle->setAlignment(Qt::AlignCenter);

    QLabel *pLabText = new QLabel("请依次将每个按键轻按到底并停留至少1秒钟，直到按键变为橙色（表示该按键校准成功），请勿遗漏，可重复按按键。无线下不支持按键校准个数提示。校准过程中请勿拔出数据线。", pContentWidget);
    pLabText->setStyleSheet("font-size: 13px; color: #333; text-align: left; min-height:80px; margin: 5px 20px;");
    pLabText->setWordWrap(true);
    pLabText->setAlignment(Qt::AlignLeft);

    QPushButton* confirmBtn = new QPushButton("开始校准", pContentWidget);
    confirmBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #6329B6;
            color: white;
            border: none;
            border-radius: 12px;
            padding: 8px 8px;
            font-size: 14px;
        }
        QPushButton:hover { background-color: #0E42F2; }
        QPushButton:pressed { background-color: #0A34A1; }
    )");
    connect(confirmBtn, &QPushButton::clicked, this, &QDialog::accept);

    QPushButton* cancelBtn = new QPushButton("取消", pContentWidget);
    cancelBtn->setStyleSheet(R"(
        QPushButton {
            background-color: gray;
            color: white;
            border: none;
            border-radius: 12px;
            padding: 8px 8px;
            font-size: 14px;
        }
        QPushButton:hover { background-color: #C2C2C2; }
        QPushButton:pressed { background-color: #0A34A1; }
    )");
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    // 内容布局
    QVBoxLayout* contentLayout = new QVBoxLayout(pContentWidget);
    contentLayout->addWidget(pLabTitle);
    contentLayout->addWidget(pLabText,1);
    contentLayout->addSpacing(10);
    contentLayout->setSpacing(5);

    QHBoxLayout* btnLayout = new QHBoxLayout(pContentWidget) ;
    btnLayout->addWidget(cancelBtn, 0, Qt::AlignCenter);
    btnLayout->addWidget(confirmBtn, 0, Qt::AlignCenter);
    btnLayout->setAlignment(Qt::AlignHCenter);
    btnLayout->setSpacing(18) ;
    btnLayout->setContentsMargins(10,10,10,10) ;
    contentLayout->addLayout(btnLayout,0) ;

    // 主布局
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(pContentWidget, 1, Qt::AlignCenter);

    pContentWidget->setFixedSize(426,223);
    pContentWidget->adjustSize();
    QRect geoMetry = QApplication::primaryScreen()->geometry(); ;
    if(parent) geoMetry = parent->geometry() ;
    setFixedSize(geoMetry.width(), geoMetry.height());
}

void LinearFixing1::paintEvent(QPaintEvent *event)
{
    // 确保样式表生效
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    QDialog::paintEvent(event);
}
