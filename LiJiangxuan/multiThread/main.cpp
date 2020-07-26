#include "mainwindow.h"

#include <QApplication>

#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
public:
    MyThread(const QString &name, QObject *parent = 0);

protected:
    void run();
private:
    QString threadName;
    int count;
};

MyThread::MyThread(const QString &name, QObject *parent): QThread(parent)
{
    this->threadName = name;
    this->count = 0;
}

void MyThread::run()
{
    while (1)
    {
        ++count;
        qDebug()<<"Thread name: "<<this->threadName<<" count = "<<QString::number(this->count);
        QThread::sleep(1);
    }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyThread *t1 = new MyThread("aaa");
    MyThread *t2 = new MyThread("bbb");
    t1->start();
    t2->start();

    return a.exec();
}







