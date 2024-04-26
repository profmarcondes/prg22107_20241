#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel * label = new QLabel("Hello QT!");
    label->setAlignment(Qt::AlignHCenter);
    label->show();
    return a.exec();
}
