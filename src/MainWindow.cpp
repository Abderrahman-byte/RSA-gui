#include <qt5/QtCore/QCoreApplication>
#include <qt5/QtWidgets/QVBoxLayout>
#include <qt5/QtWidgets/QGridLayout>

#include "MainWindow.hpp"
#include "widgets/RsaForm.hpp"
#include "widgets/WarnDisplay.hpp"

MainWindow::MainWindow (QWidget *parent) {
    // QGridLayout *layout = new QGridLayout;
    QVBoxLayout *layout = new QVBoxLayout;
    RsaForm *rsaForm = new RsaForm;
    WarnDisplay *warnDisplay = new WarnDisplay;
    
    layout->setAlignment(Qt::AlignTop);
    // layout->addWidget(rsaForm, 0, 0, 0, 0);
    layout->addWidget(rsaForm);
    layout->addWidget(warnDisplay);

    layout->insertStretch(-1, 1);

    // Connect Form with warning display
    connect (rsaForm, SIGNAL(warning(QString)), warnDisplay, SLOT(displayWarning(QString)));
    connect (rsaForm, SIGNAL(fieldChanged()), warnDisplay, SLOT(clearWarning()));

    this->setLayout(layout);
    this->setWindowTitle(QCoreApplication::applicationName());
    this->resize(2000, 2000);
}