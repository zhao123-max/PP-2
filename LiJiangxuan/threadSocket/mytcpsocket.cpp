#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QTcpSocket *parent) : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readData()));
}

void MyTcpSocket::readData()
{
    QByteArray ba = this->readAll();
    emit signalRecData(ba);
    qDebug()<<"read data: receive data = "<<ba<<" current thread = "<<QThread::currentThread();
}
