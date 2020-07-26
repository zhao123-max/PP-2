#include "qwidgetdrawforserialrx.h"

QWidgetDrawForSerialRx::
QWidgetDrawForSerialRx(QWidget *parent)
    : QWidgetDraw(parent)
{

}

void QWidgetDrawForSerialRx::
initReceiver(const QString &pName, int maxD)
{
    this->rece = new QWidgetSerialRx(pName);
    this->maxData = maxD;
    connect(this->rece, &QWidgetSerialRx::rxDataSignal, this, &QWidgetDrawForSerialRx::refreshFromData);
}

void QWidgetDrawForSerialRx::
refreshFromData(char pID, int data)
{
    int height = this->height();
    data = height - data*height/this->maxData;

    QPainter *painter = new QPainter();
    painter->begin(&this->map);
    QPen *pen = new QPen();
    pen->setWidth(2);
    pen->setColor(Qt::green);
    painter->setPen(*pen);


    this->drawWave(painter, data);
    painter->end();
    // update 触发 paintEvent 事件
    this->update();
}
