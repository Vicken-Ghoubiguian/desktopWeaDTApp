#ifndef WIND_H
#define WIND_H


class Wind
{

public:

    //
    Wind(double speed, int deg, double gust);

    //
    double getSpeed();

    //
    double getDeg();

    //
    double getGust();

private:

    //
    double speed;

    //
    double deg;

    //
    double gust;
};

#endif // WIND_H
