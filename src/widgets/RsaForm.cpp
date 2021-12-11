#include <iostream>
#include <qt5/QtWidgets/QLineEdit>
#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QHBoxLayout>
#include <qt5/QtWidgets/QBoxLayout>
#include <qt5/QtWidgets/QGridLayout>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtGui/QFont>
#include <qt5/QtGui/QValidator>

#include "widgets/RsaForm.hpp"
#include "widgets/InputField.hpp"
#include "widgets/TextField.hpp"
#include "widgets/Button.hpp"
#include "rsa/utils.hpp"

RsaForm::RsaForm (QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QGridLayout *grid = new QGridLayout;
    QHBoxLayout *btnsLayout = new QHBoxLayout;
    TextField *messageField = new TextField("Saisissez le message à chiffrer :");
    TextField *cipherField = new TextField("Saisissez le message à déchiffrer :");
    Button *generateBtn = new Button("Générer des clés");
    Button *cipherBtn = new Button("Chiffrer");
    Button *decipherBtn = new Button("Déchiffrer");
    QLabel *formHeader = new QLabel;
    QIntValidator *intValidator = new QIntValidator;
    
    this->qInputField = new InputField("Le nombre Q :", "Ce nombre doit etre premier.");    
    this->pInputField = new InputField("Le nombre P :", "Ce nombre doit etre premier.");    
    this->eInputField = new InputField("Clé privées de chiffrement :", "Cette clé de cryptage doit correspondre à P et Q.");
    this->dInputField = new InputField("Clé publique de chiffrement:", "Cette clé de cryptage doit correspondre à P, Q et à la clé privée.");
    
    this->qInputField->setValidator(intValidator);
    this->pInputField->setValidator(intValidator);
    this->eInputField->setValidator(intValidator);

    formHeader->setText("Calculer les paramatres de RSA");
    formHeader->setFont(QFont("Sans Serif", 20));
    formHeader->setFixedHeight(70);

    grid->addWidget(this->pInputField, 0, 0);
    grid->addWidget(this->qInputField, 0, 1);
    grid->addWidget(this->eInputField, 1, 0);
    grid->addWidget(this->dInputField, 1, 1);
    grid->addWidget(messageField, 2, 0);
    grid->addWidget(cipherField, 2, 1);

    grid->setContentsMargins(0, 0, 0, 0);

    btnsLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    btnsLayout->addWidget(generateBtn);
    btnsLayout->addWidget(cipherBtn);
    btnsLayout->addWidget(decipherBtn);

    // btnsLayout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(formHeader);
    layout->addLayout(grid);
    layout->addLayout(btnsLayout);
    layout->insertStretch( -1, 1 );

    // Connect Signals with slots
    connect (generateBtn, SIGNAL(clicked()), this, SLOT(generateKeys()));

    this->setLayout(layout);
}

void RsaForm::generateKeys () {
    int p = this->pInputField->getValue().toInt();
    int q = this->qInputField->getValue().toInt();
    int e = this->eInputField->getValue().toInt();
    int d = this->dInputField->getValue().toInt();

    // Generer Q et P si ils ne sont pas donnes par l'utilisateur
    if (q == 0 || p == 0) {
        p = generatePrime();
        q = generatePrime();
        e = 0;
        d = 0;

        this->pInputField->setValue(QString::number(p));
        this->qInputField->setValue(QString::number(q));
    } else if (!isPrime(q)) {
        std::cout << "Q must a prime number" << std::endl;
        return ;
    } else if (!isPrime(p)) {
        std::cout << "P must a prime number" << std::endl;
        return ;
    }

    // Generer Cle privee si il n'est pas donnee par l'utilisateur
    if (e == 0) {
        d = 0;
        e = generateRSAPrivateKey(q, p);
        this->eInputField->setValue(QString::number(e));
    } else if (pgcd(e, (p - 1) * (q - 1)) != 1) {
        std::cout << "Private Key must be prime with (p - 1) * (q - 1)" << std::endl;
        return ;
    }

    // Generer Cle public ils n'est pas donnee par l'utilisateur
    if (d == 0) {
        d = generateRSAPublicKey(q, p, e);
        this->dInputField->setValue(QString::number(d));
    } else if (!checkPublicKey(q, p, e, d)) {
        std::cout << "Invalid public key" << std::endl;
        return ;
    }
}