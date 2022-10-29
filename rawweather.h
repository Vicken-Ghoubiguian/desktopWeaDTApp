#ifndef RAWWEATHER_H
#define RAWWEATHER_H

#include <QString>

class RawWeather
{

public:

    //
    RawWeather(int idValue, QString mainValue, QString descriptionValue, QString icon);

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
