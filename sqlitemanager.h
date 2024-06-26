#ifndef SQLITEMANAGER_H
#define SQLITEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include "colors_and_styles.h"

class SQLITEManager : public QObject
{
    Q_OBJECT

public:

    //
    SQLITEManager(const QString sqlitePath);

    //
    QString getCountryCodeFromTimezone(QString timezone);

signals:

private:

    //
    QSqlDatabase sqliteDBConnector;

    //
    void testDB();
};

#endif // SQLITEMANAGER_H
