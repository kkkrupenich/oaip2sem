#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QVector>


using namespace std;

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

int MainWindow::getPrior(char z)
{
    if (z == '+' || z == '-') return 1;
    if (z == '/' || z == '*') return 2;
    if (z == '^') return 3;
    return -100;
}


void MainWindow::on_pushButton_clicked()
{
    QVector <QString> answer;
    QString expression = ui->lineEdit->text();
    opers.push('!');
    QString newStrings;
    newStrings += '1';
    for (int i = 0; i< (int) expression.length(); i++)
    {
        if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.')
        {
            QString temp;
            while (i < expression.length() && ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.'))
            {
                temp += expression[i];
                i++;
            }
            answer.push_back(temp);
            answer.push_back(" , ");
            if (i == expression.length()) break;
        }
        if (expression[i] == '(') opers.push(expression[i].toLatin1());
        else if (expression[i] == ')')
        {
            while (opers.tail->operation != '(')
            {
                newStrings[0] = opers.pop();
                answer.push_back(newStrings);
                answer.push_back(" , ");
            }
            opers.pop();
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
        {
            while (opers.tail->operation != '!' && getPrior(opers.tail->operation) >= getPrior(expression[i].toLatin1()))
            {
                newStrings[0] = opers.pop();
                answer.push_back(newStrings);
                answer.push_back(" , ");
            }
            opers.push(expression[i].toLatin1());
        }
    }

    while (opers.tail->operation != '!')
    {
        newStrings[0] = opers.pop();
        answer.push_back(newStrings);
        answer.push_back(" , ");
    }

    QString temp;
    for (int i=0; i<answer.size(); i++) temp += answer[i];
    ui->answer->setText(temp);

    numbers.push(-1);
    for (int i = 0; i < (int)answer.size(); i++)
    {
        if (answer[i] == " , ") continue;
        if (answer[i].toDouble())
        {
            numbers.push(answer[i].toDouble());
        }
        else
        {
            double first = numbers.pop(), second = numbers.pop();
            if (answer[i] == '+')
            {
                numbers.push(second + first);
            }
            if (answer[i] == '-')
            {
                numbers.push(second - first);
            }
            if (answer[i] == '*')
            {
                numbers.push(second * first);
            }
            if (answer[i] == '/')
            {
                numbers.push(second / first);
            }
            if (answer[i] == '^')
            {
                numbers.push(pow(second,first));
            }
        }
    }
    ui->finalResult->setText(QString::number(numbers.pop()));
}
