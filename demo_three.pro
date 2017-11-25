#-------------------------------------------------
#
# Project created by QtCreator 2017-11-03T20:33:04
#
#-------------------------------------------------

QT       += core gui
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo_three
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    dialog.cpp \
    dialog2.cpp

HEADERS  += widget.h \
    dialog.h \
    dialog2.h

FORMS    += widget.ui \
    dialog.ui \
    dialog2.ui
