#include "ultraviolet.h"

UltraViolet::UltraViolet(QString apiKey, double longitude, double latitude)
{
    //
    QString openWeatherURLToGetUV = "https://api.openweathermap.org/data/2.5/uvi?appid=%s&lat=" + QString::number(latitude) + "&lon=" + QString::number(longitude);

    int value = 0;

    //
    if(value <= 2) {

        //
        this->risk = Low;
    }

    //
    else if (3 <= value && value <= 5) {

        //
        this->risk = Moderate;
    }

    //
    else if (6 <= value && value <= 7) {

        //
        this->risk = High;
    }

    //
    else if(8 <= value && value <= 10) {

        //
        this->risk = Very_High;
    }

    //
    else {

        //
        this->risk = Extreme;
    }

    //
    this->index = value;
}

UltraViolet::UltraViolet(QString apiKey, int value)
{

    //
    if(value <= 2) {

        //
        this->risk = Low;
    }

    //
    else if (3 <= value && value <= 5) {

        //
        this->risk = Moderate;
    }

    //
    else if (6 <= value && value <= 7) {

        //
        this->risk = High;
    }

    //
    else if(8 <= value && value <= 10) {

        //
        this->risk = Very_High;
    }

    //
    else {

        //
        this->risk = Extreme;
    }

    //
    this->index = value;
}

int UltraViolet::getIndex()
{

    //
    return this->index;
}

UltraVioletRisk UltraViolet::getRisk()
{

    //
    return this->risk;
}
