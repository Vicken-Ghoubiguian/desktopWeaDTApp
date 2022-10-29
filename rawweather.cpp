#include "rawweather.h"

//
RawWeather::RawWeather(QJsonObject openWeatherObj, QJsonValue weatherObj)
{
    this->cod = openWeatherObj["cod"].toInt();
    this->base = openWeatherObj["base"].toString();
    this->id = openWeatherObj["id"].toInt();
    this->timezone_s_offset_from_utc = openWeatherObj["timezone"].toInt();
    this->location_name = openWeatherObj["name"].toString();
    this->utc_dateTime = openWeatherObj["dt"].toInt();
    this->visibility = openWeatherObj["visibility"].toInt();
    this->id = openWeatherObj["id"].toInt();

    qDebug() << openWeatherObj;
    qDebug() << "Clouds : " << openWeatherObj["clouds"];
    qDebug() << "Coordinates : " << openWeatherObj["coord"];
    /*QJsonArray::iterator it;
    for (it = dataObject.begin(); it != dataObject.end(); it++) {
        QString key = it->first;
        QString value = it->second;
    }*/
    qDebug() << "Main : " << openWeatherObj["main"];
    qDebug() << "Sys : " << openWeatherObj["sys"];
    qDebug() << "Weather : " << weatherObj;
    qDebug() << "Wind : " << openWeatherObj["wind"];
    qDebug() << "\n\n\n\n\n";

    /*this->id = idValue;
    this->main = mainValue;
    this->description = descriptionValue;
    this->iconUrl = "https://openweathermap.org/img/wn/" + icon + ".png";*/
}

//
QString RawWeather::toString() {

    return "";
}
