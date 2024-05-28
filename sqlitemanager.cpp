#include "sqlitemanager.h"

//
SQLITEManager::SQLITEManager(QString sqlitePath)
{
    //
    QSqlDatabase sqliteDBConnector = QSqlDatabase::addDatabase("QSQLITE");

    //
    QSqlQuery query;

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

    qDebug() << "TESTS";

    query.prepare("SELECT * FROM timezones;");
    if(!query.exec())
    {
        qDebug() << "Test :";
    }
    else
    {
        //query.first();
        while (query.next())
        {
            qDebug() << query.value("id").toString() << ". " << query.value("name").toString();
        }
    }
}
