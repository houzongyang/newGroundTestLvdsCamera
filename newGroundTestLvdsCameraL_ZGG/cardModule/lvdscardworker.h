#ifndef LVDSCARDWORKER_H
#define LVDSCARDWORKER_H

#include <QObject>
#include "lvdscardhelper.h"
#include "datatransfer.h"
#include "dataanalysishelper.h"

class lvdsCardWorker : public QObject
{
    Q_OBJECT
public:
    explicit lvdsCardWorker(QObject *parent = nullptr);

    int getCardCount();
    void setCardNum(quint8 cardNum);
    void setChannelNum(bool chooseCard, quint8 channelNum);
    void openCard(bool chooseCard);
    bool closeCard(bool chooseCard);
    bool resetCard(bool chooseCard);
    bool clearFIFO(bool chooseCard);
    void configLVDSCardFrame(bool chooseCard);
    // bool configChannelPara(bool chooseCard, bool isRecv,quint8 channel,ST_LVDS_CFG stCfg);  // 新驱动不支持通道配置
    bool getLVDSCardOpenStatus(bool chooseCard);
    bool isTStart = false;
    bool StartCard(bool chooseCard);
    bool StopCard(bool chooseCard);
    void updateIsTStart(bool chooseCard, bool isTStart);
    bool getLVDSCardStartStatus(bool chooseCard);

    void onRS422DataReceived(quint8 channel,QByteArray data);
    void onLVDSDataReceived(quint8 channel,QByteArray data);



    quint8 getCardNum(bool chooseCard);
    quint8 getChannelNum(bool chooseCard);
    quint32 sendData(bool chooseCard, quint8 channel, BYTE* data, size_t dataSize);

    void updateCardNoInput(quint8 rs422No, quint8 lvdsNo);

    void threadRun();

    quint8 Card1No = 0;
    quint8 Card2No = 1;


    static const QByteArray COMMAND_FRAME_HEADER;
    static const int COMMAND_FRAME_LENGTH;

    static const QByteArray DATA_FRAME_HEADER;
    static const QByteArray RESPONSE_FRAME_HEADER;
    static const int DATA_FRAME_LENGTH;
    static const int RESPONSE_FRAME_LENGTH;

    static const QByteArray IMG_FRAME_HEADER;
    static const QByteArray IMG_FRAME_TAIL;
    static const int IMG_FRAME_LENGTH;

    QByteArray CHECKSUM_16;
    QByteArray CHECKSUM_32;

    QByteArray dataSaveTo2048;

    RingBuffer *m_ringBuffer;
    void setRingBuffer(RingBuffer *buffer);

    bool cardNo0IsRs422 = true;
    void GTChoise(bool cardNo0IsRs422Get);


private:

    LVDSCardHelper *card;
    DataTransfer *datatransfer;
    QMutex m_mutex;


signals:

    void updateBarStatusSignal(bool chooseCard, QString errorText);
    void stopThreadRec();

    void RunError(QString msg);
    void onLVDSDataToUi(quint8 channel,QString LVDSData);
    void onRS422DataToUi(quint8 channel,QString RS422Data);
    void onLVDSAnalysisToUi(quint8 channel,QByteArray data);
    void onRS422AnalysisToUi(quint8 channel,QByteArray data);
    void imageSignal(QImage image);


public slots:

    void emitRunError(QString msg);
    void readyReceive(quint8 currentCardNo, quint8 channel, QByteArray data);
};

#endif // LVDSCARDWORKER_H
