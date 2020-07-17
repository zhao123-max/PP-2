#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "qwidgetdraw.h"
#include "qwidgetserialtx.h"
#include "qwidgetserialrx.h"

void layoutdemo0(void);
void layoutdemo1(void);
void homework(void);
void testSerialPort(void);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testSerialPort();

//    layoutdemo0();
    return a.exec();
}

void testSerialPort(void)
{
    QWidget *mainWin = new QWidget();
    QWidgetSerialTx *serialTx = new QWidgetSerialTx(mainWin);
    QWidgetSerialRx *serialRx = new QWidgetSerialRx(mainWin);

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

void homework(void)
{
    int ecgWave[] =
    {
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
        2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
        2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
        2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
        2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
        1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
        2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
        2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
        1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
        2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
        2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
        2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
        2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
        2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
        2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
        2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
        2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000
    };

    int sinWave[] =
    {
        2000, 2017, 2034, 2052, 2069, 2087, 2104, 2121, 2139, 2156, 2173, 2190, 2207, 2224, 2241,
        2258, 2275, 2292, 2309, 2325, 2342, 2358, 2374, 2390, 2406, 2422, 2438, 2453, 2469, 2484,
        2500, 2515, 2529, 2544, 2559, 2573, 2587, 2601, 2615, 2629, 2642, 2656, 2669, 2681, 2694,
        2707, 2719, 2731, 2743, 2754, 2766, 2777, 2788, 2798, 2809, 2819, 2829, 2838, 2848, 2857,
        2866, 2874, 2882, 2891, 2898, 2906, 2913, 2920, 2927, 2933, 2939, 2945, 2951, 2956, 2961,
        2965, 2970, 2974, 2978, 2981, 2984, 2987, 2990, 2992, 2994, 2996, 2997, 2998, 2999, 2999,
        3000, 2999, 2999, 2998, 2997, 2996, 2994, 2992, 2990, 2987, 2984, 2981, 2978, 2974, 2970,
        2965, 2961, 2956, 2951, 2945, 2939, 2933, 2927, 2920, 2913, 2906, 2898, 2891, 2882, 2874,
        2866, 2857, 2848, 2838, 2829, 2819, 2809, 2798, 2788, 2777, 2766, 2754, 2743, 2731, 2719,
        2707, 2694, 2681, 2669, 2656, 2642, 2629, 2615, 2601, 2587, 2573, 2559, 2544, 2529, 2515,
        2500, 2484, 2469, 2453, 2438, 2422, 2406, 2390, 2374, 2358, 2342, 2325, 2309, 2292, 2275,
        2258, 2241, 2224, 2207, 2190, 2173, 2156, 2139, 2121, 2104, 2087, 2069, 2052, 2034, 2017,
        2000, 1982, 1965, 1947, 1930, 1912, 1895, 1878, 1860, 1843, 1826, 1809, 1792, 1775, 1758,
        1741, 1724, 1707, 1690, 1674, 1657, 1641, 1625, 1609, 1593, 1577, 1561, 1546, 1530, 1515,
        1500, 1484, 1470, 1455, 1440, 1426, 1412, 1398, 1384, 1370, 1357, 1343, 1330, 1318, 1305,
        1292, 1280, 1268, 1256, 1245, 1233, 1222, 1211, 1201, 1190, 1180, 1170, 1161, 1151, 1142,
        1133, 1125, 1117, 1108, 1101, 1093, 1086, 1079, 1072, 1066, 1060, 1054, 1048, 1043, 1038,
        1034, 1029, 1025, 1021, 1018, 1015, 1012, 1009, 1007, 1005, 1003, 1002, 1001, 1000, 1000,
        1000, 1000, 1000, 1001, 1002, 1003, 1005, 1007, 1009, 1012, 1015, 1018, 1021, 1025, 1029,
        1034, 1038, 1043, 1048, 1054, 1060, 1066, 1072, 1079, 1086, 1093, 1101, 1108, 1117, 1125,
        1133, 1142, 1151, 1161, 1170, 1180, 1190, 1201, 1211, 1222, 1233, 1245, 1256, 1268, 1280,
        1292, 1305, 1318, 1330, 1343, 1357, 1370, 1384, 1398, 1412, 1426, 1440, 1455, 1470, 1484,
        1500, 1515, 1530, 1546, 1561, 1577, 1593, 1609, 1625, 1641, 1657, 1674, 1690, 1707, 1724,
        1741, 1758, 1775, 1792, 1809, 1826, 1843, 1860, 1878, 1895, 1912, 1930, 1947, 1965, 1982
    };

    QWidget *winMain = new QWidget();

    int lenOfECG = sizeof(ecgWave)/sizeof(int);
    int maxECG = 4096;
    int lenOfSin = sizeof(sinWave)/sizeof(int);
    int maxSin = 3000;
    QWidgetDraw *drawWidget_a = new QWidgetDraw(ecgWave, lenOfECG, maxECG);
    QWidgetDraw *drawWidget_b = new QWidgetDraw(sinWave, lenOfSin, maxSin*1.5);

    drawWidget_a->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    drawWidget_b->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    // 创建垂直箱式 layout
    QVBoxLayout *qvbl = new QVBoxLayout();
    qvbl->addWidget(drawWidget_a);
    qvbl->addWidget(drawWidget_b);
    winMain->setWindowTitle("八仙过海队");
    winMain->resize(1600, 600);
    winMain->setLayout(qvbl);
    winMain->show();
}

