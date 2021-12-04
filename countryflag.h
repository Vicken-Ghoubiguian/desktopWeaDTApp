#ifndef COUNTRYFLAG_H
#define COUNTRYFLAG_H

#include <QObject>

class countryFlag : public QObject
{
    Q_OBJECT

public:
    explicit countryFlag(QObject *parent = nullptr);


signals:

private:
    QString flagURL;
    QString countryCode;
    QString countryName;
};

#endif // COUNTRYFLAG_H
