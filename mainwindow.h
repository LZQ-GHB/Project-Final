#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include "serialtrans.h"
#include "serialrecv.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    SerialTrans *serialTx = new SerialTrans();
    SerialRecv *serialRx = new SerialRecv();


public slots:
    void transdata1(QByteArray data);
    void transdata2(QByteArray data);

    void tcpNewConnection();
    void tcpDisconnect();

private:
    Ui::MainWindow *ui;

    QTcpServer *mTcpServer;
    QTcpSocket *mSocket;
    int mCount;


};
#endif // MAINWINDOW_H
