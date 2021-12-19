#ifndef GEOGRAPHICLOCATION_H
#define GEOGRAPHICLOCATION_H

#include <QString>

class geographicLocation
{

public:

    //
    geographicLocation(QString countryCode, QString cityName);

private:

    //
    QString countryCode;

    //
    QString cityName;
};

#endif // GEOGRAPHICLOCATION_H
