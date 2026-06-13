/**
 * @file      listwidgethelper.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "listwidgethelper.h"
#include "tabitem.h"


ListWidgetHelper::ListWidgetHelper(QObject *parent) : QObject(parent)
{

}

void ListWidgetHelper::addTabItem(QListWidget* listWidget, const QIcon& icon, const QString& text, bool setCurrentToNew) {
    QListWidgetItem* item = new QListWidgetItem(listWidget);   // 为listWidget创建一个新的项目，也就是新的一行
    item->setSizeHint(QSize(listWidget->width(), 50));

    TabItemSub* tabWidget = new TabItemSub(icon, text, listWidget);

    listWidget->setItemWidget(item, tabWidget);
    if(setCurrentToNew) listWidget->setCurrentRow(0);
    else listWidget->setCurrentRow(listWidget->count() - 1); // 选中最新添加的

    item->setData(Qt::UserRole, text);
}

void ListWidgetHelper::addStackedPage(QStackedWidget* stackedWidget, const QString& pageName) {

    QWidget* page = new QWidget(stackedWidget);
    page->setStyleSheet("background-color: white;");

    QLabel* label = new QLabel(pageName, page);
    label->setStyleSheet("font-size: 20px; color: #666;");
    QVBoxLayout* layout = new QVBoxLayout(page);
    layout->addWidget(label, 0, Qt::AlignCenter); // 测试内容居中

    stackedWidget->addWidget(page);
}
