#ifndef WIND_H
#define WIND_H

#include <QString>

class Wind
{

public:

    //
    Wind(double speed, int deg, double gust);

    //
    Wind(double speed, int deg);

    //
    double getSpeed();

    //
    double getDeg();

    //
    double getGust();

    //
    QString toString();

private:

    //
    double speed;

    //
    double deg;

    //
    double gust;
};

#endif // WIND_H
