#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T18:55:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PJC_grafika
TEMPLATE = app
CONFIG += console c++11

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/cabstractidentifier.cpp \
    src/ccontinent.cpp \
    src/cengine.cpp \
    src/cexceptions.cpp \
    src/cgame.cpp \
    src/cmap.cpp \
    src/cmodelview.cpp \
    src/cplayer.cpp \
    src/cregion.cpp \
    src/crules.cpp \
    src/csoldier.cpp \
    src/tinyxml2.cpp \
    src/cmapdisplay.cpp \
    src/inputplayersdialog.cpp \
    src/inputrulesdialog.cpp \
    src/inputarmydialog.cpp

HEADERS  += header/mainwindow.h \
    header/cabstractidentifier.h \
    header/ccontinent.h \
    header/cengine.h \
    header/cexceptions.h \
    header/cgame.h \
    header/cmap.h \
    header/cmodelview.h \
    header/cplayer.h \
    header/cregion.h \
    header/crules.h \
    header/csoldier.h \
    header/tinyxml2.h \
    header/cmapdisplay.h \
    header/inputplayersdialog.h \
    header/inputrulesdialog.h \
    header/inputarmydialog.h

FORMS    += ui/mainwindow.ui \
    ui/inputplayersdialog.ui \
    ui/inputrulesdialog.ui \
    ui/inputarmydialog.ui

RESOURCES += \
    resource/resource.qrc
