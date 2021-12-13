#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

#ifndef _WARNDISPLAY_H_
#define _WARNDISPLAY_H_ 1

class WarnDisplay : public QWidget {
    Q_OBJECT

    private :
        QLabel *label;

    public :
        WarnDisplay (QWidget * = 0);

    public slots :
        void clearWarning ();
        void displayWarning (QString);
};

#endif
