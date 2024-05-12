#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add)
{
    ui->setupUi(this);
    setWindowTitle(tr("Add Shape")); //Sets string to window name

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
    // switch(ui->penStyle->currentIndex()){ //PenStyle
    // case 0:{
    //     penStyle = static_cast<Qt::PenStyle>(0); //NoPen
    // } break;
    // case 1:{
    //     penStyle = static_cast<Qt::PenStyle>(1); //Solid pen
    // } break;
    // case 2:{
    //     penStyle = static_cast<Qt::PenStyle>(2);//Dash
    // } break;
    // case 3:{
    //     penStyle = static_cast<Qt::PenStyle>(3); //Dot
    // } break;
    // case 4:{
    //     penStyle = static_cast<Qt::PenStyle>(4); //Dash Dot
    // } break;
    // case 5:{
    //     penStyle = static_cast<Qt::PenStyle>(5); //Dash Dot Dot
    // } break;
    // }

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
        pl->move(100,150);
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
        p->move(350,270);
    }break;
    case 4:{
        rectangle* r = new rectangle(this);
        r->setId(id);
        r->setCoords(20,200);
        r->setWidth(200);
        r->setHeight(100);
        r->setPen(penColor, penWidth,penStyle, penCapStyle, penJoinStyle);
        r->setBrush(brushColor, brushStyle);
        r->move(50,200);
        shapes->push_back(r);
    }break;
    case 5:{
        ellipse* e = new ellipse(this);
        e->setId(id);
        e->setCoords(300,400);
        e->setWidth(150);
        e->setHeight(100);
        e->setPen(penColor, penWidth,penStyle, penCapStyle, penJoinStyle);
        e->setBrush(brushColor, brushStyle);
        shapes->push_back(e);
    }break;
    case 6:{
        text* t = new text(this);
        t->setId(id);
        t->setSize(16);
        t->setString(QString("2D Graphics Modeler"));
        t->setCoords(100,350);
        t->setWidth(500);
        t->setHeight(50);
        t->setStyle(QFont::Style::StyleNormal);
        t->setWeight(QFont::Weight::Normal);
        t->setPen(Qt::GlobalColor::darkMagenta, 5 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::RoundJoin);
        t->setFont(QString("Impact")); //Font
        t->move(0,100);
        shapes->push_back(t);
    }break;
    }

    this->close();
}


