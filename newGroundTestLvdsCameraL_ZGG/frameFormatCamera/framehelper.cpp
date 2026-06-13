/**
 * @file      framehelper.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "framehelper.h"
#include <QDebug>

FrameHelper::FrameHelper(QObject *parent) : QObject(parent)
{

}

/// 上位机接收帧检查
// 1. LVDS接收图像帧
void FrameHelper::frameCheckLVDS(QByteArray byteArray){
    qDebug()<<"byteArray："<<byteArray;
    qDebug()<<"byteArray size："<<byteArray.size();
}


/// 上位机发送指令帧组装
void FrameHelper::frameAssemble(QByteArray byteArray){

}


/// 校验和计算
QByteArray FrameHelper::frameChecksum(QByteArray byteArray, int checkSumLength){
    quint32 sum = 0;
    for (int i = 0; i < byteArray.size(); ++i) {
        sum += static_cast<quint8>(byteArray[i]);  // 使用无符号累加，防止负数
    }

    QByteArray result;
    if (checkSumLength == 1) {
        quint8 checksum8 = static_cast<quint8>(sum & 0xFF);
        result.append(static_cast<char>(checksum8));
    } else if (checkSumLength == 2) {
        quint16 checksum16 = static_cast<quint16>(sum & 0xFFFF);
        result.append(static_cast<char>((checksum16 >> 8) & 0xFF));
        result.append(static_cast<char>(checksum16 & 0xFF));
    }
    qDebug()<<"当前的校验和是："<<result.toHex(' ').toUpper();
    return result;

}
