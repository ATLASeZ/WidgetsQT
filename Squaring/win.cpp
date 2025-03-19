#include "win.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

Win::Win(QWidget *parent):QWidget(parent)  //реализация конструктора
{
    codec = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codec->toUnicode("Возведение в квадрат")); // устанавливаем заголовок окна

    frame = new QFrame(this); //работа с рамкой
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel(codec->toUnicode("Введите число:"), this); //метод ввода
    inputEdit = new QLineEdit("",this); //поле ввода

    StrValidator *v=new StrValidator(inputEdit); //проверка ввода
    inputEdit->setValidator(v);

    outputLabel = new QLabel(codec->toUnicode("Результат:"),this); //метод ввывода
    outputEdit = new QLineEdit("",this);

    nextButton = new QPushButton(codec->toUnicode("Следующее"), this); //кнопки
    exitButton = new QPushButton(codec->toUnicode("Выход"), this);

    // компоновка приложения выполняется согласно рисунку 2
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); //вертикаль
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this); //горизонталь
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();

    connect(exitButton, &QPushButton::clicked, this, &Win::close); //сигналы слоты
    connect(nextButton, &QPushButton::clicked, this, &Win::begin);
    connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc);
}

void Win::begin()
{
    inputEdit->clear();

    nextButton->setEnabled(false); //отключение кнопки
    nextButton->setDefault(false);

    inputEdit->setEnabled(true);
    outputLabel->setVisible(false); //отключение полей
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);

    inputEdit->setFocus(); //фокус на ввод пользователя
}

void Win::calc()
{
    bool Ok=true;
    float r; // результат
    float a; // число пользователя

    QString str=inputEdit->text(); //получение текста из поле ввода
    a=str.toDouble(&Ok);
    bool bufferOverloaded = false; //перегружен ли буфер или нет

    if (abs(a) >= sqrt(3.4 * pow(10,38))){ //оптимизация
        bufferOverloaded = true;
    }

    if (Ok && !bufferOverloaded)
    {
        r=a*a;

        str.setNum(r);
        outputEdit->setText(str);

        inputEdit->setEnabled(false); // отключаем поле ввода

        outputLabel->setVisible(true); //показываем метку и поле
        outputEdit->setVisible(true);

        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    } else {
        if (!str.isEmpty() && !bufferOverloaded) //неверное значение и буффер не переполнен
        {

            QMessageBox msgBox(QMessageBox::Information,
                               codec->toUnicode("Возведение в квадрат."),
                               codec->toUnicode("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec();
            inputEdit->clear();
        }
        else {
            QMessageBox msgBox(QMessageBox::Information,
                               codec->toUnicode("Возведение в квадрат."),
                               codec->toUnicode("Введено слишком большое число."),
                               QMessageBox::Ok);
            msgBox.exec();
            inputEdit->clear();
        }
    }
}
