#-------------------------------------------------
#
# Project created by QtCreator 2012-06-08T16:28:42
#
#-------------------------------------------------

QT       += core gui network

TARGET = FD4-Sprocket
TEMPLATE = app


SOURCES += main.cpp\
        sprocketwindow.cpp \
    sprocketthread.cpp \
    sprocketserver.cpp \
    sprocketclientconnection.cpp \
    command/buildcommand.cpp

HEADERS  += sprocketwindow.h \
    sprocketthread.h \
    sprocketserver.h \
    sprocketclientconnection.h \
    iclientcommunication.h \
    command/icommand.h \
    command/buildcommand.h

FORMS    += sprocketwindow.ui
