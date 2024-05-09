/********************************************************************************
** Form generated from reading UI file 'move.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVE_H
#define UI_MOVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_move
{
public:
    QLabel *label;
    QSpinBox *yBox;
    QSpinBox *xBox;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *exitButton;
    QPushButton *updateButton;
    QLineEdit *idInput;

    void setupUi(QDialog *move)
    {
        if (move->objectName().isEmpty())
            move->setObjectName("move");
        move->resize(400, 300);
        label = new QLabel(move);
        label->setObjectName("label");
        label->setGeometry(QRect(112, 100, 71, 20));
        yBox = new QSpinBox(move);
        yBox->setObjectName("yBox");
        yBox->setGeometry(QRect(240, 170, 41, 21));
        yBox->setMinimum(-999);
        yBox->setMaximum(999);
        xBox = new QSpinBox(move);
        xBox->setObjectName("xBox");
        xBox->setGeometry(QRect(120, 170, 41, 21));
        xBox->setMinimum(-999);
        xBox->setMaximum(999);
        label_2 = new QLabel(move);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 170, 21, 20));
        label_3 = new QLabel(move);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 170, 21, 20));
        exitButton = new QPushButton(move);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(290, 250, 93, 29));
        updateButton = new QPushButton(move);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(190, 250, 93, 29));
        idInput = new QLineEdit(move);
        idInput->setObjectName("idInput");
        idInput->setGeometry(QRect(190, 100, 61, 22));

        retranslateUi(move);

        QMetaObject::connectSlotsByName(move);
    } // setupUi

    void retranslateUi(QDialog *move)
    {
        move->setWindowTitle(QCoreApplication::translate("move", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("move", "Shape ID:", nullptr));
        label_2->setText(QCoreApplication::translate("move", "Y :", nullptr));
        label_3->setText(QCoreApplication::translate("move", "X :", nullptr));
        exitButton->setText(QCoreApplication::translate("move", "Exit", nullptr));
        updateButton->setText(QCoreApplication::translate("move", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class move: public Ui_move {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVE_H
