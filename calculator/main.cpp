#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Icon/icon/cursed.png"));
    MainWindow w;
    w.show();
    w.setFixedSize(QSize(300, 420));
    return a.exec();
}
