#include "qlabelclock.h"

QLabelClock::QLabelClock(QWidget *parent): QLabel(parent)
{
    this->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz"));
    this->setStyleSheet("font-size: 25px");

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &QLabelClock::refresh);
    timer->start(1);
}

void QLabelClock::refresh()
{
    if (toggle == 1)
        this->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz"));
}

void QLabelClock::mousePressEvent(QMouseEvent *ev)
{
    {
        if (ev->buttons() == Qt::LeftButton)
        {
            if (toggle == 1)
                toggle = 0;
            else
                toggle = 1;
        }
    }
}
