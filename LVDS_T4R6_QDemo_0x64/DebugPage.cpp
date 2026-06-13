#include "DebugPage.h"
#include "ui_DebugPage.h"
#include <QVBoxLayout>
DebugPage::DebugPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DebugPage)
{
    ui->setupUi(this);

      ui->Information_textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      // 设置 DebugPage 的布局管理器
      QVBoxLayout* layout = new QVBoxLayout(this);
      layout->setContentsMargins(0, 0, 0, 0);
      layout->setSpacing(0);
      layout->addWidget(ui->Information_textEdit);
      setLayout(layout);

      // 设置 Information_textEdit 的边距和内边距为0
      ui->Information_textEdit->setContentsMargins(0, 0, 0, 0);
      ui->Information_textEdit->setFrameShape(QFrame::NoFrame); // 设置无边框
}

DebugPage::~DebugPage()
{
    delete ui;
}

QString DebugPage::getCurrentDateTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    return QString("[%1]").arg(currentDateTime.toString("HH:mm:ss"));
}

void DebugPage::debug_Message(QString flag, QString msg)
{
    QString currentTime = getCurrentDateTime();
    QString runString = msg;

    if (flag == "Error")
    {
        ui->Information_textEdit->setTextColor(Qt::red);
        ui->Information_textEdit->append(currentTime + "  " + runString + '\n');
    }
    else if (flag == "Right")
    {
        ui->Information_textEdit->setTextColor(Qt::black);
        ui->Information_textEdit->append(currentTime + "  " + runString + '\n');
    }
    else if (flag == "NoTime")
    {
        ui->Information_textEdit->setTextColor(Qt::black);
        ui->Information_textEdit->append(runString + '\n');
    }
    else
    {
        ui->Information_textEdit->append("" + '\n');
    }

    // 检查行数
    int lineCount = ui->Information_textEdit->document()->blockCount();
    if (lineCount > 3000)
    {
        ui->Information_textEdit->clear();
    }
}

void DebugPage::DEBUG_Message_Slots(QString flag, QString msg)
{
    debug_Message(flag, msg);
}

void DebugPage::Set_PageTitle(QString name)
{
    this->setWindowTitle(name);
}
