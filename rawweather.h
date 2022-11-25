#ifndef RAWWEATHER_H
#define RAWWEATHER_H


#include <QString>
#include <QJsonObject>

#include "coordinates.h"
#include "weather.h"
#include "wind.h"
#include "ultraviolet.h"

class RawWeather
{

public:

    //
    RawWeather(QJsonObject openWeatherObj, QJsonValue weatherObj);

    //
    Coordinates getCoords();

    //
    Weather getWeather();

    //

    //
    int getUTCDateTime();

    //
    int getOffsetFromUTC();

    //
    int getId();

    //
    QString getLocationSName();

    //
    int getCod();

    //
    QString toString();

private:

    //
    QString base;

    //
    int cod;

    //
    //Coordinates cords;

    //Weather w;

    //
    double clouds;

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
