#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(int maxConnection, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mCount = 0;

    this->mTcpServer = new QTcpServer(this);
    this->mTcpServer->setMaxPendingConnections(maxConnection); // 最大连接数
    connect(this->mTcpServer, SIGNAL(newConnection()), this, SLOT(tcpNewConnection()));

    this->mTcpServer->listen(QHostAddress::Any, 1234);

    qDebug()<<"main thread = "<<QThread::currentThread();   // 打印当前线程地址
//    this->ui->label->setText("Disconnected!");   // Server启动时无连接


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tcpNewConnection()
{
    this->mSocket = this->mTcpServer->nextPendingConnection();
    // 这个来源有问题
//    this->mSocket =
    if (this->mSocket)
    {
        MyTcpSocket *mySocket = new MyTcpSocket();
        // 传递 socket 描述符
        mySocket->setSocketDescriptor(this->mSocket->socketDescriptor());
        connect(mySocket, SIGNAL(signalRecData(QByteArray)), this, SLOT(slotReceiveData(QByteArray)));

        QThread *t = new QThread();
        mySocket->moveToThread(t); // 把 mySocket 放入 t 中运行
        t->start();

        if (this->mCount == 0)
            connect(mySocket, SIGNAL(signalRecData(QByteArray)), this, SLOT(slotReceiveData_1(QByteArray)));
        else
            connect(mySocket, SIGNAL(signalRecData(QByteArray)), this, SLOT(slotReceiveData_2(QByteArray)));

        // 这么写是有问题的
        this->mCount++;

//        connect(this->mSocket, SIGNAL(readyRead()), this, SLOT(tcpReadyRead()));
//        connect(this->mSocket, SIGNAL(disconnected()), this, SLOT(tcpDisconnect()));
//        this->ui->label->setText("Connected!");   // Server已连接
    }
}

void MainWindow::tcpReadyRead()
{
    this->ui->textEdit_1->append(this->mSocket->readAll());
}

void MainWindow::tcpDisconnect()
{
    this->mSocket->deleteLater();
    mSocket = 0;
    //    this->ui->label->setText("Disconnected!");   // Server启动时无连接
}

void MainWindow::slotReceiveData_2(QByteArray ba)
{
    this->ui->textEdit_2->append(ba);
}

void MainWindow::slotReceiveData_1(QByteArray ba)
{
    this->ui->textEdit_1->append(ba);
}

