#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T14:24:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dsgui2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    terminal.cpp \
    filereader.cpp \
    binarysearchtree.cpp \
    ternarysearchtree.cpp \
    trie.cpp \
    filelisttexts.cpp \
    hash.cpp

HEADERS  += mainwindow.h \
    terminal.h \
    filereader.h \
    binarysearchtree.h \
    ternarysearchtree.h \
    trie.h \
    filelisttexts.h \
    hash.h

FORMS    += mainwindow.ui
