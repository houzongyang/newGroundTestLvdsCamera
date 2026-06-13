#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFrame>
#include <DebugPage.h>
#include <QVBoxLayout>

#include <LVDS_T4R6.h>

#include <QMessageBox>

#include <LVDS_SignalPage.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void OPen_LVDS_Car(UINT8 uCardId);


    UINT8 uCardId;

    LVDS_SignalPage *m_LVDS_SignalPage_CH1;
     LVDS_SignalPage *m_LVDS_SignalPage_CH2;

private:
    Ui::Widget *ui;

      QMutex m_QMutex;
};
#endif // WIDGET_H
