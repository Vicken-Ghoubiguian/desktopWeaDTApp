#include "wind.h"

//
Wind::Wind(double speed, int deg, double gust)
{
    this->speed = speed;
    this->deg = deg;
    this->gust = gust;
}

//
Wind::Wind(double speed, int deg)
{
    this->speed = speed;
    this->deg = deg;
}

//
double Wind::getSpeed()
{
    return this->speed;
}

//
double Wind::getDeg()
{
    return this->deg;
}

//
double Wind::getGust()
{
    return this->gust;
}

//
QString Wind::toString()
{
    return "";
}
