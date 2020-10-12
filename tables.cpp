#include "mainwindow.h"
#include "ui_mainwindow.h"

void
MainWindow::TableInit()
{
    QTableWidget* tb = ui->tableWidget;
    //парсим строку в лист, заполняем название столбоц и строк
    QStringList headCollumns;
    for(int i = 0; i < headC.length(); i++){
        headCollumns.push_back((QString)headC[i]);
    }
    tb->setHorizontalHeaderLabels(headCollumns);
    QStringList headRows;
    for(int i = 0; i < headR.length(); i++){
        headRows.push_back((QString)headR[i]);
    }
    tb->setVerticalHeaderLabels(headRows);

    //пробегаемся по массиву и заполняем элементы дефолтной строкой
    //запоняем словать шифратор
    map.clear();
    bmap.clear();
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            QString key = (QString)a[i*6+j];
            tb->item(i,j)->setText(key);
            map[key] = headRows[i] + headCollumns[j];
        }
    }
    QList <QString> maps = map.keys();
    foreach(auto el, maps){
        bmap[map[el]] = el;
    }
    ui->lineEdit->setText(headC);
    ui->lineEdit_2->setText(headR);
}

void
MainWindow::defInit()
{
    a = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ.,- ";
    headC = "АБВГДЕ";
    headR = "АБВГДЕ";
    TableInit();
}
//Нажатие кнопки по умолчанию
void MainWindow::on_pushButton_clicked()
{
    //восстанавливаем дефолтные значения
    defInit();
}

//Нажатие кнопки отмена
void MainWindow::on_pushButton_9_clicked()
{
    //восстанавливаем предыдущие значения
    TableInit();
}

//Нажатие кнопки сохранить
void MainWindow::on_pushButton_2_clicked()
{
    QTableWidget* tb = ui->tableWidget;
    int rows = tb->rowCount();
    int column = tb->columnCount();
    a = "";
    //заполняем хранилище значений из таблицы
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < column; j++){
            a += tb->item(i,j)->text();
        }
    }

    //берём новые значения из поля ввода
    //если длинна не достаточна, то дополняем её следующими по списку литерами
    QString tmp = ui->lineEdit->text();
    for(int i = 0; tmp.length() < 6; i++){
        tmp += QChar(tmp[tmp.length()-1].unicode()+1);
    }

    headC = tmp;
    tmp = ui->lineEdit_2->text();
    for(int i = 0; tmp.length() < 6; i++){
        tmp += QChar(tmp[tmp.length()-1].unicode()+1);
    }
    headR = tmp;

    //перерисовываем таблицу - вдруг столбцы или строки изменились
    //обновляем map и bmap
    TableInit();
}
