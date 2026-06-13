/**
 * @file      serialportworker.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "serialportworker.h"
#include "datatransfer.h"
//#include "dataanalysishelper.h"
#include "framehelper.h"
#include <QThread>
#include <QDebug>

#include <windows.h>
#include <QtSerialPort/QSerialPort>

SerialPortWorker::SerialPortWorker(QObject *parent) : QObject(parent)
{

    datatransfer = new DataTransfer(this);


    serialPort = new QSerialPort(this);
    serialPort->setReadBufferSize(1024 * 1024 * 50);
    connect(serialPort, &QSerialPort::readyRead, this, &SerialPortWorker::readData);
    byteArraySerial = new QByteArray;
    CHECKSUM_16 = QByteArray::fromHex("0000"); // 初始化校验和
    frameHelper = new FrameHelper(this);
    connect(serialPort, &QSerialPort::errorOccurred, [](QSerialPort::SerialPortError error) {
        if (error != QSerialPort::NoError) {
            qCritical() << "串口错误:" << error; // 打印错误（如缓冲区溢出、 parity错误）
        }
    });
}

SerialPortWorker::~SerialPortWorker(){
    byteArraySerial->clear();
}


const QByteArray SerialPortWorker::PARA_COMMAND_FRAME_HEADER = QByteArray::fromHex("B9E0"); // 相机参数命令帧
const int SerialPortWorker::PARA_COMMAND_FRAME_LENGTH = 18;
const QByteArray SerialPortWorker::TELECHECK_COMMAND_FRAME_HEADER = QByteArray::fromHex("B9F0"); // 相机遥测命令帧（遥测查询）
const int SerialPortWorker::TELECHECK_COMMAND_FRAME_LENGTH = 5;
const QByteArray SerialPortWorker::RESPONSE_FRAME_HEADER = QByteArray::fromHex("B9E0"); // 相机响应帧
const int SerialPortWorker::RESPONSE_FRAME_LENGTH = 11;
const QByteArray SerialPortWorker::DATA_FRAME_HEADER = QByteArray::fromHex("B9C0"); // 相机质心数据帧
const int SerialPortWorker::DATA_FRAME_LENGTH = 19;


void SerialPortWorker::initSerial(QString portName,int baudRate, int dataBit, int parity, int stopBit){
    serialPort->setPortName(portName);
    serialPort->setBaudRate(static_cast<QSerialPort::BaudRate>(baudRate));
    serialPort->setDataBits(static_cast<QSerialPort::DataBits>(dataBit));
    serialPort->setStopBits(static_cast<QSerialPort::StopBits>(stopBit));
    serialPort->setParity(static_cast<QSerialPort::Parity>(parity));
}

void SerialPortWorker::closeSerial(){
    if (serialPort->isOpen())
        serialPort->close();
}

void SerialPortWorker::openCloseSerial(){
    if (serialPort->isOpen()){
        serialPort->close();
        emit updatePortStateSignal(false);
    }
    else{
        if (serialPort->open(QIODevice::ReadWrite)) {
            emit updatePortStateSignal(true);
        } else {
            emit updatePortStateSignal(false);
        }
    }
}

void SerialPortWorker::writeData(QByteArray byteDataSend){
    if(serialPort->isOpen()){
        serialPort->write(byteDataSend);
    }
    else{
        emit RunError("错误,串口未打开！");
    }
}

void SerialPortWorker::readData(){

    QByteArray data = serialPort->readAll();
    QString dataReceivedString = datatransfer->Bytearray2string(data);
    emit dataToUiDirect(dataReceivedString);

    if (m_ringBuffer) {
            m_ringBuffer->push(data);
        }

}

void SerialPortWorker::clearFIFO()
{
    serialPort->clear();
}

void SerialPortWorker::setRingBuffer(RingBuffer *buffer)
{
    QMutexLocker locker(&m_mutex);
     if (m_ringBuffer != buffer) {
         m_ringBuffer = buffer;
         qDebug() << "RingBuffer updated in thread:" << QThread::currentThread();
     }
}
