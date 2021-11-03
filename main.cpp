//
#include "maindesktopweadtwindow.h"

//
#include <QApplication>
#include <QLocale>
#include <QTranslator>

//
int main(int argc, char *argv[])
{
    //
    QApplication a(argc, argv);

    /*

    */

    //
    QTranslator translator;

    //
    const QStringList uiLanguages = QLocale::system().uiLanguages();

    //
    for (const QString &locale : uiLanguages) {

        //
        const QString baseName = "desktopWeaDTApp_" + QLocale(locale).name();

        //
        if (translator.load(":/i18n/" + baseName)) {

            //
            a.installTranslator(&translator);

            //
            break;
        }
    }

    /*

    */

    //
    MainDesktopWeaDTWindow w;

    //
    QList<QByteArray> listOfAllIANATimezones = w.getAllTimezonesQList();

    //
    for(int i = 0; i < listOfAllIANATimezones.count(); i++) {

        //
        qDebug() << QString(listOfAllIANATimezones[i]) << "\n";
    }

    //
    w.show();

    //
    return a.exec();
}
