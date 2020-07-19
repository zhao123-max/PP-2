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
    // 防止隐式转换
    explicit QWidgetSerialTx(const QString &portName, QWidget *parent = nullptr);
    explicit QWidgetSerialTx(int cycle, const QString &portName, QWidget *parent = nullptr);

    void sendEcgPkg();
    int serialInit();
    unsigned int getData();
private:
    QString portName;
signals:

};

#endif // QWIDGETSERIALTX_H
