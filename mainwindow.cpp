#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("01_Lab");
    defInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Нажатие кнопки тест
void MainWindow::on_pushButton_3_clicked()
{
    ui->plainTextEdit->setPlainText("ПРИВЕТ ЭТО ТЕСТОВАЯ НАДПИСЬ ДЛЯ ДЕМОНСТРАЦИИ РАБОТЫ АЛГОРИТМА");
}

//Нажатие кнопки поменять
void MainWindow::on_pushButton_5_clicked()
{
    QString tmp = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->setPlainText(ui->plainTextEdit_2->toPlainText());
    ui->plainTextEdit_2->setPlainText(tmp);
}

//нажатие кнопки очистить
void MainWindow::on_pushButton_8_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit_2->clear();
}

//нажатие кнопки кодировать
void MainWindow::on_pushButton_4_clicked()
{
    QString from = ui->plainTextEdit->toPlainText();
    QString to = "";
    foreach(auto el,from){
        to += map[el];
    }
    ui->plainTextEdit_2->setPlainText(to);
}

//нажатие кнопки декодировать
void MainWindow::on_pushButton_6_clicked()
{
    QString from = ui->plainTextEdit->toPlainText();
    QString to = "";
    for(int i = 0; i < from.length(); i+=2){
        QString tmp = (QString)from[i] + (QString)from[i+1];
        to += bmap[tmp];
    }
    ui->plainTextEdit_2->setPlainText(to);
}

//нажатие кнопки очистить первое поле ввода
void MainWindow::on_pushButton_10_clicked()
{
    ui->plainTextEdit->clear();
}

//нажатие кнопки очистить второе поле ввода
void MainWindow::on_pushButton_11_clicked()
{
    ui->plainTextEdit_2->clear();
}
