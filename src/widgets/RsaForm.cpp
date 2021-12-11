#include <qt5/QtWidgets/QLineEdit>
#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QGridLayout>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtGui/QFont>
#include <qt5/QtGui/QValidator>

#include "widgets/RsaForm.hpp"
#include "widgets/InputField.hpp"

RsaForm::RsaForm (QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QGridLayout *grid = new QGridLayout;
    InputField *qInputField = new InputField("Entrer le nombre Q :", "Ce nombre doit etre premier.");    
    InputField *pInputField = new InputField("Entrer le nombre P :", "Ce nombre doit etre premier.");    
    InputField *eInputField = new InputField("Entrer le cle privee de chiffrement :", "Le cle de chiffrement doit etre correspondant a P et Q.");
    QLabel *formHeader = new QLabel;
    QIntValidator *intValidator = new QIntValidator;
    
    qInputField->setValidator(intValidator);
    pInputField->setValidator(intValidator);
    eInputField->setValidator(intValidator);

    grid->addWidget(pInputField, 0, 0);
    grid->addWidget(qInputField, 0, 1);
    grid->addWidget(eInputField, 1, 0, 1, 1);

    formHeader->setText("Calculer les paramatres de RSA");
    formHeader->setFont(QFont("Sans Serif", 20));
    formHeader->setFixedHeight(70);

    layout->addWidget(formHeader);
    layout->addLayout(grid);

    this->setLayout(layout);
}