#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "qwidgetdraw.h"

void layoutdemo0(void);
void layoutdemo1(void);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidgetDraw *drawWidget = new QWidgetDraw();
    drawWidget->setWindowTitle("Help");
    drawWidget->resize(600, 150);

    drawWidget->show();
    return a.exec();
}


void layoutdemo0(void)
{
    QWidget *winMain = new QWidget();

    winMain->resize(800, 480);

    // 创建按钮
    QPushButton *btnReplay = new QPushButton("Replay");
    QPushButton *btnLogin = new QPushButton("Login");
    QPushButton *btnConfig = new QPushButton("Congfig");

    // 按钮缩放策略
    btnReplay->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    btnLogin->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    btnConfig->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    // 创建水平箱式Layout
    QHBoxLayout *hblayout = new QHBoxLayout();
    hblayout->addWidget(btnReplay);
    hblayout->addWidget(btnLogin);
    hblayout->addWidget(btnConfig);

    // 拉伸因子
    hblayout->setStretchFactor(btnReplay, 2);
    hblayout->setStretchFactor(btnLogin, 2);
    hblayout->setStretchFactor(btnConfig, 2);

    // 插入拉伸因子
    hblayout->insertStretch(3, 1);
    hblayout->insertStretch(2, 1);
    hblayout->insertStretch(1, 1);
    hblayout->insertStretch(0, 1);

    // 创建垂直layout 配置并插入拉伸因子
    QVBoxLayout *vblayout = new QVBoxLayout();
    vblayout->addLayout(hblayout);
    vblayout->setStretchFactor(hblayout, 1);
    vblayout->insertStretch(1, 1);
    vblayout->insertStretch(0, 1);

    winMain->setLayout(vblayout);
    winMain->show();
}

void layoutdemo1(void)
{
    QWidget *winMain = new QWidget();

    winMain->resize(800, 480);

    // 创建水平箱式Layout
    QHBoxLayout *hblayout = new QHBoxLayout();
    hblayout->addWidget(new QPushButton("Replay"));
    hblayout->addWidget(new QPushButton("login"));
    hblayout->addWidget(new QPushButton("config"));

    // 创建垂直箱式layout
    QVBoxLayout *vblayout = new QVBoxLayout();
    vblayout->addWidget(new QPushButton("Replay"));
    vblayout->addWidget(new QPushButton("login"));
    vblayout->addWidget(new QPushButton("config"));

    // 加起来
    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addLayout(hblayout);
    layoutMain->addLayout(vblayout);

    winMain->setLayout(layoutMain);

    winMain->show();
}
