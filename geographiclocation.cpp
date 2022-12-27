#include "geographiclocation.h"

//
GeographicLocation::GeographicLocation(QString cityName, QString countryCode)
{
    this->cityName = cityName;
    this->countryCode = countryCode;
}

//
QString GeographicLocation::toString()
{
    return "(" + this->cityName + " " + this->countryCode + ")";
}
