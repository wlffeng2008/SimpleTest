#include "MainWindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "MyEasyApp.h"

int main(int argc, char *argv[])
{
    MyEasyApp app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "SimpleTest_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();

    return app.exec();
}
