#include <string>

#include <qt5/QtWidgets/QWidget>

class TextField : public QWidget {
    public :
        TextField (QWidget * = 0);
        TextField (std::string, std::string = "", QWidget * = 0);
};