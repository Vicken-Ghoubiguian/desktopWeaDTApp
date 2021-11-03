#ifndef MAINDESKTOPWEADTWINDOW_H
#define MAINDESKTOPWEADTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainDesktopWeaDTWindow; }
QT_END_NAMESPACE

//
class MainDesktopWeaDTWindow : public QMainWindow
{
    Q_OBJECT

public:

    //
    MainDesktopWeaDTWindow(QWidget *parent = nullptr);

    //
    ~MainDesktopWeaDTWindow();

    //
    QList<QByteArray> getAllTimezonesQList();

private:

    //
    Ui::MainDesktopWeaDTWindow *ui;

    //
    QList<QByteArray> allTimezonesQList;
};
#endif // MAINDESKTOPWEADTWINDOW_H
