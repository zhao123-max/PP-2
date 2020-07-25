#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->mTcpServer = new QTcpServer(this);
    this->mTcpServer->setMaxPendingConnections(1); // 最大连接数
    connect(this->mTcpServer, SIGNAL(newConnection()), this, SLOT(tcpNewConnection()));

    this->mTcpServer->listen(QHostAddress::Any, 1234);

    this->ui->label->setText("Disconnected!");   // Server启动时无连接


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tcpNewConnection()
{
    this->mSocket = mTcpServer->nextPendingConnection();
    if (this->mSocket)
    {
        connect(this->mSocket, SIGNAL(readyRead()), this, SLOT(tcpReadyRead()));
        connect(this->mSocket, SIGNAL(disconnected()), this, SLOT(tcpDisconnect()));
        this->ui->label->setText("Connected!");   // Server已连接
    }
}

void MainWindow::tcpReadyRead()
{
    this->ui->textEdit->append(this->mSocket->readAll());
}

void MainWindow::tcpDisconnect()
{
    this->mSocket->deleteLater();
    mSocket = 0;
    this->ui->label->setText("Disconnected!");   // Server启动时无连接
}


void MainWindow::on_pushButton_clicked()
{
    this->mSocket->write(this->ui->lineEdit->text().toLatin1());

}
