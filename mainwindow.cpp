#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialtrans.h"
#include "serialrecv.h"
#include "mysocket.h"
#include <QDebug>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mCount = 0;
    mTcpServer = new QTcpServer(this);
    mTcpServer->setMaxPendingConnections(2);//设置最大链接数
    connect(mTcpServer,SIGNAL(newConnection()),this,SLOT(tcpNewConnection()));

    mTcpServer->listen(QHostAddress::Any,1234);
    ui->label->setText("Disconnected!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tcpNewConnection()
{
    mSocket = mTcpServer->nextPendingConnection();
    if(mSocket)
    {
        //connect(mSocket,SIGNAL(connected()),serialTx,SLOT(timestart()));

        ui->label->setText("Connected!");

        MySocket *mySocket = new MySocket();
        mySocket->setSocketDescriptor(mSocket->socketDescriptor());

        connect(serialRx,SIGNAL(RecvData(int)),mySocket,SLOT(transdata(int)));

        QThread *thread = new QThread();
        mySocket->moveToThread(thread);//把mySocket放到thread中运行
        thread->start();

        connect(mySocket,SIGNAL(disconnected()),this,SLOT(tcpDisconnect()));

        if(mCount == 0)
        {
            connect(mySocket,SIGNAL(signalRecDa(QByteArray)),this,SLOT(transdata1(QByteArray)));
            mCount = 1;
        }else
        {
            connect(mySocket,SIGNAL(signalRecDa(QByteArray)),this,SLOT(transdata2(QByteArray)));
            mCount = 0;
        }

    }
}

void MainWindow::tcpDisconnect()
{
    disconnect(serialRx,SIGNAL(RecvData(int)),0,0);
    mSocket->deleteLater();
    mSocket = 0;
    ui->label->setText("Disconnected!");
}

void MainWindow::transdata1(QByteArray data)
{
    //qDebug()<<"ecg: "<<ecg;
    ui->textEdit->append(data);
}

void MainWindow::transdata2(QByteArray data)
{
    //qDebug()<<"ecg: "<<ecg;
    ui->textEdit_2->append(data);
}

