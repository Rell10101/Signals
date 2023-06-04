#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // связываем кнопки с соответствующими слотами
    QObject::connect(ui->Button_1, &QPushButton::clicked, this, &MainWindow::slotButton1);
    QObject::connect(ui->Button_2, &QPushButton::clicked, this, &MainWindow::slotButton2);
    QObject::connect(ui->Button_3 , &QPushButton::clicked, this, &MainWindow::slotButton3);

    // подключаем сигнал с передачей номера кнопки к слоту вывода сообщения
    QObject::connect(this, &MainWindow::signalFromButton, this, &MainWindow::slotMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// слоты для обработки нажатия кнопок
void MainWindow::slotButton1()
{
    // Ключевое слово emit вызывает сигнал signalFromButton() с новым значением в качестве аргумента
    // параметр 1 соответствует нажатию первой кнопки
    emit signalFromButton(1);
}

void MainWindow::slotButton2()
{
    emit signalFromButton(2);
}

void MainWindow::slotButton3()
{
    emit signalFromButton(3);
}

// слот вывода сообщения
void MainWindow::slotMessage(int button_id)
{
    ui->label->setText("Нажата кнопка под номером " + QString::number(button_id));
}
