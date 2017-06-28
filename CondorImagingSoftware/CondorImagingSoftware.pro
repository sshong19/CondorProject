#-------------------------------------------------
#
# Project created by QtCreator 2017-06-27T17:10:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CondorImagingSoftware
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    ArchitectorSDKFunctions.cpp

HEADERS  += mainwindow.h \
    ArchitectorSDKFunctions.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../Program Files (x86)/Quest Innovations/Architector_SDK_1.4.2/lib/' -lArchitectorCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../Program Files (x86)/Quest Innovations/Architector_SDK_1.4.2/lib/' -lArchitectorCore-d
else:unix: LIBS += -L$$PWD/'../../../../../Program Files (x86)/Quest Innovations/Architector_SDK_1.4.2/lib/' -lArchitectorCore

INCLUDEPATH += $$PWD/'../../../../../Program Files (x86)/Quest Innovations/Architector_SDK_1.4.2/include'
DEPENDPATH += $$PWD/'../../../../../Program Files (x86)/Quest Innovations/Architector_SDK_1.4.2/include'
