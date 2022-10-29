#ifndef RAWWEATHER_H
#define RAWWEATHER_H


#include <QString>
#include <QJsonObject>

class RawWeather
{

public:

    //
    RawWeather(QJsonObject openWeatherObj);

    //
    QString toString();

private:

    //
    int cod;

    //
    int utc_dateTime;

    //
    int id;

    //
    int timezone;

    //
    int visibility;

    //
    QString name;

    //
    QString iconUrl;
};

#endif // WEATHERIN_H
