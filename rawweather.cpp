#include "rawweather.h"

//
RawWeather::RawWeather(QJsonObject openWeatherObj, QJsonValue weatherObj)
{
    //
    this->cod = openWeatherObj["cod"].toInt();
    this->base = openWeatherObj["base"].toString();
    this->id = openWeatherObj["id"].toInt();
    this->timezone_s_offset_from_utc = openWeatherObj["timezone"].toInt();
    //this->location_name = openWeatherObj["name"].toString();
    this->utc_dateTime = openWeatherObj["dt"].toInt();
    this->visibility = openWeatherObj["visibility"].toInt();
    this->clouds = openWeatherObj["clouds"].toObject().take("all").toDouble();
    this->corresponding_tz_datetime = this->utc_dateTime + this->timezone_s_offset_from_utc;

    //
    this->coords = new Coordinates(openWeatherObj["coord"].toObject().take("lon").toDouble(), openWeatherObj["coord"].toObject().take("lat").toDouble());
    this->weather = new Weather(weatherObj.toObject().take("description").toString(), weatherObj.toObject().take("icon").toString(), weatherObj.toObject().take("id").toInt(), weatherObj.toObject().take("main").toString());

    this->location = new GeographicLocation(openWeatherObj["name"].toString(), "");
    this->wind = new Wind(openWeatherObj["wind"].toObject().take("speed").toDouble(), openWeatherObj["wind"].toObject().take("deg").toInt());

    qDebug() << openWeatherObj;

    qDebug() << "Main : " << openWeatherObj["main"];
    qDebug() << "Sys : " << openWeatherObj["sys"];
    qDebug() << "\n";

    //this->iconUrl = "https://openweathermap.org/img/wn/" + icon + ".png";
}

//
Coordinates* RawWeather::getCoords() {

    //
    return this->coords;
}

//
Weather* RawWeather::getWeather() {

    //
    return this->weather;
}

//
Sys* RawWeather::getSys() {

    //
    return this->sys;
}

//
int RawWeather::getUTCDateTime() {

    //
    return this->utc_dateTime;
}

//
int RawWeather::getOffsetFromUTC() {

    //
    return this->timezone_s_offset_from_utc;
}

//
int RawWeather::getId() {

    //
    return this->id;
}

//
int RawWeather::getCod() {

    //
    return this->cod;
}

//
Wind* RawWeather::getWind() {

    //
    return this->wind;
}

//
int RawWeather::getCorrespondingTZDateTime() {

    //
    return this->corresponding_tz_datetime;
}

//
UltraViolet* RawWeather::getUltraViolet() {

    //
    return this->UV;
}

//
QString RawWeather::toString() {

    //
    return "Coordinates: " + this->coords->toString() + "\n" +
           this->weather->toString() + "\n" +
           this->sys->toString() + "\n" +
           "Base: " + this->base + "\n" +
           "UTC datetime according to UTC (in UNIX format): " + QString::number(this->utc_dateTime) + "\n" +
           "Offset from UTC (in UNIX format): " + QString::number(this->timezone_s_offset_from_utc) + "\n" +
           "Datetime from location according to UTC (in UNIX format): " + QString::number(this->corresponding_tz_datetime) + "\n" +
           "Visibility: " + QString::number(this->visibility) + "\n" +
           "Id: " + QString::number(this->id) + "\n" +
           "Geographic location: " + this->location->toString() + "\n" +
           "Returning code : " + QString::number(this->cod) + "\n";
}
