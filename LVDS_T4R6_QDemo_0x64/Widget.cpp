#include "Widget.h"
#include "ui_Widget.h"
#include <QGroupBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    uCardId = 0;

    OPen_LVDS_Car(uCardId);

    m_LVDS_SignalPage_CH1 = new LVDS_SignalPage(uCardId,0,&m_QMutex);
    m_LVDS_SignalPage_CH2 = new LVDS_SignalPage(uCardId,1,&m_QMutex);


    // 1. 创建 groupBox 并起名
    auto *gbCh1 = new QGroupBox(tr("通道 1"), this);
    //auto *gbCh2 = new QGroupBox(tr("通道 2"), this);

    // 2. 每个 groupBox 内部用布局撑满
    auto *lay1 = new QVBoxLayout(gbCh1);
    lay1->setContentsMargins(2, 2, 2, 2);
    lay1->addWidget(m_LVDS_SignalPage_CH1);

   // auto *lay2 = new QVBoxLayout(gbCh2);
    //lay2->setContentsMargins(2, 2, 2, 2);
    //lay2->addWidget(m_LVDS_SignalPage_CH2);

    // 3. 外层垂直布局：通道1在上，通道2在下
    auto *mainLay = new QVBoxLayout(this);
    mainLay->addWidget(gbCh1);
    //mainLay->addWidget(gbCh2);


    mainLay->setStretch(0, 1);   // 通道1
    mainLay->setStretch(1, 1);   // 通道2


    this->setWindowTitle("LVDS:采集卡");



}

Widget::~Widget()
{
    delete ui;
}

void Widget::OPen_LVDS_Car(UINT8 uCardId)
{
    if(LVDS_T4R6_LibInit() == 0)
    {
        QMessageBox::information(this,"ERROR","未找到板卡.检查驱动.板卡连接");
        return;
    }



    if( LVDS_T4R6_Open(uCardId) == false)
    {
        QMessageBox::information(this,"ERROR","板卡打开失败");
        return;
    }


    if( LVDS_T4R6_REST(uCardId) == false)
    {
        QMessageBox::information(this,"ERROR","板卡复位失败");
        return;
    }
}



