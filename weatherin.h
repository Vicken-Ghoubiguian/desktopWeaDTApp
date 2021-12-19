#ifndef WEATHERIN_H
#define WEATHERIN_H

#include <QString>

class WeatherIn
{

public:

    //
    WeatherIn(int idValue, QString mainValue, QString descriptionValue, QString icon);

private:

    //
    int id;

    //
    QString main;

    //
    QString description;

    //
    QString iconUrl;
};

#endif // WEATHERIN_H
