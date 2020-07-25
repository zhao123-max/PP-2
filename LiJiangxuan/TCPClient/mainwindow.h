#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTcpSocket *mySocket;
    QTimer *reConnectTimer;
    QTimer *sendTimer;


private slots:
    void tcpReadyRead();
    void on_pushButton_clicked();
    void reConnect();   // 重新连接 Server

    void sendData();
    void tcpConnect();
};
#endif // MAINWINDOW_H
