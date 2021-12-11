#include "widgets/Button.hpp"
#include <qt5/QtGui/QFont>
#include <qt5/QtGui/QPalette>

Button::Button (QWidget *parent) : Button("", parent)  {}

Button::Button (QString label, QWidget * parent) {
    this->setText(label);
}