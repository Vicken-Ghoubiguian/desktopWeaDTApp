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
        qDebug() << BOLD_RED;
        qDebug() << "Error : connection with the '' sqlite database FAILLED ! Exiting application !";
        qDebug() << RESET;

        //
        exit(1);
    }

    //
    qDebug() << BOLD_GREEN;
    qDebug() << "Connection with the '' sqlite database SUCCESSFULLY ESTABLISHED ! Running application !";
    qDebug() << RESET;
}
