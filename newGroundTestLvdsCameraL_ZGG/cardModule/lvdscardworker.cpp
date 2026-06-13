/**
 * @file      lvdscardworker.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "lvdscardworker.h"
#include "lvdscardhelper.h"
#include <QObject>
#include "dataanalysishelper.h"

lvdsCardWorker::lvdsCardWorker(QObject *parent) : QObject(parent)
{
    card = new LVDSCardHelper(this); // 创建板卡对象
    datatransfer = new DataTransfer(this);
    connect(card,&LVDSCardHelper::RunError,this,&lvdsCardWorker::emitRunError);
    connect(card,&LVDSCardHelper::onDataReady,this,&lvdsCardWorker::readyReceive);
}

const QByteArray lvdsCardWorker::COMMAND_FRAME_HEADER = QByteArray::fromHex("B9E0"); // 相机接收命令帧
const int lvdsCardWorker::COMMAND_FRAME_LENGTH = 18;
const QByteArray lvdsCardWorker::DATA_FRAME_HEADER = QByteArray::fromHex("B9C0"); // 相机发送数据帧
const QByteArray lvdsCardWorker::RESPONSE_FRAME_HEADER = QByteArray::fromHex("B9D0"); // 相机发送应答帧
const int lvdsCardWorker::DATA_FRAME_LENGTH = 19;
const int lvdsCardWorker::RESPONSE_FRAME_LENGTH = 5;
const QByteArray lvdsCardWorker::IMG_FRAME_HEADER = QByteArray::fromHex("E225"); // 图像数据帧头
const QByteArray lvdsCardWorker::IMG_FRAME_TAIL = QByteArray::fromHex("FBFB"); // 图像数据帧尾
const int lvdsCardWorker::IMG_FRAME_LENGTH = 2048; // 图像数据帧长


void lvdsCardWorker::emitRunError(QString msg){
    emit RunError(msg);
}

void lvdsCardWorker::readyReceive(quint8 currentCardNo, quint8 channel,QByteArray data){
    if(cardNo0IsRs422){
        qDebug()<<"当前0号板卡为RS422";
        if(currentCardNo == Card1No) onRS422DataReceived(channel,data); // 开始对接收到的原始数据进行处理
        else if(currentCardNo == Card2No) onLVDSDataReceived(channel,data); // 开始对接收到的原始数据进行处理
    }
    // B系列地检
    else {
        qDebug()<<"当前0号板卡为LVDS";
        if(currentCardNo == Card2No) onRS422DataReceived(channel,data); // 开始对接收到的原始数据进行处理
        else if(currentCardNo == Card1No) onLVDSDataReceived(channel,data); // 开始对接收到的原始数据进行处理

    }
}

void lvdsCardWorker::updateCardNoInput(quint8 rs422N, quint8 lvdsNo){
    Card1No = rs422N;
    Card2No = lvdsNo;
}

int lvdsCardWorker::getCardCount(){
    int cardCount =card->getLVDSCardsCount();
    return cardCount;
}

void lvdsCardWorker::setCardNum(quint8 cardNum){
    card->setCurrentCardNo(cardNum);
};

quint8 lvdsCardWorker::getCardNum(bool chooseCard){
    if(chooseCard) return card->currentCardNo;
    else return card->currentCardNo;
}

quint8 lvdsCardWorker::getChannelNum(bool chooseCard){
    if(chooseCard) return card->currentChannelNo;
    else return card->currentChannelNo;
}

void lvdsCardWorker::openCard(bool chooseCard){
    if(chooseCard) card->OpenLVDSCard();
    else card->OpenLVDSCard();
}

bool lvdsCardWorker::closeCard(bool chooseCard){
    if(chooseCard) return card->CloseLVDSCard();
    else return card->CloseLVDSCard();
}

bool lvdsCardWorker::resetCard(bool chooseCard){
    if(chooseCard) return card->ResetLVDSCard();
    else return card->ResetLVDSCard();
}

bool lvdsCardWorker::clearFIFO(bool chooseCard){
    if(chooseCard) return card->ClearLVDSCardBuff();
    else return card->ClearLVDSCardBuff();
}

void lvdsCardWorker::setChannelNum(bool chooseCard, quint8 channelNum){
    if(chooseCard) card->setCurrentUseChannel(channelNum);
    else card->setCurrentUseChannel(channelNum);
};

void lvdsCardWorker::configLVDSCardFrame(bool chooseCard){
    if(chooseCard){
        qDebug()<<"lvdsCardWorker channel"<<card->currentChannelNo;
        bool frameSetRS422 = card->configLVDSCardFrame(false,card->currentChannelNo);
        bool frameSetRecRS422 = card->configLVDSCardFrame(true,card->currentChannelNo);
        if(frameSetRS422 == false || frameSetRecRS422 == false){
            emit updateBarStatusSignal(true, "RS422板卡发送通道或接收通道帧配置失败！");
        }
        else{
            emit updateBarStatusSignal(true, "RS422板卡通道帧配置成功！");
        }
    }
    else {
        bool frameSetLVDS = card->configLVDSCardFrame(false,card->currentChannelNo);
        bool frameSetRecLVDS = card->configLVDSCardFrame(true,card->currentChannelNo);
        if(frameSetLVDS == false || frameSetRecLVDS == false){
            emit updateBarStatusSignal(false, "LVDS板卡发送通道或接收通道帧配置失败！");
        }
        else{
            emit updateBarStatusSignal(false, "LVDS板卡通道帧配置成功！");
        }
    }
}

// 新驱动不支持通道配置，此函数已注释
// bool lvdsCardWorker::configChannelPara(bool chooseCard, bool isRecv,quint8 channel,ST_LVDS_CFG stCfg){
//     if(chooseCard) return card->configCardChannel(card->currentCardNo,isRecv,channel,stCfg);
//     else return card->configCardChannel(card->currentCardNo,isRecv,channel,stCfg);
// }

bool lvdsCardWorker::getLVDSCardOpenStatus(bool chooseCard){
    if(chooseCard) return card->getLVDSCardOpenStatus();
    else return card->getLVDSCardOpenStatus();
}

bool lvdsCardWorker::StartCard(bool chooseCard){
    updateIsTStart(chooseCard, true); // 开始接收数据，更新标志位
    if(chooseCard) {
        card->StartLVDSCard(true);
        return card->StartLVDSCard(true);
    }
    else{
        card->StartLVDSCard(true);
        return card->StartLVDSCard(true);
    }
}

bool lvdsCardWorker::StopCard(bool chooseCard){
    updateIsTStart(chooseCard, false); // 开始接收数据，更新标志位
    if(chooseCard) {
        card->StartLVDSCard(false);
        return card->StartLVDSCard(false);
    }
    else{
        card->StartLVDSCard(false);
        return card->StartLVDSCard(false);
    }
}



void lvdsCardWorker::updateIsTStart(bool chooseCard, bool isTStart){
    if(chooseCard) card->isT1Start = isTStart;
    else card->isT1Start = isTStart;
}

bool lvdsCardWorker::getLVDSCardStartStatus(bool chooseCard){
    if(chooseCard) return card->getLVDSCardStartStatus();
    else return card->getLVDSCardStartStatus();
}

quint32 lvdsCardWorker::sendData(bool chooseCard, quint8 channel, BYTE* data, size_t dataSize)
{
    if(chooseCard) return card->sendData(channel, data, dataSize);
    else return card->sendData(channel, data, dataSize);
}

void lvdsCardWorker::onRS422DataReceived(quint8 channel,QByteArray data){
    QByteArray dataRS422 = QByteArray::fromHex(data);
    QString hexStringRS422 = datatransfer->Bytearray2string(dataRS422);

    emit onRS422DataToUi(channel,hexStringRS422);

    if (m_ringBuffer) {
            m_ringBuffer->push(dataRS422);
        }
}

void lvdsCardWorker::onLVDSDataReceived(quint8 channel,QByteArray data){

    QByteArray dataLVDS = QByteArray::fromHex(data);
    QString hexStringLVDS = datatransfer->Bytearray2string(dataLVDS);
    qDebug()<<"hexStringLVDS:"<<hexStringLVDS;
    emit onLVDSDataToUi(channel,hexStringLVDS); // 先把数据发送给主ui直接显示
    // 将数据不断写入环形缓冲区
    if (m_ringBuffer) {
            m_ringBuffer->push(dataLVDS);  // 非阻塞写入数据
        }
}

void lvdsCardWorker::threadRun(){
    bool isCardStart = getLVDSCardStartStatus(true);
    if(isCardStart){
        card->startReceive();
    }
}

void lvdsCardWorker::setRingBuffer(RingBuffer *buffer)
{
    QMutexLocker locker(&m_mutex);
     if (m_ringBuffer != buffer) {
         m_ringBuffer = buffer;
         qDebug() << "RingBuffer updated in thread:" << QThread::currentThread();
     }
}

void lvdsCardWorker::GTChoise(bool cardNo0IsRs422Get)
{
    cardNo0IsRs422 = cardNo0IsRs422Get;
}

