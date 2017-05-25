#-------------------------------------------------
#
# Project created by QtCreator 2017-05-24T14:29:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = QtControl
TEMPLATE = app


SOURCES += main.cpp\
        MainWidget.cpp \
    mygauge1.cpp \
    mygauge2.cpp \
    mygauge3.cpp \
    mycoolbar.cpp \
    qcustomplot.cpp

HEADERS  += MainWidget.h \
    mygauge1.h \
    mygauge2.h \
    mygauge3.h \
    mycoolbar.h \
    qcustomplot.h

FORMS    += MainWidget.ui
