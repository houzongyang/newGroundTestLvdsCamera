#ifndef LVDSCARDHELPER_H
#define LVDSCARDHELPER_H

#include <QThread>
#include <QObject>
#include "LVDS_T4R6.h"
#include <QDebug>

// 新驱动没有定义 BYTE，本地定义
typedef unsigned char BYTE;

class LVDSCardHelper : public QObject
{
    Q_OBJECT

public:
    enum CardType{LVDS_CARD,RS422_CARD,CAN_CARD};
    explicit LVDSCardHelper(QObject *parent = nullptr);
    ~LVDSCardHelper();

public:

    // void uiCardInit(const std::tuple<UCHAR, BYTE> &cardSet);  // 新驱动不支持


    quint8 currentCardNo = 200;
    quint8 currentChannelNo = 200;


public:

    // static LVDSCardHelper& Instance();  // 单例模式未使用

    bool startReceive();

    int getLVDSCardsCount();
    void setCurrentCardNo(quint8 cardNo);
    // void setCardType(CardType type);  // 新驱动不支持
    // CardType getCardType();  // 新驱动不支持
    // void setChannelAndBaudRate(QList<QPair<quint8,quint32>> channelInfoList);  // 新驱动不支持
    void setCurrentUseChannel(quint8 channel);
    // void setEnable(bool enable);  // 新驱动不支持
    bool OpenLVDSCard();
    bool CloseLVDSCard();
    bool ResetLVDSCard();
    bool ClearLVDSCardBuff();
    bool StartLVDSCard(bool isStart);
    bool getLVDSCardOpenStatus();
    bool getLVDSCardStartStatus();
    // bool configCardChannel(quint8 currentCardNo,bool isRecv,quint8 channel,ST_LVDS_CFG stCfg);  // 新驱动不支持通道配置
    bool configLVDSCardFrame(bool isRecv,quint8 channel);
    // void initCard();  // 新驱动不支持
    // void uninitCard();  // 新驱动不支持
    // bool checkLVDSCard();  // 新驱动不支持
    bool isT1Start = false;
    bool isCardStart = false;
    bool isQueryStart = false;
    quint32 sendData(quint8 channel, BYTE* data, size_t dataSize);

    // 全局库卸载函数（程序退出时调用）
    static void UninitLibrary();


private:
    bool isExist = false;  // 用于退出接收循环

    // 新增：用于替代新驱动没有的状态查询函数
    bool m_isLibInit = false;       // 库是否初始化
    bool m_isCardOpen = false;      // 板卡是否打开
    bool m_isReceiving = false;     // 是否正在接收
    int m_cardCount = 0;            // 可用板卡数量（由 LibInit 返回）

    void recieveStart();


signals:
    void RunError(QString msg);
    void onDataReady(quint8 currentCardNo, quint8 channel,QByteArray data);


};

#endif // LVDSCARDHELPER_H
