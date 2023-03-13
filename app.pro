TEMPLATE = app
TARGET = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES += app.cpp main.cpp
HEADERS = main.hpp