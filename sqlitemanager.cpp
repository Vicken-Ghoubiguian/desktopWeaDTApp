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
        qDebug() << "Error : connection with the 'desktopWeaDTApp' sqlite database FAILLED ! Exiting application !";
        qDebug() << RESET;

        //
        exit(1);
    }

    //
    qDebug() << BOLD_GREEN;
    qDebug() << "Connection with the 'desktopWeaDTApp' sqlite database SUCCESSFULLY ESTABLISHED ! Running application !";
    qDebug() << RESET;

    //
    this->testDB();
}

//
QString SQLITEManager::getCountryCodeFromTimezone(QString timezone)
{
    //
    QSqlQuery query;

    //
    query.prepare("SELECT country_code FROM timezones WHERE name='" + timezone + "';");

    //
    query.exec();

    //
    query.first();

    //
    if(!query.isValid())
    {
        //
        return "za";
    }

    //
    return query.value("country_code").toString();
}

//
void SQLITEManager::testDB()
{
    //
    QSqlQuery query;

    //
    query.prepare("SELECT name FROM sqlite_schema WHERE type='table';");

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
            qDebug() << query.value("name").toString();
        }
    }
}
