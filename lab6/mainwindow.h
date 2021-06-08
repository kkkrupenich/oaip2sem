#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Tree tree;
    bool check = false;
    QStandardItemModel* model;
    QStandardItem* parentItem;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    void PrintTree(QStandardItem *copy, Node* node)
    {
        if(node != nullptr)
        {
            QStandardItem* item = new QStandardItem(QString("%0:" + QString::number(node->key)).arg(node->data));
            copy->appendRow(item);
            copy = item;
            PrintTree(copy, node->left);
            PrintTree(copy, node->right);
        }
    }
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
