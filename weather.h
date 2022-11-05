#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>

class Weather : public QObject
{
    Q_OBJECT

public:

    //
    Weather(QString description, QString icon, int id, QString main);

private:

    //
    QString description;

    //
    QString icon;

    //
    int id;

    //
    QString main;

};

#endif // WEATHER_H
