#ifndef DATAANALYSISHELPER_H
#define DATAANALYSISHELPER_H

#include <QObject>
#include "framehelper.h"
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include "ringbuffer.h"
#include <QMetaType>
#include "Structs.h"

//struct ImageAttributes{
//    int imgFrameNo = 0; // 图像帧编号
//    QString imgFrameNoString;
//    int totalImgNum = 0; // 总图像帧计数
//    int validImgNum = 0; // 正确图像帧计数
//    int errorImgNum = 0; // 错误图像帧计数，校验和不对
//    int imgWinSize = 0; // 开窗大小
//    int overThreshold = 0; // 超阈值点数量
//    QString timeCode; // 时间码 解析成XXXXX 秒 XXXXX 毫秒
//};

class DataAnalysisHelper : public QObject
{
    Q_OBJECT
public:
    explicit DataAnalysisHelper(QObject *parent = nullptr);

public:
    /// 串口通信接收数据解析函数
    void onDataAnalysisSerial1(); // 对串口1数据进行所需的解析（3M 质心遥测）
    void onDataAnalysisSerial2(); // 对串口2数据进行所需的解析（115200 温度等遥测）
    void processSerial1Frame(QByteArray frame); // 对LVDS板卡数据进行所需的解析（图像拼接）
    void processSerial2Frame(QByteArray frame); // 对LVDS板卡数据进行所需的解析（图像拼接）

    /// 板卡通信接收数据解析函数
    void onDataAnalysisRS422(); // 对422板卡数据进行所需的解析（遥测分析）
    void onDataAnalysisLVDS();  // 抓取数据
    void processRS422Frame(QByteArray frame); // 对LVDS板卡数据进行所需的解析（图像拼接）
    void processLVDSFrame(QByteArray frame); // 对LVDS板卡数据进行所需的解析（图像拼接）


    const int FRAME_SIZE = 2048;// 确定帧长
    const int FRAME_SIZE_TEM = 11;// 确定串口的温度帧帧长11字节
    const int FRAME_SIZE_CENTROID = 30;// 确定串口的质心帧帧长19字节   // 2026.03.12 技物所中高轨适配 19字节变更到30字节
    const int HEADER_SIZE = 2;
    const int frameSizePure = 2027; // 确定有效灰度数据帧长

    QByteArray serialBuffer1;
    QByteArray serialBuffer2;
    QByteArray rs422Buffer;
    QByteArray lvdsBuffer;

    QByteArray lvdsBufferTemp;
    QByteArray lvdsImgDataBuffer;
    bool headFrameExist = false;
    QByteArray imageNo;
    bool imgIsError = false;

//    int totalImgNum = 0; // 总图像帧计数
//    int validImgNum = 0; // 正确图像帧计数
//    int errorImgNum = 0; // 错误图像帧计数，校验和不对
    int imgSize = 0;

    ImageAttributes imgAttrs;
    TemperatureFrameAttributes temFrameAttrs;
    CentroidFrameAttributes centroidFrameAttrs;


    int grayThrehold = 0;
    int peakingThrehold = 0;
    void updataUiSettingsRec(const SettingsUiToSub &settingsUi);

    int tempNum = 0;
    QVector<int> arr;

    FrameHelper *frameHelper;

    void showGrayImage(const QByteArray &singleImgData, int imgSize);

    void setRingBuffer(RingBuffer *buffer);  // 关键函数声明
    RingBuffer *m_ringBuffer;

    void startProcessing() {
        QMutexLocker locker(&m_mutex);
        m_running = true;
    }

    void stopProcessing() {
        QMutexLocker locker(&m_mutex);
        m_running = false;
    }

    void imgToPeaking(bool isImgToPeakingUi, int peakingThresholdUi);


    QVector<QPoint> overThresholdCoords;


    void processAckFrame(const QByteArray &frame);
    void processTelemetryFrame(const QByteArray &frame);

    void getXmlParser(QVector<TMitemQueue> paraQueueVector);
    QVector<TMitemQueue> paraQueueVector;
    ParaListUi paraListUi;
    QVector<ParaListUi> paraListUiList;


    QString applyRule(const QString &rule, double value);

    FrameTM frameTm;

    quint8 h0_xml;
    quint8 h1_xml;
    quint8 t0_xml;
    quint8 t1_xml;
    int lengthHead = 2;
    int lengthTail = 2;
//    void updateFrameRecSetting();

private:
//    FrameHelper *frameHelper;
    volatile bool m_running = false;  // 必须加volatile防止编译器优化
    QMutex m_mutex;  // 保护缓冲区指针的互斥锁

    bool isImgToPeaking = false;
    bool isSaveCoordinate = false;

signals:

    void imageSignal(QImage image);
    void upgradeErrorImgNumUi(const ImageAttributes &attrs);
    /// 推荐用 const &，效率更高，为什么呢？
    void upgradeCentroidUi(const CentroidFrameAttributes &attrs);
    void upgradeTemUi(const TemperatureFrameAttributes &attrs);

    void updateParaListUiSignal(QVector<ParaListUi> paraListUiList);

    void updateFrameCheckSignal(bool isValid);

public slots:
    void updateSaveCoordinate(bool isSaveCoordinateUi);


};

#endif // DATAANALYSISHELPER_H
