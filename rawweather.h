#ifndef RAWWEATHER_H
#define RAWWEATHER_H

#include <QString>
#include <QJsonObject>

#include "coordinates.h"
#include "weather.h"
#include "wind.h"
#include "ultraviolet.h"
#include "sys.h"
#include "geographiclocation.h"

class RawWeather
{

public:

    //
    RawWeather(QJsonObject openWeatherObj, QJsonValue weatherObj);

    //
    Coordinates* getCoords();

    //
    Weather* getWeather();

    //
    Sys* getSys();

    //
    int getUTCDateTime();

    //
    int getOffsetFromUTC();

    //
    int getId();

    //
    GeographicLocation getLocation();

    //
    int getCod();

    //
    Wind* getWind();

    //
    int getCorrespondingTZDateTime();

    //
    UltraViolet* getUltraViolet();

    //
    QString toString();

private:

    //
    QString base;

    //
    int cod;

    //
    Coordinates* coords;

    //
    Weather* weather;

    //
    Sys* sys;

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
    GeographicLocation location;

    //
    QString iconUrl;

    //
    Wind* wind;

    //
    int corresponding_tz_datetime;

    //
    UltraViolet* UV;
};

#endif // WEATHERIN_H
