#ifndef MAINDESKTOPWEADTWINDOW_H
#define MAINDESKTOPWEADTWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimeZone>
#include <QTimer>

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

private slots:

    //
    void updateDisplayedTimeForSpecificTimeZone();

private:

    //
    Ui::MainDesktopWeaDTWindow *ui;

    //
    QList<QString> allTimezonesQList;

    //
    QList<QString> allDateTimeFormatsQList;

    //
    QTimer* dateTimeTimer;

    //
    QList<QString> getAllIANATimezones();

    //
    QString getSystemIANATimezone();

    //
    int getIANATimezoneIndex(QString ianaTimeZone);

    // 'getDateTimeForSpecificTimeZone' function to return the current date and time from the current timezone...
    qint64 getDateTimeForSpecificTimeZone();
};
#endif // MAINDESKTOPWEADTWINDOW_H
