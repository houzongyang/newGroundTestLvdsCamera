# newGroundTestLvdsCamera

基于 Qt/C++ 的地面检测主控程序，用于通过 PCIe LVDS 板卡、RS422 和串口与相机硬件通信，完成指令发送、遥测接收解析、LVDS 图像数据接收与图像显示/保存。

当前仓库同时包含主程序、LVDS_T4R6 板卡 SDK/驱动资料、厂商示例工程和部分已构建产物。

## 主要功能

- 板卡通信：通过 `LVDS_T4R6.dll` 与 `wdapi1020.dll` 访问 LVDS_T4R6 板卡。
- 串口通信：支持双串口参数配置、收发、数据显示与数据保存。
- RS422/LVDS 数据接收：板卡数据进入环形缓冲区后由后台线程解析。
- 指令发送：从 XML 指令模板加载指令组，支持参数编辑、列表发送和保存。
- 遥测解析：从遥测 XML 配置读取参数定义，解析并显示遥测结果。
- 图像显示：解析 LVDS 图像帧，显示灰度图，支持单张/连续保存。
- 数据落盘：按类型保存串口、RS422、LVDS、遥测和图像数据。

## 目录结构

```text
.
├── newGroundTestLvdsCameraL_ZGG/        # 主 Qt 工程
│   ├── newGroundTestLvdsCamera.pro      # qmake 工程文件
│   ├── main.cpp / mainwindow.*          # 程序入口与主窗口
│   ├── cardModule/                      # LVDS_T4R6 板卡封装
│   ├── serialPortModule/                # 串口收发模块
│   ├── frameFormat/                     # 通用帧格式、指令、Lua 解析相关模块
│   ├── frameFormatCamera/               # 相机帧、图像、遥测解析模块
│   ├── XML/                             # XML 指令/遥测配置解析
│   ├── GeneralTools/                    # 通用工具
│   ├── UICustom/                        # 自定义 UI 控件
│   ├── ConfigFiles/                     # 运行配置
│   ├── XmlFiles/                        # 指令和遥测 XML 模板
│   └── Driver/DLL/                      # 32/64 位运行依赖 DLL 与导入库
├── LVDS_T4R6_QDemo_0x64/                # 厂商 Qt 示例工程
├── LVDS_T4R6_Deliver/                   # 板卡交付资料、驱动、文档、示例程序
├── Dll_0x86/                            # 32 位 LVDS_T4R6 驱动库
├── winDriver_API_Dll_0x86/              # 32 位 WinDriver API 库
├── winDriver_API_Dll_0x64/              # 64 位 WinDriver API 库
└── build-newGroundTestLvdsCamera-*/     # Qt Creator 生成的构建目录
```

## 开发环境

建议环境：

- Windows 10/11
- Qt 5.13.x
- MinGW 或 MSVC 工具链，位数需与驱动 DLL 一致
- Qt 模块：`core`、`gui`、`widgets`、`serialport`、`opengl`、`qml`、`xml`
- C++11
- LVDS_T4R6 板卡、对应 WinDriver 驱动和运行时 DLL

位数匹配要求：

| 程序位数 | LVDS_T4R6 库 | WinDriver API 库 |
| --- | --- | --- |
| 32 位 | `newGroundTestLvdsCameraL_ZGG/Driver/DLL/Win32/` | `newGroundTestLvdsCameraL_ZGG/Driver/DLL/Win32/` |
| 64 位 | `newGroundTestLvdsCameraL_ZGG/Driver/DLL/Win64/` | `newGroundTestLvdsCameraL_ZGG/Driver/DLL/Win64/` |

不要混用 32 位程序和 64 位 DLL，或 64 位程序和 32 位 DLL。

## 构建方法

### 使用 Qt Creator

1. 打开 `newGroundTestLvdsCameraL_ZGG/newGroundTestLvdsCamera.pro`。
2. 选择与目标 DLL 位数一致的 Kit，例如 MinGW 32-bit 或 MinGW 64-bit。
3. 执行 qmake。
4. 构建并运行。

工程文件会按目标架构自动链接：

- `Driver/DLL/Win32/LVDS_T4R6.lib`
- `Driver/DLL/Win32/wdapi1020.lib`
- `Driver/DLL/Win64/LVDS_T4R6.lib`
- `Driver/DLL/Win64/wdapi1020.lib`

构建时还会复制以下运行文件到输出目录：

- `ConfigFiles/*`
- `XmlFiles/*`
- 对应位数的 `LVDS_T4R6.dll`
- 对应位数的 `wdapi1020.dll`

### 使用命令行

在 Qt 命令行环境中执行：

```powershell
cd newGroundTestLvdsCameraL_ZGG
qmake newGroundTestLvdsCamera.pro
mingw32-make
```

如果使用 MSVC Kit，将 `mingw32-make` 替换为对应的 `nmake` 或 Qt Creator 生成流程。

## 运行前检查

1. 已安装 LVDS_T4R6 板卡驱动。驱动资料位于 `LVDS_T4R6_Deliver/soft/Driver/`。
2. 板卡硬件连接正常，系统设备管理器可识别。
3. 程序输出目录中存在：
   - `LVDS_T4R6.dll`
   - `wdapi1020.dll`
   - `ConfigFiles/`
   - `XmlFiles/`
4. 串口设备号、波特率、校验位等参数与外部设备一致。
5. `XmlFiles/CMD/` 和 `XmlFiles/TM/` 中的指令/遥测模板与当前相机协议匹配。

## 运行输出

程序运行时会在 exe 所在目录下按需创建数据目录：

```text
DataCapture/
├── Serial1/
├── Serial2/
├── RS422/
└── LVDS/

ImageCapture/
├── ImgSingle/
└── ImgSpan/

TMData/
├── Fragment/
└── Auto/
```

其中：

- `DataCapture` 保存串口、RS422 和 LVDS 的文本/二进制数据。
- `ImageCapture/ImgSingle` 保存单次图像，包含 BMP 和可选坐标 CSV。
- `ImageCapture/ImgSpan` 保存连续采集图像。
- `TMData` 保存手动或自动遥测 CSV。

## 配置文件

- `ConfigFiles/config.ini`：主程序基础配置。
- `XmlFiles/CMD/*.xml`：指令模板，启动后加载到“指令发送”页面。
- `XmlFiles/TM/*.xml`：遥测参数模板，用于遥测解析和显示。
- `resources.qrc`：图标、QSS 等 Qt 资源。

修改 XML 后通常需要重新运行程序；如果修改的是工程资源文件，需要重新构建。

## 驱动接口说明

主程序当前通过 `cardModule/LVDSCardHelper` 封装新驱动 `LVDS_T4R6`。主要调用流程为：

```text
LVDS_T4R6_LibInit()
LVDS_T4R6_Open(cardId)
LVDS_T4R6_Set_FrameSize(cardId, frameSize)
LVDS_T4R6_RX_Enable(cardId, 1)
LVDS_T4R6_RX_DataCnt(cardId, &count)
LVDS_T4R6_RX_Data(cardId, buffer, count)
LVDS_T4R6_RX_Enable(cardId, 0)
LVDS_T4R6_Close(cardId)
LVDS_T4R6_LibUninit()
```

注意：当前代码中接收流程已接入新驱动；发送数据接口在 `LVDSCardHelper::sendData()` 中仍标记为待确认，因为当前头文件/文档中只明确了 `LVDS_T4R6_TX_Enable()`，未看到完整发送数据 API。

## 示例工程

`LVDS_T4R6_QDemo_0x64/` 是厂商提供的 Qt 示例工程，可用于验证板卡驱动和基础收发能力。其工程文件为：

```text
LVDS_T4R6_QDemo_0x64/LVDS_T4R6_QDemo_0x64.pro
```

示例程序依赖同目录下的 `LVDS_T4R6.dll` 和 `LVDS_T4R6.lib`。

## 打包发布

可使用 Qt 的 `windeployqt` 收集 Qt 运行时依赖：

```powershell
windeployqt --release --no-compiler-runtime --no-translations path\to\newGroundTestLvdsCamera.exe
```

仓库内的 `newGroundTestLvdsCameraL_ZGG/deploy.bat` 是一个打包脚本模板，使用前需要根据本机路径修改：

- `SRC_DIR`
- `EXE_NAME`
- `DEPLOY_DIR`
- `QT_DEPLOY_TOOL`

发布目录还必须包含对应位数的板卡 DLL、`ConfigFiles/` 和 `XmlFiles/`。

## 常见问题

### 程序提示找不到 DLL

确认 exe 同级目录存在 `LVDS_T4R6.dll` 和 `wdapi1020.dll`，且位数与 exe 一致。

### 初始化失败或检测不到板卡

确认板卡驱动已安装、硬件连接正常，并使用管理员权限或符合驱动要求的权限运行程序。

### 能打开程序但没有数据

检查板卡编号、通道配置、帧大小、XML 协议模板和外部设备是否正在发送数据。

### 图像异常或校验错误

检查图像帧头、帧尾、帧长、校验规则以及当前相机输出格式是否与 `XmlFiles` 和代码中的解析逻辑一致。
