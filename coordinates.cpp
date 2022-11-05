#include "coordinates.h"

//
Coordinates::Coordinates(double longitude, double latitude)
{
    this->longitude = longitude;
    this->latitude = latitude;
}

//
double Coordinates::getLongitude()
{
    return this->longitude;
}

//
double Coordinates::getLatitude()
{
    return this->latitude;
}

//
QString Coordinates::toString()
{
    return "";
}
