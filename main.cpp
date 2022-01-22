//
#include "maindesktopweadtwindow.h"

//
#include <QApplication>
#include <QString>
#include <QColorDialog>

//
int main(int argc, char *argv[])
{
    //
    QApplication a(argc, argv);

    //
    MainDesktopWeaDTWindow w;

    //
    w.show();

    QColorDialog comboBoxColorDialog;
    QString selectedColor;

    comboBoxColorDialog.show();

    //
    return a.exec();
}
