//
#include "maindesktopweadtwindow.h"

//
#include <QApplication>
#include <QLocale>
#include <QTimeZone>

//
int main(int argc, char *argv[])
{
    //
    QApplication a(argc, argv);

    //
    MainDesktopWeaDTWindow w;

    qDebug() << QTimeZone::systemTimeZone() << QTimeZone::systemTimeZone().country() << QString(QTimeZone::systemTimeZone().id());

    //
    w.show();

    //
    return a.exec();
}
