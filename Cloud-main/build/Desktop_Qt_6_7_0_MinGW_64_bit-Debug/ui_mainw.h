/********************************************************************************
** Form generated from reading UI file 'mainw.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINW_H
#define UI_MAINW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_mainw
{
public:
    QPushButton *exitButton;
    draw *canvas;
    QPushButton *updateButton;
    QPushButton *moveButton;
    QPushButton *resetButton;
    QPushButton *clearButton;
    QPushButton *loginButton;
    QPushButton *contactButton;

    void setupUi(QDialog *mainw)
    {
        if (mainw->objectName().isEmpty())
            mainw->setObjectName("mainw");
        mainw->resize(1135, 531);
        exitButton = new QPushButton(mainw);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(1030, 480, 93, 29));
        canvas = new draw(mainw);
        canvas->setObjectName("canvas");
        canvas->setGeometry(QRect(10, 10, 1011, 511));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        canvas->setPalette(palette);
        updateButton = new QPushButton(mainw);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(1030, 20, 93, 29));
        moveButton = new QPushButton(mainw);
        moveButton->setObjectName("moveButton");
        moveButton->setGeometry(QRect(1030, 60, 93, 29));
        resetButton = new QPushButton(mainw);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(1030, 440, 93, 29));
        clearButton = new QPushButton(mainw);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(1030, 100, 93, 29));
        loginButton = new QPushButton(mainw);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(1030, 400, 93, 29));
        contactButton = new QPushButton(mainw);
        contactButton->setObjectName("contactButton");
        contactButton->setGeometry(QRect(1030, 360, 93, 29));

        retranslateUi(mainw);

        QMetaObject::connectSlotsByName(mainw);
    } // setupUi

    void retranslateUi(QDialog *mainw)
    {
        mainw->setWindowTitle(QCoreApplication::translate("mainw", "Dialog", nullptr));
        exitButton->setText(QCoreApplication::translate("mainw", "Exit", nullptr));
#if QT_CONFIG(accessibility)
        canvas->setAccessibleName(QCoreApplication::translate("mainw", "canvas", nullptr));
#endif // QT_CONFIG(accessibility)
        updateButton->setText(QCoreApplication::translate("mainw", "Add", nullptr));
        moveButton->setText(QCoreApplication::translate("mainw", "Move", nullptr));
        resetButton->setText(QCoreApplication::translate("mainw", "Reset", nullptr));
        clearButton->setText(QCoreApplication::translate("mainw", "Clear", nullptr));
        loginButton->setText(QCoreApplication::translate("mainw", "Login", nullptr));
        contactButton->setText(QCoreApplication::translate("mainw", "Contact Us", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainw: public Ui_mainw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINW_H
