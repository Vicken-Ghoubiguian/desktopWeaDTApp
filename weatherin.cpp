#include "weatherin.h"

//
WeatherIn::WeatherIn(int idValue, QString mainValue, QString descriptionValue, QString icon)
{
    this->id = idValue;
    this->main = mainValue;
    this->description = descriptionValue;
    this->iconUrl = "https://openweathermap.org/img/wn/" + icon + ".png";
}
