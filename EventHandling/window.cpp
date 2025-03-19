#include "window.h"

#include <QVBoxLayout>

Window::Window()
{
    codec = QTextCodec::codecForName("utf-8");

    this->setWindowTitle(codec->toUnicode("Обработка событий")); //заголовок окна

    area = new Area(this); //создаем область для рисования

    btn = new QPushButton(codec->toUnicode("Завершить"), this ); //кнопка завершения программы

    QVBoxLayout *layout = new QVBoxLayout(this);//вертикальный компоновщик
    layout->addWidget(area);
    layout->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, &Window::close); //сигнал-слот
};
