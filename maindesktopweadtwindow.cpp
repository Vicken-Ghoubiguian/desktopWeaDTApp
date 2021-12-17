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

    // Definition and implementation of IANA timezones comboBox and of the date and time displayer...
    ui->comboBoxOfIANATimezones->addItems(this->allTimezonesQList);
    ui->comboBoxOfIANATimezones->setCurrentIndex(this->getIANATimezoneIndex(this->getSystemIANATimezone()));
    this->updateDisplayedTimeForSpecificTimeZone();

    //
    ui->comboBoxDateAndTimeFormats->addItems(this->allDateTimeFormatsQList);
    ui->comboBoxDateAndTimeFormats->setCurrentIndex(0);

    // Definition of all 'connects' functions used in this class...
    connect(ui->comboBoxOfIANATimezones, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
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
    qDebug() << this->getDateTimeForSpecificTimeZone();

    //ui->lcdNumber->display(this->getDateTimeForSpecificTimeZone());
}

//
qint64 MainDesktopWeaDTWindow::getDateTimeForSpecificTimeZone()
{
    //
    QTimeZone currentQTimeZone(ui->comboBoxOfIANATimezones->currentText().toUtf8());

    //
    return QDateTime::currentMSecsSinceEpoch() + currentQTimeZone.offsetFromUtc(QDateTime::currentDateTime());
}
