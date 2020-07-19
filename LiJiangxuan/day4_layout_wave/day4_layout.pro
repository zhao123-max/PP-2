QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

SOURCES += \
    main.cpp \
    qwidgetdraw.cpp \
    qwidgetserialrx.cpp \
    qwidgetserialtx.cpp

HEADERS += \
    data.h \
    qwidgetdraw.h
    qwidgetserialrx.h \
    qwidgetserialtx.h
