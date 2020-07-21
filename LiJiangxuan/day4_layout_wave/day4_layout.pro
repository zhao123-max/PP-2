QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

SOURCES += \
    main.cpp \
    qwidgetdraw.cpp \
    qwidgetdrawforserialrx.cpp \
    qwidgetserialrx.cpp \
    qwidgetserialtx.cpp \
    qwidgetserialtxecg.cpp \
    qwidgetserialtxibp2.cpp \
    qwidgetserialtxspo2.cpp

HEADERS += \
    data.h \
    qwidgetdraw.h \
    qwidgetdrawforserialrx.h \
    qwidgetserialrx.h \
    qwidgetserialtx.h \
    qwidgetserialtxecg.h \
    qwidgetserialtxibp2.h \
    qwidgetserialtxspo2.h \
    wavedata.h
