#include "sqlitemanager.h"

//
SQLITEManager::SQLITEManager(QString sqlitePath)
{
    //
    QSqlDatabase sqliteDBConnector = QSqlDatabase::addDatabase("QSQLITE");

    //
    sqliteDBConnector.setDatabaseName(sqlitePath);

    //
    if(!sqliteDBConnector.open())
    {
        //
        qDebug() << "\033[1m\033[31mError : connection with the '' sqlite database FAILLED ! Exiting application ! \033[0m";

        //
        exit(1);
    }
}
