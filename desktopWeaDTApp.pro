QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coordinates.cpp \
    countryflag.cpp \
    geographiclocation.cpp \
    humidity.cpp \
    main.cpp \
    maindesktopweadtwindow.cpp \
    rawweather.cpp \
    weather.cpp \
    wind.cpp

HEADERS += \
    coordinates.h \
    countryflag.h \
    geographiclocation.h \
    humidity.h \
    maindesktopweadtwindow.h \
    rawweather.h \
    weather.h \
    wind.h

FORMS += \
    maindesktopweadtwindow.ui

RESOURCES.files = \
    img\cybcity.png

RESOURCES.prefix = /

RESOURCES += \
    ressources.qrc
