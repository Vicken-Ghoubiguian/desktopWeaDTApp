#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <QString>

class Humidity
{

public:

    //
    Humidity(int humidityValue);

private:

    //
    int value;

    //
    QString unitScale;
};

#endif // HUMIDITY_H
