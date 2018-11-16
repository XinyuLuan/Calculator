#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T15:16:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gui_Calculator4
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    basenode_jw.h \
    express.h \
    fraction.h \
    linkedlistjw.h \
    mixed.h \
    nodejw.h \
    note.h \
    operators.h \
    parenthesis.h \
    parser.h \
    queue_link.h \
    stackjw.h \
    token.h

FORMS    += mainwindow.ui
