#include "sys.h"

Sys::Sys()
{

}

//
QString Sys::getCountry()
{
    //
    return this->country;
}

//
int Sys::getId()
{
    //
    return this->id;
}

//
int Sys::getSunrise()
{
    //
    return this->sunrise;
}

//
int Sys::getSunset()
{
    //
    return this->sunset;
}

int Sys::getType()
{
    //
    return this->type;
}

//
QString Sys::toString()
{
    return "";
}
