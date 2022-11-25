#ifndef ULTRAVIOLET_H
#define ULTRAVIOLET_H

#include "ultravioletrisk.h"

class UltraViolet
{

public:

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
