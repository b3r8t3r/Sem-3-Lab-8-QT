#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <locale.h>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Rus");
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Sem-3-Lab-8_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
