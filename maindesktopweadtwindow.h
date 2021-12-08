#ifndef MAINDESKTOPWEADTWINDOW_H
#define MAINDESKTOPWEADTWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimeZone>

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
    QList<QString> getAllTimezonesQList();

private:

    //
    Ui::MainDesktopWeaDTWindow *ui;

    //
    QList<QString> allTimezonesQList;

    //
    QList<QString> getAllIANATimezones();

    //
    QString getSystemIANATimezone();

    //
    int getIANATimezoneIndex(QString ianaTimeZone);

    //
    qint64 getDateTimeForSpecificTimeZone();
};
#endif // MAINDESKTOPWEADTWINDOW_H
