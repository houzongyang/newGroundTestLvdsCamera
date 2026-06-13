/********************************************************************************
** Form generated from reading UI file 'DebugPage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGPAGE_H
#define UI_DEBUGPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugPage
{
public:
    QTextEdit *Information_textEdit;

    void setupUi(QWidget *DebugPage)
    {
        if (DebugPage->objectName().isEmpty())
            DebugPage->setObjectName(QString::fromUtf8("DebugPage"));
        DebugPage->resize(635, 550);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DebugPage->sizePolicy().hasHeightForWidth());
        DebugPage->setSizePolicy(sizePolicy);
        Information_textEdit = new QTextEdit(DebugPage);
        Information_textEdit->setObjectName(QString::fromUtf8("Information_textEdit"));
        Information_textEdit->setGeometry(QRect(9, 9, 256, 192));

        retranslateUi(DebugPage);

        QMetaObject::connectSlotsByName(DebugPage);
    } // setupUi

    void retranslateUi(QWidget *DebugPage)
    {
        DebugPage->setWindowTitle(QApplication::translate("DebugPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugPage: public Ui_DebugPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGPAGE_H
