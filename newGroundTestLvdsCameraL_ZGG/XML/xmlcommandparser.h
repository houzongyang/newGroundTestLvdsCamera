#ifndef XMLCOMMANDPARSER_H
#define XMLCOMMANDPARSER_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QTableWidget>
#include <QStackedWidget>
#include <QMap>
#include <QListWidget>
#include "listwidgethelper.h"
#include "Structs.h"

class XMLCommandParser : public QObject
{
    Q_OBJECT

public:
    explicit XMLCommandParser(QObject *parent = nullptr);

    bool loadXML(const QString &filePath, QList<QDomElement> &docNodeInitList);
    void populateStackedWidget(QStackedWidget *stackWidget, QListWidget *listWidget, bool setCurrentToNew, QList<QDomElement> &docNodeInitListUi, int rowCom);

    QString calculateHex(const QString& input, const QString& rule, int byteLength);

    ListWidgetHelper *listWidgetHelper;

    void deleteComChoose(int delIndex);

    bool loadXML2(const QString &filePath, QList<QDomElement> &docList);


    QVector<CommandQueue> commandQueueVector;
    QVector<TMitemQueue> paraQueueVector;
    QVector<TMitemQueue> paraQueueVector_slow;


    void parseCommands3(QList<QDomElement> &docNodeList, int index,QStackedWidget *stackedWidget, int indexCom);
    QList<QDomElement> docNodeListTemp;

    QList<QDomElement> getDocNodeListTemp();


    bool loadTmXML(const QString &filePath);

    bool parseTMs(QDomElement boot);

    FrameTM frameTmXML;
    FrameTM frameTmXML_slow;
    bool parseTMs_slow(QDomElement root);
    bool loadTmXML_slow(const QString &filePath);
    void setDocNodeList(const QList<QDomElement> &list);
private:
    QList<Command> commandList;
    QList<Command> commandEditList; // 指令序列集合

    QDomDocument doc;

    // 存放指令序列
    QList<CommandInfo> CommandInfoList;

    void parseCommands(const QDomElement &root, QList<QDomElement> &docNodeInitList);
    void parseCommands2(const QDomElement &root, QList<QDomElement> &docNodeList);

    QTableWidget* createTableForCommand(const Command &cmd, QList<QDomElement> &docNodeInitListUi, int index);

signals:
    void updateUiCurComShowSignal(QString text);
    void updateSubUiCurComShowSignal(QString text);
    void updateParaListSignal(QVector<CommandQueue> commandQueueVector);
    void updateTMParaListSignal(QVector<TMitemQueue> paraQueueVector);
    void updateFrameTMSignal(FrameTM &frameTmXML);
    void updateFrameTMSignal_slow(FrameTM &frameTmXML);
    void updateTMParaListSignal_slow(QVector<TMitemQueue> paraQueueVector_slow);

};

#endif // XMLCOMMANDPARSER_H
