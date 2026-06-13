/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imagegraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget_12;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget_init;
    QWidget *tab_serial;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QComboBox *comboBox_serial;
    QLabel *label_2;
    QComboBox *comboBox_baudRate;
    QLabel *label_3;
    QComboBox *comboBox_dataBit;
    QLabel *label_4;
    QComboBox *comboBox_parity;
    QLabel *label_5;
    QComboBox *comboBox_stopBits;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *pushButton_serialOpenClose;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_6;
    QPlainTextEdit *plainTextEdit_send_serial;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_send_serial;
    QPushButton *pushButton_clearSend_serial;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit_receive_serial;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_saveDataSerial;
    QLineEdit *lineEdit_saveDataTimeSerial;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_clearReceive_serial;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_21;
    QPlainTextEdit *plainTextEdit_statusBar_serial;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_25;
    QWidget *widget_13;
    QVBoxLayout *verticalLayout_22;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_15;
    QComboBox *comboBox_serial_2;
    QLabel *label_16;
    QComboBox *comboBox_baudRate_2;
    QLabel *label_17;
    QComboBox *comboBox_dataBit_2;
    QLabel *label_18;
    QComboBox *comboBox_parity_2;
    QLabel *label_19;
    QComboBox *comboBox_stopBits_2;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *pushButton_serialOpenClose_2;
    QSpacerItem *horizontalSpacer_12;
    QGroupBox *groupBox_15;
    QVBoxLayout *verticalLayout_23;
    QPlainTextEdit *plainTextEdit_send_serial_2;
    QHBoxLayout *horizontalLayout_25;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_send_serial_2;
    QPushButton *pushButton_clearSend_serial_2;
    QGroupBox *groupBox_16;
    QVBoxLayout *verticalLayout_24;
    QPlainTextEdit *plainTextEdit_receive_serial_2;
    QHBoxLayout *horizontalLayout_26;
    QPushButton *pushButton_saveDataSerial_2;
    QLineEdit *lineEdit_saveDataTimeSerial_2;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_clearReceive_serial_2;
    QGroupBox *groupBox_17;
    QHBoxLayout *horizontalLayout_27;
    QPlainTextEdit *plainTextEdit_statusBar_serial_2;
    QWidget *tab_card;
    QHBoxLayout *horizontalLayout_20;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLineEdit *lineEdit_cardCount;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_cardOpenClose;
    QPushButton *pushButton_startLVDS;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_clearFIFO;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QComboBox *comboBox_channelNumRS422;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QComboBox *comboBox_baudRate_card;
    QLabel *label_8;
    QComboBox *comboBox_dataBit_card;
    QLabel *label_9;
    QComboBox *comboBox_parity_card;
    QLabel *label_10;
    QComboBox *comboBox_stopBits_card;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit_send;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_send;
    QPushButton *pushButton_clearSend;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *plainTextEdit_receive;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_saveDataRS422;
    QLineEdit *lineEdit_saveTimeRS422;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_clearReceive;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit_statusBar;
    QWidget *tab;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_14;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_32;
    QLineEdit *lineEdit_cardCount_2;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_cardOpenClose_2;
    QPushButton *pushButton_startLVDS_2;
    QPushButton *pushButton_reset_2;
    QPushButton *pushButton_clearFIFO_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_34;
    QComboBox *comboBox_channelNumLVDS;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_35;
    QComboBox *comboBox_baudRate_card_2;
    QLabel *label_36;
    QComboBox *comboBox_dataBit_card_2;
    QLabel *label_37;
    QComboBox *comboBox_parity_card_2;
    QLabel *label_38;
    QComboBox *comboBox_stopBits_card_2;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_15;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_16;
    QPlainTextEdit *plainTextEdit_send_2;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_send_2;
    QPushButton *pushButton_clearSend_2;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_17;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_19;
    QPlainTextEdit *plainTextEdit_receive_2;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_saveDataLVDS;
    QLineEdit *lineEdit_saveTimeLVDS;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_clearReceive_2;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_17;
    QGroupBox *groupBox_13;
    QHBoxLayout *horizontalLayout_18;
    QPlainTextEdit *plainTextEdit_statusBar_2;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_33;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_28;
    QWidget *widget_16;
    QVBoxLayout *verticalLayout_20;
    QListWidget *listWidget_2;
    QPushButton *pushButton_import_com_xml;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout;
    QLabel *label_21;
    QLabel *lb_local_count;
    QLabel *label_31;
    QLabel *lb_time;
    QLabel *label_33;
    QLabel *lb_cmd_id;
    QLabel *label_39;
    QLabel *lb_result;
    QLabel *label_40;
    QLabel *lb_error_type;
    QTextEdit *te_response_result;
    QWidget *widget_17;
    QVBoxLayout *verticalLayout_21;
    QWidget *widget_18;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_41;
    QLabel *lb_current_cmd_name;
    QStackedWidget *stackedWidget_com;
    QWidget *page_5;
    QWidget *widget_19;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_cardCom;
    QPushButton *pushButton_sendCardCom;
    QPushButton *pb_del_cmd;
    QPushButton *pb_clear_cmd;
    QPushButton *pb_insert_cmd;
    QPushButton *pb_add_cmd;
    QWidget *widget_20;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_42;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pb_send_cmd_immediately;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_34;
    QSpacerItem *horizontalSpacer_17;
    QCheckBox *checkBox_COMI;
    QLabel *label_52;
    QCheckBox *checkBox_COMII;
    QLabel *label_53;
    QCheckBox *checkBox_CARDRS422;
    QLabel *label_54;
    QCheckBox *checkBox_CARDLVDS;
    QLabel *label_55;
    QTableWidget *tableWidget_cmd_immediately;
    QWidget *widget_21;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *pb_import_xml;
    QPushButton *pushButton_editPara;
    QPushButton *pb_export_xml;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pb_send_cmd;
    QWidget *page_2;
    QGridLayout *gridLayout_6;
    QWidget *widget_22;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBox_20;
    QVBoxLayout *verticalLayout_29;
    QTableView *tableView;
    QGroupBox *groupBox_21;
    QVBoxLayout *verticalLayout_30;
    QTableView *tableView_2;
    QWidget *widget_23;
    QVBoxLayout *verticalLayout_31;
    QGroupBox *groupBox_22;
    QVBoxLayout *verticalLayout_32;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_61;
    QSpinBox *sb_request_interval;
    QPushButton *pb_begin_request;
    QGroupBox *groupBox_23;
    QGridLayout *gridLayout_5;
    QLabel *label_69;
    QLabel *lb_recv_tm_data_time;
    QLabel *label_68;
    QLineEdit *le_frame_total_count;
    QLabel *label_74;
    QLineEdit *le_frame_crc_wrong_count;
    QLabel *label_81;
    QLineEdit *le_frame_crc_success_count;
    QPushButton *pb_clear_frame_errors;
    QLabel *lb_frame_success_status;
    QLabel *lb_frame_crc_wrong_status;
    QLabel *lb_frame_timeout_status;
    QGroupBox *groupBox_24;
    QVBoxLayout *verticalLayout_33;
    QHBoxLayout *horizontalLayout_37;
    QRadioButton *rb_save_data_manual;
    QRadioButton *rb_save_data_auto;
    QHBoxLayout *horizontalLayout_38;
    QPushButton *pb_begin_save_data;
    QSpinBox *sb_time;
    QHBoxLayout *horizontalLayout_39;
    QLabel *label_62;
    QLabel *lb_status_show;
    QGroupBox *groupBox_25;
    QVBoxLayout *verticalLayout_34;
    QTextEdit *te_tm_info;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_40;
    QHBoxLayout *horizontalLayout_36;
    QGroupBox *groupBox_18;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_centroidX;
    QLineEdit *lineEdit_maxGray;
    QLineEdit *lineEdit_centroidY;
    QLabel *label_49;
    QLabel *label_50;
    QLineEdit *lineEdit_validCentroidFameNum;
    QLabel *label_46;
    QLineEdit *lineEdit_errorCentroidFameNum;
    QLineEdit *lineEdit_minGray;
    QLabel *label_48;
    QLabel *label_47;
    QLineEdit *lineEdit_totalCentroidFameNum;
    QLineEdit *lineEdit_overGrayscaleNum;
    QLabel *label_45;
    QLineEdit *lineEdit_grayscaleSum;
    QLabel *label_51;
    QLineEdit *lineEdit_exposureTime;
    QLabel *label_44;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_19;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_58;
    QLineEdit *lineEdit_elecCurrSEL;
    QLabel *label_57;
    QLineEdit *lineEdit_temFPGA;
    QLabel *label_56;
    QLineEdit *lineEdit_temTEC;
    QLabel *label_59;
    QLineEdit *lineEdit_TemVtemp;
    QLabel *label_60;
    QLineEdit *lineEdit_statusSEL;
    QLabel *label_73;
    QLineEdit *lineEdit_numOvercurr;
    QLabel *label_75;
    QLineEdit *lineEdit_recordNumOvercurr;
    QLabel *label_76;
    QLineEdit *lineEdit_samplingValueOvercurr;
    QLabel *label_77;
    QLineEdit *lineEdit_cameraExpoMode;
    QLabel *label_78;
    QLineEdit *lineEdit_deadPixelCorrMode;
    QLabel *label_79;
    QLineEdit *lineEdit_imageDataSource;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_28;
    ImageGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_35;
    QSpacerItem *horizontalSpacer_18;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_saveImage_2;
    QPushButton *pushButton_beginSaveImages_2;
    QLineEdit *lineEdit_saveImagesTime_2;
    QLabel *label_30;
    QCheckBox *checkBox_overGrayScaleCoordinates;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QLabel *label_23;
    QLineEdit *lineEdit_imageFrameNum_2;
    QLabel *label_28;
    QLineEdit *lineEdit_falseFrameNum_2;
    QLineEdit *lineEdit_imageWindowSize_2;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_29;
    QLabel *label_27;
    QLineEdit *lineEdit_frameNum_2;
    QLineEdit *lineEdit_timeCode_2;
    QLineEdit *lineEdit_rightFrameNum_2;
    QGroupBox *groupBox_26;
    QGridLayout *gridLayout_7;
    QLabel *label_43;
    QLabel *label_63;
    QLineEdit *lineEdit_ImgCentroidY;
    QLabel *label_25;
    QLineEdit *lineEdit_ImgCentroidX;
    QLineEdit *lineEdit_grayThre_2;
    QLabel *label_64;
    QLineEdit *lineEdit_peakingThreshold;
    QLabel *label_65;
    QLineEdit *lineEdit_oversizeNum_2;
    QCheckBox *checkBox_peaking;
    QLabel *label_26;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1450, 835);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_11 = new QHBoxLayout(centralwidget);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        widget_12 = new QWidget(centralwidget);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setMinimumSize(QSize(95, 0));
        widget_12->setMaximumSize(QSize(95, 16777215));
        listWidget = new QListWidget(widget_12);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(9, 9, 85, 694));
        listWidget->setMinimumSize(QSize(85, 0));
        listWidget->setMaximumSize(QSize(85, 16777215));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_11->addWidget(widget_12);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_10 = new QVBoxLayout(page);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        widget_4 = new QWidget(page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMaximumSize(QSize(1222222, 16777215));
        verticalLayout_7 = new QVBoxLayout(widget_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tabWidget_init = new QTabWidget(widget_4);
        tabWidget_init->setObjectName(QString::fromUtf8("tabWidget_init"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget_init->sizePolicy().hasHeightForWidth());
        tabWidget_init->setSizePolicy(sizePolicy);
        tabWidget_init->setTabPosition(QTabWidget::North);
        tabWidget_init->setTabShape(QTabWidget::Rounded);
        tab_serial = new QWidget();
        tab_serial->setObjectName(QString::fromUtf8("tab_serial"));
        horizontalLayout_6 = new QHBoxLayout(tab_serial);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget_5 = new QWidget(tab_serial);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_18 = new QVBoxLayout(widget_5);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        comboBox_serial = new QComboBox(widget_5);
        comboBox_serial->setObjectName(QString::fromUtf8("comboBox_serial"));

        horizontalLayout_7->addWidget(comboBox_serial);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        comboBox_baudRate = new QComboBox(widget_5);
        comboBox_baudRate->setObjectName(QString::fromUtf8("comboBox_baudRate"));

        horizontalLayout_7->addWidget(comboBox_baudRate);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        comboBox_dataBit = new QComboBox(widget_5);
        comboBox_dataBit->setObjectName(QString::fromUtf8("comboBox_dataBit"));

        horizontalLayout_7->addWidget(comboBox_dataBit);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        comboBox_parity = new QComboBox(widget_5);
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));

        horizontalLayout_7->addWidget(comboBox_parity);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        comboBox_stopBits = new QComboBox(widget_5);
        comboBox_stopBits->setObjectName(QString::fromUtf8("comboBox_stopBits"));

        horizontalLayout_7->addWidget(comboBox_stopBits);


        verticalLayout_18->addLayout(horizontalLayout_7);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        pushButton_serialOpenClose = new QPushButton(widget_5);
        pushButton_serialOpenClose->setObjectName(QString::fromUtf8("pushButton_serialOpenClose"));
        pushButton_serialOpenClose->setCheckable(true);

        horizontalLayout_22->addWidget(pushButton_serialOpenClose);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_4);


        verticalLayout_18->addLayout(horizontalLayout_22);

        groupBox_8 = new QGroupBox(widget_5);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_6 = new QVBoxLayout(groupBox_8);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        plainTextEdit_send_serial = new QPlainTextEdit(groupBox_8);
        plainTextEdit_send_serial->setObjectName(QString::fromUtf8("plainTextEdit_send_serial"));

        verticalLayout_6->addWidget(plainTextEdit_send_serial);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_2);

        pushButton_send_serial = new QPushButton(groupBox_8);
        pushButton_send_serial->setObjectName(QString::fromUtf8("pushButton_send_serial"));

        horizontalLayout_19->addWidget(pushButton_send_serial);

        pushButton_clearSend_serial = new QPushButton(groupBox_8);
        pushButton_clearSend_serial->setObjectName(QString::fromUtf8("pushButton_clearSend_serial"));

        horizontalLayout_19->addWidget(pushButton_clearSend_serial);


        verticalLayout_6->addLayout(horizontalLayout_19);


        verticalLayout_18->addWidget(groupBox_8);

        groupBox_9 = new QGroupBox(widget_5);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        verticalLayout_2 = new QVBoxLayout(groupBox_9);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        plainTextEdit_receive_serial = new QPlainTextEdit(groupBox_9);
        plainTextEdit_receive_serial->setObjectName(QString::fromUtf8("plainTextEdit_receive_serial"));
        plainTextEdit_receive_serial->setReadOnly(true);

        verticalLayout_2->addWidget(plainTextEdit_receive_serial);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_saveDataSerial = new QPushButton(groupBox_9);
        pushButton_saveDataSerial->setObjectName(QString::fromUtf8("pushButton_saveDataSerial"));

        horizontalLayout_4->addWidget(pushButton_saveDataSerial);

        lineEdit_saveDataTimeSerial = new QLineEdit(groupBox_9);
        lineEdit_saveDataTimeSerial->setObjectName(QString::fromUtf8("lineEdit_saveDataTimeSerial"));
        lineEdit_saveDataTimeSerial->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(lineEdit_saveDataTimeSerial);

        label_6 = new QLabel(groupBox_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_clearReceive_serial = new QPushButton(groupBox_9);
        pushButton_clearReceive_serial->setObjectName(QString::fromUtf8("pushButton_clearReceive_serial"));

        horizontalLayout_4->addWidget(pushButton_clearReceive_serial);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_18->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(widget_5);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        horizontalLayout_21 = new QHBoxLayout(groupBox_10);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        plainTextEdit_statusBar_serial = new QPlainTextEdit(groupBox_10);
        plainTextEdit_statusBar_serial->setObjectName(QString::fromUtf8("plainTextEdit_statusBar_serial"));
        plainTextEdit_statusBar_serial->setReadOnly(true);

        horizontalLayout_21->addWidget(plainTextEdit_statusBar_serial);


        verticalLayout_18->addWidget(groupBox_10);


        horizontalLayout_6->addWidget(widget_5);

        tabWidget_init->addTab(tab_serial, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_25 = new QVBoxLayout(tab_4);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        widget_13 = new QWidget(tab_4);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        verticalLayout_22 = new QVBoxLayout(widget_13);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_15 = new QLabel(widget_13);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_23->addWidget(label_15);

        comboBox_serial_2 = new QComboBox(widget_13);
        comboBox_serial_2->setObjectName(QString::fromUtf8("comboBox_serial_2"));

        horizontalLayout_23->addWidget(comboBox_serial_2);

        label_16 = new QLabel(widget_13);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_23->addWidget(label_16);

        comboBox_baudRate_2 = new QComboBox(widget_13);
        comboBox_baudRate_2->setObjectName(QString::fromUtf8("comboBox_baudRate_2"));

        horizontalLayout_23->addWidget(comboBox_baudRate_2);

        label_17 = new QLabel(widget_13);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_23->addWidget(label_17);

        comboBox_dataBit_2 = new QComboBox(widget_13);
        comboBox_dataBit_2->setObjectName(QString::fromUtf8("comboBox_dataBit_2"));

        horizontalLayout_23->addWidget(comboBox_dataBit_2);

        label_18 = new QLabel(widget_13);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_23->addWidget(label_18);

        comboBox_parity_2 = new QComboBox(widget_13);
        comboBox_parity_2->setObjectName(QString::fromUtf8("comboBox_parity_2"));

        horizontalLayout_23->addWidget(comboBox_parity_2);

        label_19 = new QLabel(widget_13);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_23->addWidget(label_19);

        comboBox_stopBits_2 = new QComboBox(widget_13);
        comboBox_stopBits_2->setObjectName(QString::fromUtf8("comboBox_stopBits_2"));

        horizontalLayout_23->addWidget(comboBox_stopBits_2);


        verticalLayout_22->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        pushButton_serialOpenClose_2 = new QPushButton(widget_13);
        pushButton_serialOpenClose_2->setObjectName(QString::fromUtf8("pushButton_serialOpenClose_2"));
        pushButton_serialOpenClose_2->setCheckable(true);

        horizontalLayout_24->addWidget(pushButton_serialOpenClose_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_12);


        verticalLayout_22->addLayout(horizontalLayout_24);

        groupBox_15 = new QGroupBox(widget_13);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        verticalLayout_23 = new QVBoxLayout(groupBox_15);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        plainTextEdit_send_serial_2 = new QPlainTextEdit(groupBox_15);
        plainTextEdit_send_serial_2->setObjectName(QString::fromUtf8("plainTextEdit_send_serial_2"));

        verticalLayout_23->addWidget(plainTextEdit_send_serial_2);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_13);

        pushButton_send_serial_2 = new QPushButton(groupBox_15);
        pushButton_send_serial_2->setObjectName(QString::fromUtf8("pushButton_send_serial_2"));

        horizontalLayout_25->addWidget(pushButton_send_serial_2);

        pushButton_clearSend_serial_2 = new QPushButton(groupBox_15);
        pushButton_clearSend_serial_2->setObjectName(QString::fromUtf8("pushButton_clearSend_serial_2"));

        horizontalLayout_25->addWidget(pushButton_clearSend_serial_2);


        verticalLayout_23->addLayout(horizontalLayout_25);


        verticalLayout_22->addWidget(groupBox_15);

        groupBox_16 = new QGroupBox(widget_13);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        verticalLayout_24 = new QVBoxLayout(groupBox_16);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        plainTextEdit_receive_serial_2 = new QPlainTextEdit(groupBox_16);
        plainTextEdit_receive_serial_2->setObjectName(QString::fromUtf8("plainTextEdit_receive_serial_2"));
        plainTextEdit_receive_serial_2->setReadOnly(true);

        verticalLayout_24->addWidget(plainTextEdit_receive_serial_2);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        pushButton_saveDataSerial_2 = new QPushButton(groupBox_16);
        pushButton_saveDataSerial_2->setObjectName(QString::fromUtf8("pushButton_saveDataSerial_2"));

        horizontalLayout_26->addWidget(pushButton_saveDataSerial_2);

        lineEdit_saveDataTimeSerial_2 = new QLineEdit(groupBox_16);
        lineEdit_saveDataTimeSerial_2->setObjectName(QString::fromUtf8("lineEdit_saveDataTimeSerial_2"));
        lineEdit_saveDataTimeSerial_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_26->addWidget(lineEdit_saveDataTimeSerial_2);

        label_20 = new QLabel(groupBox_16);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_26->addWidget(label_20);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_14);

        pushButton_clearReceive_serial_2 = new QPushButton(groupBox_16);
        pushButton_clearReceive_serial_2->setObjectName(QString::fromUtf8("pushButton_clearReceive_serial_2"));

        horizontalLayout_26->addWidget(pushButton_clearReceive_serial_2);


        verticalLayout_24->addLayout(horizontalLayout_26);


        verticalLayout_22->addWidget(groupBox_16);

        groupBox_17 = new QGroupBox(widget_13);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        horizontalLayout_27 = new QHBoxLayout(groupBox_17);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        plainTextEdit_statusBar_serial_2 = new QPlainTextEdit(groupBox_17);
        plainTextEdit_statusBar_serial_2->setObjectName(QString::fromUtf8("plainTextEdit_statusBar_serial_2"));
        plainTextEdit_statusBar_serial_2->setReadOnly(true);

        horizontalLayout_27->addWidget(plainTextEdit_statusBar_serial_2);


        verticalLayout_22->addWidget(groupBox_17);


        verticalLayout_25->addWidget(widget_13);

        tabWidget_init->addTab(tab_4, QString());
        tab_card = new QWidget();
        tab_card->setObjectName(QString::fromUtf8("tab_card"));
        horizontalLayout_20 = new QHBoxLayout(tab_card);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        groupBox_6 = new QGroupBox(tab_card);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_13 = new QVBoxLayout(groupBox_6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        widget_6 = new QWidget(groupBox_6);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_12 = new QLabel(widget_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        lineEdit_cardCount = new QLineEdit(widget_6);
        lineEdit_cardCount->setObjectName(QString::fromUtf8("lineEdit_cardCount"));
        lineEdit_cardCount->setMaximumSize(QSize(100, 16777215));
        lineEdit_cardCount->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit_cardCount);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        pushButton_cardOpenClose = new QPushButton(widget_6);
        pushButton_cardOpenClose->setObjectName(QString::fromUtf8("pushButton_cardOpenClose"));
        pushButton_cardOpenClose->setCheckable(false);

        horizontalLayout_5->addWidget(pushButton_cardOpenClose);

        pushButton_startLVDS = new QPushButton(widget_6);
        pushButton_startLVDS->setObjectName(QString::fromUtf8("pushButton_startLVDS"));

        horizontalLayout_5->addWidget(pushButton_startLVDS);

        pushButton_reset = new QPushButton(widget_6);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));

        horizontalLayout_5->addWidget(pushButton_reset);

        pushButton_clearFIFO = new QPushButton(widget_6);
        pushButton_clearFIFO->setObjectName(QString::fromUtf8("pushButton_clearFIFO"));

        horizontalLayout_5->addWidget(pushButton_clearFIFO);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_11 = new QLabel(widget_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_9->addWidget(label_11);

        comboBox_channelNumRS422 = new QComboBox(widget_6);
        comboBox_channelNumRS422->setObjectName(QString::fromUtf8("comboBox_channelNumRS422"));

        horizontalLayout_9->addWidget(comboBox_channelNumRS422);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        comboBox_baudRate_card = new QComboBox(widget_6);
        comboBox_baudRate_card->setObjectName(QString::fromUtf8("comboBox_baudRate_card"));

        horizontalLayout_9->addWidget(comboBox_baudRate_card);

        label_8 = new QLabel(widget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        comboBox_dataBit_card = new QComboBox(widget_6);
        comboBox_dataBit_card->setObjectName(QString::fromUtf8("comboBox_dataBit_card"));

        horizontalLayout_9->addWidget(comboBox_dataBit_card);

        label_9 = new QLabel(widget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        comboBox_parity_card = new QComboBox(widget_6);
        comboBox_parity_card->setObjectName(QString::fromUtf8("comboBox_parity_card"));

        horizontalLayout_9->addWidget(comboBox_parity_card);

        label_10 = new QLabel(widget_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        comboBox_stopBits_card = new QComboBox(widget_6);
        comboBox_stopBits_card->setObjectName(QString::fromUtf8("comboBox_stopBits_card"));

        horizontalLayout_9->addWidget(comboBox_stopBits_card);


        verticalLayout_5->addLayout(horizontalLayout_9);


        verticalLayout_13->addWidget(widget_6);

        widget = new QWidget(groupBox_6);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit_send = new QPlainTextEdit(groupBox);
        plainTextEdit_send->setObjectName(QString::fromUtf8("plainTextEdit_send"));

        verticalLayout->addWidget(plainTextEdit_send);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        pushButton_send = new QPushButton(groupBox);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        horizontalLayout_8->addWidget(pushButton_send);

        pushButton_clearSend = new QPushButton(groupBox);
        pushButton_clearSend->setObjectName(QString::fromUtf8("pushButton_clearSend"));

        horizontalLayout_8->addWidget(pushButton_clearSend);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_8->addWidget(groupBox);


        verticalLayout_13->addWidget(widget);

        widget_2 = new QWidget(groupBox_6);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_9 = new QVBoxLayout(widget_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        plainTextEdit_receive = new QPlainTextEdit(groupBox_2);
        plainTextEdit_receive->setObjectName(QString::fromUtf8("plainTextEdit_receive"));
        plainTextEdit_receive->setReadOnly(true);

        verticalLayout_3->addWidget(plainTextEdit_receive);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_saveDataRS422 = new QPushButton(groupBox_2);
        pushButton_saveDataRS422->setObjectName(QString::fromUtf8("pushButton_saveDataRS422"));

        horizontalLayout_10->addWidget(pushButton_saveDataRS422);

        lineEdit_saveTimeRS422 = new QLineEdit(groupBox_2);
        lineEdit_saveTimeRS422->setObjectName(QString::fromUtf8("lineEdit_saveTimeRS422"));
        lineEdit_saveTimeRS422->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(lineEdit_saveTimeRS422);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_10->addWidget(label_13);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        pushButton_clearReceive = new QPushButton(groupBox_2);
        pushButton_clearReceive->setObjectName(QString::fromUtf8("pushButton_clearReceive"));

        horizontalLayout_10->addWidget(pushButton_clearReceive);


        verticalLayout_3->addLayout(horizontalLayout_10);


        verticalLayout_9->addWidget(groupBox_2);


        verticalLayout_13->addWidget(widget_2);

        widget_3 = new QWidget(groupBox_6);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_3 = new QGroupBox(widget_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit_statusBar = new QPlainTextEdit(groupBox_3);
        plainTextEdit_statusBar->setObjectName(QString::fromUtf8("plainTextEdit_statusBar"));
        plainTextEdit_statusBar->setReadOnly(true);

        horizontalLayout->addWidget(plainTextEdit_statusBar);


        horizontalLayout_2->addWidget(groupBox_3);


        verticalLayout_13->addWidget(widget_3);


        horizontalLayout_20->addWidget(groupBox_6);

        tabWidget_init->addTab(tab_card, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_12 = new QVBoxLayout(tab);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_14 = new QVBoxLayout(groupBox_7);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        widget_8 = new QWidget(groupBox_7);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_11 = new QVBoxLayout(widget_8);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_32 = new QLabel(widget_8);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_12->addWidget(label_32);

        lineEdit_cardCount_2 = new QLineEdit(widget_8);
        lineEdit_cardCount_2->setObjectName(QString::fromUtf8("lineEdit_cardCount_2"));
        lineEdit_cardCount_2->setMaximumSize(QSize(100, 16777215));
        lineEdit_cardCount_2->setReadOnly(true);

        horizontalLayout_12->addWidget(lineEdit_cardCount_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);

        pushButton_cardOpenClose_2 = new QPushButton(widget_8);
        pushButton_cardOpenClose_2->setObjectName(QString::fromUtf8("pushButton_cardOpenClose_2"));
        pushButton_cardOpenClose_2->setCheckable(false);

        horizontalLayout_12->addWidget(pushButton_cardOpenClose_2);

        pushButton_startLVDS_2 = new QPushButton(widget_8);
        pushButton_startLVDS_2->setObjectName(QString::fromUtf8("pushButton_startLVDS_2"));

        horizontalLayout_12->addWidget(pushButton_startLVDS_2);

        pushButton_reset_2 = new QPushButton(widget_8);
        pushButton_reset_2->setObjectName(QString::fromUtf8("pushButton_reset_2"));

        horizontalLayout_12->addWidget(pushButton_reset_2);

        pushButton_clearFIFO_2 = new QPushButton(widget_8);
        pushButton_clearFIFO_2->setObjectName(QString::fromUtf8("pushButton_clearFIFO_2"));

        horizontalLayout_12->addWidget(pushButton_clearFIFO_2);


        verticalLayout_11->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_34 = new QLabel(widget_8);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_13->addWidget(label_34);

        comboBox_channelNumLVDS = new QComboBox(widget_8);
        comboBox_channelNumLVDS->setObjectName(QString::fromUtf8("comboBox_channelNumLVDS"));

        horizontalLayout_13->addWidget(comboBox_channelNumLVDS);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        label_35 = new QLabel(widget_8);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_13->addWidget(label_35);

        comboBox_baudRate_card_2 = new QComboBox(widget_8);
        comboBox_baudRate_card_2->setObjectName(QString::fromUtf8("comboBox_baudRate_card_2"));

        horizontalLayout_13->addWidget(comboBox_baudRate_card_2);

        label_36 = new QLabel(widget_8);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_13->addWidget(label_36);

        comboBox_dataBit_card_2 = new QComboBox(widget_8);
        comboBox_dataBit_card_2->setObjectName(QString::fromUtf8("comboBox_dataBit_card_2"));

        horizontalLayout_13->addWidget(comboBox_dataBit_card_2);

        label_37 = new QLabel(widget_8);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_13->addWidget(label_37);

        comboBox_parity_card_2 = new QComboBox(widget_8);
        comboBox_parity_card_2->setObjectName(QString::fromUtf8("comboBox_parity_card_2"));

        horizontalLayout_13->addWidget(comboBox_parity_card_2);

        label_38 = new QLabel(widget_8);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_13->addWidget(label_38);

        comboBox_stopBits_card_2 = new QComboBox(widget_8);
        comboBox_stopBits_card_2->setObjectName(QString::fromUtf8("comboBox_stopBits_card_2"));

        horizontalLayout_13->addWidget(comboBox_stopBits_card_2);


        verticalLayout_11->addLayout(horizontalLayout_13);


        verticalLayout_14->addWidget(widget_8);

        widget_9 = new QWidget(groupBox_7);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        verticalLayout_15 = new QVBoxLayout(widget_9);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        groupBox_11 = new QGroupBox(widget_9);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        verticalLayout_16 = new QVBoxLayout(groupBox_11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        plainTextEdit_send_2 = new QPlainTextEdit(groupBox_11);
        plainTextEdit_send_2->setObjectName(QString::fromUtf8("plainTextEdit_send_2"));

        verticalLayout_16->addWidget(plainTextEdit_send_2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_10);

        pushButton_send_2 = new QPushButton(groupBox_11);
        pushButton_send_2->setObjectName(QString::fromUtf8("pushButton_send_2"));

        horizontalLayout_15->addWidget(pushButton_send_2);

        pushButton_clearSend_2 = new QPushButton(groupBox_11);
        pushButton_clearSend_2->setObjectName(QString::fromUtf8("pushButton_clearSend_2"));

        horizontalLayout_15->addWidget(pushButton_clearSend_2);


        verticalLayout_16->addLayout(horizontalLayout_15);


        verticalLayout_15->addWidget(groupBox_11);


        verticalLayout_14->addWidget(widget_9);

        widget_10 = new QWidget(groupBox_7);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        verticalLayout_17 = new QVBoxLayout(widget_10);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        groupBox_12 = new QGroupBox(widget_10);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        verticalLayout_19 = new QVBoxLayout(groupBox_12);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        plainTextEdit_receive_2 = new QPlainTextEdit(groupBox_12);
        plainTextEdit_receive_2->setObjectName(QString::fromUtf8("plainTextEdit_receive_2"));
        plainTextEdit_receive_2->setReadOnly(true);

        verticalLayout_19->addWidget(plainTextEdit_receive_2);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        pushButton_saveDataLVDS = new QPushButton(groupBox_12);
        pushButton_saveDataLVDS->setObjectName(QString::fromUtf8("pushButton_saveDataLVDS"));

        horizontalLayout_16->addWidget(pushButton_saveDataLVDS);

        lineEdit_saveTimeLVDS = new QLineEdit(groupBox_12);
        lineEdit_saveTimeLVDS->setObjectName(QString::fromUtf8("lineEdit_saveTimeLVDS"));
        lineEdit_saveTimeLVDS->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_16->addWidget(lineEdit_saveTimeLVDS);

        label_14 = new QLabel(groupBox_12);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_16->addWidget(label_14);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_11);

        pushButton_clearReceive_2 = new QPushButton(groupBox_12);
        pushButton_clearReceive_2->setObjectName(QString::fromUtf8("pushButton_clearReceive_2"));

        horizontalLayout_16->addWidget(pushButton_clearReceive_2);


        verticalLayout_19->addLayout(horizontalLayout_16);


        verticalLayout_17->addWidget(groupBox_12);


        verticalLayout_14->addWidget(widget_10);

        widget_11 = new QWidget(groupBox_7);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_17 = new QHBoxLayout(widget_11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        groupBox_13 = new QGroupBox(widget_11);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        horizontalLayout_18 = new QHBoxLayout(groupBox_13);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        plainTextEdit_statusBar_2 = new QPlainTextEdit(groupBox_13);
        plainTextEdit_statusBar_2->setObjectName(QString::fromUtf8("plainTextEdit_statusBar_2"));
        plainTextEdit_statusBar_2->setReadOnly(true);

        horizontalLayout_18->addWidget(plainTextEdit_statusBar_2);


        horizontalLayout_17->addWidget(groupBox_13);


        verticalLayout_14->addWidget(widget_11);


        verticalLayout_12->addWidget(groupBox_7);

        tabWidget_init->addTab(tab, QString());

        verticalLayout_7->addWidget(tabWidget_init);


        verticalLayout_10->addWidget(widget_4);

        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        horizontalLayout_33 = new QHBoxLayout(page_3);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        widget_15 = new QWidget(page_3);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        horizontalLayout_28 = new QHBoxLayout(widget_15);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        widget_16 = new QWidget(widget_15);
        widget_16->setObjectName(QString::fromUtf8("widget_16"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_16->sizePolicy().hasHeightForWidth());
        widget_16->setSizePolicy(sizePolicy1);
        widget_16->setMaximumSize(QSize(200, 16777215));
        verticalLayout_20 = new QVBoxLayout(widget_16);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        listWidget_2 = new QListWidget(widget_16);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_20->addWidget(listWidget_2);

        pushButton_import_com_xml = new QPushButton(widget_16);
        pushButton_import_com_xml->setObjectName(QString::fromUtf8("pushButton_import_com_xml"));

        verticalLayout_20->addWidget(pushButton_import_com_xml);

        groupBox_14 = new QGroupBox(widget_16);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setMinimumSize(QSize(0, 100));
        gridLayout = new QGridLayout(groupBox_14);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_21 = new QLabel(groupBox_14);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout->addWidget(label_21, 0, 0, 1, 1);

        lb_local_count = new QLabel(groupBox_14);
        lb_local_count->setObjectName(QString::fromUtf8("lb_local_count"));
        lb_local_count->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_local_count, 0, 1, 1, 1);

        label_31 = new QLabel(groupBox_14);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout->addWidget(label_31, 1, 0, 1, 1);

        lb_time = new QLabel(groupBox_14);
        lb_time->setObjectName(QString::fromUtf8("lb_time"));
        lb_time->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_time, 1, 1, 1, 1);

        label_33 = new QLabel(groupBox_14);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout->addWidget(label_33, 2, 0, 1, 1);

        lb_cmd_id = new QLabel(groupBox_14);
        lb_cmd_id->setObjectName(QString::fromUtf8("lb_cmd_id"));
        lb_cmd_id->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_cmd_id, 2, 1, 1, 1);

        label_39 = new QLabel(groupBox_14);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout->addWidget(label_39, 3, 0, 1, 1);

        lb_result = new QLabel(groupBox_14);
        lb_result->setObjectName(QString::fromUtf8("lb_result"));
        lb_result->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_result, 3, 1, 1, 1);

        label_40 = new QLabel(groupBox_14);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout->addWidget(label_40, 4, 0, 1, 1);

        lb_error_type = new QLabel(groupBox_14);
        lb_error_type->setObjectName(QString::fromUtf8("lb_error_type"));
        lb_error_type->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_error_type, 4, 1, 1, 1);

        te_response_result = new QTextEdit(groupBox_14);
        te_response_result->setObjectName(QString::fromUtf8("te_response_result"));

        gridLayout->addWidget(te_response_result, 5, 0, 1, 2);


        verticalLayout_20->addWidget(groupBox_14);

        verticalLayout_20->setStretch(0, 1);

        horizontalLayout_28->addWidget(widget_16);

        widget_17 = new QWidget(widget_15);
        widget_17->setObjectName(QString::fromUtf8("widget_17"));
        verticalLayout_21 = new QVBoxLayout(widget_17);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        widget_18 = new QWidget(widget_17);
        widget_18->setObjectName(QString::fromUtf8("widget_18"));
        horizontalLayout_29 = new QHBoxLayout(widget_18);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_41 = new QLabel(widget_18);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_29->addWidget(label_41);

        lb_current_cmd_name = new QLabel(widget_18);
        lb_current_cmd_name->setObjectName(QString::fromUtf8("lb_current_cmd_name"));
        lb_current_cmd_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        horizontalLayout_29->addWidget(lb_current_cmd_name);

        horizontalLayout_29->setStretch(1, 1);

        verticalLayout_21->addWidget(widget_18);

        stackedWidget_com = new QStackedWidget(widget_17);
        stackedWidget_com->setObjectName(QString::fromUtf8("stackedWidget_com"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget_com->addWidget(page_5);

        verticalLayout_21->addWidget(stackedWidget_com);

        widget_19 = new QWidget(widget_17);
        widget_19->setObjectName(QString::fromUtf8("widget_19"));
        widget_19->setMinimumSize(QSize(0, 50));
        horizontalLayout_3 = new QHBoxLayout(widget_19);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_cardCom = new QComboBox(widget_19);
        comboBox_cardCom->setObjectName(QString::fromUtf8("comboBox_cardCom"));

        horizontalLayout_3->addWidget(comboBox_cardCom);

        pushButton_sendCardCom = new QPushButton(widget_19);
        pushButton_sendCardCom->setObjectName(QString::fromUtf8("pushButton_sendCardCom"));

        horizontalLayout_3->addWidget(pushButton_sendCardCom);

        pb_del_cmd = new QPushButton(widget_19);
        pb_del_cmd->setObjectName(QString::fromUtf8("pb_del_cmd"));

        horizontalLayout_3->addWidget(pb_del_cmd);

        pb_clear_cmd = new QPushButton(widget_19);
        pb_clear_cmd->setObjectName(QString::fromUtf8("pb_clear_cmd"));

        horizontalLayout_3->addWidget(pb_clear_cmd);

        pb_insert_cmd = new QPushButton(widget_19);
        pb_insert_cmd->setObjectName(QString::fromUtf8("pb_insert_cmd"));

        horizontalLayout_3->addWidget(pb_insert_cmd);

        pb_add_cmd = new QPushButton(widget_19);
        pb_add_cmd->setObjectName(QString::fromUtf8("pb_add_cmd"));

        horizontalLayout_3->addWidget(pb_add_cmd);

        widget_20 = new QWidget(widget_19);
        widget_20->setObjectName(QString::fromUtf8("widget_20"));
        widget_20->setMinimumSize(QSize(100, 0));
        horizontalLayout_31 = new QHBoxLayout(widget_20);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        label_42 = new QLabel(widget_20);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_31->addWidget(label_42);

        spinBox = new QSpinBox(widget_20);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(1000000000);

        horizontalLayout_31->addWidget(spinBox);


        horizontalLayout_3->addWidget(widget_20);

        horizontalSpacer_15 = new QSpacerItem(20, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_15);

        pb_send_cmd_immediately = new QPushButton(widget_19);
        pb_send_cmd_immediately->setObjectName(QString::fromUtf8("pb_send_cmd_immediately"));

        horizontalLayout_3->addWidget(pb_send_cmd_immediately);


        verticalLayout_21->addWidget(widget_19);

        widget_14 = new QWidget(widget_17);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        horizontalLayout_34 = new QHBoxLayout(widget_14);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_17);

        checkBox_COMI = new QCheckBox(widget_14);
        checkBox_COMI->setObjectName(QString::fromUtf8("checkBox_COMI"));

        horizontalLayout_34->addWidget(checkBox_COMI);

        label_52 = new QLabel(widget_14);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        horizontalLayout_34->addWidget(label_52);

        checkBox_COMII = new QCheckBox(widget_14);
        checkBox_COMII->setObjectName(QString::fromUtf8("checkBox_COMII"));

        horizontalLayout_34->addWidget(checkBox_COMII);

        label_53 = new QLabel(widget_14);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        horizontalLayout_34->addWidget(label_53);

        checkBox_CARDRS422 = new QCheckBox(widget_14);
        checkBox_CARDRS422->setObjectName(QString::fromUtf8("checkBox_CARDRS422"));

        horizontalLayout_34->addWidget(checkBox_CARDRS422);

        label_54 = new QLabel(widget_14);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        horizontalLayout_34->addWidget(label_54);

        checkBox_CARDLVDS = new QCheckBox(widget_14);
        checkBox_CARDLVDS->setObjectName(QString::fromUtf8("checkBox_CARDLVDS"));

        horizontalLayout_34->addWidget(checkBox_CARDLVDS);

        label_55 = new QLabel(widget_14);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        horizontalLayout_34->addWidget(label_55);


        verticalLayout_21->addWidget(widget_14);

        tableWidget_cmd_immediately = new QTableWidget(widget_17);
        tableWidget_cmd_immediately->setObjectName(QString::fromUtf8("tableWidget_cmd_immediately"));

        verticalLayout_21->addWidget(tableWidget_cmd_immediately);

        widget_21 = new QWidget(widget_17);
        widget_21->setObjectName(QString::fromUtf8("widget_21"));
        widget_21->setMinimumSize(QSize(0, 50));
        horizontalLayout_32 = new QHBoxLayout(widget_21);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        pb_import_xml = new QPushButton(widget_21);
        pb_import_xml->setObjectName(QString::fromUtf8("pb_import_xml"));

        horizontalLayout_32->addWidget(pb_import_xml);

        pushButton_editPara = new QPushButton(widget_21);
        pushButton_editPara->setObjectName(QString::fromUtf8("pushButton_editPara"));

        horizontalLayout_32->addWidget(pushButton_editPara);

        pb_export_xml = new QPushButton(widget_21);
        pb_export_xml->setObjectName(QString::fromUtf8("pb_export_xml"));

        horizontalLayout_32->addWidget(pb_export_xml);

        horizontalSpacer_16 = new QSpacerItem(388, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_16);

        pb_send_cmd = new QPushButton(widget_21);
        pb_send_cmd->setObjectName(QString::fromUtf8("pb_send_cmd"));

        horizontalLayout_32->addWidget(pb_send_cmd);


        verticalLayout_21->addWidget(widget_21);


        horizontalLayout_28->addWidget(widget_17);

        horizontalLayout_28->setStretch(1, 1);

        horizontalLayout_33->addWidget(widget_15);

        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_6 = new QGridLayout(page_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        widget_22 = new QWidget(page_2);
        widget_22->setObjectName(QString::fromUtf8("widget_22"));
        horizontalLayout_14 = new QHBoxLayout(widget_22);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        groupBox_20 = new QGroupBox(widget_22);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        verticalLayout_29 = new QVBoxLayout(groupBox_20);
        verticalLayout_29->setObjectName(QString::fromUtf8("verticalLayout_29"));
        tableView = new QTableView(groupBox_20);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_29->addWidget(tableView);


        horizontalLayout_14->addWidget(groupBox_20);

        groupBox_21 = new QGroupBox(widget_22);
        groupBox_21->setObjectName(QString::fromUtf8("groupBox_21"));
        verticalLayout_30 = new QVBoxLayout(groupBox_21);
        verticalLayout_30->setObjectName(QString::fromUtf8("verticalLayout_30"));
        tableView_2 = new QTableView(groupBox_21);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        verticalLayout_30->addWidget(tableView_2);


        horizontalLayout_14->addWidget(groupBox_21);


        gridLayout_6->addWidget(widget_22, 0, 1, 1, 1);

        widget_23 = new QWidget(page_2);
        widget_23->setObjectName(QString::fromUtf8("widget_23"));
        widget_23->setMaximumSize(QSize(230, 16777215));
        verticalLayout_31 = new QVBoxLayout(widget_23);
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));
        groupBox_22 = new QGroupBox(widget_23);
        groupBox_22->setObjectName(QString::fromUtf8("groupBox_22"));
        groupBox_22->setMinimumSize(QSize(0, 0));
        verticalLayout_32 = new QVBoxLayout(groupBox_22);
        verticalLayout_32->setObjectName(QString::fromUtf8("verticalLayout_32"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        label_61 = new QLabel(groupBox_22);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        horizontalLayout_30->addWidget(label_61);

        sb_request_interval = new QSpinBox(groupBox_22);
        sb_request_interval->setObjectName(QString::fromUtf8("sb_request_interval"));
        sb_request_interval->setMinimum(1);

        horizontalLayout_30->addWidget(sb_request_interval);

        pb_begin_request = new QPushButton(groupBox_22);
        pb_begin_request->setObjectName(QString::fromUtf8("pb_begin_request"));

        horizontalLayout_30->addWidget(pb_begin_request);


        verticalLayout_32->addLayout(horizontalLayout_30);


        verticalLayout_31->addWidget(groupBox_22);

        groupBox_23 = new QGroupBox(widget_23);
        groupBox_23->setObjectName(QString::fromUtf8("groupBox_23"));
        groupBox_23->setMinimumSize(QSize(200, 0));
        gridLayout_5 = new QGridLayout(groupBox_23);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_69 = new QLabel(groupBox_23);
        label_69->setObjectName(QString::fromUtf8("label_69"));

        gridLayout_5->addWidget(label_69, 0, 0, 1, 1);

        lb_recv_tm_data_time = new QLabel(groupBox_23);
        lb_recv_tm_data_time->setObjectName(QString::fromUtf8("lb_recv_tm_data_time"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        lb_recv_tm_data_time->setFont(font);
        lb_recv_tm_data_time->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        gridLayout_5->addWidget(lb_recv_tm_data_time, 0, 1, 1, 2);

        label_68 = new QLabel(groupBox_23);
        label_68->setObjectName(QString::fromUtf8("label_68"));

        gridLayout_5->addWidget(label_68, 1, 0, 1, 1);

        le_frame_total_count = new QLineEdit(groupBox_23);
        le_frame_total_count->setObjectName(QString::fromUtf8("le_frame_total_count"));
        le_frame_total_count->setMinimumSize(QSize(0, 25));

        gridLayout_5->addWidget(le_frame_total_count, 1, 1, 1, 1);

        label_74 = new QLabel(groupBox_23);
        label_74->setObjectName(QString::fromUtf8("label_74"));

        gridLayout_5->addWidget(label_74, 2, 0, 1, 1);

        le_frame_crc_wrong_count = new QLineEdit(groupBox_23);
        le_frame_crc_wrong_count->setObjectName(QString::fromUtf8("le_frame_crc_wrong_count"));
        le_frame_crc_wrong_count->setMinimumSize(QSize(0, 25));

        gridLayout_5->addWidget(le_frame_crc_wrong_count, 2, 1, 1, 1);

        label_81 = new QLabel(groupBox_23);
        label_81->setObjectName(QString::fromUtf8("label_81"));

        gridLayout_5->addWidget(label_81, 3, 0, 1, 1);

        le_frame_crc_success_count = new QLineEdit(groupBox_23);
        le_frame_crc_success_count->setObjectName(QString::fromUtf8("le_frame_crc_success_count"));
        le_frame_crc_success_count->setMinimumSize(QSize(0, 25));

        gridLayout_5->addWidget(le_frame_crc_success_count, 3, 1, 1, 1);

        pb_clear_frame_errors = new QPushButton(groupBox_23);
        pb_clear_frame_errors->setObjectName(QString::fromUtf8("pb_clear_frame_errors"));

        gridLayout_5->addWidget(pb_clear_frame_errors, 4, 0, 1, 3);

        lb_frame_success_status = new QLabel(groupBox_23);
        lb_frame_success_status->setObjectName(QString::fromUtf8("lb_frame_success_status"));
        lb_frame_success_status->setMinimumSize(QSize(25, 25));
        lb_frame_success_status->setMaximumSize(QSize(25, 25));
        lb_frame_success_status->setStyleSheet(QString::fromUtf8("background-color: rgb(3, 179, 115);"));

        gridLayout_5->addWidget(lb_frame_success_status, 3, 2, 1, 1);

        lb_frame_crc_wrong_status = new QLabel(groupBox_23);
        lb_frame_crc_wrong_status->setObjectName(QString::fromUtf8("lb_frame_crc_wrong_status"));
        lb_frame_crc_wrong_status->setMinimumSize(QSize(25, 25));
        lb_frame_crc_wrong_status->setMaximumSize(QSize(25, 25));
        lb_frame_crc_wrong_status->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 6, 43);"));

        gridLayout_5->addWidget(lb_frame_crc_wrong_status, 2, 2, 1, 1);

        lb_frame_timeout_status = new QLabel(groupBox_23);
        lb_frame_timeout_status->setObjectName(QString::fromUtf8("lb_frame_timeout_status"));
        lb_frame_timeout_status->setMinimumSize(QSize(25, 25));
        lb_frame_timeout_status->setMaximumSize(QSize(25, 25));
        lb_frame_timeout_status->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 21);"));
        lb_frame_timeout_status->setFrameShape(QFrame::NoFrame);
        lb_frame_timeout_status->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(lb_frame_timeout_status, 1, 2, 1, 1);


        verticalLayout_31->addWidget(groupBox_23);

        groupBox_24 = new QGroupBox(widget_23);
        groupBox_24->setObjectName(QString::fromUtf8("groupBox_24"));
        groupBox_24->setMinimumSize(QSize(0, 100));
        verticalLayout_33 = new QVBoxLayout(groupBox_24);
        verticalLayout_33->setObjectName(QString::fromUtf8("verticalLayout_33"));
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        rb_save_data_manual = new QRadioButton(groupBox_24);
        rb_save_data_manual->setObjectName(QString::fromUtf8("rb_save_data_manual"));
        rb_save_data_manual->setChecked(true);

        horizontalLayout_37->addWidget(rb_save_data_manual);

        rb_save_data_auto = new QRadioButton(groupBox_24);
        rb_save_data_auto->setObjectName(QString::fromUtf8("rb_save_data_auto"));

        horizontalLayout_37->addWidget(rb_save_data_auto);


        verticalLayout_33->addLayout(horizontalLayout_37);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        pb_begin_save_data = new QPushButton(groupBox_24);
        pb_begin_save_data->setObjectName(QString::fromUtf8("pb_begin_save_data"));

        horizontalLayout_38->addWidget(pb_begin_save_data);

        sb_time = new QSpinBox(groupBox_24);
        sb_time->setObjectName(QString::fromUtf8("sb_time"));
        sb_time->setMaximum(100000);
        sb_time->setValue(600);

        horizontalLayout_38->addWidget(sb_time);


        verticalLayout_33->addLayout(horizontalLayout_38);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        label_62 = new QLabel(groupBox_24);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setFont(font);

        horizontalLayout_39->addWidget(label_62);

        lb_status_show = new QLabel(groupBox_24);
        lb_status_show->setObjectName(QString::fromUtf8("lb_status_show"));
        lb_status_show->setFont(font);
        lb_status_show->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        horizontalLayout_39->addWidget(lb_status_show);

        horizontalLayout_39->setStretch(1, 1);

        verticalLayout_33->addLayout(horizontalLayout_39);


        verticalLayout_31->addWidget(groupBox_24);

        groupBox_25 = new QGroupBox(widget_23);
        groupBox_25->setObjectName(QString::fromUtf8("groupBox_25"));
        groupBox_25->setMaximumSize(QSize(16666, 16777215));
        verticalLayout_34 = new QVBoxLayout(groupBox_25);
        verticalLayout_34->setObjectName(QString::fromUtf8("verticalLayout_34"));
        te_tm_info = new QTextEdit(groupBox_25);
        te_tm_info->setObjectName(QString::fromUtf8("te_tm_info"));

        verticalLayout_34->addWidget(te_tm_info);


        verticalLayout_31->addWidget(groupBox_25);


        gridLayout_6->addWidget(widget_23, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_4 = new QVBoxLayout(page_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_7 = new QWidget(page_4);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 0));
        widget_7->setMaximumSize(QSize(500000, 16777215));
        horizontalLayout_40 = new QHBoxLayout(widget_7);
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        groupBox_18 = new QGroupBox(widget_7);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setMinimumSize(QSize(180, 0));
        groupBox_18->setMaximumSize(QSize(180, 16777215));
        gridLayout_4 = new QGridLayout(groupBox_18);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_centroidX = new QLineEdit(groupBox_18);
        lineEdit_centroidX->setObjectName(QString::fromUtf8("lineEdit_centroidX"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_centroidX->sizePolicy().hasHeightForWidth());
        lineEdit_centroidX->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(lineEdit_centroidX, 1, 0, 1, 1);

        lineEdit_maxGray = new QLineEdit(groupBox_18);
        lineEdit_maxGray->setObjectName(QString::fromUtf8("lineEdit_maxGray"));
        sizePolicy2.setHeightForWidth(lineEdit_maxGray->sizePolicy().hasHeightForWidth());
        lineEdit_maxGray->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(lineEdit_maxGray, 3, 1, 1, 1);

        lineEdit_centroidY = new QLineEdit(groupBox_18);
        lineEdit_centroidY->setObjectName(QString::fromUtf8("lineEdit_centroidY"));
        sizePolicy2.setHeightForWidth(lineEdit_centroidY->sizePolicy().hasHeightForWidth());
        lineEdit_centroidY->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(lineEdit_centroidY, 1, 1, 1, 1);

        label_49 = new QLabel(groupBox_18);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_4->addWidget(label_49, 10, 0, 1, 1);

        label_50 = new QLabel(groupBox_18);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        gridLayout_4->addWidget(label_50, 12, 0, 1, 1);

        lineEdit_validCentroidFameNum = new QLineEdit(groupBox_18);
        lineEdit_validCentroidFameNum->setObjectName(QString::fromUtf8("lineEdit_validCentroidFameNum"));

        gridLayout_4->addWidget(lineEdit_validCentroidFameNum, 15, 0, 1, 2);

        label_46 = new QLabel(groupBox_18);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        gridLayout_4->addWidget(label_46, 4, 0, 1, 2);

        lineEdit_errorCentroidFameNum = new QLineEdit(groupBox_18);
        lineEdit_errorCentroidFameNum->setObjectName(QString::fromUtf8("lineEdit_errorCentroidFameNum"));

        gridLayout_4->addWidget(lineEdit_errorCentroidFameNum, 13, 0, 1, 2);

        lineEdit_minGray = new QLineEdit(groupBox_18);
        lineEdit_minGray->setObjectName(QString::fromUtf8("lineEdit_minGray"));
        sizePolicy2.setHeightForWidth(lineEdit_minGray->sizePolicy().hasHeightForWidth());
        lineEdit_minGray->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(lineEdit_minGray, 3, 0, 1, 1);

        label_48 = new QLabel(groupBox_18);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout_4->addWidget(label_48, 8, 0, 1, 2);

        label_47 = new QLabel(groupBox_18);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_4->addWidget(label_47, 6, 0, 1, 2);

        lineEdit_totalCentroidFameNum = new QLineEdit(groupBox_18);
        lineEdit_totalCentroidFameNum->setObjectName(QString::fromUtf8("lineEdit_totalCentroidFameNum"));

        gridLayout_4->addWidget(lineEdit_totalCentroidFameNum, 11, 0, 1, 2);

        lineEdit_overGrayscaleNum = new QLineEdit(groupBox_18);
        lineEdit_overGrayscaleNum->setObjectName(QString::fromUtf8("lineEdit_overGrayscaleNum"));

        gridLayout_4->addWidget(lineEdit_overGrayscaleNum, 5, 0, 1, 2);

        label_45 = new QLabel(groupBox_18);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_4->addWidget(label_45, 2, 0, 1, 2);

        lineEdit_grayscaleSum = new QLineEdit(groupBox_18);
        lineEdit_grayscaleSum->setObjectName(QString::fromUtf8("lineEdit_grayscaleSum"));

        gridLayout_4->addWidget(lineEdit_grayscaleSum, 9, 0, 1, 2);

        label_51 = new QLabel(groupBox_18);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        gridLayout_4->addWidget(label_51, 14, 0, 1, 1);

        lineEdit_exposureTime = new QLineEdit(groupBox_18);
        lineEdit_exposureTime->setObjectName(QString::fromUtf8("lineEdit_exposureTime"));

        gridLayout_4->addWidget(lineEdit_exposureTime, 7, 0, 1, 2);

        label_44 = new QLabel(groupBox_18);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_4->addWidget(label_44, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 16, 0, 1, 1);


        horizontalLayout_36->addWidget(groupBox_18);

        groupBox_19 = new QGroupBox(widget_7);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setMinimumSize(QSize(180, 0));
        groupBox_19->setMaximumSize(QSize(180, 1800000));
        verticalLayout_26 = new QVBoxLayout(groupBox_19);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));
        label_58 = new QLabel(groupBox_19);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        verticalLayout_26->addWidget(label_58);

        lineEdit_elecCurrSEL = new QLineEdit(groupBox_19);
        lineEdit_elecCurrSEL->setObjectName(QString::fromUtf8("lineEdit_elecCurrSEL"));

        verticalLayout_26->addWidget(lineEdit_elecCurrSEL);

        label_57 = new QLabel(groupBox_19);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        verticalLayout_26->addWidget(label_57);

        lineEdit_temFPGA = new QLineEdit(groupBox_19);
        lineEdit_temFPGA->setObjectName(QString::fromUtf8("lineEdit_temFPGA"));

        verticalLayout_26->addWidget(lineEdit_temFPGA);

        label_56 = new QLabel(groupBox_19);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        verticalLayout_26->addWidget(label_56);

        lineEdit_temTEC = new QLineEdit(groupBox_19);
        lineEdit_temTEC->setObjectName(QString::fromUtf8("lineEdit_temTEC"));

        verticalLayout_26->addWidget(lineEdit_temTEC);

        label_59 = new QLabel(groupBox_19);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        verticalLayout_26->addWidget(label_59);

        lineEdit_TemVtemp = new QLineEdit(groupBox_19);
        lineEdit_TemVtemp->setObjectName(QString::fromUtf8("lineEdit_TemVtemp"));

        verticalLayout_26->addWidget(lineEdit_TemVtemp);

        label_60 = new QLabel(groupBox_19);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        verticalLayout_26->addWidget(label_60);

        lineEdit_statusSEL = new QLineEdit(groupBox_19);
        lineEdit_statusSEL->setObjectName(QString::fromUtf8("lineEdit_statusSEL"));

        verticalLayout_26->addWidget(lineEdit_statusSEL);

        label_73 = new QLabel(groupBox_19);
        label_73->setObjectName(QString::fromUtf8("label_73"));

        verticalLayout_26->addWidget(label_73);

        lineEdit_numOvercurr = new QLineEdit(groupBox_19);
        lineEdit_numOvercurr->setObjectName(QString::fromUtf8("lineEdit_numOvercurr"));

        verticalLayout_26->addWidget(lineEdit_numOvercurr);

        label_75 = new QLabel(groupBox_19);
        label_75->setObjectName(QString::fromUtf8("label_75"));

        verticalLayout_26->addWidget(label_75);

        lineEdit_recordNumOvercurr = new QLineEdit(groupBox_19);
        lineEdit_recordNumOvercurr->setObjectName(QString::fromUtf8("lineEdit_recordNumOvercurr"));

        verticalLayout_26->addWidget(lineEdit_recordNumOvercurr);

        label_76 = new QLabel(groupBox_19);
        label_76->setObjectName(QString::fromUtf8("label_76"));

        verticalLayout_26->addWidget(label_76);

        lineEdit_samplingValueOvercurr = new QLineEdit(groupBox_19);
        lineEdit_samplingValueOvercurr->setObjectName(QString::fromUtf8("lineEdit_samplingValueOvercurr"));

        verticalLayout_26->addWidget(lineEdit_samplingValueOvercurr);

        label_77 = new QLabel(groupBox_19);
        label_77->setObjectName(QString::fromUtf8("label_77"));

        verticalLayout_26->addWidget(label_77);

        lineEdit_cameraExpoMode = new QLineEdit(groupBox_19);
        lineEdit_cameraExpoMode->setObjectName(QString::fromUtf8("lineEdit_cameraExpoMode"));

        verticalLayout_26->addWidget(lineEdit_cameraExpoMode);

        label_78 = new QLabel(groupBox_19);
        label_78->setObjectName(QString::fromUtf8("label_78"));

        verticalLayout_26->addWidget(label_78);

        lineEdit_deadPixelCorrMode = new QLineEdit(groupBox_19);
        lineEdit_deadPixelCorrMode->setObjectName(QString::fromUtf8("lineEdit_deadPixelCorrMode"));

        verticalLayout_26->addWidget(lineEdit_deadPixelCorrMode);

        label_79 = new QLabel(groupBox_19);
        label_79->setObjectName(QString::fromUtf8("label_79"));

        verticalLayout_26->addWidget(label_79);

        lineEdit_imageDataSource = new QLineEdit(groupBox_19);
        lineEdit_imageDataSource->setObjectName(QString::fromUtf8("lineEdit_imageDataSource"));

        verticalLayout_26->addWidget(lineEdit_imageDataSource);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_26->addItem(verticalSpacer_2);


        horizontalLayout_36->addWidget(groupBox_19);


        horizontalLayout_40->addLayout(horizontalLayout_36);

        verticalLayout_28 = new QVBoxLayout();
        verticalLayout_28->setObjectName(QString::fromUtf8("verticalLayout_28"));
        graphicsView = new ImageGraphicsView(widget_7);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: rgb(109, 109, 109);"));

        verticalLayout_28->addWidget(graphicsView);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_18);

        groupBox_4 = new QGroupBox(widget_7);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(250, 16666));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_saveImage_2 = new QPushButton(groupBox_4);
        pushButton_saveImage_2->setObjectName(QString::fromUtf8("pushButton_saveImage_2"));

        gridLayout_2->addWidget(pushButton_saveImage_2, 0, 0, 1, 1);

        pushButton_beginSaveImages_2 = new QPushButton(groupBox_4);
        pushButton_beginSaveImages_2->setObjectName(QString::fromUtf8("pushButton_beginSaveImages_2"));

        gridLayout_2->addWidget(pushButton_beginSaveImages_2, 0, 1, 1, 1);

        lineEdit_saveImagesTime_2 = new QLineEdit(groupBox_4);
        lineEdit_saveImagesTime_2->setObjectName(QString::fromUtf8("lineEdit_saveImagesTime_2"));

        gridLayout_2->addWidget(lineEdit_saveImagesTime_2, 1, 1, 1, 1);

        label_30 = new QLabel(groupBox_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setMaximumSize(QSize(160, 16777215));

        gridLayout_2->addWidget(label_30, 1, 2, 1, 1);

        checkBox_overGrayScaleCoordinates = new QCheckBox(groupBox_4);
        checkBox_overGrayScaleCoordinates->setObjectName(QString::fromUtf8("checkBox_overGrayScaleCoordinates"));

        gridLayout_2->addWidget(checkBox_overGrayScaleCoordinates, 1, 0, 1, 1);


        horizontalLayout_35->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(widget_7);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(16777215, 240));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_23 = new QLabel(groupBox_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_3->addWidget(label_23, 0, 1, 1, 1);

        lineEdit_imageFrameNum_2 = new QLineEdit(groupBox_5);
        lineEdit_imageFrameNum_2->setObjectName(QString::fromUtf8("lineEdit_imageFrameNum_2"));
        lineEdit_imageFrameNum_2->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_imageFrameNum_2, 1, 0, 1, 1);

        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_3->addWidget(label_28, 2, 2, 1, 1);

        lineEdit_falseFrameNum_2 = new QLineEdit(groupBox_5);
        lineEdit_falseFrameNum_2->setObjectName(QString::fromUtf8("lineEdit_falseFrameNum_2"));
        lineEdit_falseFrameNum_2->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_falseFrameNum_2, 3, 2, 1, 1);

        lineEdit_imageWindowSize_2 = new QLineEdit(groupBox_5);
        lineEdit_imageWindowSize_2->setObjectName(QString::fromUtf8("lineEdit_imageWindowSize_2"));
        lineEdit_imageWindowSize_2->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_imageWindowSize_2, 1, 1, 1, 1);

        label_24 = new QLabel(groupBox_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_3->addWidget(label_24, 0, 2, 1, 1);

        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_3->addWidget(label_22, 0, 0, 1, 1);

        label_29 = new QLabel(groupBox_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_3->addWidget(label_29, 2, 1, 1, 1);

        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_3->addWidget(label_27, 2, 0, 1, 1);

        lineEdit_frameNum_2 = new QLineEdit(groupBox_5);
        lineEdit_frameNum_2->setObjectName(QString::fromUtf8("lineEdit_frameNum_2"));
        lineEdit_frameNum_2->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_frameNum_2, 3, 0, 1, 1);

        lineEdit_timeCode_2 = new QLineEdit(groupBox_5);
        lineEdit_timeCode_2->setObjectName(QString::fromUtf8("lineEdit_timeCode_2"));
        lineEdit_timeCode_2->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_timeCode_2, 1, 2, 1, 1);

        lineEdit_rightFrameNum_2 = new QLineEdit(groupBox_5);
        lineEdit_rightFrameNum_2->setObjectName(QString::fromUtf8("lineEdit_rightFrameNum_2"));
        lineEdit_rightFrameNum_2->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_rightFrameNum_2, 3, 1, 1, 1);


        horizontalLayout_35->addWidget(groupBox_5);

        groupBox_26 = new QGroupBox(widget_7);
        groupBox_26->setObjectName(QString::fromUtf8("groupBox_26"));
        gridLayout_7 = new QGridLayout(groupBox_26);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_43 = new QLabel(groupBox_26);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_7->addWidget(label_43, 0, 0, 1, 1);

        label_63 = new QLabel(groupBox_26);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        gridLayout_7->addWidget(label_63, 6, 0, 1, 1);

        lineEdit_ImgCentroidY = new QLineEdit(groupBox_26);
        lineEdit_ImgCentroidY->setObjectName(QString::fromUtf8("lineEdit_ImgCentroidY"));

        gridLayout_7->addWidget(lineEdit_ImgCentroidY, 6, 3, 1, 1);

        label_25 = new QLabel(groupBox_26);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_7->addWidget(label_25, 2, 0, 1, 1);

        lineEdit_ImgCentroidX = new QLineEdit(groupBox_26);
        lineEdit_ImgCentroidX->setObjectName(QString::fromUtf8("lineEdit_ImgCentroidX"));

        gridLayout_7->addWidget(lineEdit_ImgCentroidX, 6, 2, 1, 1);

        lineEdit_grayThre_2 = new QLineEdit(groupBox_26);
        lineEdit_grayThre_2->setObjectName(QString::fromUtf8("lineEdit_grayThre_2"));

        gridLayout_7->addWidget(lineEdit_grayThre_2, 2, 2, 1, 1);

        label_64 = new QLabel(groupBox_26);
        label_64->setObjectName(QString::fromUtf8("label_64"));

        gridLayout_7->addWidget(label_64, 5, 2, 1, 1);

        lineEdit_peakingThreshold = new QLineEdit(groupBox_26);
        lineEdit_peakingThreshold->setObjectName(QString::fromUtf8("lineEdit_peakingThreshold"));

        gridLayout_7->addWidget(lineEdit_peakingThreshold, 0, 2, 1, 1);

        label_65 = new QLabel(groupBox_26);
        label_65->setObjectName(QString::fromUtf8("label_65"));

        gridLayout_7->addWidget(label_65, 5, 3, 1, 1);

        lineEdit_oversizeNum_2 = new QLineEdit(groupBox_26);
        lineEdit_oversizeNum_2->setObjectName(QString::fromUtf8("lineEdit_oversizeNum_2"));
        lineEdit_oversizeNum_2->setReadOnly(true);

        gridLayout_7->addWidget(lineEdit_oversizeNum_2, 2, 4, 1, 1);

        checkBox_peaking = new QCheckBox(groupBox_26);
        checkBox_peaking->setObjectName(QString::fromUtf8("checkBox_peaking"));

        gridLayout_7->addWidget(checkBox_peaking, 0, 3, 1, 1);

        label_26 = new QLabel(groupBox_26);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_7->addWidget(label_26, 2, 3, 1, 1);


        horizontalLayout_35->addWidget(groupBox_26);


        verticalLayout_28->addLayout(horizontalLayout_35);


        horizontalLayout_40->addLayout(verticalLayout_28);


        verticalLayout_4->addWidget(widget_7);

        stackedWidget->addWidget(page_4);

        horizontalLayout_11->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1450, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        tabWidget_init->setCurrentIndex(2);
        stackedWidget_com->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        pushButton_serialOpenClose->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244\345\217\221\351\200\201", nullptr));
        pushButton_send_serial->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        pushButton_clearSend_serial->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\346\224\266", nullptr));
        pushButton_saveDataSerial->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        lineEdit_saveDataTimeSerial->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
        pushButton_clearReceive_serial->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
        plainTextEdit_statusBar_serial->setPlainText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232\351\273\230\350\256\244\344\270\262\345\217\2431\347\232\204\346\263\242\347\211\271\347\216\207\346\230\2573M\357\274\214\345\217\257\347\224\250\344\272\216\347\272\242\345\244\226\347\233\270\346\234\272\345\222\214\345\217\257\350\247\201\345\205\211\347\233\270\346\234\272\347\232\204\350\264\250\345\277\203\345\270\247\346\225\260\346\215\256\346\216\245\346\224\266\343\200\201\345\217\257\350\247\201\345\205\211\347\233\270\346\234\272\346\214\207\344\273\244\345\217\221\351\200\201\343\200\201\345\217\257\350\247\201\345\205\211\347\233\270\346\234\272\345\223\215\345\272\224\345\270\247\346\216\245\346\224\266", nullptr));
        tabWidget_init->setTabText(tabWidget_init->indexOf(tab_serial), QCoreApplication::translate("MainWindow", "COM I", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\220\215", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        pushButton_serialOpenClose_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244\345\217\221\351\200\201", nullptr));
        pushButton_send_serial_2->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        pushButton_clearSend_serial_2->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        groupBox_16->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\346\224\266", nullptr));
        pushButton_saveDataSerial_2->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        lineEdit_saveDataTimeSerial_2->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
        pushButton_clearReceive_serial_2->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
        plainTextEdit_statusBar_serial_2->setPlainText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232\351\273\230\350\256\244\344\270\262\345\217\2432\347\232\204\346\263\242\347\211\271\347\216\207\346\230\257115200\357\274\214\345\217\257\347\224\250\344\272\216\347\272\242\345\244\226\347\233\270\346\234\272\345\223\215\345\272\224\345\270\247\346\216\245\346\224\266\343\200\201\347\272\242\345\244\226\347\233\270\346\234\272\346\214\207\344\273\244\345\217\221\351\200\201\343\200\201\347\272\242\345\244\226\347\233\270\346\234\272\346\270\251\345\272\246\351\201\245\346\265\213\345\270\247\346\216\245\346\224\266", nullptr));
        tabWidget_init->setTabText(tabWidget_init->indexOf(tab_4), QCoreApplication::translate("MainWindow", "COM II", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "RS422", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\235\277\345\215\241\346\225\260", nullptr));
        pushButton_cardOpenClose->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_startLVDS->setText(QCoreApplication::translate("MainWindow", "\344\275\277\350\203\275", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        pushButton_clearFIFO->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\347\274\223\345\255\230", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\235\277\345\215\241\351\200\232\351\201\223", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244\345\217\221\351\200\201", nullptr));
        plainTextEdit_send->setPlainText(QCoreApplication::translate("MainWindow", "EB 90 00 02 01 00 00 03 09 D7", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", " \345\217\221\351\200\201 ", nullptr));
        pushButton_clearSend->setText(QCoreApplication::translate("MainWindow", " \346\270\205\347\251\272 ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\346\224\266", nullptr));
        pushButton_saveDataRS422->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        lineEdit_saveTimeRS422->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
        pushButton_clearReceive->setText(QCoreApplication::translate("MainWindow", " \346\270\205\347\251\272 ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
        plainTextEdit_statusBar->setPlainText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232RS422\346\235\277\345\215\241\351\273\230\350\256\244\346\263\242\347\211\271\347\216\2073M\357\274\214\345\217\257\347\224\250\344\272\216\345\217\257\350\247\201\345\205\211\347\233\270\346\234\272\346\214\207\344\273\244\345\217\221\351\200\201\343\200\201\350\264\250\345\277\203\345\270\247\346\216\245\346\224\266\343\200\201\345\223\215\345\272\224\345\270\247\346\216\245\346\224\266", nullptr));
        tabWidget_init->setTabText(tabWidget_init->indexOf(tab_card), QCoreApplication::translate("MainWindow", "\346\235\277\345\215\241RS422", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", " LVDS", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\346\235\277\345\215\241\346\225\260", nullptr));
        pushButton_cardOpenClose_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_startLVDS_2->setText(QCoreApplication::translate("MainWindow", "\344\275\277\350\203\275", nullptr));
        pushButton_reset_2->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        pushButton_clearFIFO_2->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\347\274\223\345\255\230", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\346\235\277\345\215\241\351\200\232\351\201\223", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244\345\217\221\351\200\201", nullptr));
        plainTextEdit_send_2->setPlainText(QCoreApplication::translate("MainWindow", "EB 90 00 02 01 00 00 03 09 D7", nullptr));
        pushButton_send_2->setText(QCoreApplication::translate("MainWindow", " \345\217\221\351\200\201 ", nullptr));
        pushButton_clearSend_2->setText(QCoreApplication::translate("MainWindow", " \346\270\205\347\251\272 ", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\216\245\346\224\266", nullptr));
        pushButton_saveDataLVDS->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        lineEdit_saveTimeLVDS->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
        pushButton_clearReceive_2->setText(QCoreApplication::translate("MainWindow", " \346\270\205\347\251\272 ", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
        plainTextEdit_statusBar_2->setPlainText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232LVDS\346\235\277\345\215\241\345\217\257\347\224\250\344\272\216\345\217\257\350\247\201\345\205\211\347\233\270\346\234\272\345\222\214\347\272\242\345\244\226\347\233\270\346\234\272\347\232\204\345\233\276\345\203\217\346\225\260\346\215\256\346\216\245\346\224\266", nullptr));
        tabWidget_init->setTabText(tabWidget_init->indexOf(tab), QCoreApplication::translate("MainWindow", " \346\235\277\345\215\241LVDS", nullptr));
        pushButton_import_com_xml->setText(QCoreApplication::translate("MainWindow", " \346\267\273\345\212\240\346\214\207\344\273\244\347\273\204", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244\345\223\215\345\272\224\347\273\223\346\236\234", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\345\270\247:", nullptr));
        lb_local_count->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\210\263:", nullptr));
        lb_time->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244ID:", nullptr));
        lb_cmd_id->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\272\224\347\273\223\346\236\234:", nullptr));
        lb_result->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "\351\224\231\350\257\257\347\261\273\345\236\213:", nullptr));
        lb_error_type->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\214\207\344\273\244:", nullptr));
        lb_current_cmd_name->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\346\214\207\344\273\244", nullptr));
        pushButton_sendCardCom->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
        pb_del_cmd->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\214\207\344\273\244", nullptr));
        pb_clear_cmd->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\214\207\344\273\244\345\272\217\345\210\227", nullptr));
        pb_insert_cmd->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\345\210\260\346\214\207\344\273\244\345\272\217\345\210\227", nullptr));
        pb_add_cmd->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\210\260\346\214\207\344\273\244\345\272\217\345\210\227", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\210\263:", nullptr));
        spinBox->setSuffix(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
        pb_send_cmd_immediately->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\347\253\213\345\215\263\344\273\244", nullptr));
        checkBox_COMI->setText(QString());
        label_52->setText(QCoreApplication::translate("MainWindow", "COMI", nullptr));
        checkBox_COMII->setText(QString());
        label_53->setText(QCoreApplication::translate("MainWindow", "COMII", nullptr));
        checkBox_CARDRS422->setText(QString());
        label_54->setText(QCoreApplication::translate("MainWindow", "\346\235\277\345\215\241RS422", nullptr));
        checkBox_CARDLVDS->setText(QString());
        label_55->setText(QCoreApplication::translate("MainWindow", "\346\235\277\345\215\241LVDS", nullptr));
        pb_import_xml->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245XML", nullptr));
        pushButton_editPara->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\346\214\207\344\273\244\350\241\214", nullptr));
        pb_export_xml->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272XML", nullptr));
        pb_send_cmd->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\221\275\344\273\244", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("MainWindow", "\345\216\237\345\247\213\345\270\247", nullptr));
        groupBox_21->setTitle(QCoreApplication::translate("MainWindow", "\345\205\264\350\266\243\345\270\247", nullptr));
        groupBox_22->setTitle(QCoreApplication::translate("MainWindow", "\351\201\245\346\265\213\350\257\267\346\261\202\350\256\276\347\275\256", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "\350\257\267\346\261\202\351\227\264\351\232\224:", nullptr));
        sb_request_interval->setSuffix(QCoreApplication::translate("MainWindow", "S", nullptr));
        pb_begin_request->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\267\346\261\202", nullptr));
        groupBox_23->setTitle(QCoreApplication::translate("MainWindow", "\351\201\245\346\265\213\345\270\247", nullptr));
        label_69->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256\346\227\266\351\227\264\357\274\232", nullptr));
        lb_recv_tm_data_time->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_68->setText(QCoreApplication::translate("MainWindow", "\351\201\245\346\265\213\346\200\273\345\270\247\346\225\260\357\274\232", nullptr));
        le_frame_total_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_74->setText(QCoreApplication::translate("MainWindow", "\351\201\245\346\265\213\351\224\231\350\257\257\345\270\247\346\225\260\357\274\232", nullptr));
        le_frame_crc_wrong_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_81->setText(QCoreApplication::translate("MainWindow", "\351\201\245\346\265\213\346\255\243\347\241\256\345\270\247\346\225\260\357\274\232", nullptr));
        le_frame_crc_success_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pb_clear_frame_errors->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\350\256\241\346\225\260", nullptr));
        lb_frame_success_status->setText(QString());
        lb_frame_crc_wrong_status->setText(QString());
        lb_frame_timeout_status->setText(QString());
        groupBox_24->setTitle(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\350\256\276\347\275\256", nullptr));
        rb_save_data_manual->setText(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\344\277\235\345\255\230", nullptr));
        rb_save_data_auto->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\344\277\235\345\255\230", nullptr));
        pb_begin_save_data->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        sb_time->setSuffix(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\347\212\266\346\200\201:", nullptr));
        lb_status_show->setText(QCoreApplication::translate("MainWindow", "\346\232\202\346\227\240\347\212\266\346\200\201", nullptr));
        groupBox_25->setTitle(QCoreApplication::translate("MainWindow", "\351\201\245\346\265\213\346\225\260\346\215\256\346\227\245\345\277\227", nullptr));
        te_tm_info->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        groupBox_18->setTitle(QString());
        label_49->setText(QCoreApplication::translate("MainWindow", "\345\270\247\350\256\241\346\225\260", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "\351\224\231\350\257\257\345\270\247\350\256\241\346\225\260", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "\350\266\205\351\230\210\345\200\274\347\202\271\344\270\252\346\225\260", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "\350\266\205\351\230\210\345\200\274\347\202\271\347\201\260\345\272\246\347\264\257\345\212\240\345\222\214", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "\346\233\235\345\205\211\346\227\266\351\227\264", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\347\201\260\345\272\246\346\234\200\345\260\217\346\234\200\345\244\247\345\200\274", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "\346\255\243\347\241\256\345\270\247\350\256\241\346\225\260", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", " \350\264\250\345\277\203\345\235\220\346\240\207", nullptr));
        groupBox_19->setTitle(QString());
        label_58->setText(QCoreApplication::translate("MainWindow", "SEL\347\224\265\346\265\201\345\200\274", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "FPGA\346\270\251\345\272\246", nullptr));
        lineEdit_temFPGA->setText(QString());
        label_56->setText(QCoreApplication::translate("MainWindow", "TEC\346\270\251\345\272\246", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "\346\216\242\346\265\213\345\231\250Vtemp\346\270\251\345\272\246\345\200\274", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "SEL\347\212\266\346\200\201", nullptr));
        label_73->setText(QCoreApplication::translate("MainWindow", "SEL5s\345\206\205\350\277\207\346\265\201\346\254\241\346\225\260", nullptr));
        label_75->setText(QCoreApplication::translate("MainWindow", "SEL\350\277\207\346\265\201\346\254\241\346\225\260\350\256\260\345\275\225", nullptr));
        label_76->setText(QCoreApplication::translate("MainWindow", "SEL\350\277\207\346\265\201\346\227\266\347\224\265\346\265\201\351\207\207\346\240\267\345\200\274", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\346\233\235\345\205\211\346\250\241\345\274\217", nullptr));
        label_78->setText(QCoreApplication::translate("MainWindow", "\345\235\217\347\202\271\346\240\241\346\255\243\346\250\241\345\274\217", nullptr));
        label_79->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\346\225\260\346\215\256\346\272\220", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", " \345\233\276\345\203\217\344\277\235\345\255\230", nullptr));
        pushButton_saveImage_2->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\233\276\345\203\217", nullptr));
        pushButton_beginSaveImages_2->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\344\277\235\345\255\230", nullptr));
        lineEdit_saveImagesTime_2->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
        checkBox_overGrayScaleCoordinates->setText(QCoreApplication::translate("MainWindow", " \350\266\205\351\230\210\345\200\274\347\202\271\345\235\220\346\240\207", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\270\247\350\247\243\346\236\220", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\345\274\200\347\252\227\345\244\247\345\260\217", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "LVDS\351\224\231\350\257\257\345\270\247\346\225\260", nullptr));
        lineEdit_falseFrameNum_2->setText(QString());
        label_24->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\347\240\201", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\270\247\347\274\226\345\217\267", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "LVDS\346\255\243\347\241\256\345\270\247\346\225\260", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "LVDS\346\200\273\345\270\247\346\225\260", nullptr));
        groupBox_26->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206(\344\270\212\344\275\215)", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\351\224\220\345\214\226\347\201\260\345\272\246\351\230\210\345\200\274", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "\350\264\250\345\277\203", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\347\201\260\345\272\246\351\230\210\345\200\274", nullptr));
        lineEdit_grayThre_2->setText(QCoreApplication::translate("MainWindow", "128", nullptr));
        label_64->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lineEdit_peakingThreshold->setText(QCoreApplication::translate("MainWindow", "128", nullptr));
        label_65->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        checkBox_peaking->setText(QCoreApplication::translate("MainWindow", "\345\205\211\346\226\221\351\224\220\345\214\226", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\350\266\205\351\230\210\345\200\274\345\203\217\347\264\240\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
