#include "countryflag.h"

//
CountryFlag::CountryFlag(QString countryCode, QObject *parent) : QObject(parent)
{   
    //
    this->countryCode = countryCode;

    //
    this->flagURL = ":/flagpedia/" + countryCode + ".png";
}

//
QString CountryFlag::getFlagURL()
{
    return this->flagURL;
}

//
QString CountryFlag::getCountryCode()
{
    return this->countryCode;
}

//
QString CountryFlag::getCountryName()
{
    return this->countryName;
}
