#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H


#include <QTcpSocket>
#include <QDebug>
#include <QThread>
#include <QByteArray>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QTcpSocket *parent = nullptr);

private slots:
    void readData();

signals:
    void signalRecData(QByteArray ba);

};

#endif // MYTCPSOCKET_H
