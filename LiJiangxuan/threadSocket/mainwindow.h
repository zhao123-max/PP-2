#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include "mytcpsocket.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int maxConnection, QWidget *parent = nullptr);
    ~MainWindow();


    QTcpServer *mTcpServer;
    QTcpSocket *mSocket;
private:
    Ui::MainWindow *ui;
    int mCount;

private slots:
    void tcpNewConnection();
    void tcpReadyRead();
    void tcpDisconnect();

    void slotReceiveData_1(QByteArray ba);

    void slotReceiveData_2(QByteArray ba);
};
#endif // MAINWINDOW_H
