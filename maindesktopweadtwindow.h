#ifndef MAINDESKTOPWEADTWINDOW_H
#define MAINDESKTOPWEADTWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimeZone>
#include <QTimer>
#include <QFont>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSysInfo>

#include <rawweather.h>

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

    //
    QList<QString> getAllDateTimeFormatsQList();

    //
    QList<QString> getAvailableBackgroundColorQList();

    //
    QFont getCurrentFont();

    //
    QString getCountryCodeFromTimezone(QString tz);

private slots:

    //
    void updateDisplayedTimeForSpecificTimeZone();

    //
    void updateDisplayedCountryFlagForSpecificTimeZone();

    //
    void resetInputsForWeather();

    //
    void validationInputsWeather();

    //
    void managerFinishedForWeather(QNetworkReply *reply);

    //
    void changeFamilyFont();

    //
    void changeBackgroundColorOfComboBox();

    //void managerFinishedForFlag(QNetworkReply *reply);

private:

    //
    Ui::MainDesktopWeaDTWindow *ui;

    //
    QList<QString> allTimezonesQList;

    //
    QList<QString> allDateTimeFormatsQList;

    //
    QList<QString> availableBackgroundColorQList;

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
    QJsonDocument weatherJsonDocument;

    //
    QFont currentFont;

    //
    QJsonDocument getWeatherJsonDocument();

    //
    QList<QString> getAllIANATimezones();

    //
    QString getSystemIANATimezone();

    //
    int getIANATimezoneIndex(QString ianaTimeZone);
};
#endif // MAINDESKTOPWEADTWINDOW_H
