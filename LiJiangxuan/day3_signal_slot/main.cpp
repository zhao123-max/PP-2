
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QDateTime>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <QDateTime>
#include "qlabelclock.h"

#if 0
class QLabelClock: public QLabel
{
public:
    QTimer *timer;
    int toggle = 1;
    QLabelClock(QWidget *parent): QLabel(parent)
    {
        this->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz"));
        this->setStyleSheet("font-size: 25px");

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &QLabelClock::refresh);
        timer->start(1);
    }
    void refresh()
    {
        if (toggle == 1)
            this->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz"));
    }

    // 事件机制
    void mousePressEvent(QMouseEvent *ev) override
    {
        if (ev->buttons() == Qt::LeftButton)
        {
            if (toggle == 1)
                toggle = 0;
            else
                toggle = 1;
        }
    }
};
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建界面
    QWidget *winMain = new QWidget();
    // 修改界面标题
    winMain->setWindowTitle("温度");

    // 创建标签 显示温度标记
    QLabel *tempText = new QLabel();
    tempText->setText("T-");
    // 绑定到 mainWin
    tempText->setParent(winMain);
    // 设置显示位置
    tempText->setGeometry(0, 50, 50, 50);
//    tempText->setStyleSheet("font-size: 80px");

    // 创建标签 显示温度值
    QLabel *tempData = new QLabel(winMain);
    tempData->setText("36.5");
    // 设置样式表
    tempData->setStyleSheet("font-size: 60px");
    // 设置显示位置
    tempData->setGeometry(50, 0, 200, 150);
    tempData->show();

    // 创建标签 显示日期
//    QLabel *tempDate = new QLabel(winMain);
//    QString dateTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
//    tempDate->setText(dateTime);
//    tempDate->setStyleSheet("font-size: 30px");
//    tempDate->setGeometry(0, 100, 300, 50);
//    tempDate->show();

    QLabelClock *clock = new QLabelClock(winMain);
    clock->setGeometry(0, 100, 300, 50);

    winMain->setStyleSheet("background-color: balck; color: pink; font-size: 40px");
    winMain->resize(300, 150);
    winMain->show();

    qDebug()<<"Time: "<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");


    return a.exec();
}
