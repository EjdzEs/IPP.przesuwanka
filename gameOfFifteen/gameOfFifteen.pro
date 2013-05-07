#-------------------------------------------------
#
# Project created by QtCreator 2013-05-06T17:57:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gameOfFifteen
TEMPLATE = app


SOURCES += main.cpp \
		mainwindow.cpp \
		pomoc.cpp \
		klocek.cpp \
		obrazek.cpp \
		permutacje.cpp \
		plansza.cpp

HEADERS  += mainwindow.h \
			pomoc.h \
			klocek.h \
			obrazek.h \
			permutacje.hxx \
			plansza.hxx

FORMS    += mainwindow.ui \
    pomoc.ui

RESOURCES += \
    MyResources.qrc
