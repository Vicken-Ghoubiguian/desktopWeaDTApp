#include "sqlitemanager.h"

//
SQLITEManager::SQLITEManager(QString sqlitePath, QString testQuery)
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

    //
    this->testDB(testQuery);
}

//
void SQLITEManager::testDB(QString testQuery)
{
    //
    QSqlQuery query;

    //
    query.prepare(testQuery);

    //
    if(!query.exec())
    {
        //
        qDebug() << "Test :";
    }
    //
    else
    {
        //
        while (query.next())
        {
            //
            qDebug() << query.value("id") << ". " << query.value("name").toString();
        }
    }
}
