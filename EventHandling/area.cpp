#include "area.h"

Area::Area(QWidget *parent):QWidget(parent) //конструктор
{
    setFixedSize(QSize(300,200));
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}

void Area::showEvent(QShowEvent *) //показ виджета
{
    myTimer=startTimer(50);
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this); //создаем объект для рисования
    painter.setPen(Qt::blue); //устанавливаем цвет

    myline->move(alpha,&painter);
    myrect->move(alpha*(-0.5),&painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer)//обновление фигуры с новым углом
    {
        alpha=alpha+0.2;

        update();
    }
}

void Area::hideEvent(QHideEvent *) //остановка счетчика
{
    killTimer(myTimer);
}

Area::~Area() //диструктор
{
    delete myline;
    delete myrect;
}
