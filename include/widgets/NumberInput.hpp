#include <string>

#include <qt5/QtWidgets/QWidget>

#ifndef _NUMBERINPUT_H_
#define _NUMBERINPUT_H_ 1

class NumberInput : public QWidget {
    public :
        NumberInput (QWidget * = 0) ;
        NumberInput (std::string , std::string = "", QWidget * = 0);
};

#endif