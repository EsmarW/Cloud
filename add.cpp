#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add)
{
    ui->setupUi(this);
    setWindowTitle(tr("Add Shape")); //Sets string to window name
    ui->penStyle->setCurrentIndex(1);
    ui->penWidth->setValue(1);
    ui->textSize->setValue(16);

    //Hide Text Properties until Text Shape is selected
    // ui->textString->hide();
    // ui->textStringLabel->hide();
    // ui->textSize->hide();
    // ui->textSizeLabel->hide();
    // ui->textSLabel->hide();
    // ui->textStyle->hide();
    // ui->textWeight->hide();
    // ui->textWLabel->hide();
    // ui->textA->hide();
    // ui->textALabel->hide();
    // ui->textFontLabel->hide();
    // ui->textFont->hide();
}

add::~add()
{
    delete ui;
}

void add::setShapeList(vector<shape *> &old)
{
    shapes = &old;
}

void add::on_exitButton_clicked(){
    this->close();
}

void add::on_updateButton_clicked()
{
    int id = shapes->size();
    ++id;
    int penWidth = ui->penWidth->value();
    Qt::GlobalColor penColor; //https://doc.qt.io/qt-6/qt.html#GlobalColor-enum
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
    Qt::PenStyle penStyle;
    Qt::GlobalColor brushColor;
    Qt::BrushStyle brushStyle;

    Qt::AlignmentFlag align;
    QFont::Style fontStyle;
    QString font; //https://doc.qt.io/qt-5/qfont.html#StyleHint-enum
    QFont::Weight weight; //https://doc.qt.io/qt-5/qfont.html#Weight-enum
    QString textString;
    textString = ui->textString->text();
    int fontSize;
    fontSize = ui->textSize->value();

    //font = static_cast<QFont::StyleHint>(ui->textFont->currentIndex());

    switch(ui->textFont->currentIndex()){
        case 0:{
            font = "Helvetica"	;
        }break;
        case 1:{
            font = "Impact"	;
        }break;
        case 2:{
            font = "Courier";
        }break;
        case 3:{
            font = "System"	;
        }break;
    }

    switch(ui->textWeight->currentIndex()){
    case 0:{
        weight = QFont::Thin	;
    } break;
    case 1:{
        weight = QFont::Light;
    } break;
    case 2:{
        weight = QFont::Medium;
    } break;
    case 3:{
        weight = QFont::Bold;
    } break;
    case 4:{
        weight = QFont::ExtraBold;
    } break;
    case 5:{
        weight = QFont::Black;
    } break;
    }

    switch(ui->textStyle->currentIndex()){
    case 0:{
        fontStyle = QFont::StyleNormal;
    } break;
    case 1:{
        fontStyle = QFont::StyleItalic;
    } break;
    case 2:{
        fontStyle = QFont::StyleOblique;
    } break;
    }

    switch(ui->textA->currentIndex()){
    case 0:{
        align = Qt::AlignLeft;
    } break;
    case 1:{
        align = Qt::AlignRight;
    } break;
    case 2:{
        align = Qt::AlignJustify;
    } break;
    case 3:{
        align = Qt::AlignCenter;
    } break;
    }

    switch(ui->brushStyleBox->currentIndex()){
    case 0:{
        brushStyle = Qt::SolidPattern;
     } break;
    case 1:{
        brushStyle = Qt::HorPattern;
    } break;
    case 2:{
        brushStyle = Qt::VerPattern;
    } break;
    case 3:{
        brushStyle = Qt::NoBrush;
    } break;
    case 4:{
        brushStyle = Qt::CrossPattern;
    } break;
    }

    switch(ui->penJoinStyle->currentIndex()){
    case 0:{
        penJoinStyle = Qt::MiterJoin;
     } break;
    case 1:{
         penJoinStyle = Qt::BevelJoin;
    } break;
    case 2:{
        penJoinStyle = Qt::RoundJoin;
    } break;
    }

    switch(ui->penCapStyle->currentIndex()){ //PenCapStyle
        case 0:{
            penCapStyle = Qt::FlatCap;
        } break;
        case 1:{
            penCapStyle = Qt::SquareCap;
        } break;
        case 2:{
            penCapStyle = Qt::RoundCap;
        } break;
    }

    penStyle = static_cast<Qt::PenStyle>(ui->penStyle->currentIndex());

    //Qt::GlobalColor penColor = static_cast<Qt::GlobalColor>(ui->penColorBox->currentIndex());
    switch(ui->penColorBox->currentIndex()){ //Pen Color
    case 0:{
        penColor = static_cast<Qt::GlobalColor>(3); //White
    } break;
    case 1:{
        penColor = static_cast<Qt::GlobalColor>(2); //Black
    } break;
    case 2:{
        penColor = static_cast<Qt::GlobalColor>(7); //Red
    } break;
    case 3:{
        penColor = static_cast<Qt::GlobalColor>(8); //Green
    } break;
    case 4:{
        penColor = static_cast<Qt::GlobalColor>(9); //Blue
    } break;
    case 5:{
        penColor = static_cast<Qt::GlobalColor>(10); //Cyan
    } break;
    case 6:{
        penColor = static_cast<Qt::GlobalColor>(11); //Magenta
    } break;
    case 7:{
        penColor = static_cast<Qt::GlobalColor>(12); //Yellow
    } break;
    case 8:{
        penColor = static_cast<Qt::GlobalColor>(5); //Gray
    } break;
    }

    switch(ui->brushColorBox->currentIndex()){ //Pen Color
    case 0:{
        brushColor = static_cast<Qt::GlobalColor>(3); //White
    } break;
    case 1:{
        brushColor = static_cast<Qt::GlobalColor>(2); //Black
    } break;
    case 2:{
        brushColor = static_cast<Qt::GlobalColor>(7); //Red
    } break;
    case 3:{
        brushColor = static_cast<Qt::GlobalColor>(8); //Green
    } break;
    case 4:{
        brushColor = static_cast<Qt::GlobalColor>(9); //Blue
    } break;
    case 5:{
        brushColor = static_cast<Qt::GlobalColor>(10); //Cyan
    } break;
    case 6:{
        brushColor = static_cast<Qt::GlobalColor>(11); //Magenta
    } break;
    case 7:{
        brushColor = static_cast<Qt::GlobalColor>(12); //Yellow
    } break;
    case 8:{
        brushColor = static_cast<Qt::GlobalColor>(5); //Gray
    } break;
    }

    switch(ui->shapeBox->currentIndex() + 1){ //Shape Creation Switch

    case 1:{
        //std::cout <<"Line\n";
        line* l = new line(this);
        l->setId(id);
        l->setCoords(20,50);
        l->setStart(20,100);
        l->setEnd(100,20);
        l->setPen(penColor, penWidth,penStyle, penCapStyle, penJoinStyle);
        l->setBrush(brushColor, brushStyle);
        l->move(500,0);
        shapes->push_back(l);
    }break;

    case 2:{
        //std::cout <<"PolyLine\n";
        polyline* pl = new polyline(this);
        pl->setId(id);
        pl->set_point(QPoint(460,90));
        pl->set_point(QPoint(470,20));
        pl->set_point(QPoint(530,40));
        pl->set_point(QPoint(540,80));
        pl->set_point(QPoint(500,100));
        pl->setPen(penColor, penWidth,penStyle, penCapStyle, penJoinStyle);
        pl->setBrush(brushColor, brushStyle);
        pl->move(200,0);
        shapes->push_back(pl);

    }break;

    case 3:{
        //std::cout <<"Polygon\n";
        polygon* p = new polygon(this);
        p->setId(id);
        p->set_point(QPoint(100,100));
        p->set_point(QPoint(250,100));
        p->set_point(QPoint(200,200));
        p->set_point(QPoint(50,200));
        p->setPen(penColor, penWidth,penStyle, penCapStyle, penJoinStyle);
        p->setBrush(brushColor, brushStyle);
        shapes->push_back(p);
        p->move(710,-70);
    }break;

    case 4:{
        rectangle* r = new rectangle(this);
        r->setId(id);
        r->setCoords(20,200);
        r->setWidth(200);
        r->setHeight(100);
        r->setPen(penColor, penWidth,penStyle, penCapStyle, penJoinStyle);
        r->setBrush(brushColor, brushStyle);
        r->move(400,170);
        shapes->push_back(r);
    }break;

    case 5:{
        ellipse* e = new ellipse(this);
        e->setId(id);
        e->setCoords(700,370);
        e->setWidth(150);
        e->setHeight(100);
        e->setPen(penColor, penWidth,penStyle, penCapStyle, penJoinStyle);
        e->setBrush(brushColor, brushStyle);
        shapes->push_back(e);
    }break;

    case 6:{
        text* t = new text(this);
        t->setId(id);
        t->setSize(fontSize);
        //t->setString(QString("Class Project - 2D Graphics Modeler"));
        t->setString(textString); //Print Text from inputted string
        t->setCoords(20,350);
        t->setWidth(fontSize * textString.length());
        t->setHeight(5 * fontSize);
        t->setStyle(fontStyle);
        t->setWeight(weight);
        t->setAlignment(align);
        // t->setStyle(QFont::Style::StyleItalic);
        // t->setWeight(QFont::Weight::Normal);
        // t->setAlignment(Qt::AlignmentFlag::AlignCenter);
        t->setPen(penColor, penWidth,penStyle, penCapStyle, penJoinStyle);
        //t->setFont(("Impact"));
        t->setFont(font);
        t->move(0,70);
        shapes->push_back(t);
    }break;
    }

    this->close();
}


