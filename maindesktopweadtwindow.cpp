//
#include "maindesktopweadtwindow.h"
#include "ui_maindesktopweadtwindow.h"

//
MainDesktopWeaDTWindow::MainDesktopWeaDTWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainDesktopWeaDTWindow)
{
    // Definition and implementation of IANA timezones QList<QString>...
    this->allTimezonesQList = this->getAllIANATimezones();

    // Definition and implementation of date and time formats QList<QString>...
    this->allDateTimeFormatsQList.append("timestamp");
    this->allDateTimeFormatsQList.append("dd.MM.yyyy");
    this->allDateTimeFormatsQList.append("ddd MMMM d yy");
    this->allDateTimeFormatsQList.append("hh:mm:ss.zzz");
    this->allDateTimeFormatsQList.append("hh:mm:ss.z");
    this->allDateTimeFormatsQList.append("h:m:s ap");

    //
    //this->setWindowIcon(QIcon("https://flagcdn.com/16x12/za.png"));

    //
    //QPixmap pm("https://flagcdn.com/16x12/za.png");

    //
    //ui->flagDisplayer->setPixmap(pm);

    //
    //ui->flagDisplayer->setScaledContents(true);

    //
    ui->setupUi(this);

    //
    ui->comboBoxDateAndTimeFormats->addItems(this->allDateTimeFormatsQList);
    ui->comboBoxDateAndTimeFormats->setCurrentIndex(0);

    // Definition and implementation of IANA timezones comboBox and of the date and time displayer...
    ui->comboBoxOfIANATimezones->addItems(this->allTimezonesQList);
    ui->comboBoxOfIANATimezones->setCurrentIndex(this->getIANATimezoneIndex(this->getSystemIANATimezone()));
    this->updateDisplayedTimeForSpecificTimeZone();

    //
    this->dateTimeTimer = new QTimer(this);

    //
    this->dateTimeTimer->start(1000);

    // Definition of all 'connects' functions used in this class...
    connect(ui->comboBoxOfIANATimezones, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(ui->comboBoxDateAndTimeFormats, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(this->dateTimeTimer, SIGNAL(timeout()), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
}

//
MainDesktopWeaDTWindow::~MainDesktopWeaDTWindow()
{
    //
    delete ui;
}

//
QList<QString> MainDesktopWeaDTWindow::getAllTimezonesQList()
{
    //
    return this->allTimezonesQList;
}

//
QList<QString> MainDesktopWeaDTWindow::getAllIANATimezones()
{
    //
    QList<QString> listOfAllIANATimezonesQListQString = QList<QString>();

    //
    QList<QByteArray> listOfAllIANATimezonesQListQByteArray = QTimeZone::availableTimeZoneIds();

    //
    for(int i = 0; i < listOfAllIANATimezonesQListQByteArray.count(); i++) {

        //
        QString currentTimeZoneAsString = QString(listOfAllIANATimezonesQListQByteArray[i]);

        //
        QStringList currentTimeZoneAsStringList = currentTimeZoneAsString.split("/");

        //
        if(currentTimeZoneAsStringList.contains("Africa") || currentTimeZoneAsStringList.contains("America") || currentTimeZoneAsStringList.contains("Asia") || currentTimeZoneAsStringList.contains("Atlantic") || currentTimeZoneAsStringList.contains("Australia") || currentTimeZoneAsStringList.contains("Europe") || currentTimeZoneAsStringList.contains("Indian") || currentTimeZoneAsStringList.contains("Pacific")) {

            //
            listOfAllIANATimezonesQListQString.append(currentTimeZoneAsString);
        }
    }

    //
    return listOfAllIANATimezonesQListQString;
}

//
QString MainDesktopWeaDTWindow::getSystemIANATimezone()
{
    //
    return QString(QTimeZone::systemTimeZone().id());
}

//
int MainDesktopWeaDTWindow::getIANATimezoneIndex(QString ianaTimeZone)
{
    //
    return this->allTimezonesQList.indexOf(ianaTimeZone);
}

//
void MainDesktopWeaDTWindow::updateDisplayedTimeForSpecificTimeZone()
{
    //
    if(ui->comboBoxDateAndTimeFormats->currentText() == "timestamp")
    {

        //
        qDebug() << "PPPP: " << this->getDateTimeForSpecificTimeZone();

    //
    } else {

        //
        QDateTime qdateTimeForSpecificTimeZone;

        //
        qdateTimeForSpecificTimeZone.setSecsSinceEpoch(this->getDateTimeForSpecificTimeZone());

        //
        qDebug() << "PPPP: " << qdateTimeForSpecificTimeZone.toString(ui->comboBoxDateAndTimeFormats->currentText());
    }

    //ui->lcdNumber->display(this->getDateTimeForSpecificTimeZone());
}

// 'getDateTimeForSpecificTimeZone' function to return the current date and time from the current timezone...
qint64 MainDesktopWeaDTWindow::getDateTimeForSpecificTimeZone()
{
    // Definition of the 'currentQTimeZone' QTimeZone object from the current timezone...
    QTimeZone currentQTimeZone(ui->comboBoxOfIANATimezones->currentText().toUtf8());

    // Returning the current date and time of the current timezone, from the sum of the UTC timestamp with the timezone's offset from UTC as number of seconds, as a timestamp...
    return QDateTime::currentSecsSinceEpoch() + currentQTimeZone.offsetFromUtc(QDateTime::currentDateTime());
}
