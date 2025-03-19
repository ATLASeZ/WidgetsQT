#ifndef WINDOW_H
#define WINDOW_H

#include "area.h"
#include <QWidget>
#include <QtGui>
#include <QPushButton>

class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area;
    QPushButton * btn;

public:
    Window();
};

#endif
