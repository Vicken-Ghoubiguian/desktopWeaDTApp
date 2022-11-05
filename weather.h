#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>

class Weather : public QObject
{
    Q_OBJECT

public:

    //
    Weather(QString description, QString icon, int id, QString main);

    //
    QString getDescription();

    //
    QString getIcon();

    //
    int getId();

    //
    QString getMain();

    //
    QString toString();

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
