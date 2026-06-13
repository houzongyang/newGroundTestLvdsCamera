QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DebugPage.cpp \
    LVDS_SignalPage.cpp \
    LVDS_Thread.cpp \
    main.cpp \
    Widget.cpp

HEADERS += \
    DebugPage.h \
    LVDS_SignalPage.h \
    LVDS_T4R6.h \
    LVDS_Thread.h \
    Widget.h

FORMS += \
    DebugPage.ui \
    LVDS_SignalPage.ui \
    Widget.ui

#LVDS-Dll
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/ -lLVDS_T4R6
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ -lLVDS_T4R6
else:unix: LIBS += -L$$PWD/ -lLVDS_T4R6
