#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{ 
    try
    {
        checkInt(ui->lineSalary->text());
        checkDouble(ui->lineMarks->text());
        Student * student = new Student;
        student->firstname = ui->lineFirstName->text();
        student->lastname = ui->lineLastName->text();
        student->fathersname = ui->lineFathersName->text();
        student->group = ui->lineGroup->text();
        student->marks = ui->lineMarks->text().toDouble();
        student->salary = ui->lineSalary->text().toInt();
        listStudents->push(student);
        QMessageBox::information(0, "Успешно добавлен", "Студент " + ui->lineLastName->text() + " успешно добавлен!");
    }
    catch (Errors &exception)
    {
        QMessageBox::critical(0, "ERROR", "An error occured: \n" + QString(exception.what()));
    }
    catch (exception &exception)
    {
        QMessageBox::critical(0, "ERROR", "An error occured: \n" + QString(exception.what()));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->setText(listStudents->getAll());
    QMessageBox::information(0, "Весь список", "Полный список студентов успешно загружен");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->setText(listStudents->getByName(ui->lineFindByName->text()));
    if(ui->textBrowser->toPlainText().isEmpty())
    {
        QMessageBox::information(0, "", "По данной фамилии ничего не найдено!");
    }
    else
    {
        QMessageBox::information(0,"Успешно", "Студент " + ui->lineFindByName->text() + " успешно найден");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->setText(listStudents->getMoreThanSalary(ui->lineGetMoreThanSalary->text().toInt()));
    if(ui->textBrowser->toPlainText().isEmpty())
    {
        QMessageBox::information(0, "", "По данному доходу ничего не найдено!");
    }
    else
    {
        QMessageBox::information(0,"Успешно", "Студент(ы) успешно найден(ы)");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->setText(listStudents->getLowMarks(ui->lineGetByMarks->text().toDouble()));
    if(ui->textBrowser->toPlainText().isEmpty())
    {
        QMessageBox::information(0, "", "По этим данным ничего не найдено!");
    }
    else
    {
        QMessageBox::information(0,"Успешно", "Студент(ы) успешно найден(ы)");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    listStudents->delByIndex(ui->lineDelete->text().toInt());
    ui->textBrowser->setText(listStudents->getAll());
}
