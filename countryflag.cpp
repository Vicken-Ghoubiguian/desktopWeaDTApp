#include "countryflag.h"

//
CountryFlag::CountryFlag(QString countryCode, QObject *parent) : QObject(parent)
{   
    //
    this->countryCode = countryCode;

    //
    this->flagURL = "https://flagcdn.com/w40/" + countryCode + ".png";
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
