/********************************************************************************
** Form generated from reading UI file 'LVDS_SignalPage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LVDS_SIGNALPAGE_H
#define UI_LVDS_SIGNALPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LVDS_SignalPage
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Tx_State_pushButton;
    QPushButton *Rx_State_pushButton;

    void setupUi(QWidget *LVDS_SignalPage)
    {
        if (LVDS_SignalPage->objectName().isEmpty())
            LVDS_SignalPage->setObjectName(QString::fromUtf8("LVDS_SignalPage"));
        LVDS_SignalPage->resize(419, 138);
        gridLayout_2 = new QGridLayout(LVDS_SignalPage);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(LVDS_SignalPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(LVDS_SignalPage);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);

        label_3 = new QLabel(LVDS_SignalPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        pushButton = new QPushButton(LVDS_SignalPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(LVDS_SignalPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Tx_State_pushButton = new QPushButton(groupBox);
        Tx_State_pushButton->setObjectName(QString::fromUtf8("Tx_State_pushButton"));

        horizontalLayout_2->addWidget(Tx_State_pushButton);

        Rx_State_pushButton = new QPushButton(groupBox);
        Rx_State_pushButton->setObjectName(QString::fromUtf8("Rx_State_pushButton"));

        horizontalLayout_2->addWidget(Rx_State_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);

        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(LVDS_SignalPage);

        QMetaObject::connectSlotsByName(LVDS_SignalPage);
    } // setupUi

    void retranslateUi(QWidget *LVDS_SignalPage)
    {
        LVDS_SignalPage->setWindowTitle(QApplication::translate("LVDS_SignalPage", "Form", nullptr));
        label_2->setText(QApplication::translate("LVDS_SignalPage", "\344\270\200\345\270\247\346\216\245\346\224\266\346\225\260\346\215\256\351\207\217", nullptr));
        lineEdit_2->setText(QApplication::translate("LVDS_SignalPage", "2048", nullptr));
        label_3->setText(QApplication::translate("LVDS_SignalPage", "\345\255\227\350\212\202", nullptr));
        pushButton->setText(QApplication::translate("LVDS_SignalPage", "\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QApplication::translate("LVDS_SignalPage", "\346\216\245\346\224\266/\345\217\221\351\200\201", nullptr));
        label->setText(QApplication::translate("LVDS_SignalPage", "\345\275\223\345\211\215\351\200\237\345\272\246", nullptr));
        Tx_State_pushButton->setText(QApplication::translate("LVDS_SignalPage", "\345\274\200\345\247\213\345\217\221\351\200\201", nullptr));
        Rx_State_pushButton->setText(QApplication::translate("LVDS_SignalPage", "\345\274\200\345\247\213\346\216\245\346\224\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LVDS_SignalPage: public Ui_LVDS_SignalPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LVDS_SIGNALPAGE_H
