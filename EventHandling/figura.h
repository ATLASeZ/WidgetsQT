#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>

class Figura
{
protected:
    int x; //центр фигуры по х
    int y; //центр фигуры по у
    int halflen; //половина длины фигуры
    int dx; //смещение по х
    int dy; //смещение по у

    virtual void draw(QPainter *Painter) = 0; //чисто виртуальная функция

public:
    Figura(int X,int Y,int Halflen)://конструктор
        x(X),y(Y),halflen(Halflen){}

    void move(float Alpha,QPainter *Painter); //перемещает фигуру(угол и ручка)
};

class MyLine:public Figura
{
protected:
    void draw(QPainter *Painter);

public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
};

class MyRect:public Figura
{
protected:
    void draw(QPainter *Painter);

public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};

#endif
