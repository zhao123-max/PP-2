#ifndef QWIDGETSERIALRX_H
#define QWIDGETSERIALRX_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>

class QWidgetSerialRx: public QWidget
{
    Q_OBJECT
public:
    QSerialPort *com;
    char status = 0;
    unsigned char pkgDataCnt;
    unsigned char pkgDataCrc;
    unsigned char pkgData[7];
    unsigned char pkgDataHead;
    int ecg1, ecg2, ecg3;

    explicit QWidgetSerialRx(QWidget *parent = nullptr);
    int serialInit();
    void serialRx();
    void rxDataHandle(unsigned char data);
};

#endif // QWIDGETSERIALRX_H
