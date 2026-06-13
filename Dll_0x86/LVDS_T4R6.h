#pragma once
#include <functional>
#define DLL __declspec(dllexport)

//using namespace std;  
//using namespace std::placeholders;
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef unsigned char   UINT8;         /* Unsigned  8 bit quantity     */
typedef signed   char   INT8;          /* Signed    8 bit quantity     */
typedef unsigned short  UINT16;        /* Unsigned  16 bit quantity    */
typedef signed   short  INT16;         /* Signed    16 bit quantity    */
typedef unsigned int    UINT32;        /* Unsigned  32 bit quantity    */
typedef signed   int    INT32;         /* Signed    32 bit quantity    */

typedef int    BOOL;




typedef std::function<void(UINT32, UINT32*)> LVDS_T4R6_callback_fun_t;




/***************************************
功能：初始化库
参数：
   无
返回值：
   大于0表示成功
***************************************/
DLL UINT32 __stdcall LVDS_T4R6_LibInit();

/***************************************
功能：卸载库
参数：
   无
返回值：
	TRUE: 成功
	FALSE:失败
***************************************/
DLL BOOL __stdcall LVDS_T4R6_LibUninit();


/***************************************
功能：打开板卡
参数：
   uCardId:输入参数，第几块板卡(从0开始，设备中有一块卡就输入0，设备中有两块卡可用0和1来区分这两块卡）
返回值：
   TRUE: 成功
   FALSE:失败
***************************************/
DLL BOOL __stdcall LVDS_T4R6_Open(UINT8 uCardId);

/***************************************
功能：关闭板卡
参数：
   uCardId:输入参数，第几块板卡
返回值：
   TRUE: 成功
   FALSE:失败
***************************************/
DLL BOOL __stdcall LVDS_T4R6_Close(UINT8 uCardId);

/***************************************
功能：复位板卡
参数：
   uCardId:输入参数，第几块板卡
返回值：
   TRUE: 成功
   FALSE:失败
***************************************/
DLL BOOL __stdcall LVDS_T4R6_REST(UINT8 uCardId);


/***************************************
功能：设置接收一帧数据量大小
参数：
   uCardId:输入参数，第几块板卡
   uSize:一帧数据量大小(单位:字节)
返回值：
   TRUE: 成功
   FALSE:失败
***************************************/
DLL BOOL __stdcall LVDS_T4R6_Set_FrameSize(UINT8 uCardId,UINT32 uSize);


/***************************************
功能：接收使能
参数：
   uCardId:输入参数，第几块板卡
   uEnable： 0:关闭接收  1:开始接收
返回值：
   TRUE: 成功
   FALSE:失败
***************************************/
DLL BOOL __stdcall LVDS_T4R6_RX_Enable(UINT8 uCardId,UINT8 uEnable);


/***************************************
功能：获取可以接收的数据量
参数：
   CardID:输入参数，第几块板卡
   pDataCnt:数据量(单位:字节)
返回值：
   TRUE: 成功
   FALSE:失败
***************************************/
DLL BOOL __stdcall LVDS_T4R6_RX_DataCnt(UINT8 uCardId,UINT32 *pDataCnt);


/***************************************
功能：接收数据
参数：
   CardID:输入参数，第几块板卡
   pData:数据
   uDataCnt:数据量(单位:字节)
返回值：
   TRUE: 成功
   FALSE:失败
***************************************/
DLL BOOL __stdcall LVDS_T4R6_RX_Data(UINT8 uCardId,UINT8 *pData,UINT32 uDataCnt);




//<<发送:使能(测试使用)
DLL BOOL __stdcall LVDS_T4R6_TX_Enable(UINT8 uCardId,UINT8 uChannel,UINT8 uEnable);
























#ifdef __cplusplus
}
#endif // __cplusplus