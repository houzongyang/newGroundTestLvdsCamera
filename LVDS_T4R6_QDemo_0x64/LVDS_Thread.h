#ifndef LVDS_THREAD_H
#define LVDS_THREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <LVDS_T4R6.h>
#include <QMutex>


class LVDS_Rx_Thead:public QThread
{
    Q_OBJECT
public:
    LVDS_Rx_Thead(UINT8 uCarID,UINT8 uCh,QMutex *pQMutex);

    void run() override;

    void Thead_Working();
    void Thread_Stop();



    QByteArray m_streamData;

    QString Net_Speed;

signals:
    void DEBUG_Message_Signal(QString type,QString msg);

    void Tx_StreamData_Signal(QByteArray streamData);


    void NET_Seppd(QString speed);




private:
    UINT8 m_CarID;
    UINT8 m_Ch;
    bool m_FLAG;

      bool m_FLAG_2;

      unsigned int cout;

    QMutex *m_pQMutex;


};




//<<环形缓冲区结构体
typedef struct circlebuffer
{
    unsigned int  size;
    unsigned int wroffset;
    unsigned int rdoffser;
    unsigned char * buf;
    unsigned int buflen;
}circleBuffer;


//<<缓冲区:类
class ToolCircleBuffer : public QObject
{
    Q_OBJECT
public:
    explicit ToolCircleBuffer(QObject *parent = nullptr);

    //<<初始化:环形缓冲区
    circleBuffer * Cb_Init(unsigned int pBufLen);

    //<<获取:环形缓冲区:数据量
    unsigned int Cb_GetCnt(circleBuffer *pCbBuffer);

    //<<读取:环形缓冲区:数据
    unsigned int Cb_ReadData(circleBuffer *pCbBuffer,unsigned char *pOutbuf,unsigned int uReadLen);

    //<<写入:环形缓冲区:数据
    unsigned int Cb_WriteData(circleBuffer *pCbBuffer,unsigned char *pInbuf,unsigned int uWrireLen);

    //<<释放:环形缓冲区
    unsigned int Cb_FreeBuf(circleBuffer *pCbBuffer);


};

#include <QPixmap>
class Dis_Data_Thead:public QObject
{
    Q_OBJECT
public:
    Dis_Data_Thead();
    ~Dis_Data_Thead();

    QTimer *m_QTimer;
    
    QThread *m_QThread;
    
    circleBuffer* m_CbBuffer;
    ToolCircleBuffer *m_ToolCircleBuffer = NULL;

    unsigned int pictureSize;
     QPixmap     m_framePix;
    QByteArray  m_SignalStream_Data;


    unsigned int frameCnt;
    unsigned int  fps;

    QPixmap Trs_StreamData_QPixmap(QByteArray streamData);
    
signals:
    void Tx_Picture_Data_Signal(QPixmap frame);
public slots:
    void Rx_StreamData_Slots(QByteArray streamData);

    void Cul_FPS();
    

};


#endif // LVDS_THREAD_H
