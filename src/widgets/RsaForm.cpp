#include <qt5/QtWidgets/QLineEdit>
#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QBoxLayout>
#include <qt5/QtWidgets/QGridLayout>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtGui/QFont>
#include <qt5/QtGui/QValidator>

#include "widgets/RsaForm.hpp"
#include "widgets/InputField.hpp"
#include "widgets/TextField.hpp"
#include "widgets/Button.hpp"

RsaForm::RsaForm (QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QGridLayout *grid = new QGridLayout;
    QBoxLayout *btnsLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    InputField *qInputField = new InputField("Entrer le nombre Q :", "Ce nombre doit etre premier.");    
    InputField *pInputField = new InputField("Entrer le nombre P :", "Ce nombre doit etre premier.");    
    InputField *eInputField = new InputField("Entrer le cle privee de chiffrement :", "Le cle de chiffrement doit etre correspondant a P et Q.");
    TextField *messageField = new TextField("Entrer le message a chiffrer :");
    TextField *cipherField = new TextField("Entrer le message a dechiffrer :");
    Button *generateBtn = new Button("Generer cle public");
    QLabel *formHeader = new QLabel;
    QIntValidator *intValidator = new QIntValidator;
    
    qInputField->setValidator(intValidator);
    pInputField->setValidator(intValidator);
    eInputField->setValidator(intValidator);

    formHeader->setText("Calculer les paramatres de RSA");
    formHeader->setFont(QFont("Sans Serif", 20));
    formHeader->setFixedHeight(70);

    grid->addWidget(pInputField, 0, 0);
    grid->addWidget(qInputField, 0, 1);
    grid->addWidget(eInputField, 1, 0, 1, 1);
    grid->addWidget(messageField, 2, 0);
    grid->addWidget(cipherField, 2, 1);

    btnsLayout->addWidget(generateBtn);

    layout->addWidget(formHeader);
    layout->addLayout(grid);
    layout->addLayout(btnsLayout);

    this->setLayout(layout);
}