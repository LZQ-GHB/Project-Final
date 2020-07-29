#include "mysocket.h"
#include <QDebug>
#include <QThread>
#include <QTimer>

MySocket::MySocket(QObject *parent) : QTcpSocket(parent)
{
    qDebug()<<"curr thread = "<<QThread::currentThread();
}

void MySocket::transdata(int data)
{
    //qDebug()<<"ecg: "<<ecg;
    QString da = QString::number(data);
    emit signalRecDa(da.toLatin1());
    this->write(da.toLatin1());
    qDebug()<<"curr thread = "<<QThread::currentThread();
}
