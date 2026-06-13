/**
 * @file      dialogpara.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "dialogpara.h"
#include "ui_dialogpara.h"
#include "xmlcommandparser.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

DialogPara::DialogPara(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPara)
{
    ui->setupUi(this);

    // 连接按钮信号
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DialogPara::onOkButtonClicked);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DialogPara::on_buttonBox_rejected);
}

DialogPara::~DialogPara()
{
    delete ui;
}

void DialogPara::loadCommand(XMLCommandParser* parser,QList<QDomElement> &docNodeList , int indexCom, int index)
{
    // 清空所有旧页面
    while (ui->stackedWidget_paraList->count() > 0) {
        QWidget *widget = ui->stackedWidget_paraList->widget(0);
        ui->stackedWidget_paraList->removeWidget(widget);
        delete widget;
    }
    if (!parser) return;
    parser->parseCommands3(docNodeList,index,ui->stackedWidget_paraList, indexCom);
}

void DialogPara::onOkButtonClicked()
{

    // 从表格中组装最新参数
    QWidget* currentPage = ui->stackedWidget_paraList->currentWidget();
    QTableWidget* currentTable = qobject_cast<QTableWidget*>(currentPage);
    if (!currentTable) {
       QMessageBox::warning(this, "错误", "当前未显示任何指令表格！");
       return;
    }
    int sourceColumnIdx = -1;
    for (int i = 0; i < currentTable->columnCount(); ++i) {
        QTableWidgetItem* header = currentTable->horizontalHeaderItem(i);
        if (header && header->text().trimmed() == "源码") { // 匹配列标题“源码”
            sourceColumnIdx = i;
            break;
        }
    }

    if (sourceColumnIdx == -1) {
        QMessageBox::warning(this, "错误", "当前表格缺少\"源码\"列！");
        return;
    }
    else {

    }


    QStringList sourceCodes; // 存储有效的源码（大写十六进制）
        int rowCount = currentTable->rowCount();
        qDebug()<<"rowCount"<<rowCount;

        for (int row = 0; row < rowCount; ++row) {
            QTableWidgetItem* sourceItem = currentTable->item(row, sourceColumnIdx);
            if (!sourceItem) continue; // 跳过无源码的行

            QString sourceText = sourceItem->text().trimmed();
            if (sourceText.isEmpty()) continue; // 跳过空值

            bool isHexValid = true;
            for (QChar c : sourceText) {
                if (!c.isDigit() && !((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
                    isHexValid = false;
                    break;
                }
            }
            if (!isHexValid) {
                QMessageBox::warning(this, "警告", QString("第%1行的源码\"%2\"无效（非十六进制），已跳过！").arg(row+1).arg(sourceText));
                continue;
            }

            sourceCodes << sourceText.toUpper(); // 统一转为大写（可选，规范格式）
        }
        qDebug()<<"sourceCodes:"<<sourceCodes;
        // 边界处理：无有效源码
        if (sourceCodes.isEmpty()) {
            QMessageBox::critical(this, "错误", "未收集到任何有效源码，请检查表格！");
            return;
        }

        QString commandSequence = sourceCodes.join("");
        qDebug()<<"commandSequence:"<<commandSequence;

        emit updateParaSignal(commandSequence);

        emit getDocNodeListTempSignal();
}

void DialogPara::on_buttonBox_rejected() { // 连接Cancel按钮
        reject(); // 不发射信号
    }


