#-------------------------------
#
# Project created by QtCreator
#
#-------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pong
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        paddle.cpp \
    ball.cpp \
    gamecontroller.cpp

HEADERS += \
        mainwindow.h \
        paddle.h \
    ball.h \
    gamecontroller.h \
    config.h

FORMS += \
        mainwindow.ui

DISTFILES +=
