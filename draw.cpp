#include "draw.h"
using namespace Draw;
//using namespace std;
void draw::drawShapes()
{

    //QPainter painter(this);
    line* l = new line(this);
    l->setId(1);
    l->setCoords(20,50);
    l->setStart(20,100);
    l->setEnd(100,20);
    l->setPen(Qt::GlobalColor::red, 4 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::MiterJoin);
    l->setBrush(Qt::GlobalColor::red, Qt::VerPattern);
    //l->move(200,200);
    shapes.push_back(l);

    polyline* pl = new polyline(this);
    pl->setId(2);
    //pl->setCoords(100,50);
    pl->set_point(QPoint(460,90));
    pl->set_point(QPoint(470,20));
    pl->set_point(QPoint(530,40));
    pl->set_point(QPoint(540,80));
    pl->set_point(QPoint(500,100));
    pl->setPen(Qt::GlobalColor::blue, 6 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    pl->setBrush(Qt::GlobalColor::red, Qt::VerPattern);
    pl->move(-300,0); //Translates shape next to shape 1
    shapes.push_back(pl);

    polygon* p = new polygon(this);
    p->setId(3);
    p->set_point(QPoint(100,100));
    p->set_point(QPoint(250,100));
    p->set_point(QPoint(200,200));
    p->set_point(QPoint(50,200));
    p->setPen(Qt::GlobalColor::black, 3 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    p->setBrush(Qt::GlobalColor::red, Qt::SolidPattern);
    shapes.push_back(p);
    p->move(200,-70); //Translates shape next to shape 2
    //p->draw(painter, this);

    rectangle* r = new rectangle(this);
    r->setId(4);
    r->setCoords(20,200);
    r->setWidth(200);
    r->setHeight(100);
    r->setPen(Qt::GlobalColor::darkCyan, 3 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin);
    r->setBrush(Qt::GlobalColor::lightGray, Qt::CrossPattern);
    shapes.push_back(r);
    //r->draw(painter, this);

    ellipse* e = new ellipse(this);
    e->setId(5);
    e->setCoords(320,200);
    e->setWidth(150);
    e->setHeight(100);
    e->setPen(Qt::GlobalColor::black, 5 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    e->setBrush(Qt::GlobalColor::gray, Qt::SolidPattern);
    shapes.push_back(e);
    //e->draw(painter,this);

    text* t = new text(this);
    t->setId(6);
    t->setSize(16);
    t->setString(QString("2D Graphics Modeler"));
    t->setCoords(100,350);
    t->setWidth(500);
    t->setHeight(50);
    t->setStyle(QFont::Style::StyleNormal);
    t->setWeight(QFont::Weight::Normal);
    //t->setPen(Qt::GlobalColor::blue, 5 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::RoundJoin);
    t->setFont(QString("Impact")); //Font
    shapes.push_back(t);
    //t->draw(painter,this);*/

    //this->update();

}

void draw::addShape(shape *shapePtr){

    shapes.push_back(shapePtr);

    //int id = shapePtr->getId();
    //std::cout << id << std::endl;

}

void draw::clearShapes(){
    shapes.clear();
}

void draw::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for (int i = 0; i < shapes.size(); ++i) {
        //shapes[i]->draw(painter,this);
        shape::shapeType shapeT = shapes[i]->getShape();

        switch(shapeT){
    case 1: {
        shapes[i]->draw(painter,this);
            //std::cout << "Line print\n";
            }
            break;

    case 2: {
        shapes[i]->draw(painter,this);

    } break;

    case 3: {
        shapes[i]->draw(painter,this);

    }     break;

    case 4: {
        shapes[i]->draw(painter,this);

    }    break;

    case 5: {
        shapes[i]->draw(painter,this);

        //std::cout << "Ellipse print\n";

    }    break;

    case 6: {
        painter.setPen(Qt::GlobalColor::darkMagenta);
        shapes[i]->draw(painter,this);

            }    break;

    default:{
            std::cout << "Error; invalid shape ID\n";
        } break;
    }


        //getShapeList()[i]->draw(painter, this);
        // shapes[i]->setPen(Qt::GlobalColor::darkMagenta, 5 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::RoundJoin);
        // shapes[i]->setBrush(Qt::GlobalColor::black, Qt::VerPattern);
        // shapes[i]->setPen(Qt::GlobalColor::darkMagenta, 5 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::RoundJoin);
        // shapes[i]->setString(QString("2D Graphics Modeler"));

        //shapes[i]->draw(painter, this);

    }
/*
    line* l = new line(this);
    l->setId(1);
    l->setCoords(20,50);
    l->setStart(20,100);
    l->setEnd(100,20);
    l->setPen(Qt::GlobalColor::red, 4 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::MiterJoin);
    l->setBrush(Qt::GlobalColor::red, Qt::VerPattern);
    shapes.push_back(l);
    l->draw(painter, this);

    polyline* pl = new polyline(this);
    pl->setId(2);
    //pl->setCoords(100,50);
    pl->set_point(QPoint(460,90));
    pl->set_point(QPoint(470,20));
    pl->set_point(QPoint(530,40));
    pl->set_point(QPoint(540,80));
    pl->set_point(QPoint(500,100));
    pl->setPen(Qt::GlobalColor::blue, 6 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    pl->setBrush(Qt::GlobalColor::red, Qt::VerPattern);
    shapes.push_back(pl);
    pl->move(-300,0); //Translates shape next to shape 1
    pl->draw(painter, this);

    polygon* p = new polygon(this);
    p->setId(3);
    p->set_point(QPoint(100,100));
    p->set_point(QPoint(250,100));
    p->set_point(QPoint(200,200));
    p->set_point(QPoint(50,200));
    p->setPen(Qt::GlobalColor::black, 3 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    p->setBrush(Qt::GlobalColor::red, Qt::SolidPattern);
    shapes.push_back(p);
    p->move(200,-70); //Translates shape next to shape 2
    p->draw(painter, this);

    rectangle* r = new rectangle(this);
    r->setId(4);
    r->setCoords(20,200);
    r->setWidth(200);
    r->setHeight(100);
    r->setPen(Qt::GlobalColor::darkCyan, 3 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin);
    r->setBrush(Qt::GlobalColor::lightGray, Qt::CrossPattern);
    shapes.push_back(r);
    r->draw(painter, this);

    ellipse* e = new ellipse(this);
    e->setId(5);
    e->setCoords(320,200);
    e->setWidth(150);
    e->setHeight(100);
    e->setPen(Qt::GlobalColor::black, 5 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::MiterJoin);
    e->setBrush(Qt::GlobalColor::white, Qt::NoBrush);
    shapes.push_back(e);
    e->draw(painter,this);

    text* t = new text(this);
    t->setId(6);
    t->setSize(16);
    t->setString(QString("2D Graphics Modeler"));
    t->setCoords(100,350);
    t->setWidth(500);
    t->setHeight(50);
    t->setStyle(QFont::Style::StyleNormal);
    t->setWeight(QFont::Weight::Normal);
    t->setPen(Qt::GlobalColor::darkMagenta, 5 ,Qt::PenStyle::SolidLine, Qt::PenCapStyle::FlatCap, Qt::PenJoinStyle::RoundJoin);
    t->setFont(QString("Impact")); //Font
    shapes.push_back(t);
    t->draw(painter,this);*/

//    QWidget::setUpdatesEnabled(true);
}

void draw::setShapeList(vector<shape *> old)
{
    shapes = old;
}

vector<shape*>& draw::getShapeList()
{
    return this->shapes;
}

/*
QSize draw::minimumSizeHint() const
{
    return QSize(1000, 500);
}

QSize draw::sizeHint() const
{
    return QSize(1000, 500);
}

void draw::addShape(shape *s)
{
    shapes.push_back(s);
}

void draw::clearShapes()
{
    shapes.resize(0);
    update();
}
*/
