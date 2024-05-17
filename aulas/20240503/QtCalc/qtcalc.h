#ifndef QTCALC_H
#define QTCALC_H

#include <QtWidgets>
#include "numpad.h"

class QtCalc : public QWidget
{
        Q_OBJECT
    public:
        explicit QtCalc(QWidget *parent = nullptr);

    public slots:
        void keyInput(char value);

    signals:

    private:
        void doMath();

    private:
        QLabel * _label;
        QString  _value;
        Numpad * _numpad;

        bool     _reset;
        double   _last_value;
        char     _cur_op;

        QVBoxLayout * _layout;
};

#endif // QTCALC_H
