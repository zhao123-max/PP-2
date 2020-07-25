#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QTcpServer *mTcpServer;
    QTcpSocket *mSocket;
private:
    Ui::MainWindow *ui;
private slots:
    void tcpNewConnection();
    void tcpReadyRead();
    void tcpDisconnect();
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
