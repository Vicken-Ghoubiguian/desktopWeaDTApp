#include "maindesktopweadtwindow.h"
#include "ui_maindesktopweadtwindow.h"

MainDesktopWeaDTWindow::MainDesktopWeaDTWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainDesktopWeaDTWindow)
{
    ui->setupUi(this);
}

MainDesktopWeaDTWindow::~MainDesktopWeaDTWindow()
{
    delete ui;
}

