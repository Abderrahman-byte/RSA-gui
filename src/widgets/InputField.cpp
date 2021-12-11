#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtWidgets/QLineEdit>
#include <qt5/QtGui/QFont>
#include <qt5/QtGui/QIntValidator>

#include "widgets/InputField.hpp"

InputField::InputField (QWidget *parent) : InputField("Label goes here", "nullptr", parent) {};

InputField::InputField (std::string labelText, std::string descriptionText, QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *label = new QLabel;
    QLabel *description = new QLabel;
    this->inputField = new QLineEdit;

    label->setFixedHeight(40);
    label->setText(QString(labelText.c_str()));
    label->setAlignment(Qt::AlignLeft);
    this->inputField->setMaximumSize(400, 30);

    layout->addWidget(label);
    layout->addWidget(this->inputField);

    if (descriptionText.length() > 0) {
        description->setAlignment(Qt::AlignLeft);
        description->setText(QString(descriptionText.c_str()));
        description->setFont(QFont("Sans Serif", 10));

        layout->addWidget(description);
    }

    this->setLayout(layout);
}

void InputField::setValidator (QValidator *validator) {
    this->inputField->setValidator(validator);
}

QString InputField::getValue () {
    return this->inputField->text();
}

void InputField::setValue (QString value) {
    this->inputField->setText(value);
}