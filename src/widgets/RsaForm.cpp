#include <qt5/QtWidgets/QLineEdit>
#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QGridLayout>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtGui/QFont>

#include "widgets/RsaForm.hpp"
#include "widgets/NumberInput.hpp"

RsaForm::RsaForm (QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QGridLayout *grid = new QGridLayout;
    NumberInput *qInputField = new NumberInput("Entrer le nombre Q :", "Ce nombre doit etre premier.");    
    NumberInput *pInputField = new NumberInput("Entrer le nombre P :", "Ce nombre doit etre premier.");    
    NumberInput *eInputField = new NumberInput("Entrer le cle de chiffrement :", "Le cle de chiffrement doit etre correspondant a P et Q.");    
    QLabel *formHeader = new QLabel;

    grid->addWidget(pInputField, 0, 0);
    grid->addWidget(qInputField, 0, 1);
    grid->addWidget(eInputField, 1, 0);

    formHeader->setText("Calculer les paramatres de RSA");
    formHeader->setFont(QFont("Sans Serif", 20));
    formHeader->setFixedHeight(70);

    layout->addWidget(formHeader);
    layout->addLayout(grid);

    this->setLayout(layout);
}