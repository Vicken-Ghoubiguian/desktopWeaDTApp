#ifndef ULTRAVIOLET_H
#define ULTRAVIOLET_H

#include <QString>
#include <QJsonObject>

#include "ultravioletrisk.h"

class UltraViolet
{

public:

    //
    UltraViolet(double longitude, double latitude);

    //
    UltraViolet(int value);

    //
    int getIndex();

    //
    UltraVioletRisk getRisk();

private:

    //
    int index;

    //
    UltraVioletRisk risk;
};

#endif // ULTRAVIOLET_H
