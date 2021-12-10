greaterThan(QT_MAJOR_VERSION, 5): QT += core gui widgets

QT += core gui widgets

TEMPLATE = app

INCLUDEPATH += ./include

HEADERS += ./include/MainWindow.hpp\
        ./include/widgets/RsaForm.hpp
        ./include/widgets/NumberInput.hpp

SOURCES += ./src/main.cpp\
    ./src/MainWindow.cpp\
    ./src/widgets/NumberInput.cpp\
    ./src/widgets/RsaForm.cpp

TARGET = rsa_gui