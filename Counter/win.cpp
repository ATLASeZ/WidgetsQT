#include "win.h"

#include <QHBoxLayout>

Win::Win(QWidget *parent):QWidget(parent) //конструктор
{
    setWindowTitle("Счётчик");

    label1 = new QLabel("Счёт по 1",this);
    label2 = new QLabel("Счёт по 5",this);

    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);

    calcbutton = new QPushButton("+1" , this);
    exitbutton = new QPushButton("Выход",this);

    if(!label1 || !label2 || !edit1 || !edit2 || !calcbutton || !exitbutton) //проверка на успешное выделение памяти
    {
        std::cerr << "Memory allocation error!";
    }

    QHBoxLayout *layout1 = new QHBoxLayout(); //компоновщик для меток
    QHBoxLayout *layout2 = new QHBoxLayout(); //компоновщик для счетчиков
    QHBoxLayout *layout3 = new QHBoxLayout(); //компоновщик для кнопок
    QVBoxLayout *layout4 = new QVBoxLayout(this); //компоновщик для окна приложения

    if(layout1 && layout2 && layout3 && layout4)
    {
        layout1->addWidget(label1);
        layout1->addWidget(label2);

        layout2->addWidget(edit1);
        layout2->addWidget(edit2);

        layout3->addWidget(calcbutton);
        layout3->addWidget(exitbutton);

        layout4->addLayout(layout1);
        layout4->addLayout(layout2);
        layout4->addLayout(layout3);

    }
    else
    {
        std::cerr << "Memory allocation error!"; //проверка
    }

    edit1->setEnabled(false); //отключение 1 и 2 счетчиков
    edit2->setEnabled(false);

    connect(exitbutton, &QPushButton::clicked, this, &Win::close); //сигнал закрытия  окна
    connect(calcbutton, &QPushButton::clicked, edit1, &Counter::add_one); //сигнал для +1
    connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one); //сигнал на счет по 5
}
