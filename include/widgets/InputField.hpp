#include <string>

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtGui/QValidator>

#ifndef _INPUTFIELD_H_
#define _INPUTFIELD_H_ 1

class InputField : public QWidget {
    Q_OBJECT

    public :
        InputField (QWidget * = 0) ;
        InputField (std::string , std::string = "", QWidget * = 0);
        void setValidator (QValidator *);
        QString getValue ();
        void setValue (QString);
    signals :
        void valueChanged ();

    public slots :
        void emitValueChanged ();

    private :
        QLineEdit *inputField;
};

#endif
