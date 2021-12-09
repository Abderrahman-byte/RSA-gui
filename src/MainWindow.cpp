#include <qt5/QtWidgets/QPushButton>
#include <qt5/QtWidgets/QLCDNumber>
#include <qt5/QtWidgets/QSlider>
#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QGridLayout>

#include "MainWindow.hpp"

MainWindow::MainWindow (QWidget *parent) {
    QGridLayout *layout = new QGridLayout;
    QPushButton *quitButton = new QPushButton ("Quit");
    QLCDNumber *lcd = new QLCDNumber(2);
    QSlider *slider = new QSlider(Qt::Horizontal);

    quitButton->setFixedSize(75, 30);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setFixedSize(100, 100);
    slider->setRange(0, 99);
    slider->setValue(50);

    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    layout->addWidget(lcd);
    layout->addWidget(slider);
    layout->addWidget(quitButton);

    this->setLayout(layout);
    this->resize(2000, 2000);
}