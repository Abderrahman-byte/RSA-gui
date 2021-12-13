#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>

#include "widgets/TextField.hpp"

TextField::TextField (QWidget * parent) : TextField("", "", parent) {}

TextField::TextField (std::string labelText, std::string descriptionText, QWidget *parent) {
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *label = new QLabel;
    this->editor = new QTextEdit;

    label->setFixedHeight(40);
    label->setText(QString(labelText.c_str()));
    label->setAlignment(Qt::AlignLeft);

    this->editor->setMaximumHeight(150);
    
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(label);
    layout->addWidget(this->editor);

    // Connect signals and slots
    connect (this->editor, SIGNAL(textChanged()), this, SLOT(emitValueChanged()));

    this->setLayout(layout);
}

std::string TextField::getValue () {
    return this->editor->toPlainText().toStdString();
}

void TextField::setValue (std::string value) {
    this->editor->setText(QString(value.c_str()));
}

void TextField::emitValueChanged () {
    emit valueChanged();
}
