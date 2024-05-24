#ifndef COUNTRYFLAG_H
#define COUNTRYFLAG_H

#include <QObject>
#include <QSqlDatabase>

class CountryFlag : public QObject
{
    Q_OBJECT

public:
    explicit CountryFlag(QString wishedTimezone, QObject *parent = nullptr);
    QString getFlagURL();
    QString getCountryCode();
    QString getCountryName();

signals:

private:
    QString flagURL;
    QString countryCode;
    QString countryName;
};

#endif // COUNTRYFLAG_H
