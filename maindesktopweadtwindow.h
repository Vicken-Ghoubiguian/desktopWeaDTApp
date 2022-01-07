#ifndef MAINDESKTOPWEADTWINDOW_H
#define MAINDESKTOPWEADTWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimeZone>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainDesktopWeaDTWindow; }
QT_END_NAMESPACE

//
class MainDesktopWeaDTWindow : public QMainWindow
{
    Q_OBJECT

public:

    // Definition of the 'MainDesktopWeaDTWindow' class constructor...
    MainDesktopWeaDTWindow(QWidget *parent = nullptr);

    // Definition of the 'MainDesktopWeaDTWindow' class destructor...
    ~MainDesktopWeaDTWindow();

    //
    QList<QString> getAllTimezonesQList(); 

private slots:

    //
    void updateDisplayedTimeForSpecificTimeZone();

    //
    void resetInputsForWeather();

    //
    void validationInputsWeather();

    //
    void managerFinished(QNetworkReply *reply);

    //void managerFinishedForFlag(QNetworkReply *reply);

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
    //QNetworkAccessManager flagManager;

    //
    QNetworkAccessManager weatherManager;

    //
    //QNetworkRequest flagRequest;

    //
    QNetworkRequest weatherRequest;

    //
    QList<QString> getAllIANATimezones();

    //
    QString getSystemIANATimezone();

    //
    int getIANATimezoneIndex(QString ianaTimeZone);
};
#endif // MAINDESKTOPWEADTWINDOW_H
