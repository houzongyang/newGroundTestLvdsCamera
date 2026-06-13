#include "LVDS_Thread.h"
#include <QCoreApplication>

LVDS_Rx_Thead::LVDS_Rx_Thead(UINT8 uCarID,UINT8 uCh,QMutex *pQMutex)
{
    m_CarID = uCarID;
    m_Ch = uCh;
    m_pQMutex = pQMutex;

    m_streamData.resize(200*1024*1024);

}

#include <QElapsedTimer>
void LVDS_Rx_Thead::run()
{

    QString strPath = QCoreApplication::applicationDirPath();
    strPath += QString("//Rx%1Data.dat").arg(m_Ch);
    FILE* fp = fopen(strPath.toStdString().c_str(), "wb+");



    // ===================== 速度计算变量 =====================
       QElapsedTimer timer;          // 高精度计时器
       timer.start();                // 启动计时

       quint64 totalBytes = 0;       // 总接收字节数
       quint64 speedBytes = 0;       // 1秒内累计的字节数（用于计算速度）
       const int UPDATE_INTERVAL = 1000; // 每1000ms更新一次速度
       // ======================================================


    while (m_FLAG)
    {
        m_pQMutex->lock();
        UINT32 dataCnt = 0;
        if(LVDS_T4R6_RX_DataCnt(m_CarID,&dataCnt) == true)
        {

            if(dataCnt >0 )
            {



UINT8  *pData8  = (UINT8 *)malloc(dataCnt);


                if(LVDS_T4R6_RX_Data(m_CarID,pData8,dataCnt) >0)
                {

                     if(m_FLAG_2 == false)
                     {
                         if((dataCnt == 0) && (cout == 1000000000))
                         {
                             cout++;
                             m_FLAG = false;
                         }
                     }

                    //emit  NET_Seppd(QString("数据量:%1").arg(QString::number(dataCnt,10)));

                    fwrite(pData8,1, dataCnt, fp);

                    // ===================== 累计字节数 =====================
                                    totalBytes += dataCnt;
                                    speedBytes += dataCnt;
                                    // =====================================================



                    free(pData8);

                }else
                {

                    free(pData8);
                }
            }



        }else
        {

        }


        // ===================== 每秒计算一次速度 =====================
            if (timer.elapsed() >= UPDATE_INTERVAL)
            {
                // 计算速度：Bytes -> KB/s -> MB/s
                double speedKBps = speedBytes / 1024.0;
                double speedMBps = speedKBps / 1024.0;
                double totalMB = totalBytes / 1024.0 / 1024.0;

                // 打印输出（你可以把这些值显示到UI界面）
                Net_Speed = QString("通道[%1] 接收速度：%2 KB/s | %3 MB/s | 总数据：%4 MB ")
                       .arg(m_Ch)
                       .arg(speedKBps, 6, 'f', 2)
                       .arg(speedMBps, 6, 'f', 2)
                       .arg(totalMB, 8, 'f', 2);


               emit  NET_Seppd(Net_Speed);

                // 重置计数器与计时器
                speedBytes = 0;
                timer.restart();
            }
            // ============================================================

         m_pQMutex->unlock();


    }


    fclose(fp);
}

void LVDS_Rx_Thead::Thead_Working()
{
    m_FLAG = true;
      m_FLAG_2 = true;
      cout = 0;
    this->start();
}

void LVDS_Rx_Thead::Thread_Stop()
{
    cout = 0;
    m_FLAG_2 = false;
    //m_FLAG = false;
}



ToolCircleBuffer::ToolCircleBuffer(QObject *parent) : QObject(parent)
{

}

circleBuffer *ToolCircleBuffer::Cb_Init(unsigned int pBufLen)
{
    if (pBufLen == 0) return NULL;

    /* 1. 先分配结构体 */
    circleBuffer *cb = (circleBuffer *)malloc(sizeof(*cb));
    if (!cb) return NULL;

    memset(cb,0,sizeof(circleBuffer));

    /* 2. 再分配数据区 */
    cb->buf = (unsigned char *)malloc(pBufLen);
    if (!cb->buf) { free(cb); return NULL; }

    /* 3. 初始化字段 */
    cb->buflen  = pBufLen;


    return cb;          /* 调用者只拿到这个指针 */
}

unsigned int ToolCircleBuffer::Cb_GetCnt(circleBuffer *pCbBuffer)
{
    unsigned int  dataCnt = 0;
    dataCnt = pCbBuffer->size;
    return dataCnt;
}

unsigned int ToolCircleBuffer::Cb_ReadData(circleBuffer *pCbBuffer, unsigned char *pOutbuf, unsigned int uReadLen)
{
    unsigned int  canuReadLen=0;
    if(pOutbuf==NULL) return 0;
    if(pCbBuffer->size==0) return 0;//没有数据可以读
    canuReadLen=pCbBuffer->wroffset-pCbBuffer->rdoffser;
    if(canuReadLen<0) canuReadLen+=pCbBuffer->buflen;

    if(pCbBuffer->size == pCbBuffer->buflen)
        canuReadLen = pCbBuffer->buflen;
    if(canuReadLen<uReadLen)
    {
        uReadLen=canuReadLen;//uReadLen是能读到的数量
    }
    if(uReadLen<pCbBuffer->buflen-pCbBuffer->rdoffser)
    {
        //说明不用不用折回来读
        memcpy(pOutbuf,&pCbBuffer->buf[pCbBuffer->rdoffser],uReadLen);
    }else
    {
        //说明存到最大的地方没存完，需要继续折回来读,第一次读先读到数组的结尾
        memcpy(pOutbuf,&pCbBuffer->buf[pCbBuffer->rdoffser],pCbBuffer->buflen-pCbBuffer->rdoffser);
        memcpy(&pOutbuf[pCbBuffer->buflen-pCbBuffer->rdoffser],pCbBuffer->buf,uReadLen-(pCbBuffer->buflen-pCbBuffer->rdoffser));
    }

    //更新读指针
    pCbBuffer->rdoffser=(uReadLen+pCbBuffer->rdoffser)%pCbBuffer->buflen;
    //更新下实际的数量大小
    pCbBuffer->size-=uReadLen;
    return uReadLen;//返回读到的数据量
}

unsigned int ToolCircleBuffer::Cb_WriteData(circleBuffer *pCbBuffer, unsigned char *pInbuf, unsigned int uWrireLen)
{
    unsigned int  canWriteLen=0;
    //老样子，做参数检查
    if(pCbBuffer==NULL ||pInbuf==NULL ||uWrireLen==0 )
    {
        return 0;
    }
    //检查环形buffer是否是满的
    if(pCbBuffer->size==pCbBuffer->buflen)
    {
        return 0;
    }
    //检查剩余的空间是否够写入
    canWriteLen=pCbBuffer->rdoffser-pCbBuffer->wroffset;
    if(canWriteLen<=0) canWriteLen+=pCbBuffer->buflen;
    if(uWrireLen>canWriteLen) return -1;//没有足够的空间则不写入
    //开始写
    if(uWrireLen<pCbBuffer->buflen-pCbBuffer->wroffset)
    {
        //不用折行，直接写入
        memcpy(&pCbBuffer->buf[pCbBuffer->wroffset],pInbuf,uWrireLen);
    }else
    {
        //一行写完以后，需要重新折过来，从开头在写入 uWrireLen-(pCbBuffer->buflen-pCbBuffer->wroffset)
        memcpy(&pCbBuffer->buf[pCbBuffer->wroffset],pInbuf,pCbBuffer->buflen-pCbBuffer->wroffset);
        memcpy(pCbBuffer->buf,&pInbuf[pCbBuffer->buflen-pCbBuffer->wroffset],uWrireLen-(pCbBuffer->buflen-pCbBuffer->wroffset));
    }
    //更新写指针
    pCbBuffer->wroffset=(uWrireLen+pCbBuffer->wroffset)%pCbBuffer->buflen;
    //更新size
    pCbBuffer->size+=uWrireLen;
    return uWrireLen;
}

unsigned int ToolCircleBuffer::Cb_FreeBuf(circleBuffer *pCbBuffer)
{
    if (pCbBuffer)
    {
        if (pCbBuffer->buf)
        {
            free(pCbBuffer->buf);
            pCbBuffer->buf = NULL;
        }
        free(pCbBuffer);
        pCbBuffer = NULL;
    }else
    {
        return  false;
    }

    return  true;
}


#include <QPixmap>
#include <QTimer>
Dis_Data_Thead::Dis_Data_Thead()
{
    m_QThread = new QThread();
    this->moveToThread(m_QThread);
    m_QThread->start();


    //<<开辟空间:环形缓冲区:32M
    m_CbBuffer = m_ToolCircleBuffer->Cb_Init(100*1024*1024);

    pictureSize = 320*240;
    m_SignalStream_Data.resize(pictureSize);

    m_QTimer = new QTimer();
    m_QTimer->setInterval(1000);

   // connect(m_QTimer,SIGNAL(timeout()),this,SLOT(Cul_FPS()));
    //m_QTimer->start();


}

Dis_Data_Thead::~Dis_Data_Thead()
{

}

QPixmap Dis_Data_Thead::Trs_StreamData_QPixmap(QByteArray streamData)
{
    const int w = 320;
    const int h = 240;
    const int need = w * h;              // 76 800 字节

    if (streamData.size() != need)       // 长度不对直接返回空图
        return QPixmap();

    // 1. 裸数据 → QImage（零拷贝）
    QImage img(reinterpret_cast<const uchar*>(streamData.constData()),
               w, h,                     // 宽高
               w,                        // 每行字节数
               QImage::Format_Grayscale8);

    // 2. QImage → QPixmap
    return QPixmap::fromImage(img);
}

void Dis_Data_Thead::Rx_StreamData_Slots(QByteArray streamData)
{

    m_ToolCircleBuffer->Cb_WriteData(m_CbBuffer,(unsigned char *)streamData.data(),streamData.size());



    while ( m_ToolCircleBuffer->Cb_GetCnt(m_CbBuffer) >= pictureSize)
    {

        m_ToolCircleBuffer->Cb_ReadData(m_CbBuffer,(unsigned char *)m_SignalStream_Data.data(),pictureSize);

        emit Tx_Picture_Data_Signal(Trs_StreamData_QPixmap(m_SignalStream_Data));
        fps++;
    }
}

void Dis_Data_Thead::Cul_FPS()
{

    qDebug()<<"fps"<<fps;
    fps = 0;
}
