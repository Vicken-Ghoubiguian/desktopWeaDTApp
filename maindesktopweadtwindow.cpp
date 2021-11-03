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
    this->allTimezonesQList = QTimeZone::availableTimeZoneIds();

    //
    ui->setupUi(this);
}

MainDesktopWeaDTWindow::~MainDesktopWeaDTWindow()
{
    delete ui;
}

//
QList<QByteArray> MainDesktopWeaDTWindow::getAllTimezonesQList()
{
    return this->allTimezonesQList;
}

