#/**
# * @file      newGroundTestLvdsCamera.pro
# * @author    徐笑寒 (milurx@163.com)
# * @date      2026-04-2
# * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
# */

QT       += core gui widgets qml

# 强制使用 DirectX 11
# QMAKE_CXXFLAGS += -DQT_USE_DIRECT3D11
# 强制使用 OpenGL
#QMAKE_CXXFLAGS += -DQT_USE_OPENGL
QT += opengl



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += c++17
 CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogpara.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Structs.h \
    dialogpara.h \
    mainwindow.h

FORMS += \
    dialogpara.ui \
    mainwindow.ui

# 添加所需的 Qt 模块
QT += core gui widgets serialport


# 添加库文件路径配置
win32 {
    contains(QMAKE_TARGET.arch, x86_64) {
        # 64位系统配置
        LIBS += -L$$PWD/Driver/DLL/Win64 -lLVDS_T4R6 -lwdapi1020
        INCLUDEPATH += $$PWD/Driver/DLL/Win64
    } else {
        # 32位系统配置
        LIBS += -L$$PWD/Driver/DLL/Win32 -lLVDS_T4R6 -lwdapi1020
        INCLUDEPATH += $$PWD/Driver/DLL/Win32
    }
}



CODECFORSRC = UTF-8

QMAKE_CXXFLAGS += -Wno-unused-parameter  #mingW版本的
#QMAKE_CXXFLAGS += /wd4828

RESOURCES += \
    resources.qrc

#INCLUDEPATH += $$PWD/frmPages
#include($$PWD/frmPages/frmPages.pri)

INCLUDEPATH += $$PWD/cardModule
include($$PWD/cardModule/cardModule.pri)

INCLUDEPATH += $$PWD/serialPortModule
include($$PWD/serialPortModule/serialPortModule.pri)

INCLUDEPATH += $$PWD/frameFormat
include($$PWD/frameFormat/frameFormat.pri)

INCLUDEPATH += $$PWD/frameFormatCamera
include($$PWD/frameFormatCamera/frameFormatCamera.pri)

INCLUDEPATH += $$PWD/XML
include($$PWD/XML/XML.pri)

INCLUDEPATH += $$PWD/GeneralTools
include($$PWD/GeneralTools/GeneralTools.pri)

INCLUDEPATH += $$PWD/UICustom
include($$PWD/UICustom/UICustom.pri)


CONFIG += debug release
CONFIG -= debug_and_release

CONFIG_INI_SRC = $$PWD/ConfigFiles/*
CONFIG_INI_DEST = $$OUT_PWD/ConfigFiles

copy_config.files = $$CONFIG_INI_SRC
copy_config.path = $$CONFIG_INI_DEST

COPIES += copy_config


XML_FILES_SRC = $$PWD/XmlFiles/*
XML_FILES_DEST = $$OUT_PWD/XmlFiles

copy_xml.files = $$XML_FILES_SRC
copy_xml.path = $$XML_FILES_DEST

COPIES += copy_xml

# 自动复制驱动 DLL 到构建目录
win32 {
    contains(QMAKE_TARGET.arch, x86_64) {
        # 64位 DLL
        copy_lvds_dll.files = $$PWD/Driver/DLL/Win64/LVDS_T4R6.dll
        copy_lvds_dll.path = $$OUT_PWD
        COPIES += copy_lvds_dll

        copy_wdapi_dll.files = $$PWD/Driver/DLL/Win64/wdapi1020.dll
        copy_wdapi_dll.path = $$OUT_PWD
        COPIES += copy_wdapi_dll
    } else {
        # 32位 DLL
        copy_lvds_dll.files = $$PWD/Driver/DLL/Win32/LVDS_T4R6.dll
        copy_lvds_dll.path = $$OUT_PWD
        COPIES += copy_lvds_dll

        copy_wdapi_dll.files = $$PWD/Driver/DLL/Win32/wdapi1020.dll
        copy_wdapi_dll.path = $$OUT_PWD
        COPIES += copy_wdapi_dll
    }
}

#DEPLOY_PATH = $$PWD/../deploy # 代码所在文件夹
##DEPLOY_PATH = $$OUT_PWD/deploy # 构建目录

#deploy_config.files = $$PWD/ConfigFiles/*  # 将要被拷贝的文件们
#deploy_config.path = $$DEPLOY_PATH/ConfigFiles # 文件们将要被拷贝到的地址
#COPIES += deploy_config

#deploy_xml.files = $$PWD/XmlFiles/*
#deploy_xml.path = $$DEPLOY_PATH/XmlFiles
#COPIES += deploy_xml

#deploy_lvds_dll.files = $$PWD/Driver/DLL/Win32/LVDS_DLL.dll
#deploy_lvds_dll.path = $$DEPLOY_PATH
#COPIES += deploy_lvds_dll



