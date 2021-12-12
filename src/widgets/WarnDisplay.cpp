#include <qt5/QtWidgets/QLabel>
#include <qt5/QtWidgets/QVBoxLayout>

#include "widgets/WarnDisplay.hpp"

WarnDisplay::WarnDisplay (QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    this->label = new QLabel;
    
    this->label->setStyleSheet("QLabel { background-color: red; color: whitesmoke; padding: 10 20; border-radius: 5; }");
    this->label->setText("Warnings and error goes here");
    this->label->hide();

    layout->setAlignment(Qt::AlignLeft);
    layout->addWidget(this->label);
    this->setLayout(layout);
}

void WarnDisplay::displayWarning (QString message) {
    this->label->setText(message);
    this->label->show();
}

void WarnDisplay::clearWarning () {
    this->label->setText("");
    this->label->hide();
}