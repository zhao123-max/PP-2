#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "qwidgetdraw.h"

#include "data.h"
#include "wavedata.h"
#include "qwidgetserialtx.h"
#include "qwidgetserialrx.h"
#include "qwidgetserialtxecg.h"
#include "qwidgetserialtxibp2.h"
#include "qwidgetserialtxspo2.h"
#include "qwidgetdrawforserialrx.h"

void layoutdemo0(void);
void layoutdemo1(void);

void homework(void);
void testSerialPort(void);
void testTxRxDraw();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    homework();
//    testSerialPort();
    testTxRxDraw();
    return a.exec();
}

void homework(void)
{
    QWidget *winMain = new QWidget();

    int lenOfECG = sizeof(ecgWave)/sizeof(int);
    int maxECG = 4096;
    int lenOfSin = sizeof(sinWave)/sizeof(int);
    int maxSin = 3000;
    QWidgetDraw *drawWidget_a = new QWidgetDraw(10, Ecg2_500DemoData, 500, maxECG);
    QWidgetDraw *drawWidget_b = new QWidgetDraw(20, Ibp2_DemoData, 125, 120);
    QWidgetDraw *drawWidget_c = new QWidgetDraw(40, Spo2_DemoData, 248, 100);

    drawWidget_a->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    drawWidget_b->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    drawWidget_c->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    drawWidget_a->setLabelText("ECG     I");
    drawWidget_b->setLabelText("ECG     II");
    drawWidget_c->setLabelText("ECG     III");

    // 创建垂直箱式 layout
    QVBoxLayout *qvbl = new QVBoxLayout();
    qvbl->addWidget(drawWidget_a);
    qvbl->addWidget(drawWidget_b);
    qvbl->addWidget(drawWidget_c);


    /*********************************************************/
    // 添加按钮和标签
    QLabel *widgetHr = new QLabel();
    QLabel *widgetNibp = new QLabel();
    widgetHr->setText("HR");
    widgetNibp->setText("NiBP");

    QPushButton *btnUp = new QPushButton("UP");
    QPushButton *btnDowm = new QPushButton("DOWN");

    btnUp->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    btnDowm->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);


    QVBoxLayout *lytLabelBtn = new QVBoxLayout();
    lytLabelBtn->addWidget(widgetHr);
    lytLabelBtn->addWidget(widgetNibp);
    lytLabelBtn->addWidget(btnUp);
    lytLabelBtn->addWidget(btnDowm);

    QHBoxLayout *lytMain = new QHBoxLayout();
    lytMain->addLayout(qvbl);
    lytMain->addLayout(lytLabelBtn);
    // 配置拉伸因子
    lytMain->setStretchFactor(qvbl, 2);
    lytMain->setStretchFactor(lytLabelBtn, 1);

    winMain->setWindowTitle("八仙过海队");
    winMain->resize(1000, 600);
    winMain->setLayout(lytMain);
    winMain->show();
}

void testTxRxDraw()
{
    QWidget *mainWin = new QWidget();
    // 发送
    QWidgetSerialTxEcg *serialTx = new QWidgetSerialTxEcg(2, "COM1", Ecg2_500DemoData, 500, mainWin);
    QWidgetSerialTxIBP2 *serialTx2 = new QWidgetSerialTxIBP2(8, "COM3", Ibp2_DemoData, 125, mainWin);
    QWidgetSerialTxSPO2 *serialTx3 = new QWidgetSerialTxSPO2(4, "COM5", Spo2_DemoData, 248, mainWin);

    // 接收并画图
    QWidgetDrawForSerialRx *drawEcg = new QWidgetDrawForSerialRx();
    QWidgetDrawForSerialRx *drawIBP = new QWidgetDrawForSerialRx();
    QWidgetDrawForSerialRx *drawSPO2 = new QWidgetDrawForSerialRx();

    // 启动
    drawEcg->initReceiver("COM2", 4096);
    drawIBP->initReceiver("COM4", 80);
    drawSPO2->initReceiver("COM6", 100);

    // 位置摆放
    drawEcg->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    drawSPO2->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    drawIBP->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    drawEcg->setLabelText("ECG");
    drawSPO2->setLabelText("SPO2");
    drawIBP->setLabelText("IBP2");

    // 创建垂直箱式 layout
    QVBoxLayout *qvbl = new QVBoxLayout();
    qvbl->addWidget(drawEcg);
    qvbl->addWidget(drawSPO2);
    qvbl->addWidget(drawIBP);

    /*********************************************************/
    // 添加按钮和标签
    QLabel *widgetHr = new QLabel();
    QLabel *widgetNibp = new QLabel();
    widgetHr->setText("HR");
    widgetNibp->setText("NiBP");

    QPushButton *btnUp = new QPushButton("UP");
    QPushButton *btnDowm = new QPushButton("DOWN");

    btnUp->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    btnDowm->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);


    QVBoxLayout *lytLabelBtn = new QVBoxLayout();
    lytLabelBtn->addWidget(widgetHr);
    lytLabelBtn->addWidget(widgetNibp);
    lytLabelBtn->addWidget(btnUp);
    lytLabelBtn->addWidget(btnDowm);

    QHBoxLayout *lytMain = new QHBoxLayout();
    lytMain->addLayout(qvbl);
    lytMain->addLayout(lytLabelBtn);
    // 配置拉伸因子
    lytMain->setStretchFactor(qvbl, 2);
    lytMain->setStretchFactor(lytLabelBtn, 1);

    mainWin->setWindowTitle("八仙过海队");
    mainWin->resize(1000, 600);
    mainWin->setLayout(lytMain);
    mainWin->show();
}

void testSerialPort(void)
{
    QWidget *mainWin = new QWidget();
    // int *source, Len
    QWidgetSerialTxEcg *serialTx = new QWidgetSerialTxEcg(2, "COM1", Ecg2_500DemoData, 500, mainWin);
    QWidgetSerialTxIBP2 *serialTx2 = new QWidgetSerialTxIBP2(8, "COM3", Ibp2_DemoData, 125, mainWin);
    QWidgetSerialTxSPO2 *serialTx3 = new QWidgetSerialTxSPO2(4, "COM5", Spo2_DemoData, 248, mainWin);
    QWidgetSerialRx *serialRx = new QWidgetSerialRx("COM2", mainWin);
    QWidgetSerialRx *serialRx2 = new QWidgetSerialRx("COM4", mainWin);
    QWidgetSerialRx *serialRx3 = new QWidgetSerialRx("COM6", mainWin);

    mainWin->resize(300, 300);
    mainWin->show();
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

