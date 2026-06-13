/**
 * @file      xmlcommandparser.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */


#include "xmlcommandparser.h"
#include <QDebug>
#include <QHeaderView>
#include <QComboBox>
#include <cmath>
#include <QJSEngine>


XMLCommandParser::XMLCommandParser(QObject *parent) : QObject(parent) {

    listWidgetHelper = new ListWidgetHelper(this);

}

bool XMLCommandParser::loadXML(const QString &filePath, QList<QDomElement> &docNodeInitList)
{
    /// 准备xml文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "无法打开XML文件:" << filePath;
        return false;
    }

    /// 准备xml文档对象（容器）
    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qWarning() << "XML 解析失败";
        file.close();
        return false;
    }
    file.close();

    /// 元素节点，最常用
    QDomElement root = doc.documentElement();
    if (root.tagName() != "SYSTEM") {
        qWarning() << "XML根标签不是<SYSTEM>";
        return false;
    }
    parseCommands(root, docNodeInitList);
    return true;
}

void XMLCommandParser::parseCommands(const QDomElement &root, QList<QDomElement> &docNodeInitList) /// 注意，这里必须使用引用传递，否则，只是对拷贝的对象进行操作
{

    QDomNodeList commandNodes = root.elementsByTagName("Command");
    for (int i = 0; i < commandNodes.count(); ++i) {

        /// 任何节点的基类
        QDomNode node = commandNodes.at(i);

        if (node.isElement()) {
            QDomElement element = node.toElement();

            docNodeInitList.append(element);
            qDebug()<<"docNodeInitList.count()"<<docNodeInitList.count();
            // 打印该元素的所有属性
            QDomNamedNodeMap attributes = element.attributes();
            for (int j = 0; j < attributes.count(); ++j) {
                QDomNode attr = attributes.item(j);
                qDebug() << "   Attribute:" << attr.nodeName() << "=" << attr.nodeValue();
            }
        }
    }

    for (int i = 0; i < commandNodes.count(); ++i) {

        QDomElement commandElem = commandNodes.at(i).toElement();
        Command cmd;
        cmd.name = commandElem.attribute("CommandSpecificationT", QString("Command %1").arg(i));
        cmd.Index = commandElem.attribute("CommandSeqIdxD", QString::number(i)).toInt();
        cmd.header = commandElem.attribute("FrameHeader", QString::number(i));
        cmd.tail = commandElem.attribute("FrameTail", QString::number(i));
        cmd.checkSumLength = commandElem.attribute("CheckSumLength", QString::number(i)).toInt();

        emit updateUiCurComShowSignal(cmd.name);

        QDomNodeList attrNodes = commandElem.elementsByTagName("CommandPara");
        for (int j = 0; j < attrNodes.count(); ++j) {
            QDomElement attrElem = attrNodes.at(j).toElement();
            CommandAttribute attr;
            attr.paraNo = attrElem.attribute("CommandParaSeqIdxD"); // 参数编号
            attr.paraName = attrElem.attribute("CommandParaSpecificationT"); // 参数名称
            attr.paraType = attrElem.attribute("CommandParamTypeT"); // 参数类别
            attr.byteNotes = attrElem.attribute("AttributeByteLenD");// 备注
            attr.initIndex = attrElem.attribute("CommandParaInitSelectD").toInt(); // 转为整数; // 默认索引

            // 查找 <Para> 子项
            QDomNodeList paraNodes = attrElem.elementsByTagName("Para");
            for (int k = 0; k < paraNodes.count(); ++k) {
                QDomElement paraElem = paraNodes.at(k).toElement();
                QString option = paraElem.attribute("ParaSpecificationT");
                QString code = paraElem.attribute("ParaRawCodeH");
                QString intCode = paraElem.attribute("ParaInitCode");

                if (!option.isEmpty())
                    attr.paraOptions << option;
                if (!code.isEmpty())
                    attr.hexCodes << code;

                if (k == 0) {
                    // 默认值来自第一个选项
                    attr.paraValue = option;
                    attr.byteHex = code;
                    attr.paraIntCode = intCode;
                }
            }

            // 新增字段解析
             attr.encodeRule = attrElem.attribute("CommandParaEncodeTypeT");
             attr.byteLength = attrElem.attribute("CommandParaByteLengthD").toInt();
             attr.minValue = attrElem.attribute("CommandParaMinF");
             attr.maxValue = attrElem.attribute("CommandParaMaxF");

            cmd.attributes.append(attr);
        }
        commandList.append(cmd);
    }

}



QTableWidget* XMLCommandParser::createTableForCommand(const Command &cmd, QList<QDomElement> &docNodeInitListUi, int index)
{
    QTableWidget *table = new QTableWidget(cmd.attributes.size(), 5);
    table->setHorizontalHeaderLabels({"参数编号", "参数名称", "参数数值", "源码", "备注"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setVisible(false);

    for (int i = 0; i < cmd.attributes.size(); ++i) {
        const CommandAttribute &attr = cmd.attributes.at(i);

        table->setItem(i, 0, new QTableWidgetItem(attr.paraNo));
        table->setItem(i, 1, new QTableWidgetItem(attr.paraName));

        if (attr.paraType == "COMBOX") {
            QComboBox *combo = new QComboBox(table);
            combo->addItems(attr.paraOptions);
            combo->setCurrentText(attr.paraValue);
            combo->setCurrentIndex(attr.initIndex);

            QTableWidgetItem* item = new QTableWidgetItem(attr.hexCodes[attr.initIndex]);
            table->setItem(i, 3, item);
            table->setCellWidget(i, 2, combo);
            combo->setMinimumWidth(table->columnWidth(2));
            connect(combo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                    this,
                    [this, &docNodeInitListUi, seqIndex=index, table, i, cmd](int comboIndex)
            {
                const CommandAttribute &attr = cmd.attributes.at(i);
                // 确保索引有效
                if (comboIndex >= 0 && comboIndex < attr.hexCodes.size()) {
                    QTableWidgetItem* item = new QTableWidgetItem(attr.hexCodes[comboIndex]);
                    table->setItem(i, 3, item);

                    int curIndexCom = seqIndex;


                    QDomElement elem = docNodeInitListUi.at(curIndexCom);
                    if (seqIndex < 0 || seqIndex >= docNodeInitListUi.size())
                        return;
                    QDomNodeList commandParaList = elem.elementsByTagName("CommandPara");
                    QDomElement elemCommandPara = commandParaList.at(i).toElement();
                    elemCommandPara.setAttribute("CommandParaInitSelectD", comboIndex);
                }
            });
        }


        else if (attr.paraType == "EDIT") {
            QTableWidgetItem *item = new QTableWidgetItem(attr.paraIntCode);
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            table->setItem(i, 2, item);

            QVariantMap editData;
            editData["encodeRule"] = attr.encodeRule;
            editData["byteLength"] = attr.byteLength;
            item->setData(Qt::UserRole, editData);
        }
        else {

            table->setItem(i, 2, new QTableWidgetItem(attr.paraValue));
        }

        table->setItem(i, 3, new QTableWidgetItem(attr.hexCodes[attr.initIndex]));
        table->setItem(i, 4, new QTableWidgetItem(attr.byteNotes));
    }


    connect(table, &QTableWidget::itemChanged, [=](QTableWidgetItem *item) {
        if (item->column() != 2) return; // 只处理参数数值列（第2列）

        QVariant data = item->data(Qt::UserRole);
        if (!data.isValid()) return; // 非EDIT类型跳过

        QVariantMap editData = data.toMap();
        QString encodeRule = editData["encodeRule"].toString(); // 使用编码规则编码
        int byteLength = editData["byteLength"].toInt();


        QString hexCode = calculateHex(item->text(), encodeRule, byteLength);


        int row = item->row();
        table->blockSignals(true); // 避免递归触发
        table->item(row, 3)->setText(hexCode);
        table->blockSignals(false);


        int curIndexCom = index;

        QDomElement elem = docNodeInitListUi.at(curIndexCom);
        QDomNodeList commandParaList = elem.elementsByTagName("CommandPara");
        QDomElement elemCommandPara = commandParaList.at(item->row()).toElement();
        QDomNodeList paraList = elemCommandPara.elementsByTagName("Para");
        QDomElement elemPara = paraList.at(0).toElement();
        elemPara.setAttribute("ParaInitCode", item->text());
        elemPara.setAttribute("ParaRawCodeH", hexCode);
    });

    table->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    return table;
}


void XMLCommandParser::populateStackedWidget(QStackedWidget *stackWidget, QListWidget *listWidget, bool setCurrentToNew, QList<QDomElement> &docNodeInitListUi, int rowCom)
{


    listWidget->clear();

    // 清空所有旧页面
    while (stackWidget->count() > 0) {
        QWidget *widget = stackWidget->widget(0);
        stackWidget->removeWidget(widget);
        delete widget; // 更高效
    }


    for (const Command &cmd : commandList) {
        qDebug() << "cmd.name = " << cmd.name;
        QTableWidget *table = createTableForCommand(cmd, docNodeInitListUi, rowCom);
        stackWidget->addWidget(table);  // 不再使用 addTab，而是 addWidget
        QIcon iconTabSub(":/Icon/3592866-attach-attachment-clip-clipping-general-office-paperclip_107732.png");
        listWidgetHelper->addTabItem(listWidget,iconTabSub,cmd.name,setCurrentToNew);
    }
    qDebug()<<"stackWidget->count()"<<stackWidget->count();
}

QString XMLCommandParser::calculateHex(const QString& input, const QString& rule, int byteLength) {
    bool ok;
    double value = input.toDouble(&ok);
    if (!ok) return "Invalid";

    QJSEngine engine;
    engine.globalObject().setProperty("x", value);
    QJSValue result = engine.evaluate(rule);
    if (result.isError()) {
        return QString("EvalError: ") + result.toString();
    }

    quint64 rawValue = static_cast<quint64>(std::llround(result.toNumber()));
    if (byteLength > 0) {
        quint64 mask = (byteLength >= 8)
            ? 0xFFFFFFFFFFFFFFFFULL
            : ((1ULL << (byteLength * 8)) - 1);
        rawValue &= mask;
    }

    QString hex = QString::number(rawValue, 16).toUpper();

    if (byteLength > 0) {
        int totalChars = byteLength * 2;
        hex = hex.rightJustified(totalChars, '0');
    }
    return hex;
}

void XMLCommandParser::deleteComChoose(int delIndex)
{
    commandList.removeAt(delIndex);
}

///*********************************加载指令序列xml文件*************************************

bool XMLCommandParser::loadXML2(const QString &filePath,QList<QDomElement> &docNodeList)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "无法打开XML文件:" << filePath;
        return false;
    }

    doc.clear();
    if (!doc.setContent(&file)) {
        qWarning() << "XML 解析失败";
        file.close();
        return false;
    }
    file.close();

    /// 元素节点，最常用
    QDomElement root = doc.documentElement();// 拿到根元素 System
    if (root.tagName() != "SYSTEM") {
        qWarning() << "XML根标签不是<SYSTEM>";
        return false;
    }

    parseCommands2(root,docNodeList);
    return true;
}

void XMLCommandParser::parseCommands2(const QDomElement &root, QList<QDomElement> &docNodeList)
{
    docNodeList.clear();
    commandQueueVector.clear();
    /// 节点列表
    QDomNodeList nodeList_Command = root.elementsByTagName("Command");

    qDebug()<<"Command 数量"<<nodeList_Command.count();
    for (int i = 0; i < nodeList_Command.count(); ++i) {

        /// 任何节点的基类
        QDomElement element_Command = nodeList_Command.at(i).toElement();

        docNodeList.append(element_Command.cloneNode(true).toElement());
        // 开始读取我所需要的信息填入指令序列
        QString commandTime = element_Command.attribute("CommandTimeD");
        QString commandName = element_Command.attribute("CommandSpecificationT");
        QString commandCodeH = element_Command.attribute("CommandCodeH");
        QString commandRemarksH = element_Command.attribute("RemarksD");

        CommandQueue queue;
        queue.commandTime = commandTime;
        queue.commandName = commandName;
        queue.commandCodeH = commandCodeH;
        queue.commandRemarks = commandRemarksH;


        QDomNodeList nodeList_CommandPara = element_Command.elementsByTagName("CommandPara");
        QString commandCode;
        qDebug()<<"CommandPara 数量"<<nodeList_CommandPara.count();
        for (int j = 0; j < nodeList_CommandPara.count();++j) {
            QDomElement element_CommandPara = nodeList_CommandPara.at(j).toElement();
            int initIndex = element_CommandPara.attribute("CommandParaInitSelectD").toInt();
//            qDebug()<<"initIndex:"<<initIndex;

            QDomNodeList nodeList_Para = element_CommandPara.elementsByTagName("Para");
//            QDomElement element_Para = nodeList_Para.at(i).toElement();
            QVector<QString> paraCodeList;
            qDebug()<<"nodeList_Para 数量"<<nodeList_Para.count();
            for (int k = 0; k < nodeList_Para.count();++k) {
                QDomElement element_Para = nodeList_Para.at(k).toElement();
                QString ParaRawCodeH = element_Para.attribute("ParaRawCodeH");
                qDebug()<<"ParaRawCodeH :"<<ParaRawCodeH;
                paraCodeList.append(ParaRawCodeH);
            }
            commandCode+=paraCodeList.at(initIndex);
        }
        queue.commandCode = commandCode;
        commandQueueVector.append(queue);
    }

    emit updateParaListSignal(commandQueueVector);
    qDebug()<<"信号已发送";
    qDebug()<<"docNodeList.count()"<<docNodeList.count();

}

void XMLCommandParser::parseCommands3(QList<QDomElement> &docNodeList, int index, QStackedWidget *stackedWidget, int indexCom)
{
    qDebug() << "PARSE";
    QDomElement commandElem = docNodeList.at(index).toElement();
    Command cmd;
    cmd.name = commandElem.attribute("CommandSpecificationT", QString("Command %1").arg(index));
    cmd.Index = commandElem.attribute("CommandSeqIdxD", QString::number(index)).toInt();
    emit updateSubUiCurComShowSignal(cmd.name);
    QDomNodeList attrNodes = commandElem.elementsByTagName("CommandPara");
    for (int j = 0; j < attrNodes.count(); ++j) {
        QDomElement attrElem = attrNodes.at(j).toElement();
        CommandAttribute attr;
        attr.paraNo = attrElem.attribute("CommandParaSeqIdxD"); // 参数编号
        attr.paraName = attrElem.attribute("CommandParaSpecificationT"); // 参数名称
        attr.paraType = attrElem.attribute("CommandParamTypeT"); // 参数类别
        attr.byteNotes = attrElem.attribute("AttributeByteLenD");// 备注
        attr.initIndex = attrElem.attribute("CommandParaInitSelectD").toInt(); // 转为整数; // 默认索引

        // 查找 <Para> 子项
        QDomNodeList paraNodes = attrElem.elementsByTagName("Para");
        for (int k = 0; k < paraNodes.count(); ++k) {
            QDomElement paraElem = paraNodes.at(k).toElement();
            QString option = paraElem.attribute("ParaSpecificationT");
            QString code = paraElem.attribute("ParaRawCodeH");
            QString intCode = paraElem.attribute("ParaInitCode");

            if (!option.isEmpty())
                attr.paraOptions << option; // combobox对应的选项
            if (!code.isEmpty())
                attr.hexCodes << code; // combobox对应的源码

            if (k == 0) {
                // 默认值来自第一个选项
                attr.paraValue = option;
                attr.byteHex = code;
                attr.paraIntCode = intCode;
            }
        }

        // 新增字段解析
         attr.encodeRule = attrElem.attribute("CommandParaEncodeTypeT");
         attr.byteLength = attrElem.attribute("CommandParaByteLengthD").toInt(); // 转为整数
         attr.minValue = attrElem.attribute("CommandParaMinF");
         attr.maxValue = attrElem.attribute("CommandParaMaxF");

        cmd.attributes.append(attr);
    }


    QTableWidget *table = createTableForCommand(cmd, docNodeListTemp, index);
    stackedWidget->addWidget(table);
    stackedWidget->setCurrentWidget(table);
}

QList<QDomElement> XMLCommandParser::getDocNodeListTemp()
{
    return docNodeListTemp;
}


/// 遥测XML文件读取及表格创建
bool XMLCommandParser::loadTmXML(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "无法打开XML文件:" << filePath;
        return false;
    }

    /// 整个XML文档对象
    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qWarning() << "XML 解析失败";
        file.close();
        return false;
    }
    file.close();

    /// 元素节点，最常用
    QDomElement root = doc.documentElement();// 拿到根元素 System
    if (root.tagName() != "SYSTEM") {
        qWarning() << "XML根标签不是<SYSTEM>";
        return false;
    }

    parseTMs(root);
    return true;
}

/// 遥测XML文件读取及表格创建
bool XMLCommandParser::loadTmXML_slow(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "无法打开XML文件:" << filePath;
        return false;
    }

    /// 整个XML文档对象
    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qWarning() << "XML 解析失败";
        file.close();
        return false;
    }
    file.close();

    /// 元素节点，最常用
    QDomElement root = doc.documentElement();
    if (root.tagName() != "SYSTEM") {
        qWarning() << "XML根标签不是<SYSTEM>";
        return false;
    }

    parseTMs_slow(root);
    return true;
}

bool XMLCommandParser::parseTMs(QDomElement root){

//    int frameLength = 0;
    QDomNodeList nodeList_TM = root.elementsByTagName("TM");
    for (int i = 0; i < nodeList_TM.size(); ++i) {
        QDomElement elemTM = nodeList_TM.at(i).toElement();
//        frameLength = elemTM.attribute("FrameLength").toInt();
        frameTmXML.frameLength = elemTM.attribute("FrameLength").toInt();
        frameTmXML.frameHead = elemTM.attribute("FrameHeader");
        frameTmXML.frameTail = elemTM.attribute("FrameTail");
        frameTmXML.checkSumNum = elemTM.attribute("CheckSumLength").toInt();

        frameTmXML.frameLengthAll = elemTM.attribute("FrameLengthAll").toInt();
        frameTmXML.frameHeadAll = elemTM.attribute("FrameHeaderAll");
        frameTmXML.CutFront = elemTM.attribute("CutFront");

    }
    qDebug()<<"FrameLength"<<frameTmXML.frameLength; // 127
    emit updateFrameTMSignal(frameTmXML);

    /// 节点列表
    QDomNodeList nodeList_TMitem = root.elementsByTagName("TMitem"); /// 1_TMitem：element——>list
    int TMitemCount = nodeList_TMitem.count();
    qDebug()<<"TMitem 数量"<<TMitemCount;

    for (int i = 0; i < nodeList_TMitem.count(); ++i) {

        /// 任何节点的基类
        QDomElement element_TMitem = nodeList_TMitem.at(i).toElement(); /// 1_TMitem：list——>element

        // 开始读取我所需要的信息填入指令序列
        QString TMitemLength = element_TMitem.attribute("TMitemByteLengthD");
        QString TMitemNo = element_TMitem.attribute("TMitemNoName");
        QString TMitemName = element_TMitem.attribute("TMitemSpecificationT");
        QString ParaType = element_TMitem.attribute("TMitemType");
        QString EncodeType = element_TMitem.attribute("TMitemEncodeTypeT");
        QString Para = element_TMitem.attribute("TMitemNoName");
        QString TMitemRemarks = element_TMitem.attribute("TMitemNote");
        QString TMitemMinF = element_TMitem.attribute("TMitemMinF");
        QString TMitemMaxF = element_TMitem.attribute("TMitemMaxF");
        QString ByteInherit = element_TMitem.attribute("ByteInherit");
        QString BitOffset = element_TMitem.attribute("BitOffset");
        QString BitLength = element_TMitem.attribute("BitLength");
        QString TMsignedType = element_TMitem.attribute("TMsignedType");

        TMitemQueue queue;
        queue. TMitemLength = TMitemLength; // 遥测参数源码长度
        queue. TMitemNo = TMitemNo; // 遥测参数编号
        queue. TMitemName = TMitemName ; // 遥测参数名称
        queue. ParaType = ParaType; // 遥测参数类型
        queue. EncodeType = EncodeType; // 遥测参数解码规则（从十六位源码到十进制数值）
//        queue. Para = Para; // 遥测参数数值
        queue. TMitemRemarks  = TMitemRemarks; // 备注
        queue. TMitemMinF  = TMitemMinF; // 备注// 最小值
        queue. TMitemMaxF  = TMitemMaxF; // 备注// 最大值
        queue. ByteInherit  = ByteInherit; // 继承性
        queue. BitOffset  = BitOffset; // 继承性
        queue. BitLength  = BitLength; // 继承性
        queue. TMsignedType = TMsignedType; // 符号数类型

        QDomNodeList nodeList_Para = element_TMitem.elementsByTagName("Para"); /// 2_Para：element——>list
        qDebug()<<"Para 数量"<<nodeList_Para.count();
        for (int j = 0; j < nodeList_Para.count();++j) {
            QDomElement element_Para = nodeList_Para.at(j).toElement(); /// 2_Para：list——>element
            QString paraName = element_Para.attribute("ParaSpecificationT");
            QString paraCode = element_Para.attribute("ParaRawCodeH");
            TMparaQueue TMqueue;
            TMqueue.paraName = paraName;
            TMqueue.initCode = paraCode;
            queue.TMparaList.append(TMqueue);
        }
        paraQueueVector.append(queue);
    }

    emit updateTMParaListSignal(paraQueueVector);
    qDebug()<<"遥测列表初始化信号已发送";
    qDebug()<<paraQueueVector.at(0).FrameLength.toInt();

}

bool XMLCommandParser::parseTMs_slow(QDomElement root){

//    int frameLength = 0;
    QDomNodeList nodeList_TM = root.elementsByTagName("TM");
    for (int i = 0; i < nodeList_TM.size(); ++i) {
        QDomElement elemTM = nodeList_TM.at(i).toElement();
        frameTmXML_slow.frameLength = elemTM.attribute("FrameLength").toInt();
        frameTmXML_slow.frameHead = elemTM.attribute("FrameHeader");
        frameTmXML_slow.frameTail = elemTM.attribute("FrameTail");
        frameTmXML_slow.checkSumNum = elemTM.attribute("CheckSumLength").toInt();

    }
    qDebug()<<"FrameLength"<<frameTmXML_slow.frameLength; // 169
    emit updateFrameTMSignal_slow(frameTmXML_slow);



    /// 节点列表
    QDomNodeList nodeList_TMitem = root.elementsByTagName("TMitem"); /// 1_TMitem：element——>list
    int TMitemCount = nodeList_TMitem.count(); // 遥测参数数量

    for (int i = 0; i < nodeList_TMitem.count(); ++i) {

        /// 任何节点的基类
        QDomElement element_TMitem = nodeList_TMitem.at(i).toElement(); /// 1_TMitem：list——>element

        // 开始读取我所需要的信息填入指令序列
        QString TMitemLength = element_TMitem.attribute("TMitemByteLengthD");
        QString TMitemNo = element_TMitem.attribute("TMitemNoName");
        QString TMitemName = element_TMitem.attribute("TMitemSpecificationT");
        QString ParaType = element_TMitem.attribute("TMitemType");
        QString EncodeType = element_TMitem.attribute("TMitemEncodeTypeT");
        QString Para = element_TMitem.attribute("TMitemNoName");
        QString TMitemRemarks = element_TMitem.attribute("TMitemNote");
        QString TMitemMinF = element_TMitem.attribute("TMitemMinF");
        QString TMitemMaxF = element_TMitem.attribute("TMitemMaxF");
        QString ByteInherit = element_TMitem.attribute("ByteInherit");
        QString BitOffset = element_TMitem.attribute("BitOffset");
        QString BitLength = element_TMitem.attribute("BitLength");
        QString TMsignedType = element_TMitem.attribute("TMsignedType");


        TMitemQueue queue;
        queue. TMitemLength = TMitemLength; // 遥测参数源码长度
        queue. TMitemNo = TMitemNo; // 遥测参数编号
        queue. TMitemName = TMitemName ; // 遥测参数名称
        queue. ParaType = ParaType; // 遥测参数类型
        queue. EncodeType = EncodeType; // 遥测参数解码规则（从十六位源码到十进制数值）
        queue. TMitemRemarks  = TMitemRemarks; // 备注
        queue. TMitemMinF  = TMitemMinF; // 备注// 最小值
        queue. TMitemMaxF  = TMitemMaxF; // 备注// 最大值
        queue. ByteInherit  = ByteInherit; // 继承性
        queue. BitOffset  = BitOffset; // 继承性
        queue. BitLength  = BitLength; // 继承性
        queue. TMsignedType = TMsignedType; // 符号数类型


        QDomNodeList nodeList_Para = element_TMitem.elementsByTagName("Para"); /// 2_Para：element——>list
        qDebug()<<"Para 数量"<<nodeList_Para.count();
        for (int j = 0; j < nodeList_Para.count();++j) {
            QDomElement element_Para = nodeList_Para.at(j).toElement(); /// 2_Para：list——>element
            QString paraName = element_Para.attribute("ParaSpecificationT");
            QString paraCode = element_Para.attribute("ParaRawCodeH");
            TMparaQueue TMqueue;
            TMqueue.paraName = paraName;
            TMqueue.initCode = paraCode;
            queue.TMparaList.append(TMqueue);
        }
        paraQueueVector_slow.append(queue);
    }
    for (int i = 0; i < paraQueueVector_slow.size(); ++i) {
        const TMitemQueue &cmd = paraQueueVector_slow.at(i);
         for(int j = 0 ; j < cmd.TMparaList.size(); ++j){
            qDebug()<<j<<"paraName"<< cmd.TMparaList.at(j).paraName;
            qDebug()<<j<<"initCode"<< cmd.TMparaList.at(j).initCode;
        }
    }

    emit updateTMParaListSignal_slow(paraQueueVector_slow);

}

void XMLCommandParser::setDocNodeList(const QList<QDomElement> &list)
{
    docNodeListTemp.clear();
    for (const auto &elem : list)
    docNodeListTemp.append(elem.cloneNode(true).toElement());
}
