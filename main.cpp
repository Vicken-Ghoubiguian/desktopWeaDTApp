//
#include "maindesktopweadtwindow.h"

//
#include <QApplication>

//
int main(int argc, char *argv[])
{
    //
    QApplication a(argc, argv);

    //
    MainDesktopWeaDTWindow w;

    //
    w.show();

    //
    return a.exec();
}
