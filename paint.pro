TEMPLATE = app
TARGET = paint
QT = core gui 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
SOURCES +=  main.cpp mainwindow.cpp drawing.cpp
HEADERS = mainwindow.h drawing.h
QMAKE_CXXFLAGS += -DQT_QPA_PLATFORM=wayland
