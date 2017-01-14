#-------------------------------------------------
#
# Project created by QtCreator 2016-12-29T11:39:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RingleRadar
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += qwt
CONFIG += qwtpolar
CONFIG += QWT_DLL
SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    myplot.cpp \
    myaxisscaledraw.cpp \
    mydata.cpp \
    myqwtpolarmagnifier.cpp \
    myqwtpolarpanner.cpp \
    mymarker.cpp \
    paramdisplay.cpp \
    constant.cpp

HEADERS  += mainwindow.h \
    form.h \
    myplot.h \
    myaxisscaledraw.h \
    mydata.h \
    myqwtpolarmagnifier.h \
    myqwtpolarpanner.h \
    mymarker.h \
    paramdisplay.h \
    constant.h

FORMS    += mainwindow.ui \
    form.ui \
    paramdisplay.ui

RESOURCES += \
    res.qrc
