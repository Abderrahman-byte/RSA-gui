#include <string>

#include <QtWidgets/QWidget>
#include <QtWidgets/QTextEdit>

#ifndef _TEXTFIELD_H_
#define _TEXTFIELD_H_ 1

class TextField : public QWidget {
    Q_OBJECT

    private :
        QTextEdit *editor;

    public :
        TextField (QWidget * = 0);
        TextField (std::string, std::string = "", QWidget * = 0);
        std::string getValue ();
        void setValue (std::string);

    signals :
        void valueChanged ();

    public slots :
        void emitValueChanged ();
};

#endif
