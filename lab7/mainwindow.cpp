#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(nullptr));
    for(int i = 0; i < 40; i++)
        table.add(rand()%100);
    ui->textEdit->clear();
    ui->textEdit->append(table.show());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(!check)
    {
        ui->textEdit->clear();
        table.remove(ui->lineEdit->text().toInt());
        ui->lineEdit->clear();
        ui->textEdit->append(table.show());
    }
    else
    {
        ui->textEdit_2->clear();
        ui->textEdit->clear();
        int temp = ui->lineEdit->text().toInt();
        if(temp <= sred)
            tableMin.remove(temp);
        else
            tableMax.remove(temp);

        ui->lineEdit->clear();
        ui->textEdit->append(tableMin.showTwo());
        ui->textEdit_2->append(tableMax.showTwo());
    }

}

void MainWindow::on_pushButton_clicked()
{
    if(!check)
    {
        ui->textEdit->clear();
        table.add(ui->lineEdit->text().toInt());
        ui->lineEdit->clear();
        ui->textEdit->append(table.show());
    }
    else
    {
        ui->textEdit_2->clear();
        ui->textEdit->clear();
        int temp = ui->lineEdit->text().toInt();
        if(temp <= sred)
            tableMin.add(temp);
        else
            tableMax.add(temp);

        ui->lineEdit->clear();
        ui->textEdit->append(tableMin.showTwo());
        ui->textEdit_2->append(tableMax.showTwo());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit_2->clear();
    ui->textEdit->clear();
    for(int i = 0; i < table.arr.size(); i++)
        sred += table.arr[i];
    sred /= table.arr.size();

    for(int i = 0; i < table.arr.size(); i++)
    {
        if(table.arr[i] <= sred)
            tableMin.add(table.arr[i]);
        else
            tableMax.add(table.arr[i]);
    }

    ui->label->setText(QString::number(sred));
    ui->textEdit->append(tableMin.showTwo());
    ui->textEdit_2->append(tableMax.showTwo());
    table.free();
    check = true;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->label->clear();
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    tableMax.free();
    tableMin.free();
    QApplication::exit(0);
}
