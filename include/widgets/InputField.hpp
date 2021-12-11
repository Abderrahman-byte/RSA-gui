#include <string>

#include <qt5/QtWidgets/QWidget>
#include <qt5/QtWidgets/QLineEdit>
#include <qt5/QtGui/QValidator>

#ifndef _INPUTFIELD_H_
#define _INPUTFIELD_H_ 1

class InputField : public QWidget {
    QLineEdit *inputField;

    public :
        InputField (QWidget * = 0) ;
        InputField (std::string , std::string = "", QWidget * = 0);
        void setValidator (QValidator *);
        QString getValue ();
        void setValue (QString);
};

#endif