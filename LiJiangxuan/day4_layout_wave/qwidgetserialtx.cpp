#include "qwidgetserialtx.h"

QWidgetSerialTx::
QWidgetSerialTx(const QString &portName, QWidget *parent)
    : QWidget(parent), portName(portName)
{
    this->serialInit();
//    this->timer = new QTimer();
//    connect(this->timer, &QTimer::timeout, this, &QWidgetSerialTx::sendPkg);
//    this->timer->start(1000);

}

QWidgetSerialTx::
QWidgetSerialTx(int cycle, const QString &portName, int *source, int sLen, int pkgLen, QWidget *parent)
    : QWidget(parent), portName(portName), pkgLen(pkgLen), dataSource(source), sourceLen(sLen)
{
    this->serialInit();
//    this->timer = new QTimer();
//    connect(this->timer, &QTimer::timeout, this, &QWidgetSerialTx::sendPkg);
//    this->timer->start(cycle);

}

//void QWidgetSerialTx::sendPkg()
//{
////    this->com->write("hello");
//    char *dataBuf;
////    char dataBuf[this->pkgLen];
//    dataBuf = this->packageData();

//    this->com->write(dataBuf, this->pkgLen);
//    delete [] dataBuf;
//}

//char *QWidgetSerialTx::packageData()
//{
//    char *dataBuf = new char[this->pkgLen];
//    int ecgData[3] = {2048, 2048, 2048};
//    int i = 0;
//    char byteH,  byteL;

//    // 取心电数据/获取ADC数据
//    ecgData[0] = this->getData();

//    // 数据包格式： ID + 数据头 + 数据 + 校验
//    // 数据打包
//    dataBuf[0] = 0x08;  // ID
//    dataBuf[1] = 0x80;  // 数据头 最高位总为1
//    // 添加数据
//    for (; i < 3; i++)
//    {

//        byteH = (char)(ecgData[i] >> 8);
//        byteL = (char)(ecgData[i]&0xFF);
//        // 字节最高位存入数据头
//        dataBuf[1] = dataBuf[1] | ((byteH&0x80) >> (7 -i*2));
//        dataBuf[1] = dataBuf[1] | ((byteL&0x80) >> (7 - i*2 - 1));

//        dataBuf[2+i*2] = 0x80 | byteH;
//        dataBuf[2+i*2+1] = 0x80 | byteL;
//    }
//    dataBuf[8] = 0x80; // 暂时用不到
//    dataBuf[9] = 0x80; // 暂时不用
//    qDebug()<<"good";
//    return dataBuf;
//}

int QWidgetSerialTx::getData()
{
    this->index += 3;

    if (this->index >= this->sourceLen)
        this->index = 0;
    return  this->dataSource[this->index];
}



int QWidgetSerialTx::serialInit()
{
    // 查看设备信息
//    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
//    {
//        qDebug() << "Name : " << info.portName();
//        qDebug() << "Description : " << info.description();
//        qDebug() << "Manufacturer: " << info.manufacturer();
//        qDebug() << "Serial Number: " << info.serialNumber();
//    }

    // 创建串口对象
    this->com = new QSerialPort();
    // 打开串口
    this->com->setPortName(portName);
    if (!this->com->open(QIODevice::ReadWrite))
    {
        qDebug()<<"打开串口错误 "<<portName;
        return -1;
    }
    else
        qDebug()<<"打开串口 "<<portName;

    // 配置串口参数
    this->com->setBaudRate(QSerialPort::Baud115200);
    this->com->setDataBits(QSerialPort::Data8);
    this->com->setFlowControl(QSerialPort::NoFlowControl);
    this->com->setParity(QSerialPort::NoParity);
    this->com->setStopBits(QSerialPort::OneStop);

    return 0;
}
