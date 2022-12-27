#include "geographiclocation.h"

//
GeographicLocation::GeographicLocation(QString countryCode, QString cityName)
{
    this->countryCode = countryCode;
    this->cityName = cityName;
}

//
QString GeographicLocation::toString()
{
    return "";
}
