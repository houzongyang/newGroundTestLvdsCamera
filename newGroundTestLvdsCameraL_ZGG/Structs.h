/**
  时间：2025.8.6
  作者：XXH
  说明：这是一个专门用于定义结构体的头文件，没有与之对应的cpp文件
  */

#ifndef STRUCTS_H
#define STRUCTS_H
#include <QString>
#include <QStringList>
#include <QPoint>



//UI界面将用户设定的属性发送出去的结构体
struct SettingsUiToSub{
    int grayThrehold; // 灰度阈值设置
};

// LVDS图像帧解析时的属性结构体
struct ImageAttributes{
    int imgFrameNo = 0; // 图像帧编号
    QString imgFrameNoString;
    int totalImgNum = 0; // 总图像帧计数
    int validImgNum = 0; // 正确图像帧计数
    int errorImgNum = 0; // 错误图像帧计数，校验和不对
    int imgWinSize = 0; // 开窗大小
    int overThreshold = 0; // 超阈值点数量
    QString timeCode; // 时间码 解析成XXXXX 秒 XXXXX 毫秒

    QVector<QPoint> overThresholdCo;
};

// 相机质心帧属性结构体
struct CentroidFrameAttributes{
    double centroidX = 0.0; // X方向质心
    double centroidY = 0.0; // Y方向质心
    int maxGrayscale = 0; // 最大灰度值
    int minGrayscale = 0; // 最小灰度值
    int overThreshold = 0 ; // 超阈值点数量
    int exposureTime = 0; // 曝光时间
    quint32 grayscaleSum = 0; // 灰度累加和

    int totalFrameNum = 0; // 总质心帧计数
    int validFrameNum = 0; // 正确质心帧计数
    int errorFrameNum = 0; // 错误质心帧计数

    // SEL电流值
    int SEL_Current = 0;
    // FPGA温度值
    int FPGA_Tem = 0;
    // TEC温度值
    int Tec_Tem = 0;
    // 探测器Vtemp温度值
    int Vtemp_Tem = 0;
    // SEL状态
    QString SEL_Status = "无效";
    // SEL5s内过流次数
    int SEL_OverTimes = 0;
    // SEL过流次数记录
    int SEL_OverTimesRecord = 0;
    // SEL过流时电流采样值
    int SEL_OverCurrentSampling = 0;
    // 相机曝光模式
    QString Camera_ExpoMode = "无效";
    // 坏点校正模式
    QString BadPix_CoreMode = "无效";
    // 图像数据源
    QString Image_DataSource = "无效";
    // 保留1
    int Reserve1 = 0;
    // 保留2
    int Reserve2 = 0;
};

// 红外相机温度遥测帧属性结构体
struct TemperatureFrameAttributes{
    int tempTEC = 0; // TEC温度
    int tempFPGA = 0; // FPGA温度

    bool isUiParaValid = false;
    int totalUiParaNum = 0;
    int errorUiparaNum = 0;
    int validUiParaNum = 0;

    int totalFrameNum = 0; // 总温度帧计数
    int validFrameNum = 0; // 正确温度帧计数
    int errorFrameNum = 0; // 错误温度帧计数，校验和不对

};

// 这个结构体的目的是从xml中获取需要的参数
struct CommandAttribute {

    QString paraNo; // 参数编号
    QString paraName; // 参数名称
    QString paraValue; // 参数数值
    QString byteHex; // 源码
    QString byteNotes; // 备注

    QString paraType;


    QStringList paraOptions;
    QStringList hexCodes;
    QString paraIntCode;

    QString encodeRule;
    QString decodeRule;
    int byteLength;
    QString minValue;
    QString maxValue;

    // 默认索引号
    int initIndex;
};

// 指令组结构体，加载到指令配置列表
struct Command {
    QString name; // 指令组名称
    int Index; // 指令组索引

    QString header; // 指令组帧头
    QString tail; // 指令组帧尾
    int checkSumLength = 1; // 校验和占据多少个字节

    QList<CommandAttribute> attributes; // 指令组内容
};

/// 指令序列保存xml文件结构体，加载到指令发送列表
struct CommandInfo{
    int index; // 当前指令在指令序列中的索引（行号）
    QString CommandTime;            //命令发送的时间戳
    QString CommandName;            //指令名称
    QString CommandCode;            //命令码 发送命令使用
    QString CommandRemark;          //这条命令的备注信息
    QList<CommandAttribute> paraInfo;      //参数信息 一个命令有多个数据域
};

struct CommandQueue{
    QString commandTime; // 指令时间延迟
    QString commandName ; // 指令名称
    QString commandCodeH; // 指令代码
    QString commandCode;
    QString commandRemarks; // 备注
};


// 遥测解析结构体
struct TMparaQueue{
    QString paraName;
    QString initCode;
};

struct TMitemQueue{
    QString TMitemLength; // 遥测参数源码长度
    QString TMitemNo; // 遥测参数编号
    QString TMitemName ; // 遥测参数名称
    QString ParaType; // 遥测参数源码
    QString EncodeType; // 遥测参数解码规则（从十六位源码到十进制数值）
    // （COMBOX类型专用）
//    QString Para; // 遥测参数数值
    QString TMitemRemarks; // 备注
    QString TMitemMinF;
    QString TMitemMaxF;
    QString FrameLength;

    QList<TMparaQueue> TMparaList;

    QString ByteInherit;
    QString BitOffset;
    QString BitLength;

    QString TMsignedType;// 符号数
};

struct ParaListUi{
    QString paraNo;
    QString value; // 数值
    QString code; // 源码
    bool isValid  = true; // 有效性
};

struct FrameTM{
    int frameLength = 0;
    QString frameHead;
    QString frameTail;
    int checkSumNum = 0;

    int frameLengthAll = 0;
    QString frameHeadAll;
    QString CutFront;
};



#endif // STRUCTS_H

