#ifndef COORDINATES_H
#define COORDINATES_H

#include <QString>

class Coordinates
{

public:

    //
    Coordinates(double longitude, double latitude);

    //
    double getLongitude();

    //
    double getLatitude();

    //
    QString toString();

private:

    //
    double longitude;

    //
    double latitude;
};

#endif // COORDINATES_H
