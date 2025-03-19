  #ifndef AREA_H
#define AREA_H

#include "figura.h"
#include <QWidget>

class Area : public QWidget
{
    int myTimer;
    float alpha;

public:
    Area(QWidget *parent = 0);

    ~Area();

    MyLine *myline;
    MyRect *myrect;

protected:

    void paintEvent(QPaintEvent *event); //обработчик событий рисования
    void timerEvent(QTimerEvent *event); //обработчик события таймера
    void showEvent(QShowEvent *event); //обработчик события показа виджета
    void hideEvent(QHideEvent *event); //обработчик события скрытия виджета
};

#endif
