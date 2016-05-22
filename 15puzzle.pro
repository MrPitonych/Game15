TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    Menu.cpp \
    Game.cpp \
    gameboard.cpp \
    view.cpp \
    15puzzle.cpp \
    artificalintelligence.cpp

HEADERS += \
    Menu.h \
    Game.h \
    gameboard.h \
    view.h \
    artificalintelligence.h
