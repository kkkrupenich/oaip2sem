#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(nullptr));
    for(int i = 0; i < 20; i++)
        table.add(rand()%100, rand() % 1000);
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
        ui->lineEdit_2->clear();
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
        ui->lineEdit_2->clear();
        ui->textEdit->append(tableMin.showTwo());
        ui->textEdit_2->append(tableMax.showTwo());
    }

}

void MainWindow::on_pushButton_clicked()
{
    if(!check)
    {
        ui->textEdit->clear();
        table.add(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt());
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->textEdit->append(table.show());
    }
    else
    {
        ui->textEdit_2->clear();
        ui->textEdit->clear();
        int temp = ui->lineEdit_2->text().toInt();
        if(temp <= sred)
            tableMin.add(ui->lineEdit->text().toInt(), temp);
        else
            tableMax.add(ui->lineEdit->text().toInt(), temp);

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->textEdit->append(tableMin.showTwo());
        ui->textEdit_2->append(tableMax.showTwo());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit_2->clear();
    ui->textEdit->clear();
    for(int i = 0; i < table.arrData.size(); i++)
        sred += table.arrData[i];
    sred /= table.arrData.size();

    for(int i = 0; i < table.arrData.size(); i++)
    {
        if(table.arrData[i] <= sred)
            tableMin.add(table.arrKey[i], table.arrData[i]);
        else
            tableMax.add(table.arrKey[i], table.arrData[i]);
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

void MainWindow::on_pushButton_5_clicked()
{
    srand(time(nullptr));
    if(!check)
    {
        ui->textEdit->clear();
        table.add(rand()%100, rand() % 1000);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->textEdit->append(table.show());
    }
    else
    {
        ui->textEdit_2->clear();
        ui->textEdit->clear();
        int temp = rand() % 1000;
        if(temp <= sred)
            tableMin.add(rand() % 100, temp);
        else
            tableMax.add(rand() % 100, temp);

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->textEdit->append(tableMin.showTwo());
        ui->textEdit_2->append(tableMax.showTwo());
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    int key = ui->lineEdit->text().toInt();
    if(!check)
    {
        int data = table.search(key);
        if(data == -1)
        {
            QMessageBox::information(0, "Not found!", "This key contains nothing");
            ui->lineEdit->clear();
            return;
        }
        QMessageBox::information(0, "Found!", "Key " + QString::number(key) + " contains: " + QString::number(data));
    }
    else
    {
        bool left = true;
        int data = tableMin.search(key);
        if(data == -1)
        {
            data = tableMax.search(key);
            left = false;
        }
        if(data == -1)
        {
            QMessageBox::information(0, "Not found!", "This key contains nothing");
            ui->lineEdit->clear();
            return;
        }
        if(left)
            QMessageBox::information(0, "Found!", "Key " + QString::number(key) + " contains: " + QString::number(data) + " in left table");
        else
            QMessageBox::information(0, "Found!", "Key " + QString::number(key) + " contains: " + QString::number(data) + " in right table");
    }
    ui->lineEdit->clear();
}
