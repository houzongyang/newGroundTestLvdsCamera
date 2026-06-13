#ifndef SERIALPORTWORKER_H
#define SERIALPORTWORKER_H

#include <QObject>
#include <QSerialPort>
#include "datatransfer.h"
#include "dataanalysishelper.h"
#include "framehelper.h"
#include "ringbuffer.h"

class SerialPortWorker : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortWorker(QObject *parent = nullptr);
    ~SerialPortWorker();

    void initSerial(QString portName,int baudRate, int dataBit, int parity, int stopBit); // 初始化串口
    void openCloseSerial();
    void writeData(QByteArray byteDataSend);
    void readData();

    void clearFIFO();

    QSerialPort *serialPort;
    QByteArray *byteArraySerial;

    int tempTestData = 0;
    int tempTest = 0;

    static const QByteArray PARA_COMMAND_FRAME_HEADER;
    static const QByteArray TELECHECK_COMMAND_FRAME_HEADER;
    static const int PARA_COMMAND_FRAME_LENGTH;
    static const int TELECHECK_COMMAND_FRAME_LENGTH;

    static const QByteArray RESPONSE_FRAME_HEADER;
    static const int RESPONSE_FRAME_LENGTH;

    static const QByteArray DATA_FRAME_HEADER;
    static const int DATA_FRAME_LENGTH;

    QByteArray CHECKSUM_16;

    QByteArray dataTemp;

    RingBuffer *m_ringBuffer;
    void setRingBuffer(RingBuffer *buffer);

    void closeSerial();

private:

    DataTransfer *datatransfer;

    QMutex m_mutex;

    FrameHelper *frameHelper;


signals:
    void dataReceived();
    void updatePortStateSignal(bool portStatus);
    void dataToUiDirect(QString dataReceivedString);

    void RunError(QString errorText);


public slots:
};

#endif // SERIALPORTWORKER_H
