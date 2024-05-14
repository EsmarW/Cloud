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
#include <QtWidgets/QLineEdit>
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
    QLabel *textStringLabel;
    QComboBox *penColorBox;
    QPushButton *exitButton;
    QSpinBox *penWidth;
    QComboBox *penStyle;
    QComboBox *penCapStyle;
    QPushButton *updateButton;
    QComboBox *penJoinStyle;
    QComboBox *brushColorBox;
    QComboBox *brushStyleBox;
    QLineEdit *textString;
    QLabel *textSizeLabel;
    QSpinBox *textSize;
    QLabel *textALabel;
    QLabel *textFontLabel;
    QLabel *textSLabel;
    QLabel *textWLabel;
    QComboBox *textA;
    QComboBox *textFont;
    QComboBox *textStyle;
    QComboBox *textWeight;

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
        textStringLabel = new QLabel(add);
        textStringLabel->setObjectName("textStringLabel");
        textStringLabel->setGeometry(QRect(240, 20, 101, 20));
        textStringLabel->setMinimumSize(QSize(101, 20));
        textStringLabel->setFont(font1);
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
        textString = new QLineEdit(add);
        textString->setObjectName("textString");
        textString->setGeometry(QRect(320, 20, 211, 26));
        textSizeLabel = new QLabel(add);
        textSizeLabel->setObjectName("textSizeLabel");
        textSizeLabel->setGeometry(QRect(240, 60, 81, 20));
        textSizeLabel->setMinimumSize(QSize(81, 20));
        textSizeLabel->setFont(font1);
        textSize = new QSpinBox(add);
        textSize->setObjectName("textSize");
        textSize->setGeometry(QRect(320, 60, 42, 26));
        textSize->setMinimum(5);
        textSize->setMaximum(100);
        textALabel = new QLabel(add);
        textALabel->setObjectName("textALabel");
        textALabel->setGeometry(QRect(240, 100, 121, 20));
        textALabel->setMinimumSize(QSize(81, 20));
        textALabel->setFont(font1);
        textFontLabel = new QLabel(add);
        textFontLabel->setObjectName("textFontLabel");
        textFontLabel->setGeometry(QRect(240, 140, 81, 20));
        textFontLabel->setMinimumSize(QSize(81, 20));
        textFontLabel->setFont(font1);
        textSLabel = new QLabel(add);
        textSLabel->setObjectName("textSLabel");
        textSLabel->setGeometry(QRect(240, 180, 121, 20));
        textSLabel->setMinimumSize(QSize(81, 20));
        textSLabel->setFont(font1);
        textWLabel = new QLabel(add);
        textWLabel->setObjectName("textWLabel");
        textWLabel->setGeometry(QRect(240, 220, 121, 20));
        textWLabel->setMinimumSize(QSize(81, 20));
        textWLabel->setFont(font1);
        textA = new QComboBox(add);
        textA->addItem(QString());
        textA->addItem(QString());
        textA->addItem(QString());
        textA->addItem(QString());
        textA->setObjectName("textA");
        textA->setGeometry(QRect(360, 100, 161, 26));
        textFont = new QComboBox(add);
        textFont->addItem(QString());
        textFont->addItem(QString());
        textFont->addItem(QString());
        textFont->addItem(QString());
        textFont->addItem(QString());
        textFont->setObjectName("textFont");
        textFont->setGeometry(QRect(320, 140, 201, 26));
        textStyle = new QComboBox(add);
        textStyle->addItem(QString());
        textStyle->addItem(QString());
        textStyle->addItem(QString());
        textStyle->setObjectName("textStyle");
        textStyle->setGeometry(QRect(330, 180, 121, 26));
        textWeight = new QComboBox(add);
        textWeight->addItem(QString());
        textWeight->addItem(QString());
        textWeight->addItem(QString());
        textWeight->addItem(QString());
        textWeight->addItem(QString());
        textWeight->addItem(QString());
        textWeight->addItem(QString());
        textWeight->setObjectName("textWeight");
        textWeight->setGeometry(QRect(330, 220, 121, 26));

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
        textStringLabel->setText(QCoreApplication::translate("add", "TextString:", nullptr));
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

        textString->setText(QString());
        textSizeLabel->setText(QCoreApplication::translate("add", "Text Size:", nullptr));
        textALabel->setText(QCoreApplication::translate("add", "Text Alignment:", nullptr));
        textFontLabel->setText(QCoreApplication::translate("add", "Text Font :", nullptr));
        textSLabel->setText(QCoreApplication::translate("add", "Text Style :", nullptr));
        textWLabel->setText(QCoreApplication::translate("add", "Text Weight :", nullptr));
        textA->setItemText(0, QCoreApplication::translate("add", "AlignLeft", nullptr));
        textA->setItemText(1, QCoreApplication::translate("add", "AlignRight", nullptr));
        textA->setItemText(2, QCoreApplication::translate("add", "AlignJustify", nullptr));
        textA->setItemText(3, QCoreApplication::translate("add", "AlignCenter", nullptr));

        textFont->setItemText(0, QCoreApplication::translate("add", "Helvetica", nullptr));
        textFont->setItemText(1, QCoreApplication::translate("add", "Impact", nullptr));
        textFont->setItemText(2, QCoreApplication::translate("add", "Courier", nullptr));
        textFont->setItemText(3, QCoreApplication::translate("add", "OldEnglish", nullptr));
        textFont->setItemText(4, QCoreApplication::translate("add", "System", nullptr));

        textStyle->setItemText(0, QCoreApplication::translate("add", "Normal", nullptr));
        textStyle->setItemText(1, QCoreApplication::translate("add", "Italic", nullptr));
        textStyle->setItemText(2, QCoreApplication::translate("add", "Oblique", nullptr));

        textWeight->setItemText(0, QCoreApplication::translate("add", "Thin", nullptr));
        textWeight->setItemText(1, QCoreApplication::translate("add", "Light", nullptr));
        textWeight->setItemText(2, QCoreApplication::translate("add", "Normal", nullptr));
        textWeight->setItemText(3, QCoreApplication::translate("add", "Medium", nullptr));
        textWeight->setItemText(4, QCoreApplication::translate("add", "Bold", nullptr));
        textWeight->setItemText(5, QCoreApplication::translate("add", "ExtraBold", nullptr));
        textWeight->setItemText(6, QCoreApplication::translate("add", "Black", nullptr));

    } // retranslateUi

};

namespace Ui {
    class add: public Ui_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
