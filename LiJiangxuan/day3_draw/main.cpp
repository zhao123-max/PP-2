#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPainter>
#include "qwidgetdraw.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidgetDraw *winMain = new QWidgetDraw();
    winMain->show();
    return a.exec();
}

