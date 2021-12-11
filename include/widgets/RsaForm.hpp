#include <qt5/QtWidgets/QWidget>
#include <qt5/QtWidgets/QLineEdit>

#include "widgets/InputField.hpp"
#include "widgets/TextField.hpp"
#include "widgets/Button.hpp"

#ifndef _RSAFORM_H_
#define _RSAFORM_H_ 1

class RsaForm : public QWidget {
    Q_OBJECT

    private :
        InputField *qInputField;
        InputField *pInputField;
        InputField *eInputField;
        InputField *dInputField;

    public :
        RsaForm (QWidget *parent = 0);

    public slots :
        void generateKeys ();
};

#endif