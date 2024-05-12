/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_add
{
public:
    QComboBox *shapeBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *penColorBox;
    QPushButton *exitButton;
    QSpinBox *penWidth;
    QComboBox *penStyle;
    QComboBox *penCapStyle;
    QPushButton *updateButton;
    QComboBox *penJoinStyle;
    QComboBox *brushColorBox;
    QComboBox *brushStyleBox;

    void setupUi(QDialog *add)
    {
        if (add->objectName().isEmpty())
            add->setObjectName("add");
        add->resize(559, 392);
        shapeBox = new QComboBox(add);
        shapeBox->addItem(QString());
        shapeBox->addItem(QString());
        shapeBox->addItem(QString());
        shapeBox->addItem(QString());
        shapeBox->addItem(QString());
        shapeBox->addItem(QString());
        shapeBox->setObjectName("shapeBox");
        shapeBox->setGeometry(QRect(89, 20, 121, 26));
        label = new QLabel(add);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 51, 20));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(add);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 81, 20));
        label_2->setMinimumSize(QSize(81, 20));
        QFont font1;
        font1.setPointSize(9);
        label_2->setFont(font1);
        label_3 = new QLabel(add);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 100, 81, 20));
        label_3->setMinimumSize(QSize(81, 20));
        label_3->setFont(font1);
        label_4 = new QLabel(add);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 140, 81, 20));
        label_4->setMinimumSize(QSize(81, 20));
        label_4->setFont(font1);
        label_5 = new QLabel(add);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 180, 101, 20));
        label_5->setMinimumSize(QSize(101, 20));
        label_5->setFont(font1);
        label_6 = new QLabel(add);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 220, 101, 20));
        label_6->setMinimumSize(QSize(101, 20));
        label_6->setFont(font1);
        label_7 = new QLabel(add);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 260, 101, 20));
        label_7->setMinimumSize(QSize(101, 20));
        label_7->setFont(font1);
        label_8 = new QLabel(add);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 300, 101, 20));
        label_8->setMinimumSize(QSize(101, 20));
        label_8->setFont(font1);
        label_9 = new QLabel(add);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(240, 20, 101, 20));
        label_9->setMinimumSize(QSize(101, 20));
        label_9->setFont(font1);
        penColorBox = new QComboBox(add);
        penColorBox->addItem(QString());
        penColorBox->addItem(QString());
        penColorBox->addItem(QString());
        penColorBox->addItem(QString());
        penColorBox->addItem(QString());
        penColorBox->addItem(QString());
        penColorBox->addItem(QString());
        penColorBox->addItem(QString());
        penColorBox->addItem(QString());
        penColorBox->setObjectName("penColorBox");
        penColorBox->setGeometry(QRect(90, 60, 121, 26));
        exitButton = new QPushButton(add);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(440, 340, 93, 29));
        penWidth = new QSpinBox(add);
        penWidth->setObjectName("penWidth");
        penWidth->setGeometry(QRect(90, 100, 42, 26));
        penWidth->setMaximum(20);
        penStyle = new QComboBox(add);
        penStyle->addItem(QString());
        penStyle->addItem(QString());
        penStyle->addItem(QString());
        penStyle->addItem(QString());
        penStyle->addItem(QString());
        penStyle->addItem(QString());
        penStyle->setObjectName("penStyle");
        penStyle->setGeometry(QRect(100, 140, 111, 26));
        penCapStyle = new QComboBox(add);
        penCapStyle->addItem(QString());
        penCapStyle->addItem(QString());
        penCapStyle->addItem(QString());
        penCapStyle->setObjectName("penCapStyle");
        penCapStyle->setGeometry(QRect(100, 180, 111, 26));
        updateButton = new QPushButton(add);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(340, 340, 93, 29));
        penJoinStyle = new QComboBox(add);
        penJoinStyle->addItem(QString());
        penJoinStyle->addItem(QString());
        penJoinStyle->addItem(QString());
        penJoinStyle->setObjectName("penJoinStyle");
        penJoinStyle->setGeometry(QRect(100, 220, 111, 26));
        brushColorBox = new QComboBox(add);
        brushColorBox->addItem(QString());
        brushColorBox->addItem(QString());
        brushColorBox->addItem(QString());
        brushColorBox->addItem(QString());
        brushColorBox->addItem(QString());
        brushColorBox->addItem(QString());
        brushColorBox->addItem(QString());
        brushColorBox->addItem(QString());
        brushColorBox->addItem(QString());
        brushColorBox->setObjectName("brushColorBox");
        brushColorBox->setGeometry(QRect(100, 260, 111, 26));
        brushStyleBox = new QComboBox(add);
        brushStyleBox->addItem(QString());
        brushStyleBox->addItem(QString());
        brushStyleBox->addItem(QString());
        brushStyleBox->addItem(QString());
        brushStyleBox->addItem(QString());
        brushStyleBox->setObjectName("brushStyleBox");
        brushStyleBox->setGeometry(QRect(100, 300, 111, 26));

        retranslateUi(add);

        QMetaObject::connectSlotsByName(add);
    } // setupUi

    void retranslateUi(QDialog *add)
    {
        add->setWindowTitle(QCoreApplication::translate("add", "Dialog", nullptr));
        shapeBox->setItemText(0, QCoreApplication::translate("add", "Line", nullptr));
        shapeBox->setItemText(1, QCoreApplication::translate("add", "Polyline", nullptr));
        shapeBox->setItemText(2, QCoreApplication::translate("add", "Polygon", nullptr));
        shapeBox->setItemText(3, QCoreApplication::translate("add", "Rectangle", nullptr));
        shapeBox->setItemText(4, QCoreApplication::translate("add", "Ellipse", nullptr));
        shapeBox->setItemText(5, QCoreApplication::translate("add", "Text", nullptr));

        label->setText(QCoreApplication::translate("add", "Shape:", nullptr));
        label_2->setText(QCoreApplication::translate("add", "PenColor:", nullptr));
        label_3->setText(QCoreApplication::translate("add", "PenWidth:", nullptr));
        label_4->setText(QCoreApplication::translate("add", "PenStyle:", nullptr));
        label_5->setText(QCoreApplication::translate("add", "PenCapStyle:", nullptr));
        label_6->setText(QCoreApplication::translate("add", "PenJoinStyle:", nullptr));
        label_7->setText(QCoreApplication::translate("add", "BrushColor:", nullptr));
        label_8->setText(QCoreApplication::translate("add", "BrushStyle:", nullptr));
        label_9->setText(QCoreApplication::translate("add", "TextString:", nullptr));
        penColorBox->setItemText(0, QCoreApplication::translate("add", "white", nullptr));
        penColorBox->setItemText(1, QCoreApplication::translate("add", "black", nullptr));
        penColorBox->setItemText(2, QCoreApplication::translate("add", "red", nullptr));
        penColorBox->setItemText(3, QCoreApplication::translate("add", "green", nullptr));
        penColorBox->setItemText(4, QCoreApplication::translate("add", "blue", nullptr));
        penColorBox->setItemText(5, QCoreApplication::translate("add", "cyan", nullptr));
        penColorBox->setItemText(6, QCoreApplication::translate("add", "magenta", nullptr));
        penColorBox->setItemText(7, QCoreApplication::translate("add", "yellow", nullptr));
        penColorBox->setItemText(8, QCoreApplication::translate("add", "gray", nullptr));

        exitButton->setText(QCoreApplication::translate("add", "Exit", nullptr));
        penStyle->setItemText(0, QCoreApplication::translate("add", "NoPen", nullptr));
        penStyle->setItemText(1, QCoreApplication::translate("add", "SolidLine", nullptr));
        penStyle->setItemText(2, QCoreApplication::translate("add", "DashLine", nullptr));
        penStyle->setItemText(3, QCoreApplication::translate("add", "DotLine", nullptr));
        penStyle->setItemText(4, QCoreApplication::translate("add", "DashDotLine", nullptr));
        penStyle->setItemText(5, QCoreApplication::translate("add", "DashDotDotLine ", nullptr));

        penCapStyle->setItemText(0, QCoreApplication::translate("add", "FlatCap", nullptr));
        penCapStyle->setItemText(1, QCoreApplication::translate("add", "SquareCap", nullptr));
        penCapStyle->setItemText(2, QCoreApplication::translate("add", "RoundCap", nullptr));

        updateButton->setText(QCoreApplication::translate("add", "Confirm", nullptr));
        penJoinStyle->setItemText(0, QCoreApplication::translate("add", "MiterJoin", nullptr));
        penJoinStyle->setItemText(1, QCoreApplication::translate("add", "BevelJoin", nullptr));
        penJoinStyle->setItemText(2, QCoreApplication::translate("add", "RoundJoin", nullptr));

        brushColorBox->setItemText(0, QCoreApplication::translate("add", "white", nullptr));
        brushColorBox->setItemText(1, QCoreApplication::translate("add", "black", nullptr));
        brushColorBox->setItemText(2, QCoreApplication::translate("add", "red", nullptr));
        brushColorBox->setItemText(3, QCoreApplication::translate("add", "green", nullptr));
        brushColorBox->setItemText(4, QCoreApplication::translate("add", "blue", nullptr));
        brushColorBox->setItemText(5, QCoreApplication::translate("add", "cyan", nullptr));
        brushColorBox->setItemText(6, QCoreApplication::translate("add", "magenta", nullptr));
        brushColorBox->setItemText(7, QCoreApplication::translate("add", "yellow", nullptr));
        brushColorBox->setItemText(8, QCoreApplication::translate("add", "gray", nullptr));

        brushStyleBox->setItemText(0, QCoreApplication::translate("add", "SolidPattern", nullptr));
        brushStyleBox->setItemText(1, QCoreApplication::translate("add", "HorPattern", nullptr));
        brushStyleBox->setItemText(2, QCoreApplication::translate("add", "VerPattern", nullptr));
        brushStyleBox->setItemText(3, QCoreApplication::translate("add", "NoBrush", nullptr));
        brushStyleBox->setItemText(4, QCoreApplication::translate("add", "CrossPattern", nullptr));

    } // retranslateUi

};

namespace Ui {
    class add: public Ui_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
