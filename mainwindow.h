#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
        // сигнал для передачи номера нажатой кнопки
        void signalFromButton(int button_id);


private:
    Ui::MainWindow *ui;

private slots:
    // слоты-обработчики нажатой кнопки
    void slotButton1();
    void slotButton2();
    void slotButton3();

    // слот, вызывающий сообщение с номером нажатой кнопки
    void slotMessage(int button_id);

};
#endif // MAINWINDOW_H
