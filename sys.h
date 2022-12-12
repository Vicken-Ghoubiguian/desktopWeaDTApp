#ifndef SYS_H
#define SYS_H

#include <QString>

class Sys
{

public:

    //
    Sys();

    //
    QString toString();

private:

    //
    QString country;

    //
    int id;

    //
    int sunrise;

    //
    int sunset;

    //
    int type;
};

#endif // SYS_H
