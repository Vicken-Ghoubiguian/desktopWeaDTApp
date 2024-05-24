#include "countryflag.h"

//
CountryFlag::CountryFlag(QString wishedTimezone, QObject *parent) : QObject(parent)
{

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
