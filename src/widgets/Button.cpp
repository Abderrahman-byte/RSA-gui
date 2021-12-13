#include <QtGui/QFont>
#include <QtGui/QPalette>

#include "widgets/Button.hpp"

Button::Button (QWidget *parent) : Button("", parent)  {}

Button::Button (QString label, QWidget * parent) {
    this->setText(label);
}
