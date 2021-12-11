#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QTextEdit>
#include <qt5/QtWidgets/QLabel>

#include "widgets/TextField.hpp"

TextField::TextField (QWidget * parent) : TextField("", "", parent) {}

TextField::TextField (std::string labelText, std::string descriptionText, QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QTextEdit *editor = new QTextEdit;
    QLabel *label = new QLabel;

    label->setFixedHeight(40);
    label->setText(QString(labelText.c_str()));
    label->setAlignment(Qt::AlignLeft);

    editor->setMaximumHeight(150);
    
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(label);
    layout->addWidget(editor);

    this->setLayout(layout);
}