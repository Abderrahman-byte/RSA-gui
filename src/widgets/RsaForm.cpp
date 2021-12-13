#include <iostream>
#include <vector>

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtGui/QFont>
#include <QtGui/QValidator>

#include "widgets/RsaForm.hpp"
#include "widgets/InputField.hpp"
#include "widgets/TextField.hpp"
#include "widgets/Button.hpp"
#include "rsa/util.hpp"
#include "utils.hpp"

RsaForm::RsaForm (QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QGridLayout *grid = new QGridLayout;
    QHBoxLayout *btnsLayout = new QHBoxLayout;
    Button *generateBtn = new Button("Générer des clés");
    Button *cipherBtn = new Button("Chiffrer");
    Button *decipherBtn = new Button("Déchiffrer");
    QLabel *formHeader = new QLabel;
    QIntValidator *intValidator = new QIntValidator;
    
    this->qInputField = new InputField("Le nombre Q :", "Ce nombre doit etre premier.");    
    this->pInputField = new InputField("Le nombre P :", "Ce nombre doit etre premier.");    
    this->eInputField = new InputField("La clé de chiffrement :", "Cette clé de cryptage doit correspondre à P et Q.");
    this->dInputField = new InputField("La clé de déchiffrement:", "Cette clé de cryptage doit correspondre à P, Q et à La clé de chiffrement.");
    this->messageField = new TextField("Saisissez le message à chiffrer :");
    this->cipherField = new TextField("Saisissez le message à déchiffrer :");
    
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

    layout->addWidget(formHeader);
    layout->addLayout(grid);
    layout->addLayout(btnsLayout);
    layout->insertStretch( -1, 1 );

    // Connect Signals with slots
    connect (generateBtn, SIGNAL(clicked()), this, SLOT(generateKeys()));
    connect (cipherBtn, SIGNAL(clicked()), this, SLOT(encrypt()));
    connect (decipherBtn, SIGNAL(clicked()), this, SLOT(decrypt()));
    connect (this->qInputField, SIGNAL(valueChanged()), this, SLOT(emitFieldChanged()));
    connect (this->pInputField, SIGNAL(valueChanged()), this, SLOT(emitFieldChanged()));
    connect (this->eInputField, SIGNAL(valueChanged()), this, SLOT(emitFieldChanged()));
    connect (this->dInputField, SIGNAL(valueChanged()), this, SLOT(emitFieldChanged()));
    connect (this->messageField, SIGNAL(valueChanged()), this, SLOT(emitFieldChanged()));
    connect (this->cipherField, SIGNAL(valueChanged()), this, SLOT(emitFieldChanged()));

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
        emit warning("Q doit être un nombre premier");
        return ;
    } else if (!isPrime(p)) {
        emit warning("P doit être un nombre premier");
        return ;
    }

    // Generer Cle privee si il n'est pas donnee par l'utilisateur
    if (e == 0) {
        d = 0;
        e = generateRSAPrivateKey(q, p);
        this->eInputField->setValue(QString::number(e));
    } else if (pgcd(e, (p - 1) * (q - 1)) != 1) {
        emit warning("La clé de chiffrement doit être premier avec (p - 1) * (q - 1)");
        return ;
    }

    // Generer Cle public ils n'est pas donnee par l'utilisateur
    if (d == 0) {
        d = generateRSAPublicKey(q, p, e);
        this->dInputField->setValue(QString::number(d));
    } else if (!checkPublicKey(q, p, e, d)) {
        emit warning("Clé de déchiffrement est invalide");
        return ;
    }
}

void RsaForm::encrypt () {
    int p = this->pInputField->getValue().toInt();
    int q = this->qInputField->getValue().toInt();
    int e = this->eInputField->getValue().toInt();
    int d = this->dInputField->getValue().toInt();
    std::string plain = this->messageField->getValue();
    std::string encryptedFormated = "";

    if (p == 0 || !isPrime(p)) {
        emit warning("Le nombre p est invalide");
        return ;
    } else if (q == 0 || !isPrime(q)) {
        emit warning("Le nombre q est invalide");
        return ;
    } else if (e == 0 || pgcd(e, (p - 1) * (q - 1)) != 1 ) {
        emit warning("La clé de cryptage n'est pas valide");
        return ;
    } else if (d == 0 || !checkPublicKey(p, q, e, d)) {
        generateKeys();
        return ;
    }

    if (plain.length() <= 0) {
        emit warning("Veuillez saisir le texte à chiffrer");
        return ;
    }


    for (int i = 0; i < plain.length(); i++) {
        unsigned a = (unsigned)plain.at(i);
        long encryptedByte = expMod(a, e, q * p);
        encryptedFormated += std::to_string(encryptedByte);

        if (i < plain.length() - 1) encryptedFormated += " ";
    }

    this->cipherField->setValue(encryptedFormated);
}

void RsaForm::decrypt () {
    int p = this->pInputField->getValue().toInt();
    int q = this->qInputField->getValue().toInt();
    int e = this->eInputField->getValue().toInt();
    int d = this->dInputField->getValue().toInt();
    std::string encrypted = this->cipherField->getValue();
    std::string decrypted = "";
    std::vector<std::string> encryptedParts;

    if (p == 0 || !isPrime(p)) {
        emit warning("Le nombre p est invalide");
        return ;
    } else if (q == 0 || !isPrime(q)) {
        emit warning("Le nombre q est invalide");
        return ;
    } else if (d == 0 || !checkPublicKey(p, q, e, d)) {
        emit warning("La clé de déchiffrement n'est pas valide");
        return ;
    }

    if (encrypted.length() <= 0) {
        emit warning("Veuillez saisir le texte chiffré");
        return ;
    }

    encryptedParts = split(encrypted, " ");

    for (int i = 0; i < encryptedParts.size(); i++) {
        std::string encByte = encryptedParts.at(i);
        int enc = std::stoi(encByte);
        int dec = expMod(enc, d, q * p);

        decrypted += char(dec);
    }

    this->messageField->setValue(decrypted);
}

void RsaForm::emitFieldChanged () {
    emit fieldChanged();
}
