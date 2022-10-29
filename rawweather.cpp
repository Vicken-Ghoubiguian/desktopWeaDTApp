#include "rawweather.h"

//
RawWeather::RawWeather(QJsonObject openWeatherObj)
{
    this->cod = openWeatherObj["cod"].toInt();
    this->base = openWeatherObj["base"].toString();
    this->id = openWeatherObj["id"].toInt();
    this->timezone_s_offset_from_utc = openWeatherObj["timezone"].toInt();
    this->location_name = openWeatherObj["name"].toString();

    /*this->id = idValue;
    this->main = mainValue;
    this->description = descriptionValue;
    this->iconUrl = "https://openweathermap.org/img/wn/" + icon + ".png";*/
}

//
QString RawWeather::toString() {

    return "";
}
