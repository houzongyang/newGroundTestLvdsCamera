/********************************************************************************
** Form generated from reading UI file 'frmshowmsg.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSHOWMSG_H
#define UI_FRMSHOWMSG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmShowMsg
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *te_response_data;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *te_response_result;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEdit_5;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit_4;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit_6;

    void setupUi(QWidget *frmShowMsg)
    {
        if (frmShowMsg->objectName().isEmpty())
            frmShowMsg->setObjectName(QString::fromUtf8("frmShowMsg"));
        frmShowMsg->resize(1200, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/images/command.png"), QSize(), QIcon::Normal, QIcon::Off);
        frmShowMsg->setWindowIcon(icon);
        gridLayout = new QGridLayout(frmShowMsg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(frmShowMsg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        te_response_data = new QTextEdit(groupBox);
        te_response_data->setObjectName(QString::fromUtf8("te_response_data"));

        verticalLayout->addWidget(te_response_data);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(frmShowMsg);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        te_response_result = new QTextEdit(groupBox_2);
        te_response_result->setObjectName(QString::fromUtf8("te_response_result"));

        verticalLayout_2->addWidget(te_response_result);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(frmShowMsg);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        textEdit_5 = new QTextEdit(groupBox_3);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));

        verticalLayout_3->addWidget(textEdit_5);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(frmShowMsg);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textEdit_4 = new QTextEdit(groupBox_4);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));

        verticalLayout_4->addWidget(textEdit_4);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_5 = new QGroupBox(frmShowMsg);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textEdit_6 = new QTextEdit(groupBox_5);
        textEdit_6->setObjectName(QString::fromUtf8("textEdit_6"));

        verticalLayout_5->addWidget(textEdit_6);


        gridLayout->addWidget(groupBox_5, 2, 0, 1, 2);


        retranslateUi(frmShowMsg);

        QMetaObject::connectSlotsByName(frmShowMsg);
    } // setupUi

    void retranslateUi(QWidget *frmShowMsg)
    {
        frmShowMsg->setWindowTitle(QCoreApplication::translate("frmShowMsg", "\346\266\210\346\201\257\347\252\227\345\217\243", nullptr));
        groupBox->setTitle(QCoreApplication::translate("frmShowMsg", "\345\223\215\345\272\224\346\225\260\346\215\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("frmShowMsg", "\345\223\215\345\272\224\347\273\223\346\236\234", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("frmShowMsg", "GroupBox", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("frmShowMsg", "GroupBox", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("frmShowMsg", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmShowMsg: public Ui_frmShowMsg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSHOWMSG_H
