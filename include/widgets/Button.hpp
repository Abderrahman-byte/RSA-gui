#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

#ifndef _BUTTON_H_
#define _BUTTON_H_ 1

class Button : public QPushButton {
    public :
        Button (QWidget * parent = 0);
        Button (QString, QWidget *parent = 0);
};

#endif
