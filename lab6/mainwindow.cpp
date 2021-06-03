#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "passport"});
    ui->tableWidget->setColumnWidth(0,250);
    ui->tableWidget->setColumnWidth(1,150);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(check)
    {
        tree.clear();
        tree = Tree();
        model->clear();
    }

    for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        tree.push(ui->tableWidget->item(i,1)->text().toInt(),ui->tableWidget->item(i,0)->text(), &tree.root);

    model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"Name", "passport"});

    ui->treeView->setModel(model);
    ui->treeView->setColumnWidth(0, 250);
    ui->treeView->setColumnWidth(1, 150);

    parentItem = model->invisibleRootItem();
    PrintTree(parentItem, tree.root);
    ui->treeView->setModel(model);
    check = true;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->tableWidget->rowCount() == 0)
        QMessageBox::information(0,"error", "table is empty");
    else
         ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(check)
    {
        tree.clear();
        tree = Tree();
        model->clear();
    }
    QApplication::exit(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->clear();
    tree.print();

    ui->textEdit->append("Pre order:");
    for(int i = 0; i < tree.answer.size()/3; i++)
        ui->textEdit->append(tree.answer[i]->data + " - " + QString::number(tree.answer[i]->key));

    ui->textEdit->append("\nIn order:");
    for(int i = tree.answer.size() / 3; i < 2 * tree.answer.size()/3; i++)
        ui->textEdit->append(tree.answer[i]->data + " - " + QString::number(tree.answer[i]->key));

    ui->textEdit->append("\nPost order:");
    for(int i = 2 * tree.answer.size() / 3; i < tree.answer.size(); i++)
        ui->textEdit->append(tree.answer[i]->data + " - " + QString::number(tree.answer[i]->key));

    tree.answer.clear();
}

void MainWindow::on_pushButton_8_clicked()
{
    QString find = tree.find(ui->lineEdit_2->text().toInt(), tree.root);
    if(find == "-1")
        QMessageBox::information(0, "Not found", "This key contains nothing");
    else
        QMessageBox::information(0, "Found", "This key contains: " + find);
    ui->lineEdit_2->clear();

}

void MainWindow::on_pushButton_7_clicked()
{
    if(check)
    {
        int remove = ui->lineEdit_2->text().toInt();
        QVector<Node*> aboba = tree.removeSmth(remove);
        tree.clear();
        tree = Tree();
        model->clear();
        for(int i = 0; i < aboba.size(); i++)
            tree.push(aboba[i]->key, aboba[i]->data, &tree.root);

        model = new QStandardItemModel();
        model->setHorizontalHeaderLabels({"Name", "passport"});

        ui->treeView->setModel(model);
        ui->treeView->setColumnWidth(0, 250);
        ui->treeView->setColumnWidth(1, 150);

        parentItem = model->invisibleRootItem();
        PrintTree(parentItem, tree.root);
        ui->treeView->setModel(model);

        ui->lineEdit_2->clear();
        tree.answer.clear();
        aboba.clear();
        return;
    }
    QMessageBox::information(0,"error", "Enter data firstly");

}

void MainWindow::on_pushButton_6_clicked()
{
    Node* task = tree.task();
    if(!task)
        QMessageBox::warning(0,"Error","There is an errrrrrrrrror");
    else
        QMessageBox::information(0,"Found","The answer is: " + task->data + ", pass: " + QString::number(task->key));
}

void MainWindow::on_pushButton_9_clicked()
{
    int count = tree.task('E');
    if(count == 0)
        QMessageBox::information(0, "Answer", "There are no words that begin with this letter");
    else
        QMessageBox::information(0, "Answer", "There is/are " + QString::number(count) + " word(s) that begin(s) with this letter");
}
