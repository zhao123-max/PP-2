#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPainter>
#include "qwidgetdraw.h"
#include "qlabeltext.h"
#include "qlabelclock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidgetDraw *winMain = new QWidgetDraw();

    QLabelText *personalInfo = new QLabelText(winMain, "姓名：李江炫\n学号：1170500420");
    personalInfo->setGeometry(100, 50, 200, 50);

    QLabelText *teamInfo = new QLabelText(winMain, "编号：5\n队名：八仙过海队");
    teamInfo->setGeometry(100, 0, 200, 50);

    QLabelClock *clock = new QLabelClock(winMain);
    clock->setGeometry(0, 100, 300, 50);

    winMain->setWindowTitle("八仙过海队");

    winMain->show();
    return a.exec();
}

