#include "qtcalc.h"

QtCalc::QtCalc(QWidget *parent)
    : QWidget{parent}
{

    _cur_op = 0;
    _reset = true;
    _value = "0";
    _label = new QLabel(_value);
    _label->setStyleSheet("font: bold;font-size: 24px;");
    _label->setAlignment(Qt::AlignRight);
    _numpad = new Numpad;

    _layout = new QVBoxLayout;
    _layout->addWidget(_label);
    _layout->addWidget(_numpad);

    connect(_numpad, SIGNAL(keyStroke(char)), this, SLOT(keyInput(char)));

    setLayout(_layout);

}

void QtCalc::doMath(){
    double res = 0.0;
    double cur_value = 0.0;

    if(_reset){
        cur_value = 0;
    } else {
        cur_value =  _value.toDouble();
    }
    switch(_cur_op){
        case '+':
            res = _last_value + cur_value;
            break;
        case '-':
            res = _last_value - cur_value;
            break;
        case '/':
            res = _last_value / cur_value;
            break;
        case '*':
            res = _last_value * cur_value;
            break;
    }
    _value = QString::number(res, 'g');
    _label->setText(_value);
}

void QtCalc::keyInput(char value){
    switch(value){
        case '+':
        case '-':
        case '/':
        case '*':
            if(_cur_op) doMath();
            _last_value = _value.toDouble();
            _cur_op = value;
            _reset = true;
            break;

        case '=':
            if(_cur_op){
                doMath();
                _cur_op = 0;
                _reset = true;
            }
            break;

        case '.':
            if(!_value.contains(value)) {
                _value += value;
            }
            _label->setText(_value);
            break;

        case '0':
            if(_value == "0")
                break;

        default:
            if(_reset){
                _value = value;
                _reset = false;
            } else {
                _value += value;
            }
            _label->setText(_value);
    }
}
