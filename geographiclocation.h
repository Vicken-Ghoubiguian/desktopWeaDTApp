#ifndef GEOGRAPHICLOCATION_H
#define GEOGRAPHICLOCATION_H

#include <QString>

class GeographicLocation
{

public:

    //
    GeographicLocation(QString countryCode, QString cityName);

private:

    //
    QString countryCode;

    //
    QString cityName;
};

#endif // GEOGRAPHICLOCATION_H
