#ifndef GEOGRAPHICLOCATION_H
#define GEOGRAPHICLOCATION_H

#include <QString>

class GeographicLocation
{

public:

    //
    GeographicLocation(QString cityName, QString countryCode);

    //
    QString toString();

private:

    //
    QString cityName;

    //
    QString countryCode;
};

#endif // GEOGRAPHICLOCATION_H
