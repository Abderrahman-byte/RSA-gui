#include <qt5/QtCore/QCoreApplication>
#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QGridLayout>

#include "widgets/RsaForm.hpp"
#include "MainWindow.hpp"

MainWindow::MainWindow (QWidget *parent) {
    QGridLayout *layout = new QGridLayout;
    RsaForm *rsaForm = new RsaForm;
    
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(rsaForm, 0, 0, 0, 0);

    this->setLayout(layout);
    this->setWindowTitle(QCoreApplication::applicationName());
    this->resize(2000, 2000);
}