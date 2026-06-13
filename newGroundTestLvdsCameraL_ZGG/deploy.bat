@echo off
chcp 65001 >nul
title Qt一键打包工具

:: ====================== 【只需要修改这4个配置】 ======================
:: 1. 你的Release文件夹路径（编译生成exe的目录）
set SRC_DIR=G:\qt projects\newGroundTestLvdsCameraL_P1\build-newGroundTestLvdsCamera_P1-Desktop_Qt_5_13_0_MinGW_32_bit-Release
:: 2. 你的exe文件名
set EXE_NAME=newGroundTestLvdsCamera_P1.exe
:: 3. 打包输出文件夹（会自动创建，不用手动建）
set DEPLOY_DIR=G:\qt projects\newGroundTestLvdsCameraL_P1\deploy
:: 4. Qt的windeployqt工具路径（MinGW 32位）
set QT_DEPLOY_TOOL=D:\APPs\Qt\qt_5.13.0\5.13.0\mingw73_32\bin\windeployqt.exe
:: =====================================================================

:: 自动创建打包文件夹
if not exist "%DEPLOY_DIR%" mkdir "%DEPLOY_DIR%"

:: 复制最新的exe到打包文件夹
echo 正在复制exe文件...
copy /Y "%SRC_DIR%\%EXE_NAME%" "%DEPLOY_DIR%\" >nul

:: 自动生成Qt依赖库（核心步骤）
echo 正在生成Qt依赖库，请稍候...
"%QT_DEPLOY_TOOL%" --release --no-compiler-runtime --no-translations "%DEPLOY_DIR%\%EXE_NAME%"

:: 打包完成
echo.
echo ====================== 打包完成！ ======================
echo 打包目录：%DEPLOY_DIR%
echo 直接复制deploy文件夹即可发布程序
pause >nul