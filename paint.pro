TEMPLATE = app
TARGET = paint
QT = core gui 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets gui-private
SOURCES +=  main.cpp mainwindow.cpp drawing.cpp
HEADERS = mainwindow.h drawing.h
