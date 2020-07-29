#ifndef SERIALRECV_H
#define SERIALRECV_H

#include <QWidget>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QDebug>

class SerialRecv : public QWidget
{
    Q_OBJECT
public:
    QSerialPort *com;
    char status = 0;
    char pkgDataCnt;
    char pkgDataHead;
    unsigned char pkgData[11];
    char pkgDataCrc;
    int ecg1,ecg2,ecg3,spo,ibp;

    explicit SerialRecv(QWidget *parent = nullptr);
    int serialInit();
    void serialRx();
    void rxDataHandle(unsigned char data);

signals:
    void RecvData(int data);
};

#endif // SERIALRECV_H
