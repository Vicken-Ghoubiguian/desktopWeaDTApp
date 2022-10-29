#ifndef RAWWEATHER_H
#define RAWWEATHER_H


#include <QString>
#include <QJsonObject>

class RawWeather
{

public:

    //
    RawWeather(QJsonObject openWeatherObj);

private:

    //
    int id;

    //
    QString main;

    //
    QString description;

    //
    QString iconUrl;
};

#endif // WEATHERIN_H
