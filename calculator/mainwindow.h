#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool divTrigger = false;
    bool mulTrigger = false;
    bool subTrigger = false;
    bool addTrigger = false;
    bool checkForEqualButton = false;
    bool checkForMultEqualButton = false;
    bool checkForMultMathButton = false;
    double number = 0.0;
    double equalValue = 0.0;
    double memValue = 0.0;
    double memTempValue = 0.0;

private slots:
    void NumPressed();
    void on_button_dot_clicked();
    void MathButtonPressed();
    void EqualButtonPressed();
    void Clear();
    void on_button_invert_clicked();
    void on_button_lg_clicked();
    void on_button_cos_clicked();
    void on_button_sin_clicked();
    void on_button_power_clicked();
    void on_button_sqrt_clicked();
    void on_button_rev_clicked();
    void on_button_MStore_clicked();
    void on_button_Mclear_clicked();
    void on_button_Mrecall_clicked();
    void on_button_Madd_clicked();
    void on_button_Msub_clicked();
    void on_button_delete_clicked();
};
#endif // MAINWINDOW_H
