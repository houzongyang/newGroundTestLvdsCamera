/**
 * @file      mainwindow.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "mainwindow.h"
#include "datatransfer.h"
#include "ui_mainwindow.h"
// #include "LVDS_DLL.h"  // 已替换为新驱动，以下常量本地定义
#include <QDebug>

// 本地定义旧驱动常量和类型（新驱动不支持通道配置，但UI仍需要这些值）
namespace {
    // 类型定义（旧驱动有，新驱动没有）
    typedef unsigned int DWORD;
    typedef unsigned char BYTE;

    // 波特率常量
    constexpr int LVDS_BAUD_1200   = 1200;
    constexpr int LVDS_BAUD_2400   = 2400;
    constexpr int LVDS_BAUD_4800   = 4800;
    constexpr int LVDS_BAUD_9600   = 9600;
    constexpr int LVDS_BAUD_19200  = 19200;
    constexpr int LVDS_BAUD_38400  = 38400;
    constexpr int LVDS_BAUD_57600  = 57600;
    constexpr int LVDS_BAUD_115200 = 115200;
    constexpr int LVDS_BAUD_128000 = 128000;
    constexpr int LVDS_BAUD_256000 = 256000;

    // 数据位常量
    constexpr int LVDS_DATABITS_1 = 0;
    constexpr int LVDS_DATABITS_2 = 1;
    constexpr int LVDS_DATABITS_3 = 2;
    constexpr int LVDS_DATABITS_4 = 3;
    constexpr int LVDS_DATABITS_5 = 4;
    constexpr int LVDS_DATABITS_6 = 5;
    constexpr int LVDS_DATABITS_7 = 6;
    constexpr int LVDS_DATABITS_8 = 7;

    // 校验位常量
    constexpr int LVDS_PARITY_NO   = 0;
    constexpr int LVDS_PARITY_ODD  = 1;
    constexpr int LVDS_PARITY_EVEN = 2;

    // 停止位常量
    constexpr int LVDS_STOPBITS_10 = 0;
    constexpr int LVDS_STOPBITS_15 = 1;
    constexpr int LVDS_STOPBITS_20 = 2;

    // 通道常量
    constexpr int LVDS_DATA_CH1 = 0;
    constexpr int LVDS_DATA_CH2 = 1;
}
#include <QtSerialPort>
#include <QMessageBox>
#include "lvdscardworker.h"
#include "TabItem.h"
#include <QGraphicsPixmapItem>
#include <QFileDialog>
//#include "imagegraphicsview.h"
#include "tabitem.h"
#include "dataanalysishelper.h"
#include "dialogpara.h"
#include <QStandardItemModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QByteArray frameData;
    frameData.append(0xAA);
    frameData.append(0x11);

    quint16 SEL_Current =
                 (static_cast<quint16>((static_cast<quint8>(frameData[0]) & 0x0F)<<8)) |
                 (static_cast<quint8>(static_cast<quint8>(frameData[1])))
            ;

    ui->setupUi(this);

    ui->tableWidget_cmd_immediately->setColumnCount(4); // 设置3列（指令序列、时间戳、备注）
    ui->tableWidget_cmd_immediately->setHorizontalHeaderLabels({
        "时间戳（秒）",    // 列0
        "名称",// 列1
        "源码"  ,       // 列2
        "备注"         // 列3
    });

    ui->tableWidget_cmd_immediately->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    ui->tableWidget_cmd_immediately->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->tableWidget_cmd_immediately->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
    ui->tableWidget_cmd_immediately->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Interactive);
    ui->tableWidget_cmd_immediately->horizontalHeader()->setSectionsMovable(true);

    dataTransfer = new DataTransfer(this);
    frameHelper = new FrameHelper(this);

    setWindowTitle("地检主控程序");

    QIcon iconApp(":/Icon/game_hat_mario_retro_super_video_icon_183171.png");
    setWindowIcon(iconApp);

    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    QLabel *infoLabel = new QLabel(this);
    infoLabel->setText("milurx@163.com | XuXiaohan | Version ZGG.1.0.0.260318 | 2026.03.21");
    infoLabel->setFont(QFont("Times New Roman", 12));
    infoLabel->setStyleSheet("color: gray;");
    statusBar->addPermanentWidget(infoLabel);

     addTabItem(ui->listWidget, QIcon(":/Icon/3592835-general-hierachy-map-office-site-structure_107768.png"), "接口设置");
     addTabItem(ui->listWidget, QIcon(":/Icon/3592869-compose-create-edit-edit-file-office-pencil-writing-creative_107746.png"), "指令发送");
     addTabItem(ui->listWidget, QIcon(":/Icon/3592864-general-graph-increase-office-rise-statistics-success_107790.png"), "遥测显示");
     addTabItem(ui->listWidget, QIcon(":/Icon/3592837-camera-image-photo-photography-shot_107774.png"), "图像显示");

     int curIndex = ui->stackedWidget->currentIndex();
     ui->listWidget->setCurrentRow(curIndex);

     addStackedPage(ui->stackedWidget, "接口设置页面");
     addStackedPage(ui->stackedWidget, "指令发送页面");
     addStackedPage(ui->stackedWidget, "遥测显示页面");
     addStackedPage(ui->stackedWidget, "图像显示页面");

    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::onTabItemClicked);

    ui->listWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(ui->listWidget_2, &QListWidget::itemClicked, this, &MainWindow::onTabItemClicked_2);
    ui->listWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget_2, &QListWidget::customContextMenuRequested,
            this, &MainWindow::onListWidgetContextMenuRequested);

    QIntValidator *intValidator = new QIntValidator(this);
    intValidator->setBottom(0);
    intValidator->setTop(255);
    ui->lineEdit_grayThre_2->setValidator(intValidator);

    ui->comboBox_cardCom->addItem("擦除指令");
    ui->comboBox_cardCom->addItem("开始重构");
    ui->comboBox_cardCom->addItem("重载指令");
    ui->comboBox_cardCom->addItem("更改flash寄存器");
    ui->comboBox_cardCom->setCurrentIndex(0);

    xmlcommandparser = new XMLCommandParser(this);
    connect(xmlcommandparser,&XMLCommandParser::updateUiCurComShowSignal,this,[=](QString text){
        commandList.append(text);
    });

    saveDirSerial1Txt = QCoreApplication::applicationDirPath() + "/DataCapture/Serial1/txt/";
    saveDirSerial1Bin = QCoreApplication::applicationDirPath() + "/DataCapture/Serial1/bin/";
    QDir dirSerial1Txt(saveDirSerial1Txt);
    if (!dirSerial1Txt.exists()) {
        if (!dirSerial1Txt.mkpath(".")) {  // 创建多级目录
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirSerial1Txt);
            return;
        }
    }
    QDir dirSerial1Bin(saveDirSerial1Bin);
    if (!dirSerial1Bin.exists()) {
        if (!dirSerial1Bin.mkpath(".")) {  // 创建多级目录
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirSerial1Bin);
            return;
        }
    }

    /// Serial2
    saveDirSerial2Txt = QCoreApplication::applicationDirPath() + "/DataCapture/Serial2/txt/";
    saveDirSerial2Bin = QCoreApplication::applicationDirPath() + "/DataCapture/Serial2/bin/";
    QDir dirSerial2Txt(saveDirSerial2Txt);
    if (!dirSerial2Txt.exists()) {
        if (!dirSerial2Txt.mkpath(".")) {  // 创建多级目录
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirSerial2Txt);
            return;
        }
    }
    QDir dirSerial2Bin(saveDirSerial2Bin);
    if (!dirSerial2Bin.exists()) {
        if (!dirSerial2Bin.mkpath(".")) {  // 创建多级目录
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirSerial2Bin);
            return;
        }
    }

    // 控件格式设置
    ui->pushButton_serialOpenClose->setCheckable(false);
    ui->pushButton_serialOpenClose_2->setCheckable(false);
    ui->pushButton_saveDataSerial->setCheckable(true);
    ui->pushButton_saveDataSerial_2->setCheckable(true);


    ui->graphicsView->setScene(new QGraphicsScene(this));

    // 初始化波特率选项
    QList<qint32> baudRates = QSerialPortInfo::standardBaudRates();

    int index115200 = baudRates.indexOf(115200);

    foreach (qint32 baud, baudRates) {
        ui->comboBox_baudRate->addItem(QString::number(baud), baud);
        ui->comboBox_baudRate_2->addItem(QString::number(baud), baud);
    }

    ui->comboBox_baudRate->addItem("2000000",2000000);
    ui->comboBox_baudRate->addItem("3000000",3000000);
    ui->comboBox_baudRate->addItem("48000000",48000000);
    int index3M = ui->comboBox_baudRate->findData(3000000);
    ui->comboBox_baudRate->setCurrentIndex(index3M);
    ui->comboBox_baudRate_2->addItem("2000000",2000000);
    ui->comboBox_baudRate_2->addItem("3000000",3000000);
    ui->comboBox_baudRate_2->addItem("48000000",48000000);
    ui->comboBox_baudRate_2->setCurrentIndex(index115200);

    ui->comboBox_dataBit->addItem("5", QSerialPort::Data5);
    ui->comboBox_dataBit->addItem("6", QSerialPort::Data6);
    ui->comboBox_dataBit->addItem("7", QSerialPort::Data7);
    ui->comboBox_dataBit->addItem("8", QSerialPort::Data8);
    ui->comboBox_dataBit->setCurrentIndex(3);
    ui->comboBox_dataBit_2->addItem("5", QSerialPort::Data5);
    ui->comboBox_dataBit_2->addItem("6", QSerialPort::Data6);
    ui->comboBox_dataBit_2->addItem("7", QSerialPort::Data7);
    ui->comboBox_dataBit_2->addItem("8", QSerialPort::Data8);
    ui->comboBox_dataBit_2->setCurrentIndex(3);

    ui->comboBox_parity->addItem("None", QSerialPort::NoParity);
    ui->comboBox_parity->addItem("Even", QSerialPort::EvenParity);
    ui->comboBox_parity->addItem("Odd", QSerialPort::OddParity);
    ui->comboBox_parity->addItem("Mark", QSerialPort::MarkParity);
    ui->comboBox_parity->addItem("Space", QSerialPort::SpaceParity);
    ui->comboBox_parity->setCurrentIndex(2);
    ui->comboBox_parity_2->addItem("None", QSerialPort::NoParity);
    ui->comboBox_parity_2->addItem("Even", QSerialPort::EvenParity);
    ui->comboBox_parity_2->addItem("Odd", QSerialPort::OddParity);
    ui->comboBox_parity_2->addItem("Mark", QSerialPort::MarkParity);
    ui->comboBox_parity_2->addItem("Space", QSerialPort::SpaceParity);
    ui->comboBox_parity_2->setCurrentIndex(2);

    ui->comboBox_stopBits->addItem("1", QSerialPort::OneStop);
    ui->comboBox_stopBits->addItem("2", QSerialPort::TwoStop);
    ui->comboBox_stopBits->setCurrentIndex(1);
    ui->comboBox_stopBits_2->addItem("1", QSerialPort::OneStop);
    ui->comboBox_stopBits_2->addItem("2", QSerialPort::TwoStop);
    ui->comboBox_stopBits_2->setCurrentIndex(1);

    refreshSerialPorts();

    serialPortWorker1 = new SerialPortWorker();
    serialPortWorker2 = new SerialPortWorker();

    dataAnalysisHelper1 = new DataAnalysisHelper();
    dataAnalysisHelper2 = new DataAnalysisHelper();

    ringBuffer1  = new RingBuffer(10 * 1024 * 1024); // 共享环形缓冲区对象：10MB
    ringBuffer2  = new RingBuffer(10 * 1024 * 1024); // 共享环形缓冲区对象：10MB
    ringBufferRS422  = new RingBuffer(10 * 1024 * 1024); // 共享环形缓冲区对象：10MB
    ringBufferLVDS  = new RingBuffer(10 * 1024 * 1024); // 共享环形缓冲区对象：10MB

    serialPortWorker1->setRingBuffer(ringBuffer1);
    serialPortWorker2->setRingBuffer(ringBuffer2);
    dataAnalysisHelper1->setRingBuffer(ringBuffer1);
    dataAnalysisHelper2->setRingBuffer(ringBuffer2);

    t_dataAnalysis1 = new QThread(this);
    t_dataAnalysis2 = new QThread(this);
    dataAnalysisHelper1->moveToThread(t_dataAnalysis1);
    dataAnalysisHelper2->moveToThread(t_dataAnalysis2);

    connect(t_dataAnalysis1,&QThread::started,dataAnalysisHelper1,&DataAnalysisHelper::onDataAnalysisSerial1);
    connect(t_dataAnalysis2,&QThread::started,dataAnalysisHelper2,&DataAnalysisHelper::onDataAnalysisRS422);
    connect(t_dataAnalysis2,&QThread::started,dataAnalysisHelper2,&DataAnalysisHelper::onDataAnalysisSerial2);

    t_dataAnalysis1->start();
    dataAnalysisHelper1->startProcessing();
    t_dataAnalysis2->start();
    dataAnalysisHelper2->startProcessing();


    t3 = new QThread(this);
    t4 = new QThread(this);

    serialPortWorker1->moveToThread(t3);
    serialPortWorker2->moveToThread(t4);
    t3->start();
    t4->start();

    connect(this,&MainWindow::initSerialSignal,this,[=](QString portName,int baudRate, int dataBit, int parity, int stopBit){
        serialPortWorker1->initSerial(portName, baudRate, dataBit, parity, stopBit);
    });
    connect(this,&MainWindow::initSerialSignal_2,this,[=](QString portName,int baudRate, int dataBit, int parity, int stopBit){
        serialPortWorker2->initSerial(portName, baudRate, dataBit, parity, stopBit);
    });


    connect(this,&MainWindow::openCloseSignal,serialPortWorker1,&SerialPortWorker::openCloseSerial);
    connect(this,&MainWindow::openCloseSignal_2,serialPortWorker2,&SerialPortWorker::openCloseSerial);

    connect(ui->pushButton_serialOpenClose,&QPushButton::clicked,this,[=](){
        serialOpenClose(true);
    });
    connect(ui->pushButton_serialOpenClose_2,&QPushButton::clicked,this,[=](){
        serialOpenClose(false);
    });

    connect(serialPortWorker1,&SerialPortWorker::updatePortStateSignal,this,[=](bool portStatus){
        updatePortState(true, portStatus);
    });
    connect(serialPortWorker2,&SerialPortWorker::updatePortStateSignal,this,[=](bool portStatus){
        updatePortState(false, portStatus);
    });

    connect(ui->pushButton_clearSend_serial,&QPushButton::clicked,ui->plainTextEdit_send_serial,&QPlainTextEdit::clear);
    connect(ui->pushButton_clearReceive_serial,&QPushButton::clicked,ui->plainTextEdit_receive_serial,&QPlainTextEdit::clear);
    connect(ui->pushButton_clearSend_serial_2,&QPushButton::clicked,ui->plainTextEdit_send_serial_2,&QPlainTextEdit::clear);
    connect(ui->pushButton_clearReceive_serial_2,&QPushButton::clicked,ui->plainTextEdit_receive_serial_2,&QPlainTextEdit::clear);

    connect(this,&MainWindow::closeSerialSignal,serialPortWorker1,&SerialPortWorker::closeSerial);
    connect(this,&MainWindow::closeSerialSignal_2,serialPortWorker2,&SerialPortWorker::closeSerial);
    connect(ui->comboBox_serial,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose->text() == "关闭串口"){
            emit closeSerialSignal();
            serialOpenClose(true);
        }
    });
    connect(ui->comboBox_baudRate,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose->text() == "关闭串口"){
            emit closeSerialSignal();
            serialOpenClose(true);
        }
    });
    connect(ui->comboBox_dataBit,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose->text() == "关闭串口"){
            emit closeSerialSignal();
            serialOpenClose(true);
        }
    });
    connect(ui->comboBox_parity,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose->text() == "关闭串口"){
            emit closeSerialSignal();
            serialOpenClose(true);
        }
    });
    connect(ui->comboBox_stopBits,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose->text() == "关闭串口"){
            emit closeSerialSignal();
            serialOpenClose(true);
        }
    });
    connect(ui->comboBox_serial_2,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose_2->text() == "关闭串口"){
            emit closeSerialSignal_2();
            serialOpenClose(false);
        }
    });
    connect(ui->comboBox_baudRate_2,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose_2->text() == "关闭串口"){
            emit closeSerialSignal_2();
            serialOpenClose(false);
        }
    });
    connect(ui->comboBox_dataBit_2,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose_2->text() == "关闭串口"){
            emit closeSerialSignal_2();
            serialOpenClose(false);
        }
    });
    connect(ui->comboBox_parity_2,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose_2->text() == "关闭串口"){
            emit closeSerialSignal_2();
            serialOpenClose(false);
        }
    });
    connect(ui->comboBox_stopBits_2,&QComboBox::currentTextChanged,this,[=](){
        if(ui->pushButton_serialOpenClose_2->text() == "关闭串口"){
            emit closeSerialSignal_2();
            serialOpenClose(false);
        }
    });


    connect(ui->pushButton_send_serial,&QPushButton::clicked,this,[=](){
        QString tempStringData = ui->plainTextEdit_send_serial->toPlainText();
        QByteArray byteDataSend = dataTransfer->string2Bytearray(tempStringData);
        emit writeDataSignal(byteDataSend);
    });
    connect(this,&MainWindow::writeDataSignal,serialPortWorker1,[=](QByteArray byteDataSend){
        serialPortWorker1->writeData(byteDataSend);
    });
    connect(ui->pushButton_send_serial_2,&QPushButton::clicked,this,[=](){
        QString tempStringData = ui->plainTextEdit_send_serial_2->toPlainText();
        QByteArray byteDataSend = dataTransfer->string2Bytearray(tempStringData);
        emit writeDataSignal_2(byteDataSend);
    });
    connect(this,&MainWindow::writeDataSignal_2,serialPortWorker2,[=](QByteArray byteDataSend){
        serialPortWorker2->writeData(byteDataSend);
    });

    connect(serialPortWorker1,&SerialPortWorker::dataToUiDirect,this,[=](QString textToShowDirect){
        updatePlainText(true, textToShowDirect);
    });
    connect(serialPortWorker2,&SerialPortWorker::dataToUiDirect,this,[=](QString textToShowDirect){
        updatePlainText(false, textToShowDirect);
    });

    connect(ui->pushButton_saveDataSerial,&QPushButton::clicked,this,[=](){
        if(ui->pushButton_saveDataSerial->isChecked()){
            bool serialIsOpen = serialPortWorker1->serialPort->isOpen();
            if(serialIsOpen){
                ui->pushButton_saveDataSerial->setChecked(true);
                ui->pushButton_saveDataSerial->setText("等待");
                QDateTime currentTime = QDateTime::currentDateTime();
                fileNameSerial1 = currentTime.toString("yyyyMMdd_hhmmss") +"Serial1"+ ".txt";
                statusBarShowSerial(true,"准备保存数据");
                ui->pushButton_saveDataSerial->setChecked(true);
                double saveTime = ui->lineEdit_saveDataTimeSerial->text().toDouble();
                isSaveDataSerial1 = true;
                QTimer::singleShot(static_cast<int>(saveTime * 1000), this, [this](){
                    isSaveDataSerial1 = false;
                    ui->pushButton_saveDataSerial->setChecked(false);
                    ui->pushButton_saveDataSerial->setText("开始");
                    QMessageBox::information(this, "保存完成", "数据已保存到文件");
                });
            }
            else{
                qmessageBoxSet("Serial1未打开！");
                statusBarShowSerial(true,"Serial1未打开！");
                ui->pushButton_saveDataSerial->setChecked(false);
            }
        }
        else{
            qmessageBoxSet("请等待当前数据保存完毕！");
            ui->pushButton_saveDataSerial->setChecked(true);
            ui->pushButton_saveDataSerial->setText("等待");
        }
    });

    connect(ui->pushButton_saveDataSerial_2,&QPushButton::clicked,this,[=](){
        if(ui->pushButton_saveDataSerial_2->isChecked()){
            bool serialIsOpen = serialPortWorker2->serialPort->isOpen();
            if(serialIsOpen){
                ui->pushButton_saveDataSerial_2->setChecked(true);
                ui->pushButton_saveDataSerial_2->setText("等待");
                // 获取当前时间作为文件名
                QDateTime currentTime = QDateTime::currentDateTime();
                fileNameSerial2 = currentTime.toString("yyyyMMdd_hhmmss") +"Serial2"+ ".txt";
                statusBarShowSerial(false,"准备保存数据");
                ui->pushButton_saveDataSerial_2->setChecked(true);
                // 查询保存时间
                double saveTime = ui->lineEdit_saveDataTimeSerial_2->text().toDouble();
                isSaveDataSerial2 = true;

                QTimer::singleShot(static_cast<int>(saveTime * 1000), this, [this](){
                    isSaveDataSerial2 = false;
                    ui->pushButton_saveDataSerial_2->setChecked(false);
                    ui->pushButton_saveDataSerial_2->setText("开始");
                    QMessageBox::information(this, "保存完成", "数据已保存到文件");
                });
            }
            else{
                qmessageBoxSet("Serial2未打开！");
                statusBarShowSerial(false,"Serial2未打开！");
                ui->pushButton_saveDataSerial_2->setChecked(false);
            }
        }
        else{
            qmessageBoxSet("请等待当前数据保存完毕！");
            ui->pushButton_saveDataSerial_2->setChecked(true);
            ui->pushButton_saveDataSerial_2->setText("等待");
        }
    });

    connect(dataAnalysisHelper1,&DataAnalysisHelper::upgradeCentroidUi,this,[=](const CentroidFrameAttributes &attrs){
        ui->lineEdit_centroidX->setText(QString::number(attrs.centroidX));
        ui->lineEdit_centroidY->setText(QString::number(attrs.centroidY));
        ui->lineEdit_minGray->setText(QString::number(attrs.minGrayscale));
        ui->lineEdit_maxGray->setText(QString::number(attrs.maxGrayscale));
        ui->lineEdit_overGrayscaleNum->setText(QString::number(attrs.overThreshold));
        ui->lineEdit_exposureTime->setText(QString::number(attrs.exposureTime));
        ui->lineEdit_grayscaleSum->setText(QString::number(attrs.grayscaleSum));
        ui->lineEdit_totalCentroidFameNum->setText(QString::number(attrs.totalFrameNum));
        ui->lineEdit_validCentroidFameNum->setText(QString::number(attrs.validFrameNum));
        ui->lineEdit_errorCentroidFameNum->setText(QString::number(attrs.errorFrameNum));
    });

    connect(dataAnalysisHelper2,&DataAnalysisHelper::upgradeTemUi,this,[=](const TemperatureFrameAttributes &attrs){
        ui->lineEdit_temTEC->setText(QString::number(attrs.tempTEC));
        ui->lineEdit_temFPGA->setText(QString::number(attrs.tempFPGA));
    });

    saveDirRS422Txt = QCoreApplication::applicationDirPath() + "/DataCapture/RS422/txt/";
    saveDirRS422Bin = QCoreApplication::applicationDirPath() + "/DataCapture/RS422/bin/";
    QDir dirRS422Txt(saveDirRS422Txt);
    if (!dirRS422Txt.exists()) {
        if (!dirRS422Txt.mkpath(".")) {  // 创建多级目录
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirRS422Txt);
            return;
        }
    }
    QDir dirRS422Bin(saveDirRS422Bin);
    if (!dirRS422Bin.exists()) {
        if (!dirRS422Bin.mkpath(".")) {  // 创建多级目录
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirRS422Bin);
            return;
        }
    }

    saveDirLVDSTxt = QCoreApplication::applicationDirPath() + "/DataCapture/LVDS/txt/";
    saveDirLVDSBin = QCoreApplication::applicationDirPath() + "/DataCapture/LVDS/bin/";
    QDir dirLVDSTxt(saveDirLVDSTxt);
    if (!dirLVDSTxt.exists()) {
        if (!dirLVDSTxt.mkpath(".")) {  // 创建多级目录
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirLVDSTxt);
            return;
        }
    }
    QDir dirLVDSBin(saveDirLVDSBin);
    if (!dirLVDSBin.exists()) {
        if (!dirLVDSBin.mkpath(".")) {  // 创建多级目录
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirLVDSBin);
            return;
        }
    }

    saveDirLVDSImgSingle = QCoreApplication::applicationDirPath() + "/ImageCapture/ImgSingle/"; // 单次点击按钮保存图片文件夹
    saveDirLVDSImgSpan = QCoreApplication::applicationDirPath() + "/ImageCapture/ImgSpan/"; // 持续保存图片文件夹
    QDir dirLVDSImgSingle(saveDirLVDSImgSingle);
    if(!dirLVDSImgSingle.exists()){
        if(!dirLVDSImgSingle.mkpath(".")){
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirLVDSImgSingle);
            return;
        }
    }
    QDir dirLVDSImgSpan(saveDirLVDSImgSpan);
    if(!dirLVDSImgSpan.exists()){
        if(!dirLVDSImgSpan.mkpath(".")){
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirLVDSImgSpan);
            return;
        }
    }
    connect(ui->pushButton_saveImage_2,&QPushButton::clicked,this,&MainWindow::saveImgSingle);
    ui->pushButton_beginSaveImages_2->setCheckable(true);
    ui->pushButton_beginSaveImages_2->setChecked(false);
    connect(ui->pushButton_beginSaveImages_2,&QPushButton::clicked,this,&MainWindow::saveImgSpan);


    ui->pushButton_cardOpenClose->setCheckable(true);
    ui->pushButton_cardOpenClose_2->setCheckable(true);
    ui->pushButton_cardOpenClose->setChecked(false);
    ui->pushButton_cardOpenClose_2->setChecked(false);

    cardWorker1 = new lvdsCardWorker();
    t1= new QThread();
    cardWorker1->moveToThread(t1);
    cardWorker1->setRingBuffer(ringBufferRS422);
    dataAnalysisHelperRS422 = new DataAnalysisHelper();
    dataAnalysisHelperRS422->setRingBuffer(ringBufferRS422);
    t_dataAnalysisRS422 = new QThread();
    dataAnalysisHelperRS422->moveToThread(t_dataAnalysisRS422);
    connect(t_dataAnalysisRS422,&QThread::started,dataAnalysisHelperRS422,&DataAnalysisHelper::onDataAnalysisRS422);
    t_dataAnalysisRS422->start();
    dataAnalysisHelperRS422->startProcessing();

    cardWorker2 = new lvdsCardWorker();
    t2= new QThread();
    cardWorker2->moveToThread(t2);
    cardWorker2->setRingBuffer(ringBufferLVDS);
    dataAnalysisHelperLVDS = new DataAnalysisHelper();
    dataAnalysisHelperLVDS->setRingBuffer(ringBufferLVDS);
    t_dataAnalysisLVDS = new QThread();
    dataAnalysisHelperLVDS->moveToThread(t_dataAnalysisLVDS);
    connect(t_dataAnalysisLVDS,&QThread::started,dataAnalysisHelperLVDS,&DataAnalysisHelper::onDataAnalysisLVDS);
    connect(dataAnalysisHelperLVDS, &DataAnalysisHelper::imageSignal, this, [=](QImage image) {
            qDebug() << "槽函数执行线程ID：" << QThread::currentThreadId();
            showImage(image);
        });
    t_dataAnalysisLVDS->start();
    dataAnalysisHelperLVDS->startProcessing();

    connect(dataAnalysisHelperRS422,&DataAnalysisHelper::upgradeCentroidUi,this,[=](const CentroidFrameAttributes &attrs){
        ui->lineEdit_centroidX->setText(QString::number(attrs.centroidX));
        ui->lineEdit_centroidY->setText(QString::number(attrs.centroidY));
        ui->lineEdit_minGray->setText(QString::number(attrs.minGrayscale));
        ui->lineEdit_maxGray->setText(QString::number(attrs.maxGrayscale));
        ui->lineEdit_overGrayscaleNum->setText(QString::number(attrs.overThreshold));
        ui->lineEdit_exposureTime->setText(QString::number(attrs.exposureTime));
        ui->lineEdit_grayscaleSum->setText(QString::number(attrs.grayscaleSum));
        ui->lineEdit_totalCentroidFameNum->setText(QString::number(attrs.totalFrameNum));
        ui->lineEdit_validCentroidFameNum->setText(QString::number(attrs.validFrameNum));
        ui->lineEdit_errorCentroidFameNum->setText(QString::number(attrs.errorFrameNum));

        ui->lineEdit_temTEC->setText(QString::number(attrs.Tec_Tem));
        ui->lineEdit_temFPGA->setText(QString::number(attrs.FPGA_Tem));
        ui->lineEdit_elecCurrSEL->setText(QString::number(attrs.SEL_Current));
        ui->lineEdit_TemVtemp->setText(QString::number(attrs.Vtemp_Tem));
        ui->lineEdit_statusSEL->setText(attrs.SEL_Status);
        ui->lineEdit_numOvercurr->setText(QString::number(attrs.SEL_OverTimes));
        ui->lineEdit_recordNumOvercurr->setText(QString::number(attrs.SEL_OverTimesRecord));
        ui->lineEdit_samplingValueOvercurr->setText(QString::number(attrs.SEL_OverCurrentSampling));
        ui->lineEdit_cameraExpoMode->setText(attrs.Camera_ExpoMode);
        ui->lineEdit_deadPixelCorrMode->setText(attrs.BadPix_CoreMode);
        ui->lineEdit_imageDataSource->setText(attrs.Image_DataSource);

    });

    connect(dataAnalysisHelper2,&DataAnalysisHelper::upgradeCentroidUi,this,[=](const CentroidFrameAttributes &attrs){ // 临时测试用
        ui->lineEdit_centroidX->setText(QString::number(attrs.centroidX));
        ui->lineEdit_centroidY->setText(QString::number(attrs.centroidY));
        ui->lineEdit_minGray->setText(QString::number(attrs.minGrayscale));
        ui->lineEdit_maxGray->setText(QString::number(attrs.maxGrayscale));
        ui->lineEdit_overGrayscaleNum->setText(QString::number(attrs.overThreshold));
        ui->lineEdit_exposureTime->setText(QString::number(attrs.exposureTime));
        ui->lineEdit_grayscaleSum->setText(QString::number(attrs.grayscaleSum));
        ui->lineEdit_totalCentroidFameNum->setText(QString::number(attrs.totalFrameNum));
        ui->lineEdit_validCentroidFameNum->setText(QString::number(attrs.validFrameNum));
        ui->lineEdit_errorCentroidFameNum->setText(QString::number(attrs.errorFrameNum));

        // 临时测试，用于技物所ZGG红外相机
        ui->lineEdit_temTEC->setText(QString::number(attrs.Tec_Tem));
        ui->lineEdit_temFPGA->setText(QString::number(attrs.FPGA_Tem));
        ui->lineEdit_elecCurrSEL->setText(QString::number(attrs.SEL_Current));
        ui->lineEdit_TemVtemp->setText(QString::number(attrs.Vtemp_Tem));
        ui->lineEdit_statusSEL->setText(attrs.SEL_Status);
        ui->lineEdit_numOvercurr->setText(QString::number(attrs.SEL_OverTimes));
        ui->lineEdit_recordNumOvercurr->setText(QString::number(attrs.SEL_OverTimesRecord));
        ui->lineEdit_samplingValueOvercurr->setText(QString::number(attrs.SEL_OverCurrentSampling));
        ui->lineEdit_cameraExpoMode->setText(attrs.Camera_ExpoMode);
        ui->lineEdit_deadPixelCorrMode->setText(attrs.BadPix_CoreMode);
        ui->lineEdit_imageDataSource->setText(attrs.Image_DataSource);
    });

    // 更新遥测帧计数
    connect(dataAnalysisHelperRS422,&DataAnalysisHelper::updateFrameCheckSignal,this,[=](bool isValid){
        qDebug()<<"开始更新遥测帧计数";
        if(isValid){
            qDebug()<<"正确帧加一";
            validFrameCount += 1;
            ui->le_frame_crc_success_count->setText(QString::number(validFrameCount));
            // 在UI中更新当前接收到遥测的数量
            paraFrameCount += 1;
            ui->le_frame_total_count->setText(QString::number(paraFrameCount)) ;
        }
        else{
             qDebug()<<"错误帧加一";
            invalidFrameCount += 1;
            ui->le_frame_crc_wrong_count->setText(QString::number(invalidFrameCount));
            // 在UI中更新当前接收到遥测的数量
            paraFrameCount += 1;
            ui->le_frame_total_count->setText(QString::number(paraFrameCount)) ;
        }
    });

    connect(dataAnalysisHelper2,&DataAnalysisHelper::updateFrameCheckSignal,this,[=](bool isValid){  // 测试用
        if(isValid){
            qDebug()<<"正确帧加一";
            validFrameCount += 1;
            ui->le_frame_crc_success_count->setText(QString::number(validFrameCount));
            // 在UI中更新当前接收到遥测的数量
            paraFrameCount += 1;
            ui->le_frame_total_count->setText(QString::number(paraFrameCount)) ;
        }
        else{
             qDebug()<<"错误帧加一";
            invalidFrameCount += 1;
            ui->le_frame_crc_wrong_count->setText(QString::number(invalidFrameCount));
            // 在UI中更新当前接收到遥测的数量
            paraFrameCount += 1;
            ui->le_frame_total_count->setText(QString::number(paraFrameCount)) ;
        }
    });

    connect(dataAnalysisHelperRS422,&DataAnalysisHelper::updateParaListUiSignal,this,[=](QVector<ParaListUi> paraListUiList){
        for (int i = 0 ; i < paraListUiList.size(); ++i) {
            modelMain->setItem(i,2,new QStandardItem(paraListUiList.at(i).value));
            modelMain->setItem(i,3,new QStandardItem(paraListUiList.at(i).code));
            if(paraListUiList.at(i).isValid == true){
                modelMain->setItem(i,4,new QStandardItem("是"));
            }
            else{
                modelMain->setItem(i,4,new QStandardItem("否"));
            }

            QString paraNo = paraListUiList.at(i).paraNo;
            for (int r = 0; r < modelInterest->rowCount(); ++r) {
                if (modelInterest->item(r, 0)->text() == paraNo) {
                    modelInterest->setItem(r, 2, new QStandardItem(paraListUiList.at(i).value));
                    modelInterest->setItem(r, 3, new QStandardItem(paraListUiList.at(i).code));
                    modelInterest->setItem(r, 4, new QStandardItem(paraListUiList.at(i).isValid ? "是" : "否"));
                    break;
                }
            }
        }

        if(isSaveTMFile){
            QFile file(saveFileNameTm);
            QFile fileAuto(saveFileNameTmAuto);
            if(ui->rb_save_data_manual->isChecked()){
                if(file.open((QIODevice::Append | QIODevice::Text))){
                    QTextStream out(&file);
                    QStringList rowValues;
                    for (int i = 0; i < paraListUiList.size(); ++i) {
                         rowValues << paraListUiList.at(i).value;
                     }
                    out << rowValues.join(",") << "\n";  // 写入CSV一行
                    file.close();
                }
                else{
                    qmessageBoxSet("无法打开遥测手动保存CSV文件");
                }
            }
            else {
                if(fileAuto.open((QIODevice::Append | QIODevice::Text))){
                    QTextStream out(&fileAuto);
                    QStringList rowValues;
                    for (int i = 0; i < paraListUiList.size(); ++i) {
                         rowValues << paraListUiList.at(i).value;
                     }
                    out << rowValues.join(",") << "\n";  // 写入CSV一行
                    fileAuto.close();
                }
                else{
                    qmessageBoxSet("无法打开遥测自动保存CSV文件");
                }
            }
        }else {
            qWarning() << "当前未开启遥测数据保存" << saveFileNameTm;
        }
    });

    connect(dataAnalysisHelper2,&DataAnalysisHelper::updateParaListUiSignal,this,[=](QVector<ParaListUi> paraListUiList){ // 临时测试用
        for (int i = 0 ; i < paraListUiList.size(); ++i) {
            modelMain->setItem(i,2,new QStandardItem(paraListUiList.at(i).value));
            modelMain->setItem(i,3,new QStandardItem(paraListUiList.at(i).code));
            if(paraListUiList.at(i).isValid == true){
                modelMain->setItem(i,4,new QStandardItem("是"));
            }
            else{
                modelMain->setItem(i,4,new QStandardItem("否"));
            }
            QString paraNo = paraListUiList.at(i).paraNo;
            for (int r = 0; r < modelInterest->rowCount(); ++r) {
                if (modelInterest->item(r, 0)->text() == paraNo) {
                    modelInterest->setItem(r, 2, new QStandardItem(paraListUiList.at(i).value));
                    modelInterest->setItem(r, 3, new QStandardItem(paraListUiList.at(i).code));
                    modelInterest->setItem(r, 4, new QStandardItem(paraListUiList.at(i).isValid ? "是" : "否"));
                    break; // 找到后退出循环
                }
            }
        }

        if(isSaveTMFile){
            QFile file(saveFileNameTm);
            QFile fileAuto(saveFileNameTmAuto);
            if(ui->rb_save_data_manual->isChecked()){
                if(file.open((QIODevice::Append | QIODevice::Text))){
                    QTextStream out(&file);
                    QStringList rowValues;
                    for (int i = 0; i < paraListUiList.size(); ++i) {
                         rowValues << paraListUiList.at(i).value;
                     }
                    out << rowValues.join(",") << "\n";  // 写入CSV一行
                    file.close();
                }
                else{
                    qmessageBoxSet("无法打开遥测手动保存CSV文件");
                }
            }
            else {
                if(fileAuto.open((QIODevice::Append | QIODevice::Text))){
                    QTextStream out(&fileAuto);
                    QStringList rowValues;
                    for (int i = 0; i < paraListUiList.size(); ++i) {
                         rowValues << paraListUiList.at(i).value;
                     }
                    out << rowValues.join(",") << "\n";  // 写入CSV一行
                    fileAuto.close();
                }
                else{
                    qmessageBoxSet("无法打开遥测自动保存CSV文件");
                }
            }
        }else {
            qWarning() << "当前未开启遥测数据保存" << saveFileNameTm;
        }
    });

    connect(ui->pb_clear_frame_errors,&QPushButton::clicked,this,[=](){
        paraFrameCount = 0;
        validFrameCount = 0;
        invalidFrameCount = 0;
        ui->le_frame_total_count->setText(QString::number(paraFrameCount)) ;
        ui->le_frame_crc_wrong_count->setText(QString::number(invalidFrameCount)) ;
        ui->le_frame_crc_success_count->setText(QString::number(validFrameCount)) ;
    });

    connect(serialPortWorker1,&SerialPortWorker::RunError,this,&MainWindow::runError);
    connect(serialPortWorker2,&SerialPortWorker::RunError,this,&MainWindow::runError);


    int grayThrehold = ui->lineEdit_grayThre_2->text().toInt();
    settingsUiAttrs.grayThrehold = grayThrehold;
    dataAnalysisHelperLVDS->updataUiSettingsRec(settingsUiAttrs);
    dataAnalysisHelper2->updataUiSettingsRec(settingsUiAttrs);
    connect(ui->lineEdit_grayThre_2,&QLineEdit::textChanged,this,[=](){
        int grayThrehold = ui->lineEdit_grayThre_2->text().toInt();
        settingsUiAttrs.grayThrehold = grayThrehold;
        dataAnalysisHelperLVDS->updataUiSettingsRec(settingsUiAttrs);
        dataAnalysisHelper2->updataUiSettingsRec(settingsUiAttrs);
    });

    connect(this,&MainWindow::cardNoConfigSignal,this,[=](bool no1IsRs422){
            cardWorker1->GTChoise(no1IsRs422);
            cardWorker2->GTChoise(no1IsRs422);
            });

    quint8 rss422No = 1;
    quint8 lvdsNo = 0;
    emit cardNoConfigSignal(false);

    cardWorker1->setCardNum(rss422No);
    cardWorker2->setCardNum(lvdsNo);
    connect(this,&MainWindow::updateWorkerCardNum1,cardWorker1,&lvdsCardWorker::updateCardNoInput);
    connect(this,&MainWindow::updateWorkerCardNum2,cardWorker2,&lvdsCardWorker::updateCardNoInput);
    emit updateWorkerCardNum1(rss422No,lvdsNo);
    emit updateWorkerCardNum2(rss422No,lvdsNo);

    connect(t1,&QThread::started,cardWorker1,&lvdsCardWorker::threadRun);
    connect(t2,&QThread::started,cardWorker2,&lvdsCardWorker::threadRun);

    connect(cardWorker1,&lvdsCardWorker::RunError,this,&MainWindow::runError);
    connect(cardWorker2,&lvdsCardWorker::RunError,this,&MainWindow::runError);

    connect(cardWorker1,&lvdsCardWorker::updateBarStatusSignal,this,&MainWindow::updateStatusBar);
    connect(cardWorker2,&lvdsCardWorker::updateBarStatusSignal,this,&MainWindow::updateStatusBar);


    int cardCount = cardWorker1->getCardCount();
    ui->lineEdit_cardCount->setText(QString::number(cardCount));
    ui->lineEdit_cardCount_2->setText(QString::number(cardCount));

    ui->pushButton_cardOpenClose->setCheckable(true);

    ui->pushButton_send->setCheckable(false);
    ui->pushButton_send_2->setCheckable(false);

    // 波特率
    ui->comboBox_baudRate_card->addItem("1200",LVDS_BAUD_1200);
    ui->comboBox_baudRate_card->addItem("2400",LVDS_BAUD_2400);
    ui->comboBox_baudRate_card->addItem("4800",LVDS_BAUD_4800);
    ui->comboBox_baudRate_card->addItem("9600",LVDS_BAUD_9600);
    ui->comboBox_baudRate_card->addItem("19200",LVDS_BAUD_19200);
    ui->comboBox_baudRate_card->addItem("38400",LVDS_BAUD_38400);
    ui->comboBox_baudRate_card->addItem("57600",LVDS_BAUD_57600);
    ui->comboBox_baudRate_card->addItem("115200",LVDS_BAUD_115200);
    ui->comboBox_baudRate_card->addItem("128000",LVDS_BAUD_128000);
    ui->comboBox_baudRate_card->addItem("256000",LVDS_BAUD_256000);
    ui->comboBox_baudRate_card->addItem("3000000",3000000);
    ui->comboBox_baudRate_card->addItem("48000000",48000000);
    ui->comboBox_baudRate_card->setCurrentIndex(10);

    // 数据位
    ui->comboBox_dataBit_card->addItem("1", LVDS_DATABITS_1);
    ui->comboBox_dataBit_card->addItem("2", LVDS_DATABITS_2);
    ui->comboBox_dataBit_card->addItem("3", LVDS_DATABITS_3);
    ui->comboBox_dataBit_card->addItem("4", LVDS_DATABITS_4);
    ui->comboBox_dataBit_card->addItem("5", LVDS_DATABITS_5);
    ui->comboBox_dataBit_card->addItem("6", LVDS_DATABITS_6);
    ui->comboBox_dataBit_card->addItem("7", LVDS_DATABITS_7);
    ui->comboBox_dataBit_card->addItem("8", LVDS_DATABITS_8);
    ui->comboBox_dataBit_card->setCurrentIndex(7);

    // 校验位
    ui->comboBox_parity_card->addItem("None", LVDS_PARITY_NO);
    ui->comboBox_parity_card->addItem("Odd", LVDS_PARITY_ODD);
    ui->comboBox_parity_card->addItem("Even", LVDS_PARITY_EVEN);
    ui->comboBox_parity_card->setCurrentIndex(1);

    // 停止位
    ui->comboBox_stopBits_card->addItem("1", LVDS_STOPBITS_10);
    ui->comboBox_stopBits_card->addItem("1.5", LVDS_STOPBITS_15);
    ui->comboBox_stopBits_card->addItem("2", LVDS_STOPBITS_20);
    ui->comboBox_stopBits_card->setCurrentIndex(2); // 默认1位停止位

    /// LVDS板卡界面初始化配置
    // 波特率
    ui->comboBox_baudRate_card_2->addItem("1200",LVDS_BAUD_1200);
    ui->comboBox_baudRate_card_2->addItem("2400",LVDS_BAUD_2400);
    ui->comboBox_baudRate_card_2->addItem("4800",LVDS_BAUD_4800);
    ui->comboBox_baudRate_card_2->addItem("9600",LVDS_BAUD_9600);
    ui->comboBox_baudRate_card_2->addItem("19200",LVDS_BAUD_19200);
    ui->comboBox_baudRate_card_2->addItem("38400",LVDS_BAUD_38400);
    ui->comboBox_baudRate_card_2->addItem("57600",LVDS_BAUD_57600);
    ui->comboBox_baudRate_card_2->addItem("115200",LVDS_BAUD_115200);
    ui->comboBox_baudRate_card_2->addItem("128000",LVDS_BAUD_128000);
    ui->comboBox_baudRate_card_2->addItem("256000",LVDS_BAUD_256000);
    ui->comboBox_baudRate_card_2->addItem("3000000",3000000);
    ui->comboBox_baudRate_card_2->addItem("48000000",48000000);
    ui->comboBox_baudRate_card_2->setCurrentIndex(11); // 默认波特率

    // 数据位
    ui->comboBox_dataBit_card_2->addItem("1", LVDS_DATABITS_1);
    ui->comboBox_dataBit_card_2->addItem("2", LVDS_DATABITS_2);
    ui->comboBox_dataBit_card_2->addItem("3", LVDS_DATABITS_3);
    ui->comboBox_dataBit_card_2->addItem("4", LVDS_DATABITS_4);
    ui->comboBox_dataBit_card_2->addItem("5", LVDS_DATABITS_5);
    ui->comboBox_dataBit_card_2->addItem("6", LVDS_DATABITS_6);
    ui->comboBox_dataBit_card_2->addItem("7", LVDS_DATABITS_7);
    ui->comboBox_dataBit_card_2->addItem("8", LVDS_DATABITS_8);
    ui->comboBox_dataBit_card_2->setCurrentIndex(7);

    // 校验位
    ui->comboBox_parity_card_2->addItem("None", LVDS_PARITY_NO);
    ui->comboBox_parity_card_2->addItem("Odd", LVDS_PARITY_ODD);
    ui->comboBox_parity_card_2->addItem("Even", LVDS_PARITY_EVEN);
    ui->comboBox_parity_card_2->setCurrentIndex(1);

    // 停止位
    ui->comboBox_stopBits_card_2->addItem("1", LVDS_STOPBITS_10);
    ui->comboBox_stopBits_card_2->addItem("1.5", LVDS_STOPBITS_15);
    ui->comboBox_stopBits_card_2->addItem("2", LVDS_STOPBITS_20);
    ui->comboBox_stopBits_card_2->setCurrentIndex(2); // 默认1位停止位

    ui->comboBox_channelNumRS422->addItem("通道0",LVDS_DATA_CH1);
    ui->comboBox_channelNumRS422->addItem("通道1",LVDS_DATA_CH2);
    const int maxChannels = 32;  // 最多 32 个通道
    for (int i = 2; i < maxChannels; ++i) {
        ui->comboBox_channelNumRS422->addItem(QString("通道%1").arg(i), LVDS_DATA_CH1+i);
    }
    ui->comboBox_channelNumRS422->setCurrentIndex(0);

    // LVDS
    ui->comboBox_channelNumLVDS->addItem("通道0",LVDS_DATA_CH1);
    ui->comboBox_channelNumLVDS->addItem("通道1",LVDS_DATA_CH2);
    const int maxChannelsLVDS = 32;  // 最多 32 个通道
    for (int i = 2; i < maxChannelsLVDS; ++i) {
        ui->comboBox_channelNumLVDS->addItem(QString("通道%1").arg(i), LVDS_DATA_CH1+i);
    }
    ui->comboBox_channelNumLVDS->setCurrentIndex(0);

    connect(ui->comboBox_channelNumRS422, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](){
        quint8 channelNumRS422  = static_cast<quint8>(ui->comboBox_channelNumRS422->currentData().toInt());
        cardWorker1->setChannelNum(true, channelNumRS422);   
    });

    connect(ui->comboBox_channelNumLVDS, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](){
        quint8 channelNumLVDS  = static_cast<quint8>(ui->comboBox_channelNumLVDS->currentData().toInt());
        cardWorker2->setChannelNum(false, channelNumLVDS);
    });

    ui->pushButton_saveDataRS422->setCheckable(true);
    ui->pushButton_saveDataLVDS->setCheckable(true);


    connect(ui->pushButton_saveDataRS422,&QPushButton::clicked,this,[=](){
        if(ui->pushButton_saveDataRS422->isChecked()){
            bool cardIsStart = cardWorker1->getLVDSCardStartStatus(true);
            if(cardIsStart){
                ui->pushButton_saveDataRS422->setChecked(true);
                ui->pushButton_saveDataRS422->setText("等待");

                QDateTime currentTime = QDateTime::currentDateTime();
                fileNameRS422 = currentTime.toString("yyyyMMdd_hhmmss") +"RS422"+ ".txt";
                updateStatusBar(true,"准备保存数据");
                ui->pushButton_saveDataRS422->setChecked(true);
                double saveTime = ui->lineEdit_saveTimeRS422->text().toDouble();
                isSaveDataRs422 = true;

                QTimer::singleShot(static_cast<int>(saveTime * 1000), this, [this](){
                    isSaveDataRs422 = false;
                    ui->pushButton_saveDataRS422->setChecked(false);
                    ui->pushButton_saveDataRS422->setText("开始");
                    QMessageBox::information(this, "保存完成", "数据已保存到文件");
                });
            }
            else{
                qmessageBoxSet("RS422板卡未使能！");
                updateStatusBar(true,"RS422板卡未使能！");
                ui->pushButton_saveDataRS422->setChecked(false);
            }
        }
        else{
            qmessageBoxSet("请等待当前数据保存完毕！");
            ui->pushButton_saveDataRS422->setChecked(true);
            ui->pushButton_saveDataRS422->setText("等待");
        }
    });

    connect(ui->pushButton_saveDataLVDS,&QPushButton::clicked,this,[=](){
        if(ui->pushButton_saveDataLVDS->isChecked()){
            bool cardIsStart = cardWorker2->getLVDSCardStartStatus(false);
            if(cardIsStart){
                ui->pushButton_saveDataLVDS->setChecked(true);
                ui->pushButton_saveDataLVDS->setText("等待");

                QDateTime currentTime = QDateTime::currentDateTime();
                fileNameLVDS = currentTime.toString("yyyyMMdd_hhmmss") +"LVDS"+ ".txt";
                updateStatusBar(false,"准备保存数据");
                ui->pushButton_saveDataLVDS->setChecked(true);

                double saveTime = ui->lineEdit_saveTimeLVDS->text().toDouble();
                isSaveDataLVDS = true; // 开始保存

                QTimer::singleShot(static_cast<int>(saveTime * 1000), this, [this](){
                    isSaveDataLVDS = false; // 停止保存
                    ui->pushButton_saveDataLVDS->setChecked(false);
                    ui->pushButton_saveDataLVDS->setText("开始");
                    QMessageBox::information(this, "保存完成", "数据已保存到文件");
                });
            }
            else{
                qmessageBoxSet("LVDS板卡未使能！");
                updateStatusBar(false,"LVDS板卡未使能！");
                ui->pushButton_saveDataLVDS->setChecked(false);
            }
        }
        else{
            qmessageBoxSet("请等待当前数据保存完毕！");
            ui->pushButton_saveDataLVDS->setChecked(true);
            ui->pushButton_saveDataLVDS->setText("等待");
        }
    });


    connect(ui->checkBox_overGrayScaleCoordinates,&QCheckBox::toggled,this, [this](bool checked){
       emit updateSaveCoordinateSignal(checked);
    });
    connect(this,&MainWindow::updateSaveCoordinateSignal,dataAnalysisHelperLVDS,&DataAnalysisHelper::updateSaveCoordinate,Qt::DirectConnection);


    saveDirTM = QCoreApplication::applicationDirPath() + "/TMData/Fragment/";
    saveDirTMAuto = QCoreApplication::applicationDirPath() + "/TMData/Auto/";
    QDir SaveDirTM(saveDirTM);
    if(!SaveDirTM.exists()){
        if(!SaveDirTM.mkpath(".")){
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirTM);
            return;
        }
    }
    QDir SaveDirAuto(saveDirTMAuto);
    if(!SaveDirAuto.exists()){
        if(!SaveDirAuto.mkpath(".")){
            QMessageBox::critical(this, "错误", "无法创建目录: " + saveDirTMAuto);
            return;
        }
    }

    m_saveTimer = new QTimer(this);
    m_saveTimer->setSingleShot(true);

    connect(ui->pb_begin_save_data,&QPushButton::clicked,this,[=](){
        if(ui->pb_begin_save_data->text() == "停止"){
            ui->pb_begin_save_data->setChecked(false);
            ui->pb_begin_save_data->setText("开始");
            isSaveTMFile = false;
            on_stopSaveButton_clicked(); // 提前终止定时器
            if(ui->rb_save_data_auto->isChecked()){
                qmessageBoxSet("自动保存遥测数据终止");
            }
            return;
        }
        else {
            ui->pb_begin_save_data->setChecked(true);
            ui->pb_begin_save_data->setText("停止");
            isSaveTMFile = true;
        }


        if(ui->rb_save_data_manual->isChecked()){
            QString  saveTimeString = ui->sb_time->text();
            saveTimeString.remove(QRegExp("[^0-9]"));  // 删除所有非数字字符
            int saveTime = saveTimeString.toInt();

            QDateTime currentTime = QDateTime::currentDateTime();
            saveFileNameTm = saveDirTM + currentTime.toString("yyyyMMdd_hhmmss") +saveTimeString+ ".csv";


            QFile file(saveFileNameTm);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);

                QStringList headers;
                for (int i = 0; i<modelMain->rowCount();++i) {
                    QStandardItem *it = modelMain->item(i, 1);  // 第二列
                    headers << it->text();
                }
                out << headers.join(",") << "\n";
                file.close();
            }
            else {
                qDebug() << "无法创建文件:" << saveFileNameTm;
                qmessageBoxSet("无法创建遥测CSV文件");
            }

            connect(m_saveTimer, &QTimer::timeout, this, [this]() {
                isSaveTMFile = false; // 停止保存
                ui->pb_begin_save_data->setChecked(false);
                ui->pb_begin_save_data->setText("开始");
                QMessageBox::information(this, "保存完成", "数据已保存到文件");
                m_saveTimer->deleteLater(); // 定时器完成任务后清理
                m_saveTimer = nullptr;
            });
            if(m_saveTimer){
                m_saveTimer->start(static_cast<int>(saveTime * 1000));
            }
        }

        if(ui->rb_save_data_auto->isChecked()){

            QDateTime currentTimeAuto = QDateTime::currentDateTime();
            saveFileNameTmAuto = saveDirTMAuto + currentTimeAuto.toString("yyyyMMdd_hhmmss") +"Auto"+ ".csv";


            QFile file(saveFileNameTmAuto);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);

                QStringList headers;
                for (int i = 0; i<modelMain->rowCount();++i) {
                    QStandardItem *it = modelMain->item(i, 1);  // 第二列
                    headers << it->text();
                }
                out << headers.join(",") << "\n";
                file.close();
            }
            else {
                qDebug() << "无法创建文件:" << saveFileNameTmAuto;
                qmessageBoxSet("无法创建遥测CSV文件");
            }
        }

    });


    connect(ui->pushButton_cardOpenClose,&QPushButton::clicked,this,[=](){
        cardOpenBtn(true);
    });
    connect(ui->pushButton_cardOpenClose_2,&QPushButton::clicked,this,[=](){
        cardOpenBtn(false);
    });


    connect(ui->pushButton_reset,&QPushButton::clicked,this,[=](){
        bool resetSign = cardWorker1->resetCard(true);
        if(resetSign){
            updateStatusBar(true,"RS422板卡复位成功！");
        }
        else{
            qmessageBoxSet("RS422板卡复位失败！"); //复位失败，弹出警告窗口
        }
    });
    connect(ui->pushButton_reset_2,&QPushButton::clicked,this,[=](){
        bool resetSign = cardWorker2->resetCard(true);
        if(resetSign){
            updateStatusBar(false,"LVDS板卡复位成功！");
        }
        else{
            qmessageBoxSet("LVDS板卡复位失败！");
        }
    });

    connect(ui->pushButton_clearFIFO,&QPushButton::clicked,this,[=](){
        bool clearSign = cardWorker1->clearFIFO(true);
        if(clearSign){
            updateStatusBar(true,"RS422板卡清空缓存成功！");
        }
        else{
            qmessageBoxSet("RS422板卡清空缓存失败！");
        }
    });
    connect(ui->pushButton_clearFIFO_2,&QPushButton::clicked,this,[=](){
        bool clearSign = cardWorker2->clearFIFO(false);
        if(clearSign){
            updateStatusBar(false,"LVDS板卡清空缓存成功！");
        }
        else{
            qmessageBoxSet("LVDS板卡清空缓存失败！");
        }
    });


    connect(ui->pushButton_clearSend,&QPushButton::clicked,ui->plainTextEdit_send,&QPlainTextEdit::clear);
    connect(ui->pushButton_clearReceive,&QPushButton::clicked,ui->plainTextEdit_receive,&QPlainTextEdit::clear);
    connect(ui->pushButton_clearSend_2,&QPushButton::clicked,ui->plainTextEdit_send_2,&QPlainTextEdit::clear);
    connect(ui->pushButton_clearReceive_2,&QPushButton::clicked,ui->plainTextEdit_receive_2,&QPlainTextEdit::clear);
    connect(ui->pushButton_send,&QPushButton::clicked,this,[=](){
        QString tempStringData = ui->plainTextEdit_send->toPlainText();
        QByteArray byteDataSend = dataTransfer->string2Bytearray(tempStringData); // byteDataSend： "\x00\x01\x02\x03\x04\x05\x06\x07"
        bool cardOpenStatus = cardWorker1->getLVDSCardOpenStatus(true);
        if(!cardOpenStatus){
            qmessageBoxSet("发送失败，RS422板卡未打开！");
        }
        else {
            quint8 channel = cardWorker1->getChannelNum(true);
            DWORD dwSendRet = cardWorker1->sendData(true,channel, reinterpret_cast<quint8*>(byteDataSend.data()), static_cast<size_t>(byteDataSend.length())); // 新的写法
        }
    });

    connect(ui->pushButton_send_2,&QPushButton::clicked,this,[=](){
        QString tempStringData = ui->plainTextEdit_send_2->toPlainText();
        QByteArray byteDataSend = dataTransfer->string2Bytearray(tempStringData); // byteDataSend： "\x00\x01\x02\x03\x04\x05\x06\x07"
        bool cardOpenStatus = cardWorker2->getLVDSCardOpenStatus(false);
        if(!cardOpenStatus){
            qmessageBoxSet("发送失败，LVDS板卡未打开！");
        }
        else {
            quint8 channel = cardWorker2->getChannelNum(false);
            DWORD dwSendRet = cardWorker2->sendData(false,channel, reinterpret_cast<quint8*>(byteDataSend.data()), static_cast<size_t>(byteDataSend.length())); // 新的写法
        }
    });

    bool cardOpenStatusRS422 = cardWorker1->getLVDSCardOpenStatus(true);
    statusBarShow(true, "RS422板卡打开状态：" + QString::number(cardOpenStatusRS422));
    if(cardOpenStatusRS422){ // 如果板卡处于打开状态
        ui->pushButton_cardOpenClose->setChecked(true);
        ui->pushButton_cardOpenClose->setText("关闭");
    }

    bool startLVDSStatusRS422 = cardWorker1->getLVDSCardStartStatus(true);
    statusBarShow(true, "RS422板卡使能状态：" + QString::number(startLVDSStatusRS422));
    if(startLVDSStatusRS422){
        ui->pushButton_startLVDS->setChecked(true);
        ui->pushButton_startLVDS->setText("停止");
    }

    bool cardOpenStatusLVDS = cardWorker2->getLVDSCardOpenStatus(false);
    statusBarShow(false, "LVDS板卡打开状态：" + QString::number(cardOpenStatusLVDS));
    if(cardOpenStatusLVDS){
        ui->pushButton_cardOpenClose_2->setChecked(true);
        ui->pushButton_cardOpenClose_2->setText("关闭");
    }

    bool startLVDSStatusLVDS = cardWorker2->getLVDSCardStartStatus(false);
    statusBarShow(false, "LVDS板卡使能状态：" + QString::number(startLVDSStatusLVDS));
    if(startLVDSStatusLVDS){
        ui->pushButton_startLVDS_2->setChecked(true);
        ui->pushButton_startLVDS_2->setText("停止");
    }

    connect(ui->pushButton_startLVDS,&QPushButton::clicked,this,[=](){

        bool cardOpenStatus = cardWorker1->getLVDSCardOpenStatus(true);
        statusBarShow(true, "RS422板卡打开状态：" + QString::number(cardOpenStatus));
        if(cardOpenStatus){
            bool startLVDSStatus = cardWorker1->getLVDSCardStartStatus(true);
            if(startLVDSStatus){
                bool isStartCheck = cardWorker1->StopCard(true);
                if(isStartCheck) {
                    statusBarShow(true,"RS422板卡去使能成功！");
                    ui->pushButton_startLVDS->setChecked(false);
                    ui->pushButton_startLVDS->setText("使能");
                    t1->quit();
                    t1->wait();
                }
                else{
                    statusBarShow(true,"RS422板卡去使能失败！");
                    ui->pushButton_startLVDS->setChecked(true);
                    ui->pushButton_startLVDS->setText("停止");
                }
            }
            else{

                bool isStartCheck = cardWorker1->StartCard(true);
                if(isStartCheck){
                    statusBarShow(true,"RS422板卡使能成功！");
                    ui->pushButton_startLVDS->setChecked(true);
                    ui->pushButton_startLVDS->setText("停止");
                    t1->start();
                }
                else{
                    ui->pushButton_startLVDS->setChecked(false);
                    ui->pushButton_startLVDS->setText("使能");
                    statusBarShow(true,"RS422板卡使能失败！");
                }
            }
        }
        else{
            qmessageBoxSet("RS422板卡未启动！请检查");
        }
    });

    connect(ui->pushButton_startLVDS_2,&QPushButton::clicked,this,[=](){
        bool cardOpenStatus = cardWorker2->getLVDSCardOpenStatus(false);
        statusBarShow(false, "LVDS板卡打开状态：" + QString::number(cardOpenStatus));
        if(cardOpenStatus){
            bool startLVDSStatus = cardWorker2->getLVDSCardStartStatus(false);
            if(startLVDSStatus){
                bool isStartCheck = cardWorker2->StopCard(false);
                if(isStartCheck) {
                    statusBarShow(false,"LVDS板卡去使能成功！");
                    ui->pushButton_startLVDS_2->setChecked(false);
                    ui->pushButton_startLVDS_2->setText("使能");
                    qDebug() << "Thread t2 state before quit:" << t2->isRunning();
                    t2->quit();
                    t2->wait();
                    qDebug() << "Thread t2 state after quit:" << t2->isRunning();
                }
                else{
                    statusBarShow(false,"LVDS板卡去使能失败！");
                    ui->pushButton_startLVDS_2->setChecked(false);
                    ui->pushButton_startLVDS_2->setText("停止");
                }
            }
            else{
                bool isStartCheck = cardWorker2->StartCard(false);
                if(isStartCheck){
                    statusBarShow(false,"LVDS板卡使能成功！");
                    ui->pushButton_startLVDS_2->setChecked(false);
                    ui->pushButton_startLVDS_2->setText("停止");
                    t2->start();
                }
                else{
                    ui->pushButton_startLVDS_2->setChecked(false);
                    ui->pushButton_startLVDS_2->setText("使能");
                    statusBarShow(false,"LVDS板卡使能失败！");
                }
            }
        }
        else{
            qmessageBoxSet("LVDS板卡未启动！请检查");
        }
    });

    connect(xmlcommandparser,&XMLCommandParser::updateParaListSignal,this,[=](QVector<CommandQueue> commandQueueVector){
        QTableWidget* targetTable = ui->tableWidget_cmd_immediately;
        targetTable->setRowCount(commandQueueVector.count());
        for(int i=0;i<commandQueueVector.count();++i){
            QTableWidgetItem* timeItem = new QTableWidgetItem(commandQueueVector.at(i).commandTime);
            targetTable->setItem(i, 0, timeItem);
            QTableWidgetItem* nameItem = new QTableWidgetItem(commandQueueVector.at(i).commandName);
            targetTable->setItem(i, 1, nameItem);
            QTableWidgetItem* codeItem = new QTableWidgetItem(commandQueueVector.at(i).commandCode);
            targetTable->setItem(i, 2, codeItem);
            QTableWidgetItem* remarksItem = new QTableWidgetItem(commandQueueVector.at(i).commandRemarks);
            targetTable->setItem(i, 3, remarksItem);
        }
    });

    modelMain = new QStandardItemModel(this);
    ui->tableView->setModel(modelMain);
    modelInterest = new QStandardItemModel(this);
    ui->tableView_2->setModel(modelInterest);
    modelMain->setHorizontalHeaderLabels({"参数编号", "参数名称", "数值", "源码", "有效性", "是否关注"});
    modelInterest->setHorizontalHeaderLabels({"参数编号", "参数名称", "数值", "源码", "有效性"});

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // 每列宽度会按内容调整
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // 每列宽度会按内容调整
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);



    connect(xmlcommandparser,&XMLCommandParser::updateTMParaListSignal,this,[=](QVector<TMitemQueue> paraQueueVector){

        dataAnalysisHelperRS422->getXmlParser(paraQueueVector);
        dataAnalysisHelper2->getXmlParser(paraQueueVector);
    });

    connect(xmlcommandparser,&XMLCommandParser::updateFrameTMSignal,this,[=](FrameTM &frameTmXML){

        QByteArray ba_frameHead = QByteArray::fromHex(frameTmXML.frameHead.toUtf8());
        quint8 h0_xml = static_cast<quint8>(ba_frameHead[0]);
        quint8 h1_xml = static_cast<quint8>(ba_frameHead[1]);


        QByteArray ba_frameTail = QByteArray::fromHex(frameTmXML.frameTail.toUtf8());
        quint8 t0_xml = static_cast<quint8>(ba_frameTail[0]);
        quint8 t1_xml = static_cast<quint8>(ba_frameTail[1]);

        dataAnalysisHelper2->h0_xml = h0_xml; // 临时测试用
        dataAnalysisHelper2->h1_xml = h1_xml; // 临时测试用
        dataAnalysisHelper2->t0_xml = t0_xml; // 临时测试用
        dataAnalysisHelper2->t1_xml = t1_xml; // 临时测试用
        dataAnalysisHelper2->lengthHead = ba_frameHead.size(); // 临时测试用
        dataAnalysisHelper2->lengthTail = ba_frameTail.size(); // 临时测试用

        dataAnalysisHelperRS422->h0_xml = h0_xml;
        dataAnalysisHelperRS422->h1_xml = h1_xml;
        dataAnalysisHelperRS422->t0_xml = t0_xml;
        dataAnalysisHelperRS422->t1_xml = t1_xml;
        dataAnalysisHelperRS422->lengthHead = ba_frameHead.size();
        dataAnalysisHelperRS422->lengthTail = ba_frameTail.size();



        dataAnalysisHelper2->frameTm = frameTmXML; // 临时测试用
        dataAnalysisHelperRS422->frameTm = frameTmXML;


    });

    connect(xmlcommandparser,&XMLCommandParser::updateTMParaListSignal,this,[=](QVector<TMitemQueue> paraQueueVector){
        int paraNum = paraQueueVector.size();

        for(int i = 0; i <paraNum ; ++i){
            modelMain->setItem(i, 0, new QStandardItem(paraQueueVector.at(i).TMitemNo));
        }
        for(int i = 0; i <paraNum ; ++i){
            modelMain->setItem(i, 1, new QStandardItem(paraQueueVector.at(i).TMitemName));
        }
        for(int i = 0; i <paraNum ; ++i){
            modelMain->setItem(i, 2, new QStandardItem("暂无数据"));
        }
        for(int i = 0; i <paraNum ; ++i){
            modelMain->setItem(i, 3, new QStandardItem("暂无数据"));
        }
        for(int i = 0; i <paraNum ; ++i){
            modelMain->setItem(i, 4, new QStandardItem("是"));
        }
        for(int i = 0; i <paraNum ; ++i){
            QStandardItem *item = new QStandardItem();
            item->setCheckable(true);            // 设置成复选框
            item->setCheckState(Qt::Unchecked);  // 默认不勾选
            modelMain->setItem(i, 5, item);
        }
    });


    connect(modelMain, &QStandardItemModel::itemChanged, this, [=](QStandardItem *item){
        if (item->column() == 5) {  // 只处理第6列（复选框列）
            int row = item->row();
            if (item->checkState() == Qt::Checked) {
                addRowToInterestTable(row);
            } else {
                removeRowFromInterestTable(row);
            }
        }
    });


    QDir dir(CMDXmlFilesPath);
    QStringList xmlFiles = dir.entryList(QStringList() << "*.xml", QDir::Files);

    for (int i = 0; i < xmlFiles.size(); ++i) {
        readXML(CMDXmlFilesPath + xmlFiles.at(i),true);
    }


    ui->lb_current_cmd_name->setText(commandList.at(0)); // 默认显示第一个指令组的名称

    /// 发送立即令列表
    connect(ui->pb_add_cmd,&QPushButton::clicked,this,[=](){
        addCMDList(false);
    });
    connect(ui->pb_insert_cmd,&QPushButton::clicked,this,[=](){
        addCMDList(true);
    });
    connect(ui->pb_send_cmd_immediately,&QPushButton::clicked,this,[=](){
        sendCMD(0,true);
    });
    connect(ui->pb_del_cmd,&QPushButton::clicked,this,&MainWindow::delCMDList); // 删除指令序列
    connect(ui->pb_clear_cmd,&QPushButton::clicked,this,&MainWindow::clearCMDList); // 清空指令序列

    connect(ui->pb_send_cmd,&QPushButton::clicked,this,[=](){

         if (m_SendRow  >= 0) {
             qWarning() << "Command sequence is already running";
             return;
         }
         const int rowCount = ui->tableWidget_cmd_immediately->rowCount();
         if (rowCount == 0) return;

         m_timeDelays.clear();
         for(int i = 0 ; i < rowCount ; i++){
             int timeDelay = ui->tableWidget_cmd_immediately->item(i,0)->text().toInt();
             m_timeDelays.append(timeDelay);
         }

         for(int i = 0 ; i < rowCount ; i++){
             int delay = m_timeDelays[i];
             int delayIndex = i;
             QTimer::singleShot(delay * 1000, this, [this, delayIndex]() {
                 sendCMD(delayIndex,false);
             });
         }

    });

    if (ui->listWidget_2->count() > 0) {
        ui->listWidget_2->setCurrentRow(0); // 默认选中第一个
        onTabItemClicked_2(ui->listWidget_2->item(0)); // 直接调用槽
    }


    connect(cardWorker1, &lvdsCardWorker::onRS422DataToUi, this, &MainWindow::handleRS422Data);
    connect(cardWorker2, &lvdsCardWorker::onLVDSDataToUi, this, &MainWindow::handleLVDSData);

    connect(dataAnalysisHelper2,&DataAnalysisHelper::imageSignal,this,[=](QImage image){
        showImage(image);
    });

    connect(dataAnalysisHelperLVDS,&DataAnalysisHelper::imageSignal,this,[=](QImage image){
        showImage(image);
    });

    connect(dataAnalysisHelperLVDS,&DataAnalysisHelper::upgradeErrorImgNumUi,this,[=](const ImageAttributes &attrs){
        ui->lineEdit_frameNum_2->setText(QString::number(attrs.totalImgNum));
        ui->lineEdit_timeCode_2->setText(attrs.timeCode);
        ui->lineEdit_falseFrameNum_2->setText(QString::number(attrs.errorImgNum));
        ui->lineEdit_rightFrameNum_2->setText(QString::number(attrs.validImgNum));
        ui->lineEdit_oversizeNum_2->setText(QString::number(attrs.overThreshold));
        ui->lineEdit_imageFrameNum_2->setText(attrs.imgFrameNoString);
        ui->lineEdit_imageWindowSize_2->setText(QString::number(attrs.imgWinSize));
    });

    connect(dataAnalysisHelper2,&DataAnalysisHelper::upgradeErrorImgNumUi,this,[=](const ImageAttributes &attrs){
        ui->lineEdit_frameNum_2->setText(QString::number(attrs.totalImgNum));
        ui->lineEdit_timeCode_2->setText(attrs.timeCode);
        ui->lineEdit_falseFrameNum_2->setText(QString::number(attrs.errorImgNum));
        ui->lineEdit_rightFrameNum_2->setText(QString::number(attrs.validImgNum));
        ui->lineEdit_oversizeNum_2->setText(QString::number(attrs.overThreshold));
        ui->lineEdit_imageFrameNum_2->setText(attrs.imgFrameNoString);
        ui->lineEdit_imageWindowSize_2->setText(QString::number(attrs.imgWinSize));
        overThresholdCoords = attrs.overThresholdCo;
    });

    connect(cardWorker1,&lvdsCardWorker::imageSignal,this,[=](QImage image){
        showImage(image);
    });
    connect(cardWorker2,&lvdsCardWorker::imageSignal,this,[=](QImage image){
        showImage(image);
    });


    updateTimer_RS422.setInterval(50);
    connect(&updateTimer_RS422, &QTimer::timeout, this, [this]() {
        if (!pendingData_RS422.isEmpty()) {
            ui->plainTextEdit_receive->setPlainText(pendingData_RS422.join("\n"));
            pendingData_RS422.clear();
        }
    });
    updateTimer_RS422.start();

    updateTimer_LVDS.setInterval(200);
    connect(&updateTimer_LVDS, &QTimer::timeout, this, [this]() {
        if (!pendingData_LVDS.isEmpty()) {
            ui->plainTextEdit_receive_2->setPlainText(pendingData_LVDS.join("\n"));
            pendingData_LVDS.clear();
        }
    });
    updateTimer_LVDS.start();

    updateTimer_Serial1.setInterval(50);
    connect(&updateTimer_Serial1, &QTimer::timeout, this, [this]() {
        if (!pendingData_Serial1.isEmpty()) {
            ui->plainTextEdit_receive_serial->setPlainText(pendingData_Serial1.join("\n"));
            pendingData_Serial1.clear();
        }
    });
    updateTimer_Serial1.start();

    updateTimer_Serial2.setInterval(200);
    connect(&updateTimer_Serial2, &QTimer::timeout, this, [this]() {
        if (!pendingData_Serial2.isEmpty()) {
            ui->plainTextEdit_receive_serial_2->setPlainText(pendingData_Serial2.join("\n"));
            pendingData_Serial2.clear();
        }
    });
    updateTimer_Serial2.start();


    connect(this,&MainWindow::imgToPeakingSignal,dataAnalysisHelperLVDS,&DataAnalysisHelper::imgToPeaking,Qt::DirectConnection);
    connect(this,&MainWindow::imgToPeakingSignal,dataAnalysisHelper2,&DataAnalysisHelper::imgToPeaking,Qt::DirectConnection);
    connect(ui->checkBox_peaking, &QCheckBox::toggled, this, [=](bool checked){
        int peakingThreshold = ui->lineEdit_peakingThreshold->text().toInt();
        emit imgToPeakingSignal(checked, peakingThreshold);

    });
    connect(ui->lineEdit_peakingThreshold,&QLineEdit::textChanged,this,[=](){
        int peakingThreshold = ui->lineEdit_peakingThreshold->text().toInt();
        if(ui->checkBox_peaking->isChecked()){
            emit imgToPeakingSignal(true, peakingThreshold);
        }
        else {
            emit imgToPeakingSignal(false, peakingThreshold);
        }
    });
    int peakingThreshold = ui->lineEdit_peakingThreshold->text().toInt();
    if(ui->checkBox_peaking->isChecked()){
        emit imgToPeakingSignal(true, peakingThreshold);
    }
    else {
        emit imgToPeakingSignal(false, peakingThreshold);
    }


    connect(ui->pushButton_import_com_xml,&QPushButton::clicked,this,[=](){
        QString addXmlPath = QFileDialog::getOpenFileName(
                this,
                tr("选择 XML 文件"),
                "",
                tr("XML 文件 (*.xml)")
            );
            if (!addXmlPath.isEmpty()) {
                readXML(addXmlPath,false);
            }
    });

    connect(ui->pb_import_xml,&QPushButton::clicked,this,[=](){

        QString addXmlPath = QFileDialog::getOpenFileName(
                this,
                tr("选择 XML 文件"),
                "",
                tr("XML 文件 (*.xml)")
            );
            if (!addXmlPath.isEmpty()) {
                readXML2(addXmlPath);
            }
    });


    dialogPara = new DialogPara(this);
    connect(dialogPara, &DialogPara::getDocNodeListTempSignal, this, [=](){
        qDebug()<<"开始执行docNodeList = xmlcommandparser->getDocNodeListTemp();";
        docNodeList = xmlcommandparser->getDocNodeListTemp();
    });
    connect(ui->pushButton_editPara,&QPushButton::clicked,this,[=](){
        int rowCom = -1;
        rowCom = ui->listWidget_2->currentRow();
        if (rowCom == -1) {
            QMessageBox::warning(this, "提示", "请选择指令项");
            return;
        }

        int row = -1;
        row = ui->tableWidget_cmd_immediately->currentRow();
        if (row == -1) {
            QMessageBox::warning(this, "提示", "请选需要编辑的指令序列");
            return;
        }

        xmlcommandparser->setDocNodeList(docNodeList);

        dialogPara->loadCommand(xmlcommandparser,docNodeList,rowCom,row);

        dialogPara->exec();
    });

    connect(dialogPara, &DialogPara::updateParaSignal, this, [=](const QString &commandSequence){
        int row = ui->tableWidget_cmd_immediately->currentRow(); // 获取当前选中行
        if(row < 0 || row >= docNodeList.size()) return;

        QTableWidgetItem *cellItem = ui->tableWidget_cmd_immediately->item(row, 2);
        if(cellItem) cellItem->setText(commandSequence);
        else {
            qDebug()<<"cellItem不存在";
        }

        QDomElement &commandElement = docNodeList[row];

    },
    Qt::UniqueConnection);
    connect(ui->pb_export_xml,&QPushButton::clicked,this,[=](){
        QString filePath = QFileDialog::getSaveFileName(
                this,
                "另存为 XML 文件",
                QDir::currentPath(),        // 默认目录
                "XML Files (*.xml);;All Files (*.*)"
            );
            if (!filePath.isEmpty()) {
                saveDocNodeListToXML(filePath, docNodeList);
            }
    });


    pixmapItem = new QGraphicsPixmapItem();
    view = findChild<ImageGraphicsView*>("graphicsView");
    if (view) {
        view->setPixmapItem(pixmapItem);
    }
    else{
        qDebug() << "view not found";
        return;
    }

    QLabel *viewStatusLabel = new QLabel(view);
    viewStatusLabel->setStyleSheet("QLabel { color: white; background-color: rgba(0, 0, 0, 128); }");
    viewStatusLabel->setFixedSize(200, 20);
    viewStatusLabel->move(10, view->height()-30);

    QLabel *viewStatusLabelPixel = new QLabel(view);
    viewStatusLabelPixel->setStyleSheet("QLabel { color: white; background-color: rgba(0, 0, 0, 128); }");
    viewStatusLabelPixel->setFixedSize(200, 20);
    viewStatusLabelPixel->move(240, view->height()-30);

    connect(view,&ImageGraphicsView::mousePositionChanged,this,[=](int x,int y,QPointF scenePos){
        QPointF itemPos = pixmapItem->mapFromScene(scenePos);
        if(pixmapItem->contains(itemPos)){
            viewStatusLabel->setText(
                QString("Mouse Position: [%1, %2]").arg(int(x)).arg(int(y)));
        }
    });

    connect(view,&ImageGraphicsView::mouseClicked,this,[=](int pixelValue,QPointF scenePos){
        if(pixmapItem->contains(pixmapItem->mapFromScene(scenePos))){
            viewStatusLabelPixel->setText(QString("Pixel Value: [%1]").arg(pixelValue));
        }
    });

}

MainWindow::~MainWindow()
{

    if (m_saveTimer) {
        m_saveTimer->stop();
        delete m_saveTimer;
    }

    delete ui;

    cardWorker1->StopCard(true);
    cardWorker2->StopCard(false);

    cardWorker1->resetCard(true);
    cardWorker2->resetCard(false);

    cardWorker1->clearFIFO(true);
    cardWorker2->clearFIFO(false);

    cardWorker1->closeCard(true);
    cardWorker2->closeCard(false);

    t1->quit();
    t1->wait();
    t2->quit();
    t2->wait();
    t3->quit();
    t3->wait();
    t4->quit();
    t4->wait();
    dataAnalysisHelper1->stopProcessing();
    t_dataAnalysis1->quit();
    t_dataAnalysis1->wait();
    dataAnalysisHelper2->stopProcessing();
    t_dataAnalysis2->quit();
    t_dataAnalysis2->wait();
    dataAnalysisHelperRS422->stopProcessing();
    t_dataAnalysisRS422->quit();
    t_dataAnalysisRS422->wait();

    dataAnalysisHelperLVDS->stopProcessing();
    t_dataAnalysisLVDS->quit();
    t_dataAnalysisLVDS->wait();

    // 程序退出时卸载驱动库
    LVDSCardHelper::UninitLibrary();

}


void MainWindow::addTabItem(QListWidget* listWidget, const QIcon& icon, const QString& text) {
    QListWidgetItem* item = new QListWidgetItem(listWidget);
    item->setSizeHint(QSize(listWidget->width(), 100));
    TabItem* tabWidget = new TabItem(icon, text, listWidget);
    listWidget->setItemWidget(item, tabWidget);
}

void MainWindow::addStackedPage(QStackedWidget* stackedWidget, const QString& pageName) {

    QWidget* page = new QWidget(stackedWidget);
    page->setStyleSheet("background-color: white;");


    QLabel* label = new QLabel(pageName, page);
    label->setStyleSheet("font-size: 20px; color: #666;");
    QVBoxLayout* layout = new QVBoxLayout(page);
    layout->addWidget(label, 0, Qt::AlignCenter);

    stackedWidget->addWidget(page);
}


void MainWindow::onTabItemClicked(QListWidgetItem* item) {

    int index = ui->listWidget->row(item); 
    ui->stackedWidget->setCurrentIndex(index);
    updateTabSelection(index);
}

void MainWindow::onTabItemClicked_2(QListWidgetItem *item) {
    if(!item) return; 
    int index = ui->listWidget_2->row(item);
    ui->stackedWidget_com->setCurrentIndex(index);
    updateTabSelection_2(index);
    QString tabChoose = item->data(Qt::UserRole).toString();
    updateCheckboxesForTab(tabChoose);

    if (!commandList.isEmpty() && index >= 0 && index < commandList.size()) {
        ui->lb_current_cmd_name->setText(commandList.at(index));
    } else {
        ui->lb_current_cmd_name->setText("");
        qWarning() << "索引越界：index=" << index << "，列表大小=" << commandList.size();
    }
}

void MainWindow::updateTabSelection(int selectedIndex) {
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem* item = ui->listWidget->item(i);
        TabItem* tabWidget = qobject_cast<TabItem*>(ui->listWidget->itemWidget(item));
        if (tabWidget) {

            tabWidget->setProperty("isSelected", (i == selectedIndex));
            tabWidget->update();
        }
    }
}

void MainWindow::updateTabSelection_2(int selectedIndex) {
    for (int i = 0; i < ui->listWidget_2->count(); ++i) {
        QListWidgetItem* item = ui->listWidget_2->item(i);
        TabItemSub* tabWidget = qobject_cast<TabItemSub*>(ui->listWidget_2->itemWidget(item));
        if (tabWidget) {
            tabWidget->setProperty("isSelected", (i == selectedIndex));
            tabWidget->update();
        }
    }
}


void MainWindow::updatePortState(bool serialChoose, bool isOpen){
    if(serialChoose){
        ui->pushButton_serialOpenClose->setText(isOpen ? "关闭串口" : "打开串口");
    }
    else{
        ui->pushButton_serialOpenClose_2->setText(isOpen ? "关闭串口" : "打开串口");
    }
}

void MainWindow::refreshSerialPorts()
{
    ui->comboBox_serial->clear();
    ui->comboBox_serial_2->clear();

    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    if(ports.isEmpty()) {
        ui->comboBox_serial->addItem("Null");
        ui->comboBox_serial_2->addItem("Null");
        return;
    }

    foreach(const QSerialPortInfo &port, ports) {
        ui->comboBox_serial->addItem(port.portName() + " (" + port.description() + ")",
                                  port.portName()); // 实际存储的用户数据（这里存的是纯端口名）
        ui->comboBox_serial_2->addItem(port.portName() + " (" + port.description() + ")",
                                  port.portName()); // 实际存储的用户数据（这里存的是纯端口名）
    }
}

void MainWindow::serialOpenClose(bool serialChoose){
    if(serialChoose){
        QString portName = ui->comboBox_serial->currentData().toString();
        if(portName.isEmpty()){
            qmessageBoxSet("请选择有效的串口");
            return;
        }
        int baudRate = ui->comboBox_baudRate->currentData().toInt();
        int dataBit = ui->comboBox_dataBit->currentData().toInt();
        int parity = ui->comboBox_parity->currentData().toInt();
        int stopBit = ui->comboBox_stopBits->currentData().toInt();

        emit initSerialSignal(portName,baudRate,dataBit,parity, stopBit);
        emit openCloseSignal();
    }

    else{

        QString portName = ui->comboBox_serial_2->currentData().toString();
        if(portName.isEmpty()){
            qmessageBoxSet("请选择有效的串口");
            return;
        }

        int baudRate = ui->comboBox_baudRate_2->currentData().toInt();
        int dataBit = ui->comboBox_dataBit_2->currentData().toInt();
        int parity = ui->comboBox_parity_2->currentData().toInt();
        int stopBit = ui->comboBox_stopBits_2->currentData().toInt();

        emit initSerialSignal_2(portName,baudRate,dataBit,parity, stopBit);
        emit openCloseSignal_2();
    }
}

void MainWindow::updatePlainText(bool serialChoose, QString textToShowDirect){
    if(serialChoose){
        pendingData_Serial1.append(textToShowDirect);

        if(isSaveDataSerial1){

            QFile file(saveDirSerial1Txt + fileNameSerial1);
            if(file.open(QIODevice::Append | QIODevice::Text)){
                QTextStream stream(&file);
                stream << textToShowDirect + ' ';
    //            stream << textToShowDirect << "\n";  // 加换行符分隔不同数据块
                file.close();

            } else {
                QMessageBox::warning(this, "错误", "无法打开文件");
                isSaveDataSerial1 = false;
                return;
            }

            QString binFileName = fileNameSerial1;
            binFileName.replace(".txt", ".bin");
            QFile binFile(saveDirSerial1Bin + binFileName);
            if (binFile.open(QIODevice::Append)) {
                QByteArray binaryData = QByteArray::fromHex(textToShowDirect.toLatin1());
                binFile.write(binaryData);
                binFile.close();
            } else {
                QMessageBox::warning(this, "错误", "无法打开 BIN 文件");
                isSaveDataSerial1 = false;
            }
        }
        else{
        }
    }
    else{

        pendingData_Serial2.append(textToShowDirect); // 数据存入缓冲区

        if(isSaveDataSerial2){

            QFile file(saveDirSerial2Txt + fileNameSerial2);
            if(file.open(QIODevice::Append | QIODevice::Text)){
                QTextStream stream(&file);
                stream << textToShowDirect;
                file.close();

            } else {
                QMessageBox::warning(this, "错误", "无法打开文件");
                isSaveDataSerial2 = false;
                return;
            }

            QString binFileName = fileNameSerial2;
            binFileName.replace(".txt", ".bin");
            QFile binFile(saveDirSerial2Bin + binFileName);
            if (binFile.open(QIODevice::Append)) {
                QByteArray binaryData = QByteArray::fromHex(textToShowDirect.toLatin1());
                binFile.write(binaryData);
                binFile.close();
            } else {
                QMessageBox::warning(this, "错误", "无法打开 BIN 文件");
                isSaveDataSerial2 = false;
            }
        }
        else{
        }
    }
}

void MainWindow::updateCheckboxesForTab(const QString &tabName)
{
    ui->checkBox_COMII->setChecked(false);
    ui->checkBox_COMI->setChecked(false);
    ui->checkBox_CARDRS422->setChecked(false);

    if (tabName == "红外相机") {
        ui->checkBox_CARDRS422->setChecked(true);
    }
    else if (tabName == "可见光相机") {
        ui->checkBox_CARDRS422->setChecked(true);
    }
};

void MainWindow::statusBarShowSerial(bool chooseSerial,QString showString){
    if(chooseSerial) ui->plainTextEdit_statusBar_serial->appendPlainText(showString);
    else ui->plainTextEdit_statusBar_serial_2->appendPlainText(showString);
}

void MainWindow::runError(QString errorString){
    qmessageBoxSet(errorString);
}

void MainWindow::updateStatusBar(bool chooseCard,QString errorText){
    statusBarShow(chooseCard, errorText);
}


void MainWindow::handleRS422Data(quint8 channel, QString dataString)
{
    Q_UNUSED(channel);
    dataReceivedRS422(dataString);
}

void MainWindow::handleLVDSData(quint8 channel, QString dataString)
{
    Q_UNUSED(channel);
    dataReceivedLVDS(dataString);
}

void MainWindow::dataReceivedRS422(QString hexString){

    pendingData_RS422.append(hexString);
    if(isSaveDataRs422){
        QFile file(saveDirRS422Txt + fileNameRS422);
        if(file.open(QIODevice::Append | QIODevice::Text)){
            QTextStream stream(&file);
            stream << hexString;
            file.close();

        } else {
            QMessageBox::warning(this, "错误", "无法打开文件");
            isSaveDataRs422 = false;
            return;
        }

        QString binFileName = fileNameRS422; // 创建副本
        binFileName.replace(".txt", ".bin");
        QFile binFile(saveDirRS422Bin + binFileName); // 替换扩展名
        if (binFile.open(QIODevice::Append)) { // 二进制模式无需 QIODevice::TSext
            QByteArray binaryData = QByteArray::fromHex(hexString.toLatin1());
            binFile.write(binaryData); // 直接写入二进制数据
            binFile.close();
        } else {
            QMessageBox::warning(this, "错误", "无法打开 BIN 文件");
            isSaveDataRs422 = false;
        }
    }
    else{
    }
}

void MainWindow::dataReceivedLVDS(QString hexString){
    pendingData_LVDS.append(hexString); // 数据存入缓冲区
    if(isSaveDataLVDS){
        QFile file(saveDirLVDSTxt + fileNameLVDS);
        if(file.open(QIODevice::Append | QIODevice::Text)){
            QTextStream stream(&file);
            stream << hexString;
            file.close();

        } else {
            QMessageBox::warning(this, "错误", "无法打开文件");
            isSaveDataLVDS = false;
            return;
        }

        QString binFileName = fileNameLVDS;
        binFileName.replace(".txt", ".bin");
        QFile binFile(saveDirLVDSBin + binFileName);
        if (binFile.open(QIODevice::Append)) {
            QByteArray binaryData = QByteArray::fromHex(hexString.toLatin1());
            binFile.write(binaryData);
            binFile.close();
        } else {
            QMessageBox::warning(this, "错误", "无法打开 BIN 文件");
            isSaveDataLVDS = false;
        }
    }
    else{
    }
}



void MainWindow::cardOpenBtn(bool chooseCard){
     QString chooseCardString;
     if(chooseCard) chooseCardString = "RS422";
     else chooseCardString = "LVDS";
     statusBarShow(false, "当前选择的板卡是：" + chooseCardString);


    int cardCount = 2;
    if(cardCount==0){
        ui->pushButton_cardOpenClose->setChecked(false);
        qmessageBoxSet("未检测到板卡！");
        return;
    }
    else{

        if(chooseCard){

            if(ui->pushButton_cardOpenClose->isChecked()){
                quint8 currentChannelNo422 = static_cast<quint8>(ui->comboBox_channelNumRS422->currentData().toInt()); // BYTE 获取当前通道数
                statusBarShow(false, "当前选择通道号是：" + QString::number(currentChannelNo422));
                cardWorker1->openCard(true); //打开板卡
                cardWorker1->resetCard(true); // 板卡复位
                cardWorker1->clearFIFO(true); //清理缓存

                // 新驱动不支持通道配置，以下代码已注释
                // ST_LVDS_CFG stCfgRS422;
                //     memset(&stCfgRS422,0,sizeof(stCfgRS422));
                //     stCfgRS422.dwBaudRate   = ui->comboBox_baudRate_card->currentData().toUInt();//波特率 DWORD
                //     stCfgRS422.ucDataBits   = static_cast<UCHAR>(ui->comboBox_dataBit_card->currentData().toUInt());//数据位; UCHAR
                //     stCfgRS422.ucParity     = static_cast<UCHAR>(ui->comboBox_parity_card->currentData().toUInt());//校验位 UCHAR
                //     stCfgRS422.ucStopBits   = static_cast<UCHAR>(ui->comboBox_stopBits_card->currentData().toUInt());//停止位 UCHAR
                // qDebug()<<stCfgRS422.dwBaudRate;
                // qDebug()<<stCfgRS422.ucDataBits;
                // qDebug()<<stCfgRS422.ucParity;
                // qDebug()<<stCfgRS422.ucStopBits;

                cardWorker1->setChannelNum(true, currentChannelNo422);
                cardWorker1->configLVDSCardFrame(true);

                // 新驱动不支持通道配置，以下代码已注释
                // bool channelSet = cardWorker1->configChannelPara(true,false,currentChannelNo422,stCfgRS422);
                // if(channelSet){
                //     statusBarShow(true, QString("初始化发送通道%1成功：波特率：%2，数据位：%3，校验位：%4，停止位：%5").arg(currentChannelNo422).arg(stCfgRS422.dwBaudRate).arg(stCfgRS422.ucDataBits).arg(stCfgRS422.ucParity).arg(stCfgRS422.ucStopBits));
                // }
                // else statusBarShow(true, QString("初始化发送通道%1失败：波特率：%2，数据位：%3，校验位：%4，停止位：%5").arg(currentChannelNo422).arg(stCfgRS422.dwBaudRate).arg(stCfgRS422.ucDataBits).arg(stCfgRS422.ucParity).arg(stCfgRS422.ucStopBits));
                // bool channelSetRec = cardWorker1->configChannelPara(true,true,currentChannelNo422,stCfgRS422);
                // if(channelSetRec){
                //     statusBarShow(true, QString("初始化接收通道%1成功：波特率：%2，数据位：%3，校验位：%4，停止位：%5").arg(currentChannelNo422).arg(stCfgRS422.dwBaudRate).arg(stCfgRS422.ucDataBits).arg(stCfgRS422.ucParity).arg(stCfgRS422.ucStopBits));
                // }
                // else statusBarShow(true, QString("初始化接收通道%1失败：波特率：%2，数据位：%3，校验位：%4，停止位：%5").arg(currentChannelNo422).arg(stCfgRS422.dwBaudRate).arg(stCfgRS422.ucDataBits).arg(stCfgRS422.ucParity).arg(stCfgRS422.ucStopBits));
                statusBarShow(true, QString("新驱动不支持通道配置"));

                bool cardStatus = cardStatus = cardWorker1->getLVDSCardOpenStatus(true);
                if(cardStatus){
                    ui->pushButton_cardOpenClose->setText("关闭");
                }
                else{
                    qmessageBoxSet("RS422板卡打开失败！");
                    ui->pushButton_cardOpenClose->setChecked(false);
                }
            }
            else{
                bool isStartCheck = cardWorker1->StopCard(true);
                if(isStartCheck){
                    statusBarShow(true, "RS422板卡去使能成功！");
                    ui->pushButton_startLVDS->setChecked(false);
                    ui->pushButton_startLVDS->setText("使能");
                    t1->quit();      // 请求线程退出
                    t1->wait();

                }
                else{
                    statusBarShow(true, "RS422板卡去使能失败！");
                    ui->pushButton_startLVDS->setChecked(true);
                    ui->pushButton_startLVDS->setText("停止");
                }

                cardWorker1->closeCard(true);
                bool cardIsClosed = cardWorker1->getLVDSCardOpenStatus(true);
                if(!cardIsClosed){
                    ui->pushButton_cardOpenClose->setText("打开");
                    ui->pushButton_cardOpenClose->setChecked(false);
                }
                else{
                    qmessageBoxSet("RS422板卡关闭失败！");
                    ui->pushButton_cardOpenClose->setText("关闭");
                    ui->pushButton_cardOpenClose->setChecked(true);
                }
            }
        }

        else {
            if(ui->pushButton_cardOpenClose_2->isChecked()){
                quint8 currentChannelNoLVDS = static_cast<quint8>(ui->comboBox_channelNumLVDS->currentData().toInt()); // BYTE 获取当前通道数
                cardWorker2->openCard(false); //打开板卡
                cardWorker2->resetCard(false); // 板卡复位
                cardWorker2->clearFIFO(false); //清理缓存

                // 新驱动不支持通道配置，以下代码已注释
                // ST_LVDS_CFG stCfgLVDS;
                //     memset(&stCfgLVDS,0,sizeof(stCfgLVDS));
                //     stCfgLVDS.dwBaudRate   = ui->comboBox_baudRate_card->currentData().toUInt();//波特率 DWORD
                //     stCfgLVDS.ucDataBits   = static_cast<UCHAR>(ui->comboBox_dataBit_card->currentData().toUInt());//数据位; UCHAR
                //     stCfgLVDS.ucParity     = static_cast<UCHAR>(ui->comboBox_parity_card->currentData().toUInt());//校验位 UCHAR
                //     stCfgLVDS.ucStopBits   = static_cast<UCHAR>(ui->comboBox_stopBits_card->currentData().toUInt());//停止位 UCHAR
                // qDebug()<<stCfgLVDS.dwBaudRate;
                // qDebug()<<stCfgLVDS.ucDataBits;
                // qDebug()<<stCfgLVDS.ucParity;
                // qDebug()<<stCfgLVDS.ucStopBits;

                cardWorker2->setChannelNum(false, currentChannelNoLVDS);
                cardWorker2->configLVDSCardFrame(false);

                // 新驱动不支持通道配置，以下代码已注释
                // bool channelSet = cardWorker2->configChannelPara(false,false,currentChannelNoLVDS,stCfgLVDS);
                // if(channelSet){
                //     statusBarShow(false, "成功初始化发送通道");
                // }
                // else statusBarShow(false, "初始化发送通道失败");
                // bool channelSetRec = cardWorker2->configChannelPara(false,true,currentChannelNoLVDS,stCfgLVDS);
                // if(channelSetRec){
                //     statusBarShow(false, "成功初始化接收通道");
                // }
                // else statusBarShow(false, "初始化接收通道失败");
                statusBarShow(false, "新驱动不支持通道配置");

                bool cardStatus = cardStatus = cardWorker2->getLVDSCardOpenStatus(false);
                if(cardStatus){
                    ui->pushButton_cardOpenClose_2->setText("关闭");
                }
                else{
                    qmessageBoxSet("LVDS板卡打开失败！");
                    ui->pushButton_cardOpenClose_2->setChecked(false);
                }
            }
            else{

                bool isStartCheck = cardWorker2->StopCard(false);
                if(isStartCheck){
                    statusBarShow(false, "LVDS板卡去使能成功！");
                    ui->pushButton_startLVDS_2->setChecked(false);
                    ui->pushButton_startLVDS_2->setText("使能"); 
                    t2->quit();
                    t2->wait();

                }
                else{
                    statusBarShow(false, "lvds板卡去使能失败！");
                    ui->pushButton_startLVDS_2->setChecked(true);
                    ui->pushButton_startLVDS_2->setText("停止");
                }

                cardWorker2->closeCard(false); 
                bool cardIsClosed = cardWorker2->getLVDSCardOpenStatus(false);
                if(!cardIsClosed){
                    ui->pushButton_cardOpenClose_2->setText("打开");
                    ui->pushButton_cardOpenClose_2->setChecked(false);
                }
                else{
                    qmessageBoxSet("lvds板卡关闭失败！");
                    ui->pushButton_cardOpenClose_2->setText("关闭");
                    ui->pushButton_cardOpenClose_2->setChecked(true);
                }
            }
        }
    }
}

void MainWindow::qmessageBoxSet(QString errorString){
    QMessageBox::warning(this,"错误",errorString);
}


void MainWindow::addCMDList(bool insertOrAdd)
{
    QWidget* currentPage = ui->stackedWidget_com->currentWidget();
    QTableWidget* currentTable = qobject_cast<QTableWidget*>(currentPage);
    if (!currentTable) {
        QMessageBox::warning(this, "错误", "当前未显示任何指令表格！");
        return;
    }

    int tempIndexListWidget = ui->listWidget_2->currentRow();
    if(tempIndexListWidget < 0){
        QMessageBox::warning(this,"错误","未选择指令模板！");
        return;
    }

    QDomElement elem = docNodeInitList[tempIndexListWidget];
    QDomNodeList commandParaList = elem.elementsByTagName("CommandPara");

    for(int row = 0; row < currentTable->rowCount(); ++row)
    {
        QDomElement elemCommandPara = commandParaList.at(row).toElement();
        QWidget* w = currentTable->cellWidget(row,2);
        if(QComboBox* combo = qobject_cast<QComboBox*>(w))
        {
            int comboIndex = combo->currentIndex();
            elemCommandPara.setAttribute("CommandParaInitSelectD", comboIndex);
        }

        else if(QTableWidgetItem* editItem = currentTable->item(row,2))
        {
            QVariant data = editItem->data(Qt::UserRole);
            if(data.isValid())
            {
                QString value = editItem->text();
                QString hex   = currentTable->item(row,3)->text();

                QDomNodeList paraList = elemCommandPara.elementsByTagName("Para");
                QDomElement elemPara = paraList.at(0).toElement();

                elemPara.setAttribute("ParaInitCode", value);
                elemPara.setAttribute("ParaRawCodeH", hex);
            }
        }
    }


    int sourceColumnIdx = 3;
    QStringList sourceCodes;

    for (int row = 0; row < currentTable->rowCount(); ++row)
    {
        QTableWidgetItem* sourceItem = currentTable->item(row, sourceColumnIdx);
        if (!sourceItem) continue;

        QString sourceText = sourceItem->text().trimmed();
        if (sourceText.isEmpty()) continue;

        sourceCodes << sourceText.toUpper();
    }

    if (sourceCodes.isEmpty()) {
        QMessageBox::critical(this, "错误", "未收集到任何有效源码！");
        return;
    }

    QString commandSequence = sourceCodes.join("");
    int timeStamp = ui->spinBox->value();

    QTableWidget* targetTable = ui->tableWidget_cmd_immediately;

    QDomElement original = docNodeInitList[tempIndexListWidget];
    QDomElement clonedElement = original.cloneNode(true).toElement();

    if(!insertOrAdd)
    {
        int addNewRow = targetTable->rowCount();
        targetTable->insertRow(addNewRow);

        targetTable->setItem(addNewRow, 0, new QTableWidgetItem(QString::number(timeStamp)));
        targetTable->setItem(addNewRow, 1, new QTableWidgetItem(ui->lb_current_cmd_name->text()));
        targetTable->setItem(addNewRow, 2, new QTableWidgetItem(commandSequence));
        targetTable->setItem(addNewRow, 3, new QTableWidgetItem("手动添加"));

        docNodeList.append(clonedElement);
    }
    else
    {
        int insertNewRow = targetTable->currentRow() + 1;
        if (insertNewRow <= 0) {
            QMessageBox::warning(this, "提示", "请先选中一行指令再执行该操作");
            return;
        }

        targetTable->insertRow(insertNewRow);

        targetTable->setItem(insertNewRow, 0, new QTableWidgetItem(QString::number(timeStamp)));
        targetTable->setItem(insertNewRow, 1, new QTableWidgetItem(ui->lb_current_cmd_name->text()));
        targetTable->setItem(insertNewRow, 2, new QTableWidgetItem(commandSequence));
        targetTable->setItem(insertNewRow, 3, new QTableWidgetItem("手动添加"));

        docNodeList.insert(insertNewRow, clonedElement);
    }

    targetTable->scrollToBottom();
}

void MainWindow::saveDocNodeListToXML(const QString &filePath, QList<QDomElement> &docNodeList)
{
    QDomDocument doc;

    QDomElement root = doc.createElement("SYSTEM");
    doc.appendChild(root);

    for (int i = 0; i < docNodeList.size(); ++i) {
        QDomElement &cmd = docNodeList[i];  // 引用，直接修改
        if (QTableWidgetItem *item = ui->tableWidget_cmd_immediately->item(i, 0)) {
            updateCommandAttribute(cmd, "CommandTimeD", item->text());
        }
        if (QTableWidgetItem *item = ui->tableWidget_cmd_immediately->item(i, 3)) {
            updateCommandAttribute(cmd, "RemarksD", item->text());
        }
        QDomNode imported = doc.importNode(cmd, true);
        root.appendChild(imported);
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::warning(this, "保存失败", "无法保存XML文件: " + filePath);
        return;
    }

    QTextStream out(&file);
    doc.save(out, 4);
    file.close();

    QMessageBox::information(this, "保存成功", "文件已保存到:\n" + filePath);
}

void MainWindow::updateCommandAttribute(QDomElement &commandElem,
                            const QString &attrName,
                            const QString &newValue)
{
    if (commandElem.isNull()) return;
    commandElem.setAttribute(attrName, newValue);
}

void MainWindow::onListWidgetContextMenuRequested(const QPoint &pos)
{

    QListWidgetItem *item = ui->listWidget_2->itemAt(pos);
    if (!item) return;

    QMenu menu(this);
    QAction *deleteAction = menu.addAction("删除该项");

    QAction *selectedAction = menu.exec(ui->listWidget_2->mapToGlobal(pos));
    if (selectedAction == deleteAction) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "确认删除",
                                      QString("确定要删除“%1”吗？").arg(item->text()),
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int row = ui->listWidget_2->row(item);
            delete ui->listWidget_2->takeItem(row);
            xmlcommandparser->deleteComChoose(row);
            docNodeInitList.removeAt(row);
            if (row < commandList.size()) {
                commandList.removeAt(row);
            }
            if (row < ui->stackedWidget_com->count()) {
                QWidget *widget = ui->stackedWidget_com->widget(row);
                ui->stackedWidget_com->removeWidget(widget);
                delete widget;
            }
        }
    }
}

void MainWindow::sendCMD(int sendIndex, bool directOrList)
{

    int columnCount = ui->tableWidget_cmd_immediately->columnCount();
    if(columnCount<1){
        QMessageBox::warning(this, "提示", "请配置并载入指令序列");
        return;
    }
    int row = -1;
    if(!directOrList){
       row = sendIndex;
    }
    else {
        row = ui->tableWidget_cmd_immediately->currentRow(); // 获取当前选中行
    }

    if (row == -1) {
        QMessageBox::warning(this, "提示", "请选需要发送的立即令序列");
        return;
    }

    int sourceColumnIndex = -1;
    for (int col = 0; col < columnCount; ++col) {
        QString headerText = ui->tableWidget_cmd_immediately->horizontalHeaderItem(col)->text();
        if (headerText == "源码") {
            sourceColumnIndex = col;
            break;
        }
    }
    if(sourceColumnIndex == -1){
        QMessageBox::warning(this, "提示", "当前指令序列中没有“源码”");
        return;
    }

    QString tempStringData = ui->tableWidget_cmd_immediately->item(row,sourceColumnIndex)->text();

     QString frameHead;
     QString frameTail;
     int checkSumLength;
     QDomElement  tempElem  = docNodeList.at(row).toElement();
     frameHead  = tempElem.attribute("FrameHeader");
     frameTail = tempElem.attribute("FrameTail");
     checkSumLength = tempElem.attribute("CheckSumLength").toInt();

    QByteArray immediateCommand = dataTransfer->string2Bytearray(tempStringData);
    QByteArray checkSum =  frameHelper->frameChecksum(immediateCommand,checkSumLength);
    QString checkSumString = QString(checkSum.toHex().toUpper());

    QString frameHead0 = "B9E0";
    QString byteDataSendString = frameHead + tempStringData + checkSumString + frameTail;
    QByteArray byteDataSend = dataTransfer->string2Bytearray(byteDataSendString);

    if(ui->checkBox_COMI->isChecked()) emit writeDataSignal(byteDataSend);
    if(ui->checkBox_COMII->isChecked()) emit writeDataSignal_2(byteDataSend);
    if (ui->checkBox_CARDRS422->isChecked()){
        bool cardOpenStatus = cardWorker1->getLVDSCardOpenStatus(false);
        if(!cardOpenStatus){
            qmessageBoxSet("发送失败，RS422板卡未打开！");
            return;
        }
        else {
            quint8 channel = cardWorker1->getChannelNum(true);
            DWORD dwSendRet = cardWorker1->sendData(true,channel, reinterpret_cast<quint8*>(byteDataSend.data()), static_cast<size_t>(byteDataSend.length())); // 新的写法
        }
    }
}

void MainWindow::delCMDList()
{
    int row = ui->tableWidget_cmd_immediately->currentRow();
    if (row >= 0) {
        ui->tableWidget_cmd_immediately->removeRow(row);

        docNodeList.removeAt(row);
    } else {
        QMessageBox::warning(this, "提示", "请先选中要删除的行");
    }

}

void MainWindow::clearCMDList()
{
    ui->tableWidget_cmd_immediately->setRowCount(0);
    docNodeList.clear();
    ui->tableWidget_cmd_immediately->setColumnCount(4);
    ui->tableWidget_cmd_immediately->setHorizontalHeaderLabels({
        "时间戳（秒）",    // 列0
        "名称",// 列1
        "源码"  ,       // 列2
        "备注"         // 列3
    });

}

QSize MainWindow::lastSize = QSize();  // ✅ 静态成员变量定义：在类中声明了静态变量，所有静态成员变量都必须在类外再定义一次，否则链接器（linker）会找不到它的地址


void MainWindow::saveImgSingle()
{

    QGraphicsScene *currentScene = ui->graphicsView->scene();
    if(!currentScene){
       qmessageBoxSet("保存图像失败，图像框中没有关联scene!");
       return;
    }

    QGraphicsPixmapItem *pixmapItem = nullptr;
    for (QGraphicsItem *item : currentScene->items()) {
        pixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem *>(item);
        if (pixmapItem) {
            break;
        }
    }

    if (!pixmapItem) {
        QMessageBox::information(this, "提示", "图像框中没有图像！");
        return;
    }

    QPixmap pixmap = pixmapItem->pixmap();
    QDateTime currentTime = QDateTime::currentDateTime();
    QString fileNameSingle = saveDirLVDSImgSingle + currentTime.toString("yyyyMMdd_hhmmss") + ".bmp"; /// 这里不能使用jpg，使用jpg会在光斑周围产生很多杂乱像素
    if (!pixmap.isNull()) {
        if (!fileNameSingle.isEmpty()) {
            if (!pixmap.save(fileNameSingle)) {
                QMessageBox::warning(this, "错误", "保存图像失败！");
            } else {
                if(ui->checkBox_overGrayScaleCoordinates->isChecked()){
                    QString fileNameExcel = saveDirLVDSImgSingle + currentTime.toString("yyyyMMdd_hhmmss") + ".csv"; /// 这里不能使用jpg，使用jpg会在光斑周围产生很多杂乱像素
                    QFile file(fileNameExcel);
                        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
                            qWarning() << "Cannot open file for writing:" << fileNameExcel;
                            return;
                        }

                        QTextStream out(&file);
                        out << "X,Y\n";  // 可选：写表头
                        for(const QPoint &pt : overThresholdCoords){
                            out << pt.x() << "," << pt.y() << "\n";  // 每个坐标一行
                        }
                        file.close();
                }
                QMessageBox::information(this, "成功", "图像保存成功！");
            }
        }
    } else {
        QMessageBox::warning(this, "错误", "图像数据为空！");
    }
}

void MainWindow::saveImgSpan()
{
    if(!ui->pushButton_beginSaveImages_2->isChecked()){
        ui->pushButton_beginSaveImages_2->setChecked(true);
        qmessageBoxSet("请等待当前保存任务结束");
        return;
    }

    QString saveImgTime = ui->lineEdit_saveImagesTime_2->text();
    double saveImgTimeDouble = saveImgTime.toDouble();
    QDateTime currentTime = QDateTime::currentDateTime();
    LVDSImgSpanName = saveDirLVDSImgSpan + currentTime.toString("yyyyMMdd_hhmmss") + "-" + saveImgTime + "s/";
    QDir imgFolderSpan(LVDSImgSpanName);
    if(!imgFolderSpan.exists()){
        if(!imgFolderSpan.mkpath(".")){
            QMessageBox::critical(this, "错误", "无法创建目录: " + LVDSImgSpanName);
            return;
        }
    }
    isSaveImgLVDS = true;
    ui->pushButton_beginSaveImages_2->setChecked(true);
    ui->pushButton_beginSaveImages_2->setText("保存中");
    QTimer::singleShot(static_cast<int>(saveImgTimeDouble * 1000), this, [this](){
        isSaveImgLVDS = false;
        ui->pushButton_beginSaveImages_2->setChecked(false);
        ui->pushButton_beginSaveImages_2->setText("开始保存");
        QMessageBox::information(this, "保存完成", "图像已保存完毕");
    });
}

void MainWindow::showImage(QImage image)
{  
    ui->graphicsView->scene()->clear();
    pixmapItem->setPixmap(QPixmap::fromImage(image));
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    ui->graphicsView->scene()->addItem(item);

    if (image.size() != lastSize){
       lastSize  =  image.size();
       ui->graphicsView->setSceneRect(item->boundingRect().adjusted(-1000, -1000, 1000, 1000));  // adjusted(left, top, right, bottom)
    }
    if(isSaveImgLVDS){
        QDateTime currentTime = QDateTime::currentDateTime();
        QString imgNameSpan = LVDSImgSpanName + currentTime.toString("yyyyMMdd_hhmmss_zzz") + ".bmp";

        QGraphicsScene *currentScene = ui->graphicsView->scene();
        if(!currentScene){
           qmessageBoxSet("保存图像失败，图像框中没有关联scene!");
           return;
        }


        QGraphicsPixmapItem *pixmapItem = nullptr;
        for (QGraphicsItem *item : currentScene->items()) {
            pixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem *>(item);
            if (pixmapItem) {
                break;
            }
        }

        if (!pixmapItem) {
            QMessageBox::information(this, "提示", "图像框中没有图像！");
            return;
        }


        QPixmap pixmap = pixmapItem->pixmap();
        if (!pixmap.isNull()) {
            if (!imgNameSpan.isEmpty()) {
                if (!pixmap.save(imgNameSpan)) {
                    QMessageBox::warning(this, "错误", "保存图像失败！");
                }
            }
        } else {
            QMessageBox::warning(this, "错误", "图像数据为空！");
        }
    }
}

void MainWindow::readTmXML(QString xmlFiles)
{
    xmlcommandparser->loadTmXML(xmlFiles);
}

void MainWindow::readXML(QString xmlFiles, bool setCurrentToNew)
{
    if (xmlcommandparser->loadXML(xmlFiles,docNodeInitList)) {

        int rowCom = 0;
        xmlcommandparser->populateStackedWidget(ui->stackedWidget_com, ui->listWidget_2,setCurrentToNew, docNodeInitList, rowCom); // 将 CommandList中的每一个Command模块（一般是一个xml） 填入 ui 中的 QTabWidget
    }
}


void MainWindow::readXML2(QString xmlFiles)
{
    xmlcommandparser->loadXML2(xmlFiles,docNodeList);
}


void MainWindow::addRowToInterestTable(int row)
{
    int newRow = rowSort.size();
    for (int k = 0; k < rowSort.size();++k) {
        if(row<rowSort.at(k)){
            newRow = k;
            break;
        }
    }
    rowSort.insert(newRow,row);

    QList<QStandardItem*> items;
    for (int col = 0; col < modelMain->columnCount(); ++col) {

        if (col == 5) continue;
        QStandardItem *item = modelMain->item(row, col);
        if (item) {
            items.append(new QStandardItem(item->text()));
        }
    }
    modelInterest->insertRow(newRow,items);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::removeRowFromInterestTable(int row)
{
    QString id = modelMain->item(row, 0)->text();
    for (int r = 0; r < modelInterest->rowCount(); ++r) {
        if (modelInterest->item(r, 0)->text() == id) {
            modelInterest->removeRow(r);
            break;
        }
    }
    int index = rowSort.indexOf(row);
    if(index != -1) rowSort.removeAt(index);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::init()
{
    readTmXML(xmlTmPath);
}



void MainWindow::statusBarShow(bool chooseCard,QString showString){
    if(chooseCard) ui->plainTextEdit_statusBar->appendPlainText(showString);
    else ui->plainTextEdit_statusBar_2->appendPlainText(showString);
}


void MainWindow::on_stopSaveButton_clicked()
{
    if (m_saveTimer && m_saveTimer->isActive()) {
        m_saveTimer->stop();

        isSaveTMFile = false;
        ui->pb_begin_save_data->setChecked(false);
        ui->pb_begin_save_data->setText("开始");
        QMessageBox::information(this, "保存已取消", "数据保存已被中途停止");
    }
}
