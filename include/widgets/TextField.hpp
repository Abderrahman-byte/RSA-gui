#include <string>

#include <qt5/QtWidgets/QWidget>
#include <qt5/QtWidgets/QTextEdit>

#ifndef _TEXTFIELD_H_
#define _TEXTFIELD_H_ 1

class TextField : public QWidget {
    private :
        QTextEdit *editor;

    public :
        TextField (QWidget * = 0);
        TextField (std::string, std::string = "", QWidget * = 0);
        std::string getValue ();
        void setValue (std::string);
};

#endif