#include <QApplication>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget * janela = new QWidget;
    janela->setWindowTitle("Hello QT PRG22107");

    QSpinBox * spinbox = new QSpinBox;
    QSlider * slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    spinbox->setRange(0, 130);
    slider->setRange(0,130);

    QObject::connect(spinbox, SIGNAL(valueChanged(int)),
                     slider, SLOT(setValue(int)));

    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     spinbox, SLOT(setValue(int)));


    spinbox->setValue(35);

    QHBoxLayout * h_layout = new QHBoxLayout;
    h_layout->addWidget(spinbox);
    h_layout->addWidget(slider);

    QVBoxLayout * layout = new QVBoxLayout;

    QLabel * label = new QLabel("Hello QT!");
    label->setAlignment(Qt::AlignCenter);
    //label->show();

    QPushButton * button = new QPushButton("Quit");
    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
    //button->show();

    layout->addWidget(label);
    layout->addLayout(h_layout);
    layout->addWidget(button);

    janela->setLayout(layout);

    janela->setFixedSize(400,100);

    janela->show();

    return a.exec();
}
