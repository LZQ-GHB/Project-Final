QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h \
    mysocket.h \
    serialrecv.h \
    serialtrans.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mysocket.cpp \
    serialrecv.cpp \
    serialtrans.cpp
