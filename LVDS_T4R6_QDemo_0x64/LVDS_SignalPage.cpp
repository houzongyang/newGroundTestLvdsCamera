#include "LVDS_SignalPage.h"
#include "ui_LVDS_SignalPage.h"

LVDS_SignalPage::LVDS_SignalPage(UINT8 uCarID,UINT8 uCh,QMutex *pQMutex,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LVDS_SignalPage)
{
    ui->setupUi(this);

    m_CarID = uCarID;
    m_Ch = uCh;


    m_DebugPage = new DebugPage();
    //Layout_DEBUG_Page(ui->frame,m_DebugPage);
    connect(this,SIGNAL(DEBUG_Message_Signal(QString,QString)),m_DebugPage,SLOT(DEBUG_Message_Slots(QString,QString)));


    m_LVDS_Rx_Thead = new LVDS_Rx_Thead(m_CarID,m_Ch,pQMutex);
    connect(m_LVDS_Rx_Thead,SIGNAL(DEBUG_Message_Signal(QString,QString)),m_DebugPage,SLOT(DEBUG_Message_Slots(QString,QString)));


    m_Dis_Data_Thead = new Dis_Data_Thead();
    connect(m_LVDS_Rx_Thead,SIGNAL(Tx_StreamData_Signal(QByteArray)),m_Dis_Data_Thead,SLOT(Rx_StreamData_Slots(QByteArray)));
    connect(m_Dis_Data_Thead,SIGNAL(Tx_Picture_Data_Signal(QPixmap)),this,SLOT(Rx_Deal_PictureData_Slots(QPixmap)));

    connect(m_LVDS_Rx_Thead,SIGNAL(NET_Seppd(QString)),this,SLOT(showSLots(QString)));

//    ui->label_3->setScaledContents(true);

//    ui->groupBox_4->hide();
//    ui->groupBox->hide();
}

LVDS_SignalPage::~LVDS_SignalPage()
{
    delete ui;
}

void LVDS_SignalPage::Layout_DEBUG_Page(QFrame *frame, DebugPage *pDebug)
{
    QVBoxLayout* layout = new QVBoxLayout(frame);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(pDebug);
    pDebug->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    frame->setLayout(layout);
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void LVDS_SignalPage::Rx_Deal_PictureData_Slots(QPixmap frame)
{

    //ui->label_3->setPixmap(frame);
}


#include <QDir>
void LVDS_SignalPage::showSLots(QString s)
{
    ui->lineEdit->clear();
    ui->lineEdit->setText(s);

    // ===================== 保存到 日志.txt =====================
//       // 获取程序根目录 + 文件名
//       QString logPath = QDir::currentPath() + "/日志.txt";

//       QFile file(logPath);
//       // 以 追加+文本 模式打开（不会覆盖之前的内容）
//       if (file.open(QIODevice::Append | QIODevice::Text))
//       {
//           QTextStream out(&file);
//           out << s << "\n"; // 写入字符串并换行
//           file.close();
//       }
//       // ==========================================================
}



void LVDS_SignalPage::on_Rx_State_pushButton_clicked()
{
    if(ui->Rx_State_pushButton->text() == "开始接收")
    {
        LVDS_T4R6_RX_Enable(m_CarID,1);
        m_LVDS_Rx_Thead->Thead_Working();


        ui->Rx_State_pushButton->setText("停止接收");
    }else if(ui->Rx_State_pushButton->text() == "停止接收")
    {
        LVDS_T4R6_RX_Enable(m_CarID,0);

             m_LVDS_Rx_Thead->Thread_Stop();
        QThread::msleep(500);
        LVDS_T4R6_REST(m_CarID);




        ui->Rx_State_pushButton->setText("开始接收");
    }
}

void LVDS_SignalPage::on_Tx_State_pushButton_clicked()
{
    if(ui->Tx_State_pushButton->text() == "开始发送")
    {
        LVDS_T4R6_TX_Enable(m_CarID,m_Ch,1);



        ui->Tx_State_pushButton->setText("停止发送");
    }else if(ui->Tx_State_pushButton->text() == "停止发送")
    {
        LVDS_T4R6_TX_Enable(m_CarID,m_Ch,0);

        ui->Tx_State_pushButton->setText("开始发送");
    }
}

void LVDS_SignalPage::on_Tx_Time_pushButton_clicked()
{
//    unsigned int N  = ui->Tx_Time_lineEdit->text().toUInt();




//    unsigned int temptTime = 1000/N;

//    if(temptTime >=32)
//    {
//        DEBUG_Message_Signal("Error","帧率过大");
//        return;
//    }

//    unsigned int time =((temptTime-32)* 1000000)/50;

//    if(LVDS_T4R6_Set_Time(m_CarID,m_Ch,time) == true)
//    {
//        DEBUG_Message_Signal("Right",QString("设置.帧率成功.帧率为:%1").arg(N));
//    }else
//    {
//        DEBUG_Message_Signal("Error",QString("设置.帧率失败.帧率为:%1").arg(N));
//    }
}

void LVDS_SignalPage::on_pushButton_clicked()
{
    LVDS_T4R6_Set_FrameSize(m_CarID,ui->lineEdit_2->text().toUInt());
}
