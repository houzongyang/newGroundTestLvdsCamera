#ifndef DEBUGPAGE_H
#define DEBUGPAGE_H

#include <QWidget>
#include <QDateTime>
namespace Ui {
class DebugPage;
}

class DebugPage : public QWidget
{
    Q_OBJECT

public:
    explicit DebugPage(QWidget *parent = nullptr);
    ~DebugPage();


    //<<设置:标题
    void Set_PageTitle(QString name);


private:

    //<<DEBUG
    QString getCurrentDateTime();
    void   debug_Message(QString flag,QString msg);

public slots:
    void DEBUG_Message_Slots(QString flag,QString msg);

private:
    Ui::DebugPage *ui;
};

#endif // DEBUGPAGE_H
