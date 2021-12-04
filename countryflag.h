#ifndef COUNTRYFLAG_H
#define COUNTRYFLAG_H

#include <QObject>

class countryFlag : public QObject
{
    Q_OBJECT
public:
    explicit countryFlag(QObject *parent = nullptr);

signals:

};

#endif // COUNTRYFLAG_H
