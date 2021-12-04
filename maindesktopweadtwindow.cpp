//
#include "maindesktopweadtwindow.h"
#include "ui_maindesktopweadtwindow.h"

//
#include <QTimeZone>

MainDesktopWeaDTWindow::MainDesktopWeaDTWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainDesktopWeaDTWindow)
{
    //
    this->allTimezonesQList = QList<QString>();

    //
    QList<QByteArray> listOfAllIANATimezones = QTimeZone::availableTimeZoneIds();

    //
    for(int i = 0; i < listOfAllIANATimezones.count(); i++) {

        //
        QString currentTimeZoneAsString = QString(listOfAllIANATimezones[i]);

        //
        QStringList currentTimeZoneAsStringList = currentTimeZoneAsString.split("/");

        //
        if(currentTimeZoneAsStringList.contains("Africa") || currentTimeZoneAsStringList.contains("America") || currentTimeZoneAsStringList.contains("Asia") || currentTimeZoneAsStringList.contains("Atlantic") || currentTimeZoneAsStringList.contains("Australia") || currentTimeZoneAsStringList.contains("Europe") || currentTimeZoneAsStringList.contains("Indian") || currentTimeZoneAsStringList.contains("Pacific")) {

            //this->allTimezonesQList = QTimeZone::availableTimeZoneIds();
            this->allTimezonesQList.append(currentTimeZoneAsString);
        }
    }

    //
    //this->allTimezonesQList = QTimeZone::availableTimeZoneIds();

    //
    ui->setupUi(this);
}

MainDesktopWeaDTWindow::~MainDesktopWeaDTWindow()
{
    delete ui;
}

//
QList<QString> MainDesktopWeaDTWindow::getAllTimezonesQList()
{
    return this->allTimezonesQList;
}

