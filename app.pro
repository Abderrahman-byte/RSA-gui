greaterThan(QT_MAJOR_VERSION, 5): QT += core gui widgets

QT += core gui widgets

TEMPLATE = app

INCLUDEPATH += ./include

CONFIG += static

HEADERS += ./include/MainWindow.hpp ./include/widgets/RsaForm.hpp\
        ./include/widgets/InputField.hpp\
        ./include/widgets/TextField.hpp\
        ./include/widgets/Button.hpp\
        ./include/widgets/WarnDisplay.hpp\
        ./include/rsa/util.hpp\
        ./include/utils.hpp

SOURCES += ./src/main.cpp ./src/MainWindow.cpp\
    ./src/widgets/RsaForm.cpp\
    ./src/widgets/TextField.cpp\
    ./src/widgets/InputField.cpp\
    ./src/widgets/Button.cpp\
    ./src/widgets/WarnDisplay.cpp\
    ./src/rsa/util.cpp\
    ./src/utils.cpp

TARGET = rsa_gui