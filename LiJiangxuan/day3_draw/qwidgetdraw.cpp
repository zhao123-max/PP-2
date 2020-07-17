#include "qwidgetdraw.h"
#include <QPainter>

QWidgetDraw::QWidgetDraw(QWidget *parent) : QWidget(parent)
{
}

void QWidgetDraw::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    painter->drawLine(0, 0, 100, 100);
    painter->drawRect(0, 0, 100, 100);
}
