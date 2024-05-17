#include "numpad.h"

Numpad::Numpad(QWidget *parent)
    : QWidget{parent}
{
    _layout = new QGridLayout;

    setStyleSheet("font: bold;font-size: 24px;");
    setFocusPolicy(Qt::StrongFocus);

    for(int i = 0; i < 9; i++){
        _pads[i+1] = new QPushButton(QString::number(i+1));
        connect(_pads[i+1], SIGNAL(clicked()), this, SLOT(keyPressed()));
        _layout->addWidget(_pads[i+1],(2-(i/3)),i%3);
    }
    _pads[0] = new QPushButton(QString::number(0));
    connect(_pads[0], SIGNAL(clicked()), this, SLOT(keyPressed()));
    _layout->addWidget(_pads[0],3,0);

    _plus_op = new QPushButton("+");
    _layout->addWidget(_plus_op,0,3);

    _minus_op = new QPushButton("-");
    _layout->addWidget(_minus_op,1,3);

    _div_op = new QPushButton("÷");
    _layout->addWidget(_div_op,2,3);

    _mul_op = new QPushButton("x");
    _layout->addWidget(_mul_op,3,3);

    _equal_op = new QPushButton("=");
    _layout->addWidget(_equal_op,3,2);

    _period = new QPushButton(".");
    _layout->addWidget(_period,3,1);

    connect(_plus_op, SIGNAL(clicked()), this, SLOT(keyPressed()));
    connect(_minus_op, SIGNAL(clicked()), this, SLOT(keyPressed()));
    connect(_div_op, SIGNAL(clicked()), this, SLOT(keyPressed()));
    connect(_mul_op, SIGNAL(clicked()), this, SLOT(keyPressed()));
    connect(_equal_op, SIGNAL(clicked()), this, SLOT(keyPressed()));
    connect(_period, SIGNAL(clicked()), this, SLOT(keyPressed()));

    setLayout(_layout);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

}

void Numpad::keyPressed(){
    QPushButton * btnPressed = qobject_cast<QPushButton *>(sender());
    char value = btnPressed->text().at(0).toLatin1();
    int tmp = (int)value;
    if (tmp == -9)
        value = '/';
    else if (value == 'x')
        value = '*';
    emit keyStroke(value);
}

void Numpad::keyPressEvent(QKeyEvent* pe){
    int k = pe->key();

    if(k >= Qt::Key_0 && k <= Qt::Key_9){
        int idx = k - 0x30;
        _pads[idx]->animateClick();
    } else if(k == Qt::Key_Plus)
        _plus_op->animateClick(500);
    else if(k == Qt::Key_Minus)
        _minus_op->animateClick(500);
    else if(k == Qt::Key_Slash)
        _div_op->animateClick(500);
    else if(k == Qt::Key_Asterisk)
        _mul_op->animateClick(500);
    else if(k == Qt::Key_Equal)
        _equal_op->animateClick(500);
    else if(k == Qt::Key_Period)
        _period->animateClick(500);


}
