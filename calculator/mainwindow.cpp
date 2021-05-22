#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->answer->setText(QString::number(number));

    connect(ui->button_0, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_1, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_2, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_3, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_4, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_5, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_6, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_7, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_8, SIGNAL(clicked()),this, SLOT(NumPressed()));
    connect(ui->button_9, SIGNAL(clicked()),this, SLOT(NumPressed()));

    connect(ui->button_add, SIGNAL(clicked()),this, SLOT(MathButtonPressed()));
    connect(ui->button_sub, SIGNAL(clicked()),this, SLOT(MathButtonPressed()));
    connect(ui->button_div, SIGNAL(clicked()),this, SLOT(MathButtonPressed()));
    connect(ui->button_mul, SIGNAL(clicked()),this, SLOT(MathButtonPressed()));

    connect(ui->button_equal, SIGNAL(clicked()),this, SLOT(EqualButtonPressed()));

    connect(ui->button_clear, SIGNAL(clicked()), this, SLOT(Clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed()
{
    QPushButton* button = (QPushButton*)sender();
    QString butValue = button->text();
    QString ansValue = ui->answer->text();
    if(ansValue == '0')
    {
        ui->answer->setText(butValue);
    }
    else
    {
        if(butValue == '0')
        {
            QString newVal = ansValue + '0';
            ui->answer->setText(newVal);
        }
        else
        {
            QString newVal = ansValue + butValue;
            double dblValue = newVal.toDouble();
            ui->answer->setText((QString::number(dblValue, 'g', 16)));
        }
    }
    qDebug() << "Number: " << number;
    checkForMultEqualButton =  false;
}

void MainWindow::MathButtonPressed()
{
    if(divTrigger || mulTrigger || addTrigger || subTrigger)
    {
        QString newVal = ui->answer->text();
        equalValue = newVal.toDouble();
        if (addTrigger)
            number += equalValue;
        else if (subTrigger)
            number -= equalValue;
        else if (mulTrigger)
            number *= equalValue;
        else if(divTrigger)
            number /= equalValue;
        checkForEqualButton = true;
        checkForMultEqualButton = true;
    }
    divTrigger = false;
    mulTrigger = false;
    subTrigger = false;
    addTrigger = false;
    if(!checkForMultMathButton)
    {
        QString ansValue = ui->answer->text();
        number = ansValue.toDouble();
    }
    QPushButton *button = (QPushButton*)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0)
        divTrigger = checkForEqualButton = checkForMultMathButton = true;
    else if (QString::compare(butVal, "*", Qt::CaseInsensitive) == 0)
        mulTrigger = checkForEqualButton = checkForMultMathButton = true;
    else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0)
        addTrigger = checkForEqualButton = checkForMultMathButton = true;
    else
        subTrigger = checkForEqualButton = checkForMultMathButton = true;
    ui->answer->setText("");
    qDebug() << "Number: " << number;
    checkForMultEqualButton = false;
}

void MainWindow::EqualButtonPressed()
{
    if(!checkForEqualButton)
    {
        number = ui->answer->text().toDouble();
        ui->answer->setText(QString::number(number, 'g', 16));
        qDebug() << "Number: " << number;
        return;
    }

    if(!checkForMultEqualButton)
    {
        QString newVal = ui->answer->text();
        equalValue = newVal.toDouble();
        if (addTrigger)
            number += equalValue;
        else if (subTrigger)
            number -= equalValue;
        else if (mulTrigger)
            number *= equalValue;
        else if(divTrigger)
            number /= equalValue;
    }
    else
    {
        if (addTrigger)
            number += equalValue;
        else if (subTrigger)
            number -= equalValue;
        else if (mulTrigger)
            number *= equalValue;
        else if(divTrigger)
            number /= equalValue;
    }
    ui->answer->setText(QString::number(number, 'g', 16));
    checkForMultEqualButton = true;
    checkForMultMathButton = false;
    qDebug() << "Number: " << number << " ansValue: " << equalValue;
}

void MainWindow::Clear()
{
    divTrigger = false;
    mulTrigger = false;
    subTrigger = false;
    addTrigger = false;
    checkForEqualButton = false;
    checkForMultEqualButton = false;
    checkForMultMathButton = false;
    number = 0.0;
    ui->answer->setText(QString::number(number, 'g', 16));
    qDebug() << "Number: " << number;
}

void MainWindow::on_button_dot_clicked()
{
    if(!ui->answer->text().contains('.'))
        ui->answer->setText(ui->answer->text() + ".");
    qDebug() << "Number: " << number;
    checkForMultEqualButton = false;
}

void MainWindow::on_button_invert_clicked()
{
    number = (ui->answer->text()).toDouble();
    number = 1 / number;
    ui->answer->setText(QString::number(number, 'g', 16));
    qDebug() << "Number: " << number;
    checkForMultEqualButton = checkForMultMathButton =  false;
}

void MainWindow::on_button_lg_clicked()
{
    number = (ui->answer->text()).toDouble();
    number = log10(number);
    ui->answer->setText(QString::number(number, 'g', 16));
    qDebug() << "Number: " << number;
    checkForMultEqualButton = checkForMultMathButton =  false;
}

void MainWindow::on_button_cos_clicked()
{
    number = (ui->answer->text()).toDouble();
    number = cos(number);
    ui->answer->setText(QString::number(number, 'g', 16));
    qDebug() << "Number: " << number;
    checkForMultEqualButton = checkForMultMathButton =  false;
}

void MainWindow::on_button_sin_clicked()
{
    number = (ui->answer->text()).toDouble();
    number = sin(number);
    ui->answer->setText(QString::number(number, 'g', 16));
    qDebug() << "Number: " << number;
    checkForMultEqualButton = checkForMultMathButton =  false;
}

void MainWindow::on_button_power_clicked()
{
    number = (ui->answer->text()).toDouble();
    number = pow(number, 2);
    ui->answer->setText(QString::number(number, 'g', 16));
    qDebug() << "Number: " << number;
    checkForMultEqualButton = checkForMultMathButton =  false;
}

void MainWindow::on_button_sqrt_clicked()
{
    number = (ui->answer->text()).toDouble();
    number = sqrt(number);
    ui->answer->setText(QString::number(number, 'g', 16));
    qDebug() << "Number: " << number;
    checkForMultEqualButton = checkForMultMathButton =  false;
}

void MainWindow::on_button_rev_clicked()
{
    number = (ui->answer->text()).toDouble();
    number = -number;
    ui->answer->setText(QString::number(number, 'g', 16));
    qDebug() << "Number: " << number;
    checkForMultEqualButton = checkForMultMathButton =  false;
}

void MainWindow::on_button_MStore_clicked()
{
    QString memVal = ui->answer->text();
    memValue = memVal.toDouble();
    memTempValue = memValue;
}

void MainWindow::on_button_Mclear_clicked()
{
    memValue = 0.0;
    memTempValue = 0.0;
    ui->answer->setText(QString::number(memValue, 'g', 16));
}

void MainWindow::on_button_Mrecall_clicked()
{
    memValue = memTempValue;
    ui->answer->setText(QString::number(memValue, 'g', 16));
}

void MainWindow::on_button_Madd_clicked()
{
    memTempValue += memValue;
}

void MainWindow::on_button_Msub_clicked()
{
    memTempValue -= memValue;
}

void MainWindow::on_button_delete_clicked()
{
    QString ansValue = ui->answer->text();
    if(ansValue.length() > 1)
    {
        ansValue.remove(ansValue.length() - 1, ansValue.length());
        ui->answer->setText(ansValue);
    }
    else
    {
        ui->answer->setText("0");
    }
    checkForEqualButton = false;
}
