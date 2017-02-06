/********************************************************************************
** Form generated from reading UI file 'basicdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICDIALOG_H
#define UI_BASICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_basicdialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *basicdialog)
    {
        if (basicdialog->objectName().isEmpty())
            basicdialog->setObjectName(QStringLiteral("basicdialog"));
        basicdialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(basicdialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(basicdialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), basicdialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), basicdialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(basicdialog);
    } // setupUi

    void retranslateUi(QDialog *basicdialog)
    {
        basicdialog->setWindowTitle(QApplication::translate("basicdialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class basicdialog: public Ui_basicdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICDIALOG_H
