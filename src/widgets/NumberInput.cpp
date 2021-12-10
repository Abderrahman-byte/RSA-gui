#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtWidgets/QLineEdit>
#include <qt5/QtGui/QFont>
#include <qt5/QtGui/QIntValidator>

#include "widgets/NumberInput.hpp"

NumberInput::NumberInput (QWidget *parent) : NumberInput("Label goes here", "nullptr", parent) {};

NumberInput::NumberInput (std::string labelText, std::string descriptionText, QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *label = new QLabel;
    QLabel *description = new QLabel;
    QLineEdit *inputField = new QLineEdit;
    QIntValidator *validator = new QIntValidator(0, 1000);

    label->setFixedSize(200, 40);
    label->setText(QString(labelText.c_str()));
    label->setAlignment(Qt::AlignLeft);
    inputField->setMaximumSize(300, 30);
    inputField->setValidator(validator);

    layout->addWidget(label);
    layout->addWidget(inputField);

    if (descriptionText.length() > 0) {
        description->setAlignment(Qt::AlignLeft);
        description->setText(QString(descriptionText.c_str()));
        description->setFont(QFont("Sans Serif", 10));

        layout->addWidget(description);
    }


    this->setLayout(layout);
}