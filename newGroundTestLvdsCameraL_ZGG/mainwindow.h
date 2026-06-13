#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include "LVDS_T4R6.h"  // 已替换为新驱动
#include "lvdscardhelper.h"
#include "lvdscardworker.h"
#include "serialportworker.h"
#include <QListWidget>
#include <QStackedWidget>
#include "xmlcommandparser.h"
#include "ringbuffer.h"
#include "framehelper.h"
#include "listwidgethelper.h"
#include <QList>
#include "Structs.h"
#include <QTimer>
#include <QCoreApplication>
#include <QPlainTextEdit>
#include "imagegraphicsview.h"
#include "dialogpara.h"
#include <QStandardItemModel>

class DataTransfer;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    SettingsUiToSub  settingsUiAttrs;

    void addTabItem(QListWidget* listWidget, const QIcon& icon, const QString& text);
    void addStackedPage(QStackedWidget* stackedWidget, const QString& pageName);
    void onTabItemClicked(QListWidgetItem* item);
    void onTabItemClicked_2(QListWidgetItem* item);
    void updateTabSelection(int selectedIndex);
    void updateTabSelection_2(int selectedIndex);


    void refreshSerialPorts();
    void serialOpenClose(bool serialChoose);
    void updatePortState(bool serialChoose, bool isOpen);
    void updatePortPara();
    void onSerialDataReceived();
    void dataReceivedRS422(QString hexString);
    void dataReceivedLVDS(QString hexString);
    void cardOpenBtn(bool chooseCard);
    void qmessageBoxSet(QString errorString);
    std::tuple<quint8, quint8> getUiCardSet();

    void addCMDList(bool insertOrAdd);
    void onListWidgetContextMenuRequested(const QPoint &pos);
    void sendCMD(int sendIndex, bool directOrList);
    void delCMDList();
    void clearCMDList();


    bool isRecv = true;

    bool isSaveDataSerial1 = false; // 是否需要保存Serial1数据
    bool isSaveDataSerial2 = false; // 是否需要保存Serial2数据
    QString fileNameSerial1;
    QString fileNameSerial2;

    QString saveDirSerial1Txt ;
    QString saveDirSerial2Txt ;
    QString saveDirSerial1Bin ;
    QString saveDirSerial2Bin ;

    bool isSaveDataRs422 = false; // 是否需要保存422数据
    bool isSaveDataLVDS = false; // 是否需要保存LVDS数据
    QString fileNameRS422;
    QString fileNameLVDS;

    QString saveDirRS422Txt ;
    QString saveDirLVDSTxt ;
    QString saveDirRS422Bin ;
    QString saveDirLVDSBin ;

    QString saveDirLVDSImgSingle ;
    QString saveDirLVDSImgSpan ;

    QString saveDirTM;
    QString saveDirTMAuto;
    QString saveFileNameTm;
    QString saveFileNameTmAuto;
    bool isSaveTMFile = false;
    QTimer *m_saveTimer; // 保存遥测数据的指针

    bool isSaveImgLVDS = false; // 是否需要保存图像
    void saveImgSingle();
    void saveImgSpan();
    QString LVDSImgSpanName;

    int m_SendRow  = -1; // 当前要发送的指令行索引
    QVector<int> m_timeDelays; // 存放时间戳


    void showImage(QImage image);
    static QSize lastSize; // 记录上一次图像尺寸


    void readXML(QString xmlFiles, bool setCurrentToNew);
    void readXML2(QString xmlFiles);
    void writeXML(QString xmlName);
    QList<Command> commandUi;

    QList<QDomElement> docNodeInitList;
    QList<QDomElement> docNodeList;

    QList<QString> commandList = {};



    void saveDocNodeListToXML(const QString &filePath, QList<QDomElement> &docNodeList);
    void updateCommandAttribute(QDomElement &commandElem,
                                const QString &attrName,
                                const QString &newValue);

    ImageGraphicsView *view;
    QGraphicsPixmapItem *pixmapItem;
    QVector<QPoint> overThresholdCoords;

    void readTmXML(QString xmlFiles);
    void addRowToInterestTable(int row);
    void removeRowFromInterestTable(int row);

    QStandardItemModel *modelMain;
    QStandardItemModel *modelInterest;

    void init();
    QVector<int> rowSort;
    int paraFrameCount = 0;
    int validFrameCount = 0;
    int invalidFrameCount = 0;

    void on_stopSaveButton_clicked();
private:
    Ui::MainWindow *ui;



    FrameHelper *frameHelper;
//    ListWidgetHelper *listWidgetHelper;

    XMLCommandParser *xmlcommandparser;// xml指令剖析器
//    QString xmlPath = "XmlFiles/CMD/cmd_Camera.xml"; // 软件初始化时加载的默认xml文件——红外相机
//    QString xmlPathVisibleLight = "XmlFiles/CMD/cmd_Camera_Visible_Light.xml"; // 软件初始化时加载的默认xml文件——可见光相机
    QString basePath = QCoreApplication::applicationDirPath(); // exe 所在目录
//    QString xmlPath = basePath + "/XmlFiles/CMD/cmd_Camera.xml";
//    QString xmlPathVisibleLight = basePath + "/XmlFiles/CMD/cmd_Camera_Visible_Light.xml";
//    QString xmlTmPath = basePath + "/XmlFiles/TM/tm.xml";
//    QString CMDXmlFilesPath = basePath + "/XmlFiles/CMD/";
//    QString TMXmlFilesPath = basePath + "/XmlFiles/TM/";
    QString configPath = basePath + "/ConfigFiles/";
    QString xmlTmPath = basePath + "/XmlFiles/TM/";
    QString xmlTmPath_2 = basePath + "/XmlFiles/TM/";
    QString CMDXmlFilesPath = basePath + "/XmlFiles/CMD/";

    DataTransfer *dataTransfer;  // 添加 DataTransfer 对象
    SerialPortWorker *serialPortWorker1; // 串口管理对象1
    SerialPortWorker *serialPortWorker2; // 串口管理对象2
    QThread *t3;
    QThread *t4;

    // 创建帧检查对象
    DataAnalysisHelper *dataAnalysisHelper1;
    DataAnalysisHelper *dataAnalysisHelper2;
    DataAnalysisHelper *dataAnalysisHelperRS422;
    DataAnalysisHelper *dataAnalysisHelperLVDS;

    QThread *t_dataAnalysis1; // 创建串口1数据处理线程
    QThread *t_dataAnalysis2; // 创建串口1数据处理线程
    QThread *t_dataAnalysisRS422; // 创建RS422数据处理线程
    QThread *t_dataAnalysisLVDS; // 创建LVDS数据处理线程

    RingBuffer *ringBuffer1;
    RingBuffer *ringBuffer2;
    RingBuffer *ringBufferRS422;
    RingBuffer *ringBufferLVDS;

    int MAX_LOG_LINES = 50;



    lvdsCardWorker *cardWorker1; //板卡管理对象
    lvdsCardWorker *cardWorker2; //板卡管理对象
    QThread *t1;
    QThread *t2;

    void statusBarShow(bool chooseCard,QString showString);
    void statusBarShowSerial(bool chooseSerial,QString showString);
    void updatePlainText(bool serialChoose, QString textToShowDirect);
    void updateCheckboxesForTab(const QString &tabName);

    QStringList pendingData_LVDS;  // 数据缓冲区
    QStringList pendingData_RS422;  // 数据缓冲区
    QTimer updateTimer_LVDS;       // 定时器
    QTimer updateTimer_RS422;   // 定时器
    QStringList pendingData_Serial1;  // 数据缓冲区
    QStringList pendingData_Serial2;  // 数据缓冲区
    QTimer updateTimer_Serial1;       // 定时器
    QTimer updateTimer_Serial2;       // 定时器

    DialogPara *dialogPara;

signals:



    /// 串口信号
    void initSerialSignal(QString portName,int baudRate, int dataBit, int parity, int stopBit); // 初始化串口1
    void openCloseSignal(); // 打开关闭串口1
    void writeDataSignal(QByteArray byteDataSend); // 写数据到串口1
    void initSerialSignal_2(QString portName,int baudRate, int dataBit, int parity, int stopBit); // 初始化串口2
    void openCloseSignal_2(); // 打开关闭串口2
    void writeDataSignal_2(QByteArray byteDataSend); // 写数据到串口2

    void closeSerialSignal();
    void closeSerialSignal_2();
    void imgToPeakingSignal(bool isImgToPeaking, int peakingThreshold);


    /// 板卡信号
    void cardNoConfigSignal(bool no0IsRs422);

    void hexStringDataSiganl(QString hexStringData);

    void cardSetSignal(quint8 cardNo, quint8 channelNo, quint8 channelNoRec);
    void lvdsStartStopSignal(bool isStart);

    void setChannelNumSignal(bool chooseCard, quint8 channelNum);
    void updateIsT1StartSignal(bool chooseCard, bool isT1Start);

    void startLVDSSignal(bool chooseCard); // 使能
    void stopLVDSSignal(bool chooseCard); // 去使能
    void resetCardSignal(bool chooseCard); //复位
    void clearFIFOSignal(bool chooseCard); // 清空缓存
    void openCardSignal(bool chooseCard); // 打开板卡
    void closeCardSignal(bool chooseCard); // 关闭板卡
    void setChannelFrame(bool chooseCard); // 通道帧配置
    // void setChannelPara(bool chooseCard, bool isRecv,quint8 channel,ST_LVDS_CFG stCfg); // 通道参数配置 - 新驱动不支持

    void updateWorkerCardNum1(bool rss422No, bool lvdsNo);
    void updateWorkerCardNum2(bool rss422No, bool lvdsNo);

    void updateSaveCoordinateSignal(bool checked);


private slots:
    void handleRS422Data(quint8 channel, QString dataString);
    void handleLVDSData(quint8 channel, QString dataString);

    void runError(QString errorString);
    void updateStatusBar(bool chooseCard,QString errorText);
    /*
    void startCommandSequence();
    void sendCommandWithDelay();
    */

};
#endif // MAINWINDOW_H
