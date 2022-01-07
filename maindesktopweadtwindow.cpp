//
#include "maindesktopweadtwindow.h"
#include "ui_maindesktopweadtwindow.h"

// Definition of the 'MainDesktopWeaDTWindow' class constructor...
MainDesktopWeaDTWindow::MainDesktopWeaDTWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainDesktopWeaDTWindow)
{
    // Definition and implementation of IANA timezones QList<QString>...
    this->allTimezonesQList = this->getAllIANATimezones();

    // Definition and implementation of date and time formats QList<QString>...
    this->allDateTimeFormatsQList.append("ISO Date");
    this->allDateTimeFormatsQList.append("dd MM yyyy");
    this->allDateTimeFormatsQList.append("ddd. dd MMM. yyyy");
    this->allDateTimeFormatsQList.append("dddd dd MMMM yyyy");
    this->allDateTimeFormatsQList.append("dd MM yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("ddd. dd MMM. yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("dddd dd MMMM yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("dd MM yyyy hh:mm:ss ap");
    this->allDateTimeFormatsQList.append("ddd. dd MMM. yyyy hh:mm:ss ap");
    this->allDateTimeFormatsQList.append("dddd dd MMMM yyyy hh:mm:ss ap");
    this->allDateTimeFormatsQList.append("MM dd yyyy");
    this->allDateTimeFormatsQList.append("ddd. MMM. dd yyyy");
    this->allDateTimeFormatsQList.append("dddd MMMM dd yyyy");
    this->allDateTimeFormatsQList.append("MM dd yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("ddd. MMM. dd yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("dddd MMMM dd yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("MM dd yyyy hh:mm:ss ap");
    this->allDateTimeFormatsQList.append("ddd. MMM. dd yyyy hh:mm:ss ap");
    this->allDateTimeFormatsQList.append("dddd MMMM dd yyyy hh:mm:ss ap");
    this->allDateTimeFormatsQList.append("dd/MM/yyyy");
    this->allDateTimeFormatsQList.append("dd/MM/yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("dd/MM/yyyy hh:mm:ss ap");
    this->allDateTimeFormatsQList.append("hh:mm:ss.zzz");
    this->allDateTimeFormatsQList.append("hh:mm:ss");
    this->allDateTimeFormatsQList.append("hh:mm:ss ap");

    // Setup the graphical interface of this application...
    ui->setupUi(this);

    // Definition and implementation of date and time formats comboBox and the current date and time format as index...
    ui->comboBoxDateAndTimeFormats->addItems(this->allDateTimeFormatsQList);
    ui->comboBoxDateAndTimeFormats->setCurrentIndex(0);

    // Definition and implementation of IANA timezones comboBox, the current timezone and the first implementation of the date and time displayer's function...
    ui->comboBoxOfIANATimezones->addItems(this->allTimezonesQList);
    ui->comboBoxOfIANATimezones->setCurrentIndex(this->getIANATimezoneIndex(this->getSystemIANATimezone()));

    // Stylisation of widgets in the 'date and time' tab's section...
    ui->dateTimeDisplayer->setStyleSheet("font-size: 27px;");
    ui->comboBoxOfIANATimezones->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");
    ui->comboBoxDateAndTimeFormats->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");

    // Stylisation of line edits in the 'weather' tab's section...
    ui->localizationLineEdit->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");
    ui->countryCodeLineEdit->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");
    ui->apiKeyLineEdit->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");

    // Stylisation of widgets in the 'weather' tab's section...
    ui->resetButton->setStyleSheet("background-color: red; color: white; border-radius: 10px;");
    ui->validationButton->setStyleSheet("background-color: green; color: white; border-radius: 10px;");

    // Definition of the 'weather' tab's section's buttons' cursors...
    ui->resetButton->setCursor(Qt::PointingHandCursor);
    ui->validationButton->setCursor(Qt::PointingHandCursor);

    //
    this->updateDisplayedTimeForSpecificTimeZone();

    // Definition of the application's (and main window's too) name...
    this->setWindowTitle("L'app which déchire vraiment ta life !!!!");

    // Definition of the application's (and main window's too) fixed size...
    this->setFixedSize(840, 600);

    //
    //this->setWindowIcon(QIcon("://img/cybcity.png"));

    //
    //QPixmap pm("://img/cybcity.png");
    //ui->flagLabel->setPixmap(pm);
    ui->flagLabel->setStyleSheet("background-color: red");
    //ui->flagLabel->setScaledContents(true);

    // Definition of the date and time timer to follow current time...
    this->dateTimeTimer = new QTimer(this);

    // Starting the date and time timer with a 1 second interval (1000 miliseconds)...
    this->dateTimeTimer->start(1000);

    // Definition of all 'connects' functions used in this class...
    connect(ui->comboBoxOfIANATimezones, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(ui->comboBoxDateAndTimeFormats, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(this->dateTimeTimer, SIGNAL(timeout()), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(resetInputsForWeather()));
    connect(ui->validationButton, SIGNAL(clicked()), this, SLOT(validationInputsWeather()));
    connect(&weatherManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(managerFinishedForWeather(QNetworkReply*)));

    //connect(&this->flagManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(managerFinishedForFlag(QNetworkReply*)));

    /*QUrl url("https://flagcdn.com/w40/za.png");
    flagRequest.setUrl(url);
    flagManager.get(flagRequest);*/
}

/*void MainDesktopWeaDTWindow::managerFinishedForFlag(QNetworkReply *reply)
{
    if (reply->error()) {
            qDebug() << reply->errorString();
            return;
    }

    qDebug() << reply;
}*/

// Definition of the 'MainDesktopWeaDTWindow' class destructor...
MainDesktopWeaDTWindow::~MainDesktopWeaDTWindow()
{
    // Deleting the application's graphical interface...
    delete ui;
}

// Definition of the 'getAllTimezonesQList' getter which will return the 'allTimezonesQList' attribute...
QList<QString> MainDesktopWeaDTWindow::getAllTimezonesQList()
{
    // Returning the 'allTimezonesQList' attribute...
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

// Definition of the 'getSystemIANATimezone' getter which will get and return the system's IANA timezone's id...
QString MainDesktopWeaDTWindow::getSystemIANATimezone()
{
    // Getting and returning the system's IANA timezone's id...
    return QString(QTimeZone::systemTimeZone().id());
}

// Definition of the 'getIANATimezoneIndex' function which will get and return the passed in parameter IANA timezone's id...
int MainDesktopWeaDTWindow::getIANATimezoneIndex(QString ianaTimeZone)
{
    // Definition of the 'getIANATimezoneIndex' function which will get and return the passed in parameter IANA timezone's id...
    return this->allTimezonesQList.indexOf(ianaTimeZone);
}

//
void MainDesktopWeaDTWindow::updateDisplayedTimeForSpecificTimeZone()
{
    //
    QDateTime qdateTimeForSpecificTimeZone;

    //
    qdateTimeForSpecificTimeZone.setSecsSinceEpoch(QDateTime::currentSecsSinceEpoch());

    //
    QDateTime currentTimeZoneDateTime = qdateTimeForSpecificTimeZone.toTimeZone(QTimeZone(ui->comboBoxOfIANATimezones->currentText().toUtf8()));

    //
    if(ui->comboBoxDateAndTimeFormats->currentText() == "ISO Date")
    {
        //
        ui->dateTimeDisplayer->setText(ui->comboBoxOfIANATimezones->currentText() + ": " + currentTimeZoneDateTime.toString(Qt::ISODate));

    //
    } else {

        //
        ui->dateTimeDisplayer->setText(ui->comboBoxOfIANATimezones->currentText() + ": " + currentTimeZoneDateTime.toString(ui->comboBoxDateAndTimeFormats->currentText()));
    }
}

// Definition of the 'resetInputsForWeather' function to reset all localization's, country code's and api key's lineEdits and the weather's textDisplay to empty...
void MainDesktopWeaDTWindow::resetInputsForWeather()
{

    // Reseting all localization's, country code's and api key's lineEdits and the weather's textDisplay to empty...
    ui->localizationLineEdit->setText("");
    ui->countryCodeLineEdit->setText("");
    ui->apiKeyLineEdit->setText("");
    ui->weatherTextDisplay->setText("");
}

//
void MainDesktopWeaDTWindow::validationInputsWeather()
{
    //
    QString weatherRequestSUrl = "http://api.openweathermap.org/data/2.5/weather?q=" + ui->localizationLineEdit->text() + "," + ui->countryCodeLineEdit->text() + "&appid=dddd";

    //
    weatherRequest.setUrl(QUrl(weatherRequestSUrl));

    //
    weatherManager.get(weatherRequest);
}

//
void MainDesktopWeaDTWindow::managerFinishedForWeather(QNetworkReply *reply) {

    //
    if (reply->error()) {

        //
        qDebug() << reply->errorString();

        //
        return;
    }

    //
    //QString answer = reply->readAll();

    //
    ui->weatherTextDisplay->setText(reply->readAll());

    //
    //qDebug() << answer;
}
