#include "rawweather.h"

//
RawWeather::RawWeather(QJsonObject openWeatherObj, QJsonValue weatherObj)
{
    //
    this->cod = openWeatherObj["cod"].toInt();
    this->base = openWeatherObj["base"].toString();
    this->id = openWeatherObj["id"].toInt();
    this->timezone_s_offset_from_utc = openWeatherObj["timezone"].toInt();
    this->location_name = openWeatherObj["name"].toString();
    this->utc_dateTime = openWeatherObj["dt"].toInt();
    this->visibility = openWeatherObj["visibility"].toInt();
    this->clouds = openWeatherObj["clouds"].toObject().take("all").toDouble();

    //
    Coordinates coords(openWeatherObj["coord"].toObject().take("lon").toDouble(), openWeatherObj["coord"].toObject().take("lat").toDouble());

    //
    Weather weather(weatherObj.toObject().take("description").toString(), weatherObj.toObject().take("icon").toString(), weatherObj.toObject().take("id").toInt(), weatherObj.toObject().take("main").toString());

    //
    //Wind wind();

    qDebug() << openWeatherObj;

    qDebug() << "Main : " << openWeatherObj["main"];
    qDebug() << "Sys : " << openWeatherObj["sys"];
    qDebug() << "Wind : " << openWeatherObj["wind"];
    qDebug() << "\n";

    //this->iconUrl = "https://openweathermap.org/img/wn/" + icon + ".png";
}

//

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
QString RawWeather::getLocationSName() {

    //
    return this->location_name;
}

//
int RawWeather::getCod() {

    //
    return this->cod;
}

//
UltraViolet* RawWeather::getUltraViolet() {

    //
    return this->UV;
}

//
QString RawWeather::toString() {

    //
    return "Base: " + this->base + "\n" +
           "UTC datetime: " + QString::number(this->utc_dateTime) + "\n" +
           "Offset from UTC (in seconds): " + QString::number(this->timezone_s_offset_from_utc) + "\n" +
           "Datetime from location: " + QString::number(this->utc_dateTime + this->timezone_s_offset_from_utc) + "\n" +
           "Visibility: " + QString::number(this->visibility) + "\n" +
           "Id: " + QString::number(this->id) + "\n" +
           "Location's name: " + this->location_name + "\n" +
           "Returning code : " + QString::number(this->cod) + "\n";
}
