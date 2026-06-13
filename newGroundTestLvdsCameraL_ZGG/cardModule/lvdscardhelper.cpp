/**
 * @file      lvdscardhelper.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "lvdscardhelper.h"
#include "frameassemble.h"
#include <QDebug>

//#define LVDS_CARD_NO    0       //板卡号 根据自己实际定义
#define RCV_MAX_ST_CNT  32      //最大接收结构体个数

// 全局库状态（所有对象共享）
static bool s_libInitialized = false;   // 库是否已初始化
static int s_cardCount = 0;              // 可用板卡数量
static int s_openCardCount = 0;          // 当前打开的板卡数量

LVDSCardHelper::LVDSCardHelper(QObject *parent)
    : QObject{parent}
    , m_isLibInit(false)
    , m_isCardOpen(false)
    , m_isReceiving(false)
{

}


LVDSCardHelper::~LVDSCardHelper() {
    // 清理
}

// 发送数据
// 新驱动说明：只有 LVDS_T4R6_TX_Enable() 发送使能函数，没有发送数据函数
// 需要查看 API 文档确认发送数据的正确方式
quint32 LVDSCardHelper::sendData(quint8 channel, BYTE* data, size_t dataSize)
{
    qDebug() << "（helper）板卡发送数据：" << QByteArray(reinterpret_cast<const char*>(data), dataSize).toHex(' ').toUpper();

    // 新驱动暂无发送数据接口，待确认
    // LVDS_T4R6_TX_Enable(currentCardNo, channel, 1);  // 发送使能
    qDebug() << "sendData：新驱动发送数据接口待确认！";
    return 0;
}

// 开始执行板卡接收
// 新驱动说明：无 LVDS_IsOpen() 函数，使用 m_isCardOpen 成员变量判断
bool LVDSCardHelper::startReceive()
{
    if(!m_isCardOpen){
        emit RunError("startLVDS：板卡未打开！");
        return false;
    }
    else{
        isExist = false;
        recieveStart();
        return true;
    }
}


// 获取板卡数量
// 新驱动说明：LVDS_T4R6_LibInit() 返回可用板卡数量
int LVDSCardHelper::getLVDSCardsCount()
{
    return m_cardCount;
}

//发送或接收通道帧配置
// 新驱动说明：使用 LVDS_T4R6_Set_FrameSize() 设置帧大小
// 新驱动不支持帧头、帧尾、帧间隔配置
bool LVDSCardHelper::configLVDSCardFrame(bool isRecv,quint8 channel){
    qDebug()<<"LVDSCardHelper configLVDSCardFrame channel"<<channel;

    // 新驱动只支持设置帧大小
    // LVDS_T4R6_Set_FrameSize(UINT8 uCardId, UINT32 uSize)
    UINT32 frameSize = 0x1000;  // 4096 字节
    return LVDS_T4R6_Set_FrameSize(currentCardNo, frameSize);
}

// 打开板卡
// 新驱动说明：
// 1. 需要先调用 LVDS_T4R6_LibInit() 初始化库（全局只执行一次）
// 2. 使用 LVDS_T4R6_Open(UINT8 uCardId) 打开板卡
// 3. 无 LVDS_IsOpen() 函数，使用 m_isCardOpen 成员变量维护状态
bool LVDSCardHelper::OpenLVDSCard()
{
    qDebug()<<"OpenLvdscard :"<<currentCardNo;
    qDebug()<<"currentChannelNo :"<<currentChannelNo;

    // 库初始化（全局只执行一次）
    if (!s_libInitialized)
    {
        UINT32 ret = LVDS_T4R6_LibInit();
        if (ret > 0)
        {
            s_libInitialized = true;
            s_cardCount = ret;
            qDebug() << "LVDS_T4R6_LibInit 成功，检测到" << ret << "块板卡";
        }
        else
        {
            emit RunError("OpenLVDSCard：驱动库初始化失败，未检测到板卡！");
            return false;
        }
    }

    // 设置当前对象的板卡数量
    m_cardCount = s_cardCount;
    m_isLibInit = true;

    // 检查请求的板卡编号是否有效
    if (currentCardNo >= s_cardCount)
    {
        qDebug() << "请求的板卡编号" << currentCardNo << "超出范围，检测到" << s_cardCount << "块板卡";
        emit RunError(QString("板卡编号无效：请求编号%1，但只检测到%2块板卡").arg(currentCardNo).arg(s_cardCount));
        return false;
    }

    // 打开板卡
    if (!m_isCardOpen)
    {
        m_isCardOpen = LVDS_T4R6_Open(currentCardNo);
        if (!m_isCardOpen)
        {
            emit RunError("OpenLVDSCard：板卡打开失败！");
        }
        else
        {
            s_openCardCount++;  // 增加打开计数
        }
    }
    return m_isCardOpen;
}

// 关闭板卡
// 新驱动说明：
// 1. 使用 LVDS_T4R6_Close(UINT8 uCardId) 关闭板卡
// 2. 库卸载在程序退出时统一执行（调用 UninitLibrary()）
bool LVDSCardHelper::CloseLVDSCard()
{
    if (m_isCardOpen)
    {
        LVDS_T4R6_Close(currentCardNo);
        m_isCardOpen = false;
        s_openCardCount--;  // 减少打开计数
    }

    return true;
}

// 重置板卡
// 新驱动说明：使用 LVDS_T4R6_REST(UINT8 uCardId) 复位板卡
bool LVDSCardHelper::ResetLVDSCard()
{
    if (m_isCardOpen)
    {
        return LVDS_T4R6_REST(currentCardNo);
    }
    return false;
}

// 清空缓存
// 新驱动说明：无 LVDS_ClrFIFO() 函数，可能不需要手动清空 FIFO
bool LVDSCardHelper::ClearLVDSCardBuff()
{
    // 新驱动无清空 FIFO 接口
    // 可能由硬件自动管理，或通过复位实现
    return true;
}

// 启动/停止板卡
// 新驱动说明：使用 LVDS_T4R6_RX_Enable(UINT8 uCardId, UINT8 uEnable) 接收使能
// uEnable: 0=关闭接收, 1=开始接收
bool LVDSCardHelper::StartLVDSCard(bool isCardStart)
{
    if (!m_isCardOpen)
    {
        if (isCardStart)
        {
            emit RunError("StartLVDSCard：板卡未打开");
        }
        return false;
    }

    UINT8 enable = isCardStart ? 1 : 0;
    bool result = LVDS_T4R6_RX_Enable(currentCardNo, enable);

    if (result)
    {
        m_isReceiving = isCardStart;
    }

    return result;
}

// 获取板卡打开状态
// 新驱动说明：无 LVDS_IsOpen() 函数，使用 m_isCardOpen 成员变量
bool LVDSCardHelper::getLVDSCardOpenStatus()
{
    return m_isCardOpen;
}

// 获取板卡启动状态
// 新驱动说明：无 LVDS_GetStart() 函数，使用 m_isReceiving 成员变量
bool LVDSCardHelper::getLVDSCardStartStatus()
{
    return m_isReceiving;
}

// 设置当前板卡编号
void LVDSCardHelper::setCurrentCardNo(quint8 cardNo)
{
    // 允许在库初始化前设置卡号，OpenLVDSCard时会自动初始化库并获取实际卡数
    // 在库初始化前，m_cardCount为0，无法验证卡号有效性
    // 但仍需检查合理范围（假设最多2块卡：编号0和1）
    if (cardNo >= 2)
    {
        qDebug() << "板卡编号超出范围，最大支持2块卡(编号0-1)，输入编号:" << cardNo;
        return;
    }
    currentCardNo = cardNo;
}

void LVDSCardHelper::setCurrentUseChannel(quint8 channel)
{
    currentChannelNo = channel;
}


// 数据接收主循环
// 新驱动说明：
// 1. LVDS_T4R6_RX_Enable(UINT8 uCardId, UINT8 uEnable) - 启动/停止接收
// 2. LVDS_T4R6_RX_DataCnt(UINT8 uCardId, UINT32 *pDataCnt) - 获取数据字节数
// 3. LVDS_T4R6_RX_Data(UINT8 uCardId, UINT8 *pData, UINT32 uDataCnt) - 读取数据
// 注意：新驱动返回原始字节数组，没有通道号信息
void LVDSCardHelper::recieveStart()
{
    // 注意：LVDS_T4R6_RX_Enable 已在 StartLVDSCard() 中调用，此处不再重复调用
    // 如果未处于接收状态，说明启动失败
    if (!m_isReceiving)
    {
        qDebug() << "recieveStart：接收未启动！";
        emit RunError("recieveStart：接收未启动！");
        return;
    }

    qDebug() << "数据接收循环开始！";

    UINT32 dataCnt = 0;
    const UINT32 MAX_BUFFER_SIZE = 32 * 1024;  // 32KB 缓冲区

    while (isT1Start && !isExist)
    {
        // 获取接收数据计数（字节数）
        if (!LVDS_T4R6_RX_DataCnt(currentCardNo, &dataCnt))
        {
            QThread::msleep(1);
            continue;
        }

        if (dataCnt > 0)
        {
            // 限制单次读取大小
            UINT32 readSize = dataCnt > MAX_BUFFER_SIZE ? MAX_BUFFER_SIZE : dataCnt;

            UINT8* buffer = new UINT8[readSize];

            // 读取数据
            if (LVDS_T4R6_RX_Data(currentCardNo, buffer, readSize))
            {
                // 发送数据信号
                QByteArray data(reinterpret_cast<const char*>(buffer), readSize);
                emit onDataReady(currentCardNo, 0, data.toHex());  // 通道号暂时设为 0

                qDebug() << "接收数据" << readSize << "字节";
            }

            delete[] buffer;
        }
        else
        {
            QThread::msleep(1);
        }
    }

    // 停止接收
    LVDS_T4R6_RX_Enable(currentCardNo, 0);
    m_isReceiving = false;
}

// 全局库卸载函数（程序退出时调用）
void LVDSCardHelper::UninitLibrary()
{
    if (s_libInitialized && s_openCardCount == 0)
    {
        LVDS_T4R6_LibUninit();
        s_libInitialized = false;
        s_cardCount = 0;
        qDebug() << "LVDS_T4R6_LibUninit 库已卸载";
    }
    else if (s_openCardCount > 0)
    {
        qDebug() << "无法卸载库，还有" << s_openCardCount << "块板卡未关闭";
    }
}

