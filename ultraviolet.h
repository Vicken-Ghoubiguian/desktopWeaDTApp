#ifndef ULTRAVIOLET_H
#define ULTRAVIOLET_H

#include <QString>
#include <QJsonObject>

#include "ultravioletrisk.h"

class UltraViolet
{

public:

    //
    UltraViolet(QString apiKey, double longitude, double latitude);

    //
    UltraViolet(QString apiKey, int value);

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
