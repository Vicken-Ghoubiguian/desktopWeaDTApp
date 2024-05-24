#ifndef SQLITEMANAGER_H
#define SQLITEMANAGER_H

#include <QObject>
#include <QSqlDatabase>

class SQLITEManager : public QObject
{
    Q_OBJECT

public:

    //
    SQLITEManager(QString sqlitePath);

signals:

private:

    //
    QSqlDatabase sqliteDBConnector;
};

#endif // SQLITEMANAGER_H
