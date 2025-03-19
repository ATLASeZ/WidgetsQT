#ifndef WIN_H
#define WIN_H

#include <iostream>
#include <QtGui>
#include <QLineEdit>
#include <QLabel>
#include<QPushButton>

class Counter:public QLineEdit
{
    Q_OBJECT

public:
    Counter(const QString & contents, QWidget *parent=0) : QLineEdit(contents, parent){
    }

signals:
    void tick_signal();

public slots:
    void add_one()
    {
        QString str=text(); // считаем строку из поля ввода

        int r=str.toInt(); //преобразовываем к целому числу

        r++;

        if (r!=0 && r%5 == 0) emit tick_signal(); //сигнал на счетчик по 5


        str.setNum(r); //преобразование число в строку
        setText(str);
    }
};

class Win:public QWidget
{
    Q_OBJECT

protected:
    QTextCodec *codec; //для работы с русским языком
    QLabel *label1;  //метки счетчиков
    QLabel *label2;
    Counter *edit1;  //указатели на счетчики 1-1, 2-5
    Counter *edit2;
    QPushButton *calcbutton; //+1
    QPushButton *exitbutton;

public:
    Win(QWidget *parent = 0); //конструктор
};

#endif
