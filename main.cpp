#include "MainWindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

class MyApp : public QApplication {
public:
    MyApp(int &argc, char **argv) : QApplication(argc, argv) {
        // 自定义初始化逻辑
        foo = "全局数据";
    }

    bool notify(QObject *receiver, QEvent *event) override
    {
        if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

            qDebug() << "全局按键:" << keyEvent->key() << keyEvent->type() << keyEvent->text() << keyEvent->timestamp();
        }
        return QApplication::notify(receiver, event);
    }


private:
    QString foo;
};

int main(int argc, char *argv[])
{
    MyApp a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "SimpleTest_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
