/********************************************************************************
** Form generated from reading UI file 'aboutuswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTUSWIDGET_H
#define UI_ABOUTUSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aboutuswidget
{
public:
    QPushButton *exitButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *imageCloud;

    void setupUi(QDialog *aboutuswidget)
    {
        if (aboutuswidget->objectName().isEmpty())
            aboutuswidget->setObjectName("aboutuswidget");
        aboutuswidget->resize(432, 313);
        exitButton = new QPushButton(aboutuswidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(330, 270, 93, 29));
        label = new QLabel(aboutuswidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 121, 51));
        label_2 = new QLabel(aboutuswidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 131, 141));
        imageCloud = new QLabel(aboutuswidget);
        imageCloud->setObjectName("imageCloud");
        imageCloud->setGeometry(QRect(150, 20, 261, 231));

        retranslateUi(aboutuswidget);

        QMetaObject::connectSlotsByName(aboutuswidget);
    } // setupUi

    void retranslateUi(QDialog *aboutuswidget)
    {
        aboutuswidget->setWindowTitle(QCoreApplication::translate("aboutuswidget", "Dialog", nullptr));
        exitButton->setText(QCoreApplication::translate("aboutuswidget", "Exit", nullptr));
        label->setText(QCoreApplication::translate("aboutuswidget", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; text-decoration: underline;\">Team Cloud</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("aboutuswidget", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">Evan Stewart<br/>Esmar Walkman<br/>Josh Baxter<br/>Max Tan<br/>Yu-chen Chung<br/>Kaiass Asadi</span></p></body></html>", nullptr));
        imageCloud->setText(QCoreApplication::translate("aboutuswidget", "Cloud Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutuswidget: public Ui_aboutuswidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTUSWIDGET_H
