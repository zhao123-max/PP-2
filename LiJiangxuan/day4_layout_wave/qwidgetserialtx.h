#ifndef QWIDGETSERIALTX_H
#define QWIDGETSERIALTX_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QTimer>

class QWidgetSerialTx : public QWidget
{
    Q_OBJECT
public:
    QSerialPort *com;
    QTimer *timer;
    int index = 0;

    explicit QWidgetSerialTx(QWidget *parent = nullptr);

    void sendEcgPkg();
    int serialInit();
    unsigned int getEcgData();
signals:

};

#endif // QWIDGETSERIALTX_H
