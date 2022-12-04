#include "weather.h"

//
Weather::Weather(QString description, QString icon, int id, QString main)
{
    this->description = description;
    this->icon = icon;
    this->id = id;
    this->main = main;
}

//
QString Weather::getDescription()
{
    return this->description;
}

//
QString Weather::getIcon()
{
    return this->icon;
}

//
int Weather::getId()
{
    return this->id;
}

//
QString Weather::getMain()
{
    return this->main;
}

//
QString Weather::toString()
{
    return "";
}
