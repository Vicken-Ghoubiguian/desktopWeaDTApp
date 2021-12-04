#include "countryflag.h"

//
countryFlag::countryFlag(QObject *parent) : QObject(parent)
{

}

//
QString countryFlag::getFlagURL()
{
    return this->flagURL;
}

QString countryFlag::getCountryCode()
{
    return this->countryCode;
}

QString countryFlag::getCountryName()
{
    return this->countryName;
}
