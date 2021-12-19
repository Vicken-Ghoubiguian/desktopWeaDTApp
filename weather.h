#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>

class Weather : public QObject
{
    Q_OBJECT

public:

    //
    explicit Weather(QObject *parent = nullptr);

private:

    //


};

#endif // WEATHER_H
