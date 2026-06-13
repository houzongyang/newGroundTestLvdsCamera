/**
 * @file      commandcamera.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "commandcamera.h"

commandcamera::commandcamera(QObject *parent) : QObject(parent)
{

}

// 直接加载系统内部默认xml文件
void commandcamera::readXML()
{
    QString xmlFilePath = ":/XmlFiles/CMD/cmd_Camera.xml";

}

// 点击加载xml文件按钮时运行
void commandcamera::reloadXML(QString xmlName)
{

}
