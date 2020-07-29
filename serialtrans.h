#ifndef SERIALTRANS_H
#define SERIALTRANS_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QTimer>

class SerialTrans : public QWidget
{
    Q_OBJECT
public:
    QSerialPort *com;
    QTimer *timer;
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    int ecg1,ecg2,ecg3;

    explicit SerialTrans(QWidget *parent = nullptr);

    int serialInit(void);
    void sendEcgPkg();
    unsigned int getEcg2Data();
    char getSpo2Data();
    char getIbp2Data();

public slots:
    void timestop();
    void timestart();

signals:

};

#endif // SERIALTRANS_H
