/********************************************************************************
** Form generated from reading UI file 'frmpagescommand.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPAGESCOMMAND_H
#define UI_FRMPAGESCOMMAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmPagesCommand
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *lb_local_count;
    QLabel *label_4;
    QLabel *lb_time;
    QLabel *label_6;
    QLabel *lb_cmd_id;
    QLabel *label_8;
    QLabel *lb_result;
    QLabel *label_10;
    QLabel *lb_error_type;
    QTextEdit *te_response_result;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *lb_current_cmd_name;
    QTableWidget *tableWidget_cmd;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_t_1;
    QPushButton *pb_t_2;
    QPushButton *pb_t_3;
    QPushButton *pb_del_cmd;
    QPushButton *pb_clear_cmd;
    QPushButton *pb_insert_cmd;
    QPushButton *pb_add_cmd;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_send_cmd_immediately;
    QTableWidget *tableWidget_cmd_immediately;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_import_xml;
    QPushButton *pb_export_xml;
    QLineEdit *le_save_xml_name;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pb_send_cmd;

    void setupUi(QWidget *frmPagesCommand)
    {
        if (frmPagesCommand->objectName().isEmpty())
            frmPagesCommand->setObjectName(QString::fromUtf8("frmPagesCommand"));
        frmPagesCommand->resize(1040, 792);
        verticalLayout = new QVBoxLayout(frmPagesCommand);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(frmPagesCommand);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_2 = new QVBoxLayout(widget_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidget = new QListWidget(widget_6);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(listWidget);

        groupBox = new QGroupBox(widget_6);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 100));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lb_local_count = new QLabel(groupBox);
        lb_local_count->setObjectName(QString::fromUtf8("lb_local_count"));
        lb_local_count->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_local_count, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lb_time = new QLabel(groupBox);
        lb_time->setObjectName(QString::fromUtf8("lb_time"));
        lb_time->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_time, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        lb_cmd_id = new QLabel(groupBox);
        lb_cmd_id->setObjectName(QString::fromUtf8("lb_cmd_id"));
        lb_cmd_id->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_cmd_id, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        lb_result = new QLabel(groupBox);
        lb_result->setObjectName(QString::fromUtf8("lb_result"));
        lb_result->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_result, 3, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        lb_error_type = new QLabel(groupBox);
        lb_error_type->setObjectName(QString::fromUtf8("lb_error_type"));
        lb_error_type->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        gridLayout->addWidget(lb_error_type, 4, 1, 1, 1);

        te_response_result = new QTextEdit(groupBox);
        te_response_result->setObjectName(QString::fromUtf8("te_response_result"));

        gridLayout->addWidget(te_response_result, 5, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox);

        verticalLayout_2->setStretch(0, 1);

        horizontalLayout->addWidget(widget_6);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(widget_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lb_current_cmd_name = new QLabel(widget_7);
        lb_current_cmd_name->setObjectName(QString::fromUtf8("lb_current_cmd_name"));
        lb_current_cmd_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));

        horizontalLayout_5->addWidget(lb_current_cmd_name);

        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_5->addWidget(widget_7);

        tableWidget_cmd = new QTableWidget(widget_2);
        tableWidget_cmd->setObjectName(QString::fromUtf8("tableWidget_cmd"));

        verticalLayout_5->addWidget(tableWidget_cmd);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 50));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pb_t_1 = new QPushButton(widget_3);
        pb_t_1->setObjectName(QString::fromUtf8("pb_t_1"));

        horizontalLayout_3->addWidget(pb_t_1);

        pb_t_2 = new QPushButton(widget_3);
        pb_t_2->setObjectName(QString::fromUtf8("pb_t_2"));

        horizontalLayout_3->addWidget(pb_t_2);

        pb_t_3 = new QPushButton(widget_3);
        pb_t_3->setObjectName(QString::fromUtf8("pb_t_3"));

        horizontalLayout_3->addWidget(pb_t_3);

        pb_del_cmd = new QPushButton(widget_3);
        pb_del_cmd->setObjectName(QString::fromUtf8("pb_del_cmd"));

        horizontalLayout_3->addWidget(pb_del_cmd);

        pb_clear_cmd = new QPushButton(widget_3);
        pb_clear_cmd->setObjectName(QString::fromUtf8("pb_clear_cmd"));

        horizontalLayout_3->addWidget(pb_clear_cmd);

        pb_insert_cmd = new QPushButton(widget_3);
        pb_insert_cmd->setObjectName(QString::fromUtf8("pb_insert_cmd"));

        horizontalLayout_3->addWidget(pb_insert_cmd);

        pb_add_cmd = new QPushButton(widget_3);
        pb_add_cmd->setObjectName(QString::fromUtf8("pb_add_cmd"));

        horizontalLayout_3->addWidget(pb_add_cmd);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(100, 0));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        spinBox = new QSpinBox(widget_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(1000000000);

        horizontalLayout_4->addWidget(spinBox);


        horizontalLayout_3->addWidget(widget_5);

        horizontalSpacer_2 = new QSpacerItem(585, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pb_send_cmd_immediately = new QPushButton(widget_3);
        pb_send_cmd_immediately->setObjectName(QString::fromUtf8("pb_send_cmd_immediately"));

        horizontalLayout_3->addWidget(pb_send_cmd_immediately);


        verticalLayout_5->addWidget(widget_3);

        tableWidget_cmd_immediately = new QTableWidget(widget_2);
        tableWidget_cmd_immediately->setObjectName(QString::fromUtf8("tableWidget_cmd_immediately"));

        verticalLayout_5->addWidget(tableWidget_cmd_immediately);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 50));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pb_import_xml = new QPushButton(widget_4);
        pb_import_xml->setObjectName(QString::fromUtf8("pb_import_xml"));

        horizontalLayout_2->addWidget(pb_import_xml);

        pb_export_xml = new QPushButton(widget_4);
        pb_export_xml->setObjectName(QString::fromUtf8("pb_export_xml"));

        horizontalLayout_2->addWidget(pb_export_xml);

        le_save_xml_name = new QLineEdit(widget_4);
        le_save_xml_name->setObjectName(QString::fromUtf8("le_save_xml_name"));

        horizontalLayout_2->addWidget(le_save_xml_name);

        horizontalSpacer_3 = new QSpacerItem(388, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pb_send_cmd = new QPushButton(widget_4);
        pb_send_cmd->setObjectName(QString::fromUtf8("pb_send_cmd"));

        horizontalLayout_2->addWidget(pb_send_cmd);


        verticalLayout_5->addWidget(widget_4);


        horizontalLayout->addWidget(widget_2);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addWidget(widget);


        retranslateUi(frmPagesCommand);

        QMetaObject::connectSlotsByName(frmPagesCommand);
    } // setupUi

    void retranslateUi(QWidget *frmPagesCommand)
    {
        frmPagesCommand->setWindowTitle(QCoreApplication::translate("frmPagesCommand", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("frmPagesCommand", "\346\214\207\344\273\244\345\223\215\345\272\224\347\273\223\346\236\234", nullptr));
        label_2->setText(QCoreApplication::translate("frmPagesCommand", "\346\234\254\345\234\260\345\270\247:", nullptr));
        lb_local_count->setText(QCoreApplication::translate("frmPagesCommand", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_4->setText(QCoreApplication::translate("frmPagesCommand", "\346\227\266\351\227\264\346\210\263:", nullptr));
        lb_time->setText(QCoreApplication::translate("frmPagesCommand", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_6->setText(QCoreApplication::translate("frmPagesCommand", "\346\214\207\344\273\244ID:", nullptr));
        lb_cmd_id->setText(QCoreApplication::translate("frmPagesCommand", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_8->setText(QCoreApplication::translate("frmPagesCommand", "\347\233\270\345\272\224\347\273\223\346\236\234:", nullptr));
        lb_result->setText(QCoreApplication::translate("frmPagesCommand", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_10->setText(QCoreApplication::translate("frmPagesCommand", "\351\224\231\350\257\257\347\261\273\345\236\213:", nullptr));
        lb_error_type->setText(QCoreApplication::translate("frmPagesCommand", "\346\232\202\346\227\240\346\225\260\346\215\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmPagesCommand", "\345\275\223\345\211\215\346\214\207\344\273\244:", nullptr));
        lb_current_cmd_name->setText(QCoreApplication::translate("frmPagesCommand", "\346\232\202\346\227\240\346\214\207\344\273\244", nullptr));
        pb_t_1->setText(QCoreApplication::translate("frmPagesCommand", "\346\223\246\351\231\244\346\214\207\344\273\244", nullptr));
        pb_t_2->setText(QCoreApplication::translate("frmPagesCommand", "\346\233\264\346\224\271flash\345\257\204\345\255\230\345\231\250", nullptr));
        pb_t_3->setText(QCoreApplication::translate("frmPagesCommand", "\351\207\215\350\275\275\346\214\207\344\273\244", nullptr));
        pb_del_cmd->setText(QCoreApplication::translate("frmPagesCommand", "\345\210\240\351\231\244\346\214\207\344\273\244", nullptr));
        pb_clear_cmd->setText(QCoreApplication::translate("frmPagesCommand", "\346\270\205\347\251\272\346\214\207\344\273\244\345\272\217\345\210\227", nullptr));
        pb_insert_cmd->setText(QCoreApplication::translate("frmPagesCommand", "\346\217\222\345\205\245\345\210\260\346\214\207\344\273\244\345\272\217\345\210\227", nullptr));
        pb_add_cmd->setText(QCoreApplication::translate("frmPagesCommand", "\346\267\273\345\212\240\345\210\260\346\214\207\344\273\244\345\272\217\345\210\227", nullptr));
        label->setText(QCoreApplication::translate("frmPagesCommand", "\346\227\266\351\227\264\346\210\263:", nullptr));
        spinBox->setSuffix(QCoreApplication::translate("frmPagesCommand", "\347\247\222", nullptr));
        pb_send_cmd_immediately->setText(QCoreApplication::translate("frmPagesCommand", "\345\217\221\351\200\201\347\253\213\345\215\263\344\273\244", nullptr));
        pb_import_xml->setText(QCoreApplication::translate("frmPagesCommand", "\345\257\274\345\205\245XML", nullptr));
        pb_export_xml->setText(QCoreApplication::translate("frmPagesCommand", "\345\257\274\345\207\272XML", nullptr));
        pb_send_cmd->setText(QCoreApplication::translate("frmPagesCommand", "\345\217\221\351\200\201\345\221\275\344\273\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmPagesCommand: public Ui_frmPagesCommand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPAGESCOMMAND_H
