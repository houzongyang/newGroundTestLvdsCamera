/**
 * @file      dataanalysishelper.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "dataanalysishelper.h"
//#include "framehelper.h"
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QThread>
#include <QtMath>
#include <QJSEngine>
#include <QJSValue>
#include <QDomDocument>

DataAnalysisHelper::DataAnalysisHelper(QObject *parent) : QObject(parent)
{
    frameHelper = new FrameHelper(this);
    overThresholdCoords.reserve(imgSize * imgSize); // 预估 10% 的像素会超过阈值
}

void DataAnalysisHelper::onDataAnalysisSerial1(){

    while(m_running){
        if (m_ringBuffer && !m_ringBuffer->isEmpty()) {
            size_t available = m_ringBuffer->available();
            size_t chunkSize = std::min(available, static_cast<size_t>(FRAME_SIZE_CENTROID));

            if (chunkSize > 0) {
                QByteArray frame = m_ringBuffer->pop(chunkSize);
                processSerial1Frame(frame);
            } else {
                QThread::msleep(1);  // 避免忙等待
            }
        }
    }
}


void DataAnalysisHelper::onDataAnalysisSerial2(){
    while(m_running){
        if (m_ringBuffer && !m_ringBuffer->isEmpty()) {
            size_t available = m_ringBuffer->available();
            size_t chunkSize = std::min(available, static_cast<size_t>(FRAME_SIZE_TEM));
            if (chunkSize > 0) {
                QByteArray frame = m_ringBuffer->pop(chunkSize);
                processSerial2Frame(frame);
                processLVDSFrame(frame); // 临时测试，使用COMII接收图像数据
            } else {
                QThread::msleep(1);
            }
        }
    }
}

void DataAnalysisHelper::processSerial1Frame(QByteArray frame)
{
    serialBuffer1.append(frame);
    while (serialBuffer1.size() >= FRAME_SIZE_CENTROID) {
        int startIndex = -1;
        for (int i = 0; i<=serialBuffer1.size() - FRAME_SIZE_CENTROID; ++i) {
            if(static_cast<quint8>(serialBuffer1[i]) == 0xB9 &&
               static_cast<quint8>(serialBuffer1[i+1]) == 0xC0){
                startIndex = i;
                break;
            }
        }

        if(startIndex == -1){
            int keepSize = qMin(FRAME_SIZE_CENTROID-1, serialBuffer1.size());
            serialBuffer1 = serialBuffer1.right(keepSize);
            break;
        }

        if(startIndex > 0){
            serialBuffer1.remove(0,startIndex);
        }

        if(serialBuffer1.size()<FRAME_SIZE_CENTROID){
            break;
        }

        QByteArray frameData = serialBuffer1.left(FRAME_SIZE_CENTROID);
        centroidFrameAttrs.totalFrameNum += 1;
        centroidFrameAttrs.validFrameNum += 1;

        QByteArray currentCheckSum  = frameData.mid(29,1);
        QByteArray frameDataCheck = frameData.mid(2,27);
        QByteArray checkSum = frameHelper->frameChecksum(frameDataCheck,1);
       if(checkSum != currentCheckSum ){
           centroidFrameAttrs.errorFrameNum += 1;
           centroidFrameAttrs.validFrameNum -= 1;
       }

       quint16 centroidX = static_cast<quint16>(
                    (static_cast<quint8>(frameData[2]) << 8)  |
                    (static_cast<quint8>(frameData[3]))
               );

       quint16 centroidY = static_cast<quint16>(
                    (static_cast<quint8>(frameData[4]) << 8)  |
                    (static_cast<quint8>(frameData[5]))
               );

       quint16 maxGrayscale = static_cast<quint16>(
                    (static_cast<quint8>(frameData[6]) << 8)  |
                    (static_cast<quint8>(frameData[7]))
               );

       quint16 minGrayscale = static_cast<quint16>(
                    (static_cast<quint8>(frameData[8]) << 8)  |
                    (static_cast<quint8>(frameData[9]))
               );

       quint16 overThreshold = static_cast<quint16>(
                    (static_cast<quint8>(frameData[10]) << 8)  |
                    (static_cast<quint8>(frameData[11]))
               );

       quint16 exposureTime = static_cast<quint16>(
                    (static_cast<quint8>(frameData[12]) << 8)  |
                    (static_cast<quint8>(frameData[13]))
               );
       quint32 grayscaleSum = static_cast<quint32>(
                    (static_cast<quint8>(frameData[14]) << 24)  |
                    (static_cast<quint8>(frameData[15]) << 16)  |
                    (static_cast<quint8>(frameData[16]) << 8)   |
                    (static_cast<quint8>(frameData[17]))
               );

    centroidFrameAttrs.centroidX = centroidX / 32;
    centroidFrameAttrs.centroidY = centroidY / 32;
    centroidFrameAttrs.maxGrayscale = maxGrayscale;
    centroidFrameAttrs.minGrayscale = minGrayscale;
    centroidFrameAttrs.overThreshold = overThreshold;
    centroidFrameAttrs.exposureTime = exposureTime;
    centroidFrameAttrs.grayscaleSum = grayscaleSum;

    emit upgradeCentroidUi(centroidFrameAttrs);

    serialBuffer1 = serialBuffer1.mid(FRAME_SIZE_CENTROID); // 移除已处理部分
    if (serialBuffer1.size() < FRAME_SIZE_CENTROID) {
           break;
       }
    }
}

void DataAnalysisHelper::processSerial2Frame(QByteArray frame)
{
    serialBuffer2.append(frame);
    while (serialBuffer2.size() >= FRAME_SIZE_TEM) {
        int startIndex = -1;
        for (int i = 0; i<=serialBuffer2.size() - FRAME_SIZE_TEM; ++i) {
            if(static_cast<quint8>(serialBuffer2[i]) == 0xB9 &&
               static_cast<quint8>(serialBuffer2[i+1]) == 0xE0){
                startIndex = i;
                break;
            }
        }

        if(startIndex == -1){
            int keepSize = qMin(FRAME_SIZE_TEM-1, serialBuffer2.size());
            serialBuffer2 = serialBuffer2.right(keepSize);
            break;
        }

        if(startIndex > 0){
            serialBuffer2.remove(0,startIndex);
        }

        if(serialBuffer2.size()<FRAME_SIZE_TEM){
            break;
        }

        QByteArray frameData = serialBuffer2.left(FRAME_SIZE_TEM);
        temFrameAttrs.totalFrameNum += 1;
        temFrameAttrs.validFrameNum += 1;

        if(static_cast<quint8>(serialBuffer2[2]) == 0x0A){
            temFrameAttrs.totalUiParaNum +=1;
            temFrameAttrs.validUiParaNum +=1;
        }
        else {
            temFrameAttrs.totalUiParaNum +=1;
            temFrameAttrs.errorUiparaNum +=1;
        }

        QByteArray currentCheckSum  = frameData.mid(18,1);
        QByteArray frameDataCheck = frameData.mid(2,16);
        QByteArray checkSum = frameHelper->frameChecksum(frameDataCheck,1);
       if(checkSum != currentCheckSum ){
           temFrameAttrs.errorFrameNum += 1;
           temFrameAttrs.validFrameNum -= 1;
       }

       int temTEC = static_cast<qint16>(
                    (static_cast<qint8>(frameData[4]) << 8)  |
                    (static_cast<qint8>(frameData[5]))
               );
       int temFPGA = static_cast<qint16>(
                    (static_cast<qint8>(frameData[6]) << 8)  |
                    (static_cast<qint8>(frameData[7]))
               );

        temFrameAttrs.tempTEC = temTEC;
        temFrameAttrs.tempFPGA = temFPGA;

        emit upgradeTemUi(temFrameAttrs);

        serialBuffer2 = serialBuffer2.mid(FRAME_SIZE_TEM); // 移除已处理部分
        if (serialBuffer2.size() < FRAME_SIZE_TEM) {
               break;  // 剩余数据不足，等待下次输入
        }
    }
}


void DataAnalysisHelper::onDataAnalysisRS422() {
    while (m_running) {
        if (m_ringBuffer && !m_ringBuffer->isEmpty()) {
            size_t available = m_ringBuffer->available();

            // 至少要能看两个字节的帧头
            if (available < 2) {
                QThread::msleep(1);
                continue;
            }

            // pop前lengthHead个字节来判断帧类型
            QByteArray header = m_ringBuffer->peek(lengthHead);
            quint8 h0 = static_cast<quint8>(header[0]);
            quint8 h1 = static_cast<quint8>(header[1]);


            int frameLen = 0;
            enum FrameType { Unknown, Centroid, Ack, Telemetry } frameType = Unknown;

            if (h0 == 0xB9 && h1 == 0xC0) {
                frameLen = 30;
                frameType = Centroid;
            } else if (h0 == 0xB9 && h1 == 0xD0) {
                frameLen = 5;
                frameType = Ack;
            } else if (h0 == h0_xml && h1 == h1_xml) {
                frameLen =  frameTm.frameLength;
                frameType = Telemetry;
            } else {
                m_ringBuffer->pop(1);
                continue;
            }

            if (available < static_cast<size_t>(frameLen)) {
                QThread::msleep(1);
                continue;
            }

            QByteArray frame = m_ringBuffer->pop(frameLen);

            switch (frameType) {
                case Centroid:
                    processRS422Frame(frame);
                    break;
                case Ack:
                    processAckFrame(frame);
                    break;
                case Telemetry:
                    processTelemetryFrame(frame);
                    break;
                default:
                    break;
            }
        } else {
            QThread::msleep(1);  // 避免忙等待
        }
    }
}

void DataAnalysisHelper::processAckFrame(const QByteArray &frame) {
    qDebug() << "Ack Frame:" << frame.toHex(' ');
}

void DataAnalysisHelper::processTelemetryFrame(const QByteArray &frame) {

    QByteArray frameTail = frame.mid(frame.size()-lengthTail,-1);
    quint8 t0 = static_cast<quint8>(frameTail[0]);
    quint8 t1 = static_cast<quint8>(frameTail[1]);

    QByteArray ba_frameTail = QByteArray::fromHex(frameTm.frameTail.toUtf8());
    quint8 t0_xml = static_cast<quint8>(ba_frameTail[0]);
    quint8 t1_xml = static_cast<quint8>(ba_frameTail[1]);

    if(t0 != t0_xml || t1 != t1_xml){
        emit updateFrameCheckSignal(false);
        return;
    }


    QByteArray currentCheckSum  = frame.mid(frame.size() - lengthHead - lengthTail, lengthHead);

    QByteArray frameDataCheck = frame.mid(lengthHead, frame.size() - lengthHead - lengthTail - frameTm.checkSumNum); // 这里的4是帧头和帧尾占据的字节数,所以此版本必须局限在2字节的帧头

    QByteArray checkSum = frameHelper->frameChecksum(frameDataCheck, frameTm.checkSumNum);
    if(currentCheckSum != checkSum){
        emit updateFrameCheckSignal(false);
        return;
    }
    emit updateFrameCheckSignal(true);

    QByteArray frameDeal = frame.mid(lengthHead,-1);
    for(int i = 0; i < paraQueueVector.size();++i){
        const TMitemQueue &cmd = paraQueueVector.at(i);

        paraListUi.paraNo = cmd.TMitemNo;
        int codeLength = cmd.TMitemLength.toInt();
        QString code = frameDeal.mid(0,codeLength).toHex().toUpper();
        int codeInt =  code.toInt(nullptr, 16);

        frameDeal.remove(0,codeLength);

        paraListUi.code = code; // 源码
        if(cmd.ParaType == "EDIT"){


            paraListUi.value= applyRule(cmd.EncodeType,codeInt);

            double valueDouble = applyRule(cmd.EncodeType,codeInt).toDouble();
            double valueMin = cmd.TMitemMinF.toDouble();
            double valueMax = cmd.TMitemMaxF.toDouble();

            if(valueDouble>=valueMin && valueDouble<=valueMax){
                paraListUi.isValid = true;
            }
            else {
                paraListUi.isValid = false;
            }

        }
        else if(cmd.ParaType == "COMBOX"){
            bool isValid = false;
            for (int j = 0 ; j < cmd.TMparaList.size();++j) {
                if(cmd.TMparaList.at(j).initCode == code){
                    paraListUi.value = cmd.TMparaList.at(j).paraName;
                    isValid = true;
                    break;
                }
            }
            if(isValid){
                paraListUi.isValid = true;
            }
            else {
                paraListUi.isValid = false;
            }
        }
        else{
            return;
        }

        paraListUiList.append(paraListUi);
    }

    emit updateParaListUiSignal(paraListUiList);
    paraListUiList.clear();

}



void DataAnalysisHelper::getXmlParser(QVector<TMitemQueue> paraQueueVectorRec)
{
    paraQueueVector = paraQueueVectorRec;
}

void DataAnalysisHelper::onDataAnalysisLVDS(){
    while (m_running) {
        if (m_ringBuffer && !m_ringBuffer->isEmpty()) {

            size_t available = m_ringBuffer->available();
            size_t chunkSize = std::min(available, static_cast<size_t>(2048));

            if (chunkSize > 0) {
                QByteArray frame = m_ringBuffer->pop(chunkSize);
                processLVDSFrame(frame);  // 解析数据帧
            } else {
                QThread::msleep(1);  // 避免忙等待
            }
        }
    }
}

void DataAnalysisHelper::processRS422Frame(QByteArray frame)
{
    rs422Buffer.append(frame);
    while (rs422Buffer.size() >= FRAME_SIZE_CENTROID) {
        int startIndex = -1;
        for (int i = 0; i<=rs422Buffer.size() - FRAME_SIZE_CENTROID; ++i) {
            if(static_cast<quint8>(rs422Buffer[i]) == 0xB9 &&
               static_cast<quint8>(rs422Buffer[i+1]) == 0xC0){
                startIndex = i;
                break;
            }
        }

        if(startIndex == -1){
            int keepSize = qMin(FRAME_SIZE_CENTROID-1, rs422Buffer.size());
            rs422Buffer = rs422Buffer.right(keepSize);
            break;
        }

        if(startIndex > 0){
            rs422Buffer.remove(0,startIndex);
        }

        if(rs422Buffer.size()<FRAME_SIZE_CENTROID){
            break;
        }

        QByteArray frameData = rs422Buffer.left(FRAME_SIZE_CENTROID);

        if (frameData.size() < 30) {
            qWarning() << "frameData length error";
            return;
        }
        centroidFrameAttrs.totalFrameNum += 1;
        centroidFrameAttrs.validFrameNum += 1;
        QByteArray currentCheckSum  = frameData.mid(29,1);
        QByteArray frameDataCheck = frameData.mid(2,27);
        QByteArray checkSum = frameHelper->frameChecksum(frameDataCheck,1);
       if(checkSum != currentCheckSum ){
           centroidFrameAttrs.errorFrameNum += 1;
           centroidFrameAttrs.validFrameNum -= 1;
       }

       quint16 centroidX = static_cast<quint16>(
                    (static_cast<quint8>(frameData[2]) << 8)  |
                    (static_cast<quint8>(frameData[3]))
               );

       quint16 centroidY = static_cast<quint16>(
                    (static_cast<quint8>(frameData[4]) << 8)  |
                    (static_cast<quint8>(frameData[5]))
               );

       quint16 maxGrayscale = static_cast<quint16>(
                    (static_cast<quint8>(frameData[6]) << 8)  |
                    (static_cast<quint8>(frameData[7]))
               );

       quint16 minGrayscale = static_cast<quint16>(
                    (static_cast<quint8>(frameData[8]) << 8)  |
                    (static_cast<quint8>(frameData[9]))
               );

       quint16 overThreshold = static_cast<quint16>(
                    (static_cast<quint8>(frameData[10]) << 8)  |
                    (static_cast<quint8>(frameData[11]))
               );

       quint16 exposureTime = static_cast<quint16>(
                    (static_cast<quint8>(frameData[12]) << 8)  |
                    (static_cast<quint8>(frameData[13]))
               );
       quint32 grayscaleSum = static_cast<quint32>(
                    (static_cast<quint8>(frameData[14]) << 24)  |
                    (static_cast<quint8>(frameData[15]) << 16)  |
                    (static_cast<quint8>(frameData[16]) << 8)   |
                    (static_cast<quint8>(frameData[17]))
               );

       quint16 SEL_Current =
                    (static_cast<quint16>(static_cast<quint8>(frameData[18]) << 4))  |
                    (static_cast<quint8>(static_cast<quint8>(frameData[19]) >> 4))
                   ;

       quint16 FPGA_Tem =
                   (static_cast<quint16>((static_cast<quint8>(frameData[19]) & 0x0F) << 8)) |
                   (static_cast<quint8>(static_cast<quint8>(frameData[20])))
               ;

       quint16 Tec_Tem =
                    (static_cast<quint16>(static_cast<quint8>(frameData[21]) << 4))  |
                    (static_cast<quint8>(static_cast<quint8>(frameData[22]) >> 4))
                   ;

       quint16 Vtemp_Tem =
                   (static_cast<quint16>((static_cast<quint8>(frameData[22]) & 0x0F) << 8)) |
                   (static_cast<quint8>(static_cast<quint8>(frameData[23])))
               ;

       quint8 SEL_Status =
               (static_cast<quint8>(frameData[24]) >> 6)
              ;

       quint8 SEL_OverTimes =
               (static_cast<quint8>(frameData[24]) & 0x3F)
              ;

       quint8 SEL_OverTimesRecord =
               static_cast<quint8>(frameData[25])
              ;

       quint8 SEL_OverCurrentSampling =
               static_cast<quint8>(frameData[26])
              ;

       quint8 Camera_ExpoMode =
               (static_cast<quint8>(frameData[27]) >> 6)
              ;
       quint8 BadPix_CoreMode =
               (static_cast<quint8>(frameData[27]) >> 4) & 0x03
              ;
       quint8 Image_DataSource =
               (static_cast<quint8>(frameData[27]) >> 2) & 0x03
              ;
       quint8 Reserve1 =
               (static_cast<quint8>(frameData[27])) & 0x03
              ;

       quint8 Reserve2 =
               static_cast<quint8>(frameData[28])
              ;


    centroidFrameAttrs.centroidX = centroidX / 32;
    centroidFrameAttrs.centroidY = centroidY / 32;
    centroidFrameAttrs.maxGrayscale = maxGrayscale;
    centroidFrameAttrs.minGrayscale = minGrayscale;
    centroidFrameAttrs.overThreshold = overThreshold;
    centroidFrameAttrs.exposureTime = exposureTime;
    centroidFrameAttrs.grayscaleSum = grayscaleSum;

    centroidFrameAttrs.SEL_Current = SEL_Current;
    centroidFrameAttrs.FPGA_Tem = FPGA_Tem;
    centroidFrameAttrs.Tec_Tem = Tec_Tem;
    centroidFrameAttrs.Vtemp_Tem = Vtemp_Tem;
    switch(SEL_Status){
        case 1:
            centroidFrameAttrs.SEL_Status = "正常";
        break;
        case 2:
            centroidFrameAttrs.SEL_Status = "异常";
        break;
        default:
            centroidFrameAttrs.SEL_Status = "无效";
        break;
    }
    centroidFrameAttrs.SEL_OverTimes = SEL_OverTimes;
    centroidFrameAttrs.SEL_OverTimesRecord  = SEL_OverTimesRecord;
    centroidFrameAttrs.SEL_OverCurrentSampling = SEL_OverCurrentSampling;
    switch(Camera_ExpoMode){
        case 1:
            centroidFrameAttrs.Camera_ExpoMode = "自适应曝光模式开启";
        break;
        case 2:
            centroidFrameAttrs.Camera_ExpoMode = "自适应曝光模式关闭";
        break;
        default:
            centroidFrameAttrs.Camera_ExpoMode = "无效";
        break;
    }
    switch(BadPix_CoreMode){
        case 0:
            centroidFrameAttrs.BadPix_CoreMode = "不开启自动/手动坏点校正";
        break;
        case 1:
            centroidFrameAttrs.BadPix_CoreMode = "只开启手动剔除坏点模式";
        break;
        case 2:
            centroidFrameAttrs.BadPix_CoreMode = "只开启手动剔除坏点模式";
        break;
        case 3:
            centroidFrameAttrs.BadPix_CoreMode = "同时开启自动与手动剔除坏点模式";
        break;
        default:
            centroidFrameAttrs.BadPix_CoreMode = "无效";
        break;
    }
    switch(Image_DataSource){
        case 1:
            centroidFrameAttrs.Image_DataSource = "坏点校正后的图像数据";
        break;
        case 2:
            centroidFrameAttrs.Image_DataSource = "图像原始数据";
        break;
        default:
            centroidFrameAttrs.Image_DataSource = "无效";
        break;
    }

    emit upgradeCentroidUi(centroidFrameAttrs);

    rs422Buffer = rs422Buffer.mid(FRAME_SIZE_CENTROID); // 移除已处理部分
    if (rs422Buffer.size() < FRAME_SIZE_CENTROID) {
           break;  // 剩余数据不足，等待下次输入
       }
    }
}


void DataAnalysisHelper::processLVDSFrame(QByteArray frame)
{
    lvdsBuffer.append(frame);

    while (lvdsBuffer.size() >= FRAME_SIZE) {
        int startIndex = -1;
        for (int i = 0; i <= lvdsBuffer.size() - FRAME_SIZE; ++i) {
            if (static_cast<quint8>(lvdsBuffer[i]) == 0xE2 &&
                static_cast<quint8>(lvdsBuffer[i + 1]) == 0x25) {
                startIndex = i;
                break;
            }
        }
        if (startIndex == -1) {
            int keepSize = qMin(FRAME_SIZE - 1, lvdsBuffer.size());
            lvdsBuffer = lvdsBuffer.right(keepSize);
            break;
        }

        if (startIndex > 0) {
                        lvdsBuffer.remove(0, startIndex);
        }

        if (lvdsBuffer.size() < FRAME_SIZE) {
            break;
        }

        if (lvdsBuffer.size() < FRAME_SIZE) {
            break; // 等待更多数据
         }

        QByteArray frame = lvdsBuffer.left(FRAME_SIZE);
        bool validFrame = true;

        if (static_cast<quint8>(lvdsBuffer[2046]) != 0xFB ||
            static_cast<quint8>(lvdsBuffer[2047]) != 0xFB) {

            lvdsBuffer.remove(0, FRAME_SIZE);
            validFrame = false;
            continue;
        }

        if(imageNo != lvdsBuffer.mid(13,2)){
            lvdsImgDataBuffer.clear();
            headFrameExist = false;

        }

        if(!headFrameExist){
            if (frame.size() < 16) {
                lvdsBuffer.remove(0, 2); // 仅丢弃帧头
                continue;
            }

            if (static_cast<quint8>(lvdsBuffer[15]) != 0x00) {

                lvdsBuffer.remove(0,FRAME_SIZE);
                continue;
            }
            else {

                imgAttrs.totalImgNum  += 1;
                imgAttrs.validImgNum += 1;
                headFrameExist = true;
                imageNo = lvdsBuffer.mid(13,2);
                QByteArray timeCode = lvdsBuffer.mid(8,4);
                quint8 highS = static_cast<quint8>(timeCode[0]);
                quint8 lowS  = static_cast<quint8>(timeCode[1]);
                quint16 timeCodeS = static_cast<quint16>((highS << 8) | lowS);
                quint8 highMS = static_cast<quint8>(timeCode[2]);
                quint8 lowMS  = static_cast<quint8>(timeCode[3]);
                quint16 timeCodeMS = static_cast<quint16>((highMS << 8) | lowMS);
                double timeCodeMSDouble = timeCodeMS * 0.2;
                QString timeCodeString = QString::number(timeCodeS) + "秒" + QString::number(timeCodeMSDouble) + "毫秒";
                imgAttrs.timeCode = timeCodeString;

                imgAttrs.imgFrameNoString = imageNo.toHex(' ').toUpper();

                imgSize = static_cast<int>(static_cast<quint8>(lvdsBuffer[16])) * 4;
                imgAttrs.imgWinSize = imgSize;
                imgIsError = false;
            }
        }

        QByteArray frameData = lvdsBuffer.left(FRAME_SIZE);
        int frameNum = (imgSize * imgSize % frameSizePure == 0)? (imgSize * imgSize / frameSizePure ): (imgSize * imgSize / frameSizePure + 1);



        QByteArray currentCheckSum = frameData.mid(2044,2);

        QByteArray frameDataCheck = frameData.mid(2,2042);
        QByteArray checkSum =  frameHelper->frameChecksum(frameDataCheck,2);

        if(checkSum != currentCheckSum ){

            if(!imgIsError){
                imgIsError = true;
                imgAttrs.errorImgNum  += 1;
                imgAttrs.validImgNum  -= 1;
            }
        }

        QByteArray frameDataPure = frameData.mid(17,frameSizePure);
        lvdsImgDataBuffer.append(frameDataPure);


        if (lvdsImgDataBuffer.size() >= imgSize * imgSize) {
            overThresholdCoords.clear();
            QByteArray singleImgData = lvdsImgDataBuffer.mid(0, imgSize * imgSize);
            for(int i = 0 ; i  < imgSize * imgSize; i++){
                quint8 pixel = static_cast<quint8>(singleImgData.at(i));
                if(pixel > grayThrehold){
                    imgAttrs.overThreshold += 1;

                    if(isSaveCoordinate){
                        int x = i % imgSize;
                        int y = i / imgSize;
                        overThresholdCoords.append(QPoint(x,y));

                    }
                }
                if(isImgToPeaking && pixel < peakingThrehold){
                    singleImgData[i] = static_cast<char>(pixel * 0.1);
                }
            }

            imgAttrs.overThresholdCo = overThresholdCoords;

            lvdsImgDataBuffer.clear();
            showGrayImage(singleImgData, imgSize);

            emit upgradeErrorImgNumUi(imgAttrs);
            imgAttrs.overThreshold = 0;

        }

        lvdsBuffer = lvdsBuffer.mid(FRAME_SIZE);
        if (lvdsBuffer.size() < FRAME_SIZE) {
               break;
        }
    }
}

void DataAnalysisHelper::updataUiSettingsRec(const SettingsUiToSub &settingsUi)
{
    grayThrehold = settingsUi.grayThrehold;

}

void DataAnalysisHelper::showGrayImage(const QByteArray &singleImgData, int imgSize)
{

    QImage image(reinterpret_cast<const uchar*>(singleImgData.constData()),
                 imgSize,
                 imgSize,
                 QImage::Format_Grayscale8);

    QImage imageCopy = image.copy();

    emit imageSignal(imageCopy);
}

void DataAnalysisHelper::setRingBuffer(RingBuffer *buffer)
{
    QMutexLocker locker(&m_mutex);
     if (m_ringBuffer != buffer) {
         m_ringBuffer = buffer;
     }
}

void DataAnalysisHelper::imgToPeaking(bool isImgToPeakingUi, int peakingThresholdUi)
{

    isImgToPeaking = isImgToPeakingUi;
    peakingThrehold = peakingThresholdUi;
}

void DataAnalysisHelper::updateSaveCoordinate(bool isSaveCoordinateUi)
{
    isSaveCoordinate = isSaveCoordinateUi;
}


QString DataAnalysisHelper::applyRule(const QString &rule, double value) {
    QJSEngine engine;

    engine.globalObject().setProperty("x", value);

    QJSValue result = engine.evaluate(rule);

    if (result.isError()) {
        return "EvalError: " + result.toString();
    }

    return QString::number(result.toNumber(), 'f', 6);
}
