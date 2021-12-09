#include <qt5/QtWidgets/QApplication>
#include <qt5/QtWidgets/QWidget>
#include "MainWindow.hpp"

int main (int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow *window;    
    
    QCoreApplication::setApplicationName(QString("RSA"));
    window = new MainWindow();

    window->show();

    return app.exec();
}