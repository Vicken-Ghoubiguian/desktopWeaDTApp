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

    //
    this->availableBackgroundColorQList.append("skyblue");
    this->availableBackgroundColorQList.append("purple");
    this->availableBackgroundColorQList.append("green");
    this->availableBackgroundColorQList.append("hunter-green");
    this->availableBackgroundColorQList.append("orange");
    this->availableBackgroundColorQList.append("red");

    // Setup the graphical interface of this application...
    ui->setupUi(this);

    // Definition and implementation of date and time formats comboBox and the current date and time format as index...
    ui->comboBoxDateAndTimeFormats->addItems(this->allDateTimeFormatsQList);
    ui->comboBoxDateAndTimeFormats->setCurrentIndex(0);

    // Definition and implementation of background color comboBox and the current background color as index...
    ui->backgroundColorForCBComboBox->addItems(this->availableBackgroundColorQList);
    ui->backgroundColorForCBComboBox->setCurrentIndex(0);

    // Definition and implementation of IANA timezones comboBox, the current timezone and the first implementation of the date and time displayer's function...
    ui->comboBoxOfIANATimezones->addItems(this->allTimezonesQList);
    ui->comboBoxOfIANATimezones->setCurrentIndex(this->getIANATimezoneIndex(this->getSystemIANATimezone()));

    // Stylisation of widgets in the 'date and time' tab's section...
    ui->dateTimeDisplayer->setAlignment(Qt::AlignCenter);
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

    //
    ui->weatherFrame->setStyleSheet("background-color: black;");

    // Definition of the 'weather' tab's section's buttons' cursors...
    ui->resetButton->setCursor(Qt::PointingHandCursor);
    ui->validationButton->setCursor(Qt::PointingHandCursor);

    //
    this->updateDisplayedTimeForSpecificTimeZone();

    // Definition of the application's (and main window's too) name...
    this->setWindowTitle("L'app which déchire vraiment ta life !!!!");

    // Definition of the application's (and main window's too) fixed size...
    this->setFixedSize(840, 600);

    // Check if the host OS is from "Windows" type...
    if(QSysInfo::productType() == "windows")
    {
        // Defines the logo of the application for a Windows type operating system...
        setWindowIcon(QIcon(":/img/cybcity.ico"));

    }
    //
    else
    {
        //
        setWindowIcon(QIcon(":/img/cybcity.png"));
    }

    //
    QPixmap pm("https://flagcdn.com/w40/za.png");
    pm = pm.scaled(ui->flagLabelforDateTime->size(),Qt::KeepAspectRatio);
    //ui->flagLabel->setPixmap(pm);

    //ui->flagLabelforDateTime->setStyleSheet("background: red;");
    //ui->flagLabelforDateTime->setStyleSheet("background: 'https://flagcdn.com/w40/za.png';");
    ui->flagLabelforDateTime->setPixmap(pm);
    ui->flagLabelforDateTime->setMask(pm.mask());

    //ui->flagLabelforDateTime->setStyleSheet("background-image: url('https://flagcdn.com/16x12/za.png'); background-repeat: no-repeat;");
    //ui->flagLabel->setScaledContents(true);

    // Definition of the date and time timer to follow current time...
    this->dateTimeTimer = new QTimer(this);

    // Starting the date and time timer with a 1 second interval (1000 miliseconds)...
    this->dateTimeTimer->start(1000);

    //
    ui->familyFontComboBox->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");

    //
    ui->backgroundColorForCBComboBox->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");

    // Definition of all 'connects' functions used in this class...
    connect(ui->comboBoxOfIANATimezones, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(ui->comboBoxOfIANATimezones, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedCountryFlagForSpecificTimeZone()));
    connect(ui->comboBoxDateAndTimeFormats, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(this->dateTimeTimer, SIGNAL(timeout()), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(resetInputsForWeather()));
    connect(ui->validationButton, SIGNAL(clicked()), this, SLOT(validationInputsWeather()));
    connect(&this->weatherManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(managerFinishedForWeather(QNetworkReply*)));
    connect(ui->familyFontComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFamilyFont()));
    connect(ui->backgroundColorForCBComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeBackgroundColorOfComboBox()));

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

//
QJsonDocument MainDesktopWeaDTWindow::getWeatherJsonDocument()
{
    //
    return this->weatherJsonDocument;
}

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

//
QString MainDesktopWeaDTWindow::getCountryCodeFromTimezone(QString tz)
{
    return "za";
}

//
void MainDesktopWeaDTWindow::updateDisplayedCountryFlagForSpecificTimeZone()
{
    qDebug() << "https://flagcdn.com/w40/" + getCountryCodeFromTimezone(ui->comboBoxOfIANATimezones->currentText()) + ".png";
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
    QString weatherRequestSUrl = "";

    //
    if(ui->countryCodeLineEdit->text() == "")
    {

        //
        weatherRequestSUrl = "http://api.openweathermap.org/data/2.5/weather?q=" + ui->localizationLineEdit->text() + "&appid=" + ui->apiKeyLineEdit->text() + "";

    //
    } else {

        //
        weatherRequestSUrl = "http://api.openweathermap.org/data/2.5/weather?q=" + ui->localizationLineEdit->text() + "," + ui->countryCodeLineEdit->text() + "&appid=" + ui->apiKeyLineEdit->text() + "";

    }

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
        ui->weatherTextDisplay->setText(reply->errorString());

        //
        switch (reply->error())
        {
            case QNetworkReply::ConnectionRefusedError : qDebug() << "Test";
            case QNetworkReply::RemoteHostClosedError : qDebug() << "Test";
            default : qDebug() << "Test";
        }

        //
        return;
    }

    //
    QJsonParseError errJSON;

    //
    QString weatherHTTPResult = QString(reply->readAll());

    //
    QJsonDocument jsonDocument = QJsonDocument::fromJson(weatherHTTPResult.toUtf8(), &errJSON);

    //
    if(jsonDocument.isObject() == false) {

        //
        ui->weatherTextDisplay->setText(errJSON.errorString());

        //
        return;
    }

    //
    if(jsonDocument.isObject() == false) qDebug() << "Not obj...";

    //
    QJsonObject obj = jsonDocument.object();

    //
    RawWeather currentRawWeather = RawWeather(obj, obj["weather"].toArray().at(0));

    //
    ui->weatherTextDisplay->setText(currentRawWeather.toString());
}

//
void MainDesktopWeaDTWindow::changeFamilyFont() {

    //
    QFont newCurrentFontFamily(ui->familyFontComboBox->currentText(),9,400,false);

    //
    this->currentFont = newCurrentFontFamily;

    //

    //
    ui->dateTimeDisplayer->setFont(currentFont);

    //
    QApplication::setFont(this->currentFont);
}

//
void MainDesktopWeaDTWindow::changeBackgroundColorOfComboBox() {

    //
    QString backgroundColorQString = "background-color: " + ui->backgroundColorForCBComboBox->currentText() + "; color: white; border-radius: 10px;";

    //
    ui->comboBoxOfIANATimezones->setStyleSheet(backgroundColorQString);
    ui->comboBoxDateAndTimeFormats->setStyleSheet(backgroundColorQString);
    ui->localizationLineEdit->setStyleSheet(backgroundColorQString);
    ui->countryCodeLineEdit->setStyleSheet(backgroundColorQString);
    ui->apiKeyLineEdit->setStyleSheet(backgroundColorQString);
    ui->familyFontComboBox->setStyleSheet(backgroundColorQString);
    ui->backgroundColorForCBComboBox->setStyleSheet(backgroundColorQString);
}

//
QList<QString> MainDesktopWeaDTWindow::getAvailableBackgroundColorQList() {

    //
    return this->availableBackgroundColorQList;
}

//
QList<QString> MainDesktopWeaDTWindow::getAllDateTimeFormatsQList() {

    //
    return this->allDateTimeFormatsQList;
}

//
QFont MainDesktopWeaDTWindow::getCurrentFont() {

    //
    return this->currentFont;
}
