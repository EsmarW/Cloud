/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *updateButton;
    QPushButton *exitButton;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(655, 335);
        updateButton = new QPushButton(Dialog);
        buttonGroup = new QButtonGroup(Dialog);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(updateButton);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(540, 250, 93, 29));
        exitButton = new QPushButton(Dialog);
        buttonGroup->addButton(exitButton);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(540, 290, 93, 29));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        updateButton->setText(QCoreApplication::translate("Dialog", "Update", nullptr));
        exitButton->setText(QCoreApplication::translate("Dialog", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
