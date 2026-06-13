/********************************************************************************
** Form generated from reading UI file 'dialogpara.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPARA_H
#define UI_DIALOGPARA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogPara
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget_paraList;
    QWidget *page;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogPara)
    {
        if (DialogPara->objectName().isEmpty())
            DialogPara->setObjectName(QString::fromUtf8("DialogPara"));
        DialogPara->resize(672, 464);
        verticalLayout = new QVBoxLayout(DialogPara);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget_paraList = new QStackedWidget(DialogPara);
        stackedWidget_paraList->setObjectName(QString::fromUtf8("stackedWidget_paraList"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget_paraList->addWidget(page);

        verticalLayout->addWidget(stackedWidget_paraList);

        buttonBox = new QDialogButtonBox(DialogPara);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogPara);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogPara, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogPara, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPara);
    } // setupUi

    void retranslateUi(QDialog *DialogPara)
    {
        DialogPara->setWindowTitle(QCoreApplication::translate("DialogPara", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPara: public Ui_DialogPara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPARA_H
