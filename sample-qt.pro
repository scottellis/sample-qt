#
# Copyright (c) 2014 Jumpnow Technologies, LLC
#

TEMPLATE = app

TARGET = sample-qt

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp mainwindow.cpp

HEADERS  += mainwindow.h

target.path = /usr/bin
INSTALLS += target

