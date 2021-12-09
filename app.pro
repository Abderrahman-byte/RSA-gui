greaterThan(QT_MAJOR_VERSION, 5): QT += core gui widgets

QT += core gui widgets

TEMPLATE = app

INCLUDEPATH += ./include

SOURCES += ./src/main.cpp\
    ./src/MainWindow.cpp

TARGET = rsa_gui