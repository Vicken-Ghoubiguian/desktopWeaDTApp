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
    this->allDateTimeFormatsQList.append("dddd dd MM yyyy");
    this->allDateTimeFormatsQList.append("ddd dd MM yyyy");
    this->allDateTimeFormatsQList.append("dd/MM/yyyy");
    this->allDateTimeFormatsQList.append("dddd dd MM yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("dddd dd MM yyyy hh:mm:ss ap");
    this->allDateTimeFormatsQList.append("ddd dd MM yyyy hh:mm:ss");
    this->allDateTimeFormatsQList.append("ddd dd MM yyyy hh:mm:ss ap");
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

    // Definition of the 'dateTimeDisplayerFont' which is the 'dateTimeDisplayer' QLabel font...
    QFont dateTimeDisplayerFont;
    dateTimeDisplayerFont.setPointSize(20);

    // Set all fonts for corresponding widgets...
    ui->dateTimeDisplayer->setFont(dateTimeDisplayerFont);

    //
    /*QFont comboBoxOfIANATimezonesFont;
    comboBoxOfIANATimezonesFont.fromString("background-color: skyblue; color: white; border-radius: 10px;");

    //
    ui->comboBoxOfIANATimezones->setFont(comboBoxOfIANATimezonesFont);

    //
    QFont comboBoxDateAndTimeFormatsFont;
    comboBoxDateAndTimeFormatsFont.fromString("background-color: skyblue; color: white; border-radius: 10px;");

    //
    ui->comboBoxDateAndTimeFormats->setFont(comboBoxDateAndTimeFormatsFont);*/

    //
    ui->comboBoxOfIANATimezones->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");
    ui->comboBoxDateAndTimeFormats->setStyleSheet("background-color: skyblue; color: white; border-radius: 10px;");

    // Stylisation of widgets in the 'date and time' tab's section...
    this->ui->resetButton->setStyleSheet("background-color: red; color: white; border-radius: 10px;");
    this->ui->validationButton->setStyleSheet("background-color: green; color: white; border-radius: 10px;");

    //
    this->updateDisplayedTimeForSpecificTimeZone();

    // Definition of the application's (and main window's too) name...
    this->setWindowTitle("L'app which déchire vraiment ta life !!!!");

    // Definition of the application's (and main window's too) fixed size...
    this->setFixedSize(820, 600);

    //
    //this->setWindowIcon(QIcon("ressources/img/cybcity.png"));

    //
    /*QPixmap pm("https://flagcdn.com/16x12/za.png");
    ui->flagDisplayer->setPixmap(pm);
    ui->flagDisplayer->setScaledContents(true);*/

    // Definition of the date and time timer to follow current time...
    this->dateTimeTimer = new QTimer(this);

    // Starting the date and time timer with a 1 second interval (1000 miliseconds)...
    this->dateTimeTimer->start(1000);

    // Definition of all 'connects' functions used in this class...
    connect(ui->comboBoxOfIANATimezones, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(ui->comboBoxDateAndTimeFormats, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
    connect(this->dateTimeTimer, SIGNAL(timeout()), this, SLOT(updateDisplayedTimeForSpecificTimeZone()));
}

// Definition of the 'MainDesktopWeaDTWindow' class destructor...
MainDesktopWeaDTWindow::~MainDesktopWeaDTWindow()
{
    // Deleting the application's graphical interface...
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
    QDateTime qdateTimeForSpecificTimeZone;

    //
    qdateTimeForSpecificTimeZone.setSecsSinceEpoch(QDateTime::currentSecsSinceEpoch());

    //
    QDateTime currentTimeZoneDateTime = qdateTimeForSpecificTimeZone.toTimeZone(QTimeZone(ui->comboBoxOfIANATimezones->currentText().toUtf8()));

    //
    if(ui->comboBoxDateAndTimeFormats->currentText() == "ISO Date")
    {
        //
        //qDebug() << ui->comboBoxOfIANATimezones->currentText() << ": " << currentTimeZoneDateTime.toString(Qt::ISODate);
        ui->dateTimeDisplayer->setText(ui->comboBoxOfIANATimezones->currentText() + ": " + currentTimeZoneDateTime.toString(Qt::ISODate));

    //
    } else {

        //
        //qDebug() << ui->comboBoxOfIANATimezones->currentText() << ": " << currentTimeZoneDateTime.toString(ui->comboBoxDateAndTimeFormats->currentText());
        ui->dateTimeDisplayer->setText(ui->comboBoxOfIANATimezones->currentText() + ": " + currentTimeZoneDateTime.toString(ui->comboBoxDateAndTimeFormats->currentText()));
    }

    //ui->lcdNumber->display(this->getDateTimeForSpecificTimeZone());
    //ui->dateTimeDisplayer->setText(this->getDateTimeForSpecificTimeZone());
}
