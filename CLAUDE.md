# CLAUDE.md

本文件为 Claude Code (claude.ai/code) 在此仓库中工作时提供指导。

## 目录结构

```
c:\Users\hp\Desktop\newQt\
├── CLAUDE.md                                    # 本指导文件
├── newGroundTestLvdsCameraL_ZGG\                # 主项目目录
│   ├── cardModule\                              # LVDS 板卡通信模块（当前使用 LVDS_DLL.dll）
│   ├── serialPortModule\                        # 串口通信模块
│   ├── frameFormatCamera\                       # 相机帧解析模块
│   ├── frameFormat\                             # 通用帧协议模块
│   ├── GeneralTools\                            # 通用工具层
│   ├── UICustom\                                # 自定义 UI 控件
│   ├── XML\                                     # XML 解析模块
│   ├── Driver\DLL\                              # 当前驱动（LVDS_DLL.dll）
│   │   ├── Win32\                               # 32位旧驱动
│   │   └── Win64\                               # 64位旧驱动
│   └── ...
├── LVDS_T4R6_Deliver\                           # 新板卡 SDK 分发包
│   ├── soft\                                    # 软件资源
│   │   ├── Dll_0x64\                            # 64位新驱动 DLL
│   │   │   ├── LVDS_T4R6.dll                    # 新驱动主库（64位）
│   │   │   ├── LVDS_T4R6.h                      # 新驱动头文件
│   │   │   └── LVDS_T4R6.lib                    # 新驱动导入库
│   │   ├── Driver\                              # 驱动安装文件
│   │   ├── app_Release_0x64\                    # 示例应用程序（64位）
│   │   ├── LVDS_T4R6板卡API使用手册.doc         # API 使用文档
│   │   └── WinDriver.v10.20.x64.rar             # WinDriver SDK
│   ├── LVDS_T12R12.pdf                          # 板卡硬件文档
│   └── 测试说明.docx                            # 测试说明
├── Dll_0x86\                                    # 32位新驱动 DLL
│   ├── LVDS_T4R6.dll                            # 新驱动主库（32位）
│   ├── LVDS_T4R6.h                              # 新驱动头文件
│   └── LVDS_T4R6.lib                            # 新驱动导入库
├── winDriver_API_Dll_0x86\                      # WinDriver API 库（32位）
│   ├── wdapi1020.dll                            # Jungo WinDriver API 动态库 v10.20（32位）
│   └── wdapi1020.lib                            # 对应导入库
├── winDriver_API_Dll_0x64\                      # WinDriver API 库（64位）
│   ├── wdapi1020.dll                            # Jungo WinDriver API 动态库 v10.20（64位）
│   └── wdapi1020.lib                            # 对应导入库
└── build-*                                      # 构建输出目录
```

## 项目概述

基于 Qt/C++ 的 LVDS 相机板卡测试桌面应用程序——地面检测主控程序。通过 PCIe LVDS 接口卡和 RS422/串口与相机硬件通信，实现指令发送、遥测接收和图像重建。

## 构建与运行

```bash
# 使用 qmake 构建（Qt 5.13+，MinGW 或 MSVC）
qmake newGroundTestLvdsCamera.pro
make  # 或 mingw32-make / nmake，取决于工具链

# 使用 windeployqt 部署（参见 deploy.bat 配置）
windeployqt --release --no-compiler-runtime --no-translations release/newGroundTestLvdsCamera.exe
```

- **Qt 模块**: core, gui, widgets, serialport, opengl, qml, xml
- **C++ 标准**: C++11
- **配置**: 编辑 `newGroundTestLvdsCamera.pro` 修改工具链路径
- **此仓库中不包含自动化测试**

---

## 驱动说明

### 当前驱动：LVDS_DLL.dll

项目当前使用 `LVDS_DLL.dll`（位于 `newGroundTestLvdsCameraL_ZGG/Driver/DLL/`），这是第三方 PCIe LVDS 接口卡驱动。

**主要接口函数：**
| 函数 | 功能 |
|------|------|
| `LVDS_CountCards()` | 获取板卡数量 |
| `LVDS_Open/Close(cardNo)` | 打开/关闭板卡 |
| `LVDS_Reset(cardNo)` | 复位板卡 |
| `LVDS_Start(cardNo, bool)` | 启动/停止板卡 |
| `LVDS_ClrFIFO(cardNo)` | 清空 FIFO 缓冲 |
| `LVDS_Send(cardNo, channel, data, size, timeout)` | 发送数据 |
| `LVDS_QueryStart/Stop(cardNo)` | 启动/停止查询模式 |
| `LVDS_GetCount(cardNo)` | 获取接收数据计数 |
| `LVDS_ReadData(cardNo, pData, count)` | 读取数据 |
| `LVDS_SetCfg(cardNo, isRecv, channel, cfg)` | 配置通道参数 |
| `LVDS_SetChFrmCfg(cardNo, isRecv, channel, frmCfg)` | 配置帧格式 |

### 新驱动：LVDS_T4R6.dll + WinDriver

新驱动基于 Jungo WinDriver API，提供 32位和 64位两个版本。

**驱动文件位置：**

| 版本 | LVDS_T4R6.dll | wdapi1020.dll |
|------|---------------|---------------|
| **32位** | `Dll_0x86/` | `winDriver_API_Dll_0x86/` |
| **64位** | `LVDS_T4R6_Deliver/soft/Dll_0x64/` | `winDriver_API_Dll_0x64/` |

**WinDriver API 说明：**
| 文件 | 说明 |
|------|------|
| `wdapi1020.dll` | Jungo WinDriver v10.20 API 动态库，用于开发 PCI/PCIe 设备驱动 |
| `wdapi1020.lib` | 对应的静态导入库 |

**新驱动主要接口函数：**
| 函数 | 功能 |
|------|------|
| `LVDS_T4R6_LibInit()` | 初始化驱动库 |
| `LVDS_T4R6_LibUninit()` | 卸载驱动库 |
| `LVDS_T4R6_Open(UINT8 cardId)` | 打开板卡 |
| `LVDS_T4R6_Close(UINT8 cardId)` | 关闭板卡 |
| `LVDS_T4R6_REST(UINT8 cardId)` | 复位板卡 |
| `LVDS_T4R6_Set_FrameSize(UINT8 cardId, UINT32 size)` | 设置帧大小 |
| `LVDS_T4R6_RX_Enable(UINT8 cardId, UINT8 enable)` | 接收使能（0:关闭 1:开启） |
| `LVDS_T4R6_RX_DataCnt(UINT8 cardId, UINT32* cnt)` | 获取接收数据计数 |
| `LVDS_T4R6_RX_Data(UINT8 cardId, UINT8* data, UINT32 cnt)` | 读取接收数据 |
| `LVDS_T4R6_TX_Enable(UINT8 cardId, UINT8 channel, UINT8 enable)` | 发送使能 |

---

## LVDS_T4R6.dll 和 wdapi1020.dll 的关系

### 调用层次

```
你的程序 (newGroundTestLvdsCamera.exe)
    │
    │ 调用 LVDS_T4R6_Open(), LVDS_T4R6_RX_Data()...
    ▼
LVDS_T4R6.dll（板卡厂商开发）
    │
    │ 内部调用 WDC_xxx() 函数
    ▼
wdapi1020.dll（Jungo 公司开发）
    │
    │ 访问 PCI/PCIe 硬件
    ▼
PCIe LVDS 板卡硬件
```

### 类比理解

| 组件 | 类比 | 说明 |
|------|------|------|
| wdapi1020.dll | 发动机 | 通用的硬件访问能力，Jungo 提供 |
| LVDS_T4R6.dll | 整车 | 板卡特定功能，厂商开发 |
| 你的程序 | 驾驶员 | 只需调用 LVDS_T4R6.dll 的接口 |

### 版本匹配要求

```
32位程序 必须使用：
├── LVDS_T4R6.dll (32位)     ← Dll_0x86/
└── wdapi1020.dll (32位)     ← winDriver_API_Dll_0x86/

64位程序 必须使用：
├── LVDS_T4R6.dll (64位)     ← LVDS_T4R6_Deliver/soft/Dll_0x64/
└── wdapi1020.dll (64位)     ← winDriver_API_Dll_0x64/

❌ 不能混用！版本必须一致。
```

---

## 更换板卡驱动指南

### 概述

将项目中的板卡驱动从 `LVDS_DLL.dll` 更换为 `LVDS_T4R6.dll`（基于 WinDriver API）。

**现在支持两种编译目标：**
- 32位程序：使用 `Dll_0x86/` 和 `winDriver_API_Dll_0x86/`
- 64位程序：使用 `Dll_0x64/` 和 `winDriver_API_Dll_0x64/`

### 需要修改的文件

| 文件 | 修改内容 |
|------|----------|
| `cardModule/lvdscardhelper.h` | 更换头文件引用、修改数据结构 |
| `cardModule/lvdscardhelper.cpp` | 重写所有底层驱动调用 |
| `newGroundTestLvdsCamera.pro` | 更新库链接配置 |

### 详细修改步骤

#### 步骤 1：复制新驱动文件到项目目录

**32位版本：**
```
Dll_0x86/LVDS_T4R6.dll        → Driver/DLL/Win32/
Dll_0x86/LVDS_T4R6.h          → Driver/DLL/Win32/
Dll_0x86/LVDS_T4R6.lib        → Driver/DLL/Win32/
winDriver_API_Dll_0x86/wdapi1020.dll → Driver/DLL/Win32/
```

**64位版本：**
```
LVDS_T4R6_Deliver/soft/Dll_0x64/LVDS_T4R6.dll  → Driver/DLL/Win64/
LVDS_T4R6_Deliver/soft/Dll_0x64/LVDS_T4R6.h    → Driver/DLL/Win64/
LVDS_T4R6_Deliver/soft/Dll_0x64/LVDS_T4R6.lib  → Driver/DLL/Win64/
winDriver_API_Dll_0x64/wdapi1020.dll           → Driver/DLL/Win64/
```

#### 步骤 2：修改 `lvdscardhelper.h`

```cpp
// 原代码
#include "LVDS_DLL.h"

// 改为新驱动头文件
#include "LVDS_T4R6.h"
```

**需要重新定义的数据结构：**

| 原结构体 | 说明 | 新驱动对应 |
|----------|------|-----------|
| `ST_LVDS_DATA` | 接收数据结构（含通道号、长度、缓冲区） | 新驱动使用 `LVDS_T4R6_RX_Data` 直接读取 |
| `ST_LVDS_CFG` | 通道配置（波特率/数据位/停止位/校验） | 新驱动可能不支持，需确认 |
| `ST_LVDS_FRM_CFG` | 帧配置（帧头/帧尾/帧长） | 使用 `LVDS_T4R6_Set_FrameSize` |

#### 步骤 3：修改 `lvdscardhelper.cpp` — 核心工作

**函数映射表：**

| 原函数 | 原 LVDS_DLL 调用 | 新驱动调用 |
|--------|-----------------|-----------|
| `getLVDSCardsCount()` | `LVDS_CountCards()` | 新驱动无此函数，需手动管理或默认返回 1 |
| `OpenLVDSCard()` | `LVDS_Open(cardNo)` | `LVDS_T4R6_Open(cardId)` |
| `CloseLVDSCard()` | `LVDS_Close(cardNo)` | `LVDS_T4R6_Close(cardId)` |
| `ResetLVDSCard()` | `LVDS_Reset(cardNo)` | `LVDS_T4R6_REST(cardId)` |
| `ClearLVDSCardBuff()` | `LVDS_ClrFIFO(cardNo)` | 新驱动无此函数，可能不需要 |
| `StartLVDSCard()` | `LVDS_Start(cardNo, bool)` | `LVDS_T4R6_RX_Enable(cardId, enable)` |
| `getLVDSCardOpenStatus()` | `LVDS_IsOpen(cardNo)` | 需自行维护状态变量 |
| `configCardChannel()` | `LVDS_SetCfg(...)` | 新驱动可能不支持，需确认 |
| `configLVDSCardFrame()` | `LVDS_SetChFrmCfg(...)` | `LVDS_T4R6_Set_FrameSize(cardId, size)` |
| `sendData()` | `LVDS_Send(...)` | 需确认新驱动的发送接口 |
| `recieveStart()` | `LVDS_QueryStart/GetCount/ReadData` | `LVDS_T4R6_RX_Enable` + `LVDS_T4R6_RX_DataCnt` + `LVDS_T4R6_RX_Data` |

**示例代码改造：**

```cpp
// 原代码（OpenLVDSCard）
bool LVDSCardHelper::OpenLVDSCard()
{
    if(!LVDS_IsOpen(currentCardNo))
    {
        isOpenCard = LVDS_Open(currentCardNo);
    }
    return isOpenCard;
}

// 新代码
bool LVDSCardHelper::OpenLVDSCard()
{
    // 新驱动需要先初始化库
    LVDS_T4R6_LibInit();
    isOpenCard = LVDS_T4R6_Open(currentCardNo);
    return isOpenCard;
}
```

```cpp
// 原代码（recieveStart 中的数据接收）
dwSTCnt = LVDS_GetCount(currentCardNo);
if (dwSTCnt > 0)
{
    DWORD dwRetCnt = LVDS_ReadData(currentCardNo, pstInfo, dwSTCnt);
    // ...
}

// 新代码
UINT32 dataCnt = 0;
LVDS_T4R6_RX_DataCnt(currentCardNo, &dataCnt);
if (dataCnt > 0)
{
    UINT8* buffer = new UINT8[dataCnt];
    LVDS_T4R6_RX_Data(currentCardNo, buffer, dataCnt);
    // 处理数据...
    delete[] buffer;
}
```

#### 步骤 4：修改 `newGroundTestLvdsCamera.pro`

```qmake
# 原配置
win32 {
    contains(QMAKE_TARGET.arch, x86_64) {
        LIBS += -L$$PWD/Driver/DLL/Win64 -lLVDS_DLL
        INCLUDEPATH += $$PWD/Driver/DLL/Win64
    } else {
        LIBS += -L$$PWD/Driver/DLL/Win32 -lLVDS_DLL
        INCLUDEPATH += $$PWD/Driver/DLL/Win32
    }
}

# 改为新驱动（支持32位和64位）
win32 {
    contains(QMAKE_TARGET.arch, x86_64) {
        # 64位配置
        LIBS += -L$$PWD/Driver/DLL/Win64 -lLVDS_T4R6
        LIBS += -L$$PWD/Driver/DLL/Win64 -lwdapi1020
        INCLUDEPATH += $$PWD/Driver/DLL/Win64
    } else {
        # 32位配置
        LIBS += -L$$PWD/Driver/DLL/Win32 -lLVDS_T4R6
        LIBS += -L$$PWD/Driver/DLL/Win32 -lwdapi1020
        INCLUDEPATH += $$PWD/Driver/DLL/Win32
    }
}
```

#### 步骤 5：部署运行时依赖

**32位程序：**
| DLL 文件 | 来源路径 |
|----------|----------|
| `LVDS_T4R6.dll` | `Dll_0x86/` |
| `wdapi1020.dll` | `winDriver_API_Dll_0x86/` |

**64位程序：**
| DLL 文件 | 来源路径 |
|----------|----------|
| `LVDS_T4R6.dll` | `LVDS_T4R6_Deliver/soft/Dll_0x64/` |
| `wdapi1020.dll` | `winDriver_API_Dll_0x64/` |

### 关键差异需注意

| 差异点 | 旧驱动 LVDS_DLL | 新驱动 LVDS_T4R6 |
|--------|----------------|-----------------|
| 库初始化 | 无需 | 需要 `LVDS_T4R6_LibInit()` |
| 板卡计数 | `LVDS_CountCards()` | 无此接口，需手动管理 |
| 打开状态查询 | `LVDS_IsOpen()` | 无此接口，需自行维护状态变量 |
| 通道配置 | `LVDS_SetCfg()` 支持波特率等 | 可能不支持，需确认文档 |
| 帧格式配置 | 支持帧头/帧尾/帧长/帧间隔 | 仅支持 `Set_FrameSize` |
| 数据结构 | 返回 `ST_LVDS_DATA` 结构数组 | 直接返回字节数组 |
| 多通道 | 支持 32 通道 | 需确认 |

### 建议的实施步骤

1. **阅读新驱动文档** — 查看 `LVDS_T4R6_Deliver/soft/LVDS_T4R6板卡API使用手册.doc`
2. **复制新驱动文件** — 将驱动文件整理到项目 `Driver/DLL/` 目录
3. **创建驱动适配层** — 在 `lvdscardhelper` 中封装新驱动接口
4. **逐个函数替换** — 从 `Open/Close/Reset` 等简单函数开始
5. **实现数据接收** — 改造 `recieveStart()` 函数
6. **测试验证** — 确保基本通信功能正常

---

## 架构

### UI 层（MainWindow + UICustom）

- **MainWindow**: 主窗口，通过 `QListWidget` + `QStackedWidget` 实现 4 标签页导航：
  1. 接口设置 — 串口和 LVDS 板卡配置
  2. 指令发送 — 指令组合和发送
  3. 遥测显示 — 实时遥测参数监控
  4. 图像显示 — 重建的相机图像显示
- **UICustom/** — 自定义 `QGraphicsView` 子类，支持图像缩放和平移、标签项控件、列表辅助

### 硬件通信层

- **cardModule/** — 封装板卡驱动。`lvdsCardWorker` 在 `QThread` 上运行以实现并发板卡 I/O，分别处理 RS422 和 LVDS 数据通路
- **serialPortModule/** — 管理两个独立串口（Serial1：3Mbps 质心遥测，Serial2：115200 温度遥测），各自运行在独立的 `QThread` 上

### 数据处理层

- **frameFormatCamera/** — 帧分析和图像重建：
  - `DataAnalysisHelper`：从环形缓冲区解析原始字节流，提取图像帧、质心帧、温度帧。运行在专用 `QThread` 实例上
  - `FrameHelper`：帧头/帧尾检测，校验和验证
- **frameFormat/** — 通用帧组装工具、Lua 5.4.2 脚本集成、参数设置界面、遥测 XML 解析
- **GeneralTools/** — `DataTransfer`（字节/十六进制转换）、`RingBuffer`（线程安全环形缓冲区——I/O 线程和分析线程之间的主要 IPC 机制）

### XML 配置

- **XML/** — `XMLCommandParser`：从 XML 文件加载指令定义和遥测参数
- **XmlFiles/CMD/** — 相机指令 XML 定义（可见光和红外）
- **XmlFiles/TM/** — 遥测参数定义
- **ConfigFiles/** — `config.ini`，配置遥测 XML 文件名

### 数据流

```
LVDS 板卡 / 串口硬件
    ↕ （驱动/DLL）
lvdsCardWorker / SerialPortWorker （工作线程）
    ↕ （RingBuffer - 线程安全 IPC）
DataAnalysisHelper （分析线程）
    ↕ （Qt 信号/槽，跨线程队列连接）
MainWindow UI 更新
```

- 原始数据从硬件流入 → 工作线程推入 `RingBuffer` → 分析线程弹出并解析 → 发射结构化结果信号 → MainWindow 更新 UI
- 每条数据通路（Serial1、Serial2、RS422、LVDS）拥有独立的环形缓冲区和分析线程

### 关键结构体（Structs.h）

- `ImageAttributes` — 图像帧统计信息和元数据
- `CentroidFrameAttributes` — 质心帧，包含质心坐标、灰度值、SEL/FPGA/TEC 遥测
- `TemperatureFrameAttributes` — TEC 和 FPGA 温度
- `Command`、`CommandAttribute`、`CommandInfo` — 来自 XML 定义的指令/参数结构
- `TMitemQueue`、`TMparaQueue` — 遥测参数解析结构

---

## 学习路径

按此顺序逐步阅读源码，从宏观到微观，沿数据流方向推进：

### 第1步：项目概览和数据结构
- 先读本 CLAUDE.md 的**架构**和**驱动说明**章节，建立全局认知
- 然后读 `Structs.h` — 这是项目的"通用语言"，所有模块都基于这些结构体通信

### 第2步：入口和主窗口
- 读 `main.cpp` — 看到所有 `qRegisterMetaType` 调用，你就知道项目有哪些跨线程传递的数据类型
- 读 `mainwindow.h` — 看成员变量和信号声明，了解主窗口"拥有"哪些组件

### 第3步：沿数据流走（从硬件到UI）

**串口通路（最简单的起点）：**
1. `serialportworker.cpp` — 串口收到原始字节 → 推入 RingBuffer
2. `dataanalysishelper.cpp` — 分析线程从 RingBuffer 取出 → 解析成结构化数据 → 发射 Qt 信号
3. `mainwindow.cpp` — 接收信号 → 更新 UI 表格/标签

**LVDS/RS422 板卡通路：**
1. `lvdscardhelper.cpp` — 调用驱动 DLL 的 C 接口收发数据
2. `lvdscardworker.cpp` — 工作线程管理，数据推入 RingBuffer
3. `dataanalysishelper.cpp` — 同上

### 第4步：深入指令系统
- `xmlcommandparser.cpp` — 从 XML 解析指令定义和遥测参数
- `command.cpp` — 构建指令、计算编码、执行发送
- `frameassemble.cpp` — 协议层打包：RS422 定长/变长指令组装、LVDS 分包、校验和计算

### 第5步：辅助工具
- `ringbuffer.cpp` — 线程安全环形缓冲区实现
- `luahelper.cpp` — Lua 5.4.2 嵌入式脚本引擎
- `savedatahelper.cpp` — 原始数据、遥测、图像的日志和文件保存
