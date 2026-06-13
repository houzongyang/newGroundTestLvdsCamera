#ifndef LVDS_SIGNALPAGE_H
#define LVDS_SIGNALPAGE_H

#include <QWidget>
#include <QFrame>
#include <DebugPage.h>
#include <LVDS_T4R6.h>
#include <LVDS_Thread.h>

namespace Ui {
class LVDS_SignalPage;
}

class LVDS_SignalPage : public QWidget
{
    Q_OBJECT

public:
    explicit LVDS_SignalPage(UINT8 uCarID,UINT8 uCh,QMutex *pQMutex,QWidget *parent = nullptr);
    ~LVDS_SignalPage();


    DebugPage *m_DebugPage;
    void Layout_DEBUG_Page(QFrame *frame,DebugPage *pDebug);

    LVDS_Rx_Thead *m_LVDS_Rx_Thead;
    Dis_Data_Thead *m_Dis_Data_Thead;



public slots:
    void Rx_Deal_PictureData_Slots(QPixmap frame);

        void showSLots(QString s);

signals:
    void DEBUG_Message_Signal(QString type,QString msg);

private slots:
    void on_Rx_State_pushButton_clicked();

    void on_Tx_State_pushButton_clicked();

    void on_Tx_Time_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::LVDS_SignalPage *ui;

    UINT8 m_CarID;
    UINT8 m_Ch;

};

#endif // LVDS_SIGNALPAGE_H
