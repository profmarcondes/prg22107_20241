#include <QApplication>
#include "qtcalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QtCalc window;
    window.show();

    return a.exec();
}
