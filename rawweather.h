#ifndef RAWWEATHER_H
#define RAWWEATHER_H


#include <QString>
#include <QJsonObject>

class RawWeather
{

public:

    //
    RawWeather(QJsonObject openWeatherObj, QJsonValue weatherObj);

    //
    QString toString();

private:

    //
    QString base;

    //
    int cod;

    //
    int utc_dateTime;

    //
    int id;

    //
    int timezone_s_offset_from_utc;

    //
    int visibility;

    //
    QString location_name;

    //
    QString iconUrl;
};

#endif // WEATHERIN_H
