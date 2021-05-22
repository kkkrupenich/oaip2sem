#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <ctime>

QImage image(500, 500, QImage::Format_ARGB32);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    Node* item = new Node;
    item->image = image;
    item = List.leftToRight(item);
    image = item->image;
    ui->label->setPixmap(QPixmap::fromImage(image));
    item = item->prev;
    List.pop(item);
}

void MainWindow::on_pushButton_4_clicked()
{
    Node* item = new Node;
    item->image = image;
    List.push(item);
}

void MainWindow::on_pushButton_5_clicked()
{
    srand((unsigned)time(0));
    for(int y = 0; y < 500; ++y)
        for(int x = 0; x < 500; ++x)
        {
            QRgb argb = qRgb(rand() % 0xff, rand() % 0xff, rand() % 0xff);
            image.setPixel(x,y,argb);
        }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_clicked()
{
    Node* item = new Node;
    item->image = image;
    item = List.rightToLeft(item);
    image = item->image;
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_2_clicked()
{
    Node* item = new Node;
    item->image = image;
    item = List.leftToRight(item);
    image = item->image;
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_6_clicked()
{
    Node* item = new Node;
    item->queueItem = rand() % 100 + 1;
    Queue.push(item);
}

void MainWindow::on_pushButton_7_clicked()
{
    int a;
    if(!Queue.isEmpty())
    {
        a = Queue.pop();
        ui->textEdit->append(QString::number(a));
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    int a;
    for(int i = 0; !Queue.isEmpty(); i++)
    {
        a = Queue.pop();
        ui->textEdit->append(QString::number(a));
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(Queue.isEmpty())
        ui->textEdit->append("Empty");
    else
        ui->textEdit->append("NOT empty");
}
