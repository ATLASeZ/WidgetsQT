#include "figura.h"

#include <math.h>

void Figura::move(float Alpha,QPainter *Painter)
{
    dx=halflen*cos(Alpha); //смещение по х и по у
    dy=halflen*sin(Alpha);

    draw(Painter); //рисует
}

void MyLine::draw(QPainter *Painter) //отрисовка
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);
}

void MyRect::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
