#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->mySocket = new QTcpSocket(this);
    this->mySocket->connectToHost(QHostAddress::LocalHost, 1234);

    // 设定 Client 定时尝试连接 Server
    this->reConnectTimer = new QTimer(this);
    this->reConnectTimer->start(2000);       // 500ms连接一次
    connect(this->reConnectTimer, SIGNAL(timeout()), this, SLOT(reConnect()));
    connect(this->mySocket, SIGNAL(readyRead()), this, SLOT(tcpReadyRead()));
    connect(this->mySocket, SIGNAL(connected()), this->reConnectTimer, SLOT(stop()));
/*
 *
 * 服务器先断开 如何重新连接
 *
 */
    connect(this->mySocket, SIGNAL(disconnected()), this->reConnectTimer, SLOT(start()));
    connect(this->mySocket, SIGNAL(connected()), this, SLOT(tcpConnect()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendData()
{
    if (this->mySocket->state() == QAbstractSocket::UnconnectedState)
        return;
    this->mySocket->write("11111"); // 循环发送 11111 间隔时间为 1 s
}

void MainWindow::tcpConnect()
{
    this->sendTimer = new QTimer(this);
    this->sendTimer->start(1000);
    connect(this->sendTimer, SIGNAL(timeout()), this, SLOT(sendData()));
    connect(this->mySocket, SIGNAL(disconnected()), this->sendTimer, SLOT(deleteLater()));
}

void MainWindow::tcpReadyRead()
{
    this->ui->textEdit->append(this->mySocket->readAll());
}


void MainWindow::on_pushButton_clicked()
{
    if (this->mySocket->state() == QAbstractSocket::UnconnectedState)
        return;
    this->mySocket->write(this->ui->lineEdit->text().toLatin1());
}

void MainWindow::reConnect()
{
    if (this->mySocket->state() == QAbstractSocket::UnconnectedState)
        this->mySocket->connectToHost(QHostAddress::LocalHost, 1234);
}


