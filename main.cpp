#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include "serialtrans.h"
#include "serialrecv.h"

void showecg(int ecg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


