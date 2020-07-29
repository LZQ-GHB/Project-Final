#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include <serialtrans.h>
#include <serialrecv.h>
#include <QTImer>

class MySocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MySocket(QObject *parent = nullptr);

private slots:
    void transdata(int data);


signals:
    void signalRecDa(QByteArray ba);

private:
    QTimer *timer = new QTimer;
};

#endif // MYSOCKET_H
