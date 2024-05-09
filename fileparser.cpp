#include "fileparser.h"

#include <Qt>
#include <QPen>
#include <QFont>
#include <QColor>
#include <QMap>

//using Shapes::shape;
//using std::numeric_limits, std::streamsize;
/*
shape* ReadLine     (std::ifstream&, int shapeId);
shape* ReadPolyLine (std::ifstream&, int shapeId);
shape* ReadPolygon  (std::ifstream&, int shapeId);
shape* ReadRectangle(std::ifstream&, int shapeId);
shape* ReadSquare   (std::ifstream&, int shapeId);
shape* ReadEllipse  (std::ifstream&, int shapeId);
shape* ReadCircle   (std::ifstream&, int shapeId);
shape* ReadText     (std::ifstream&, int shapeId);

//shape get prototypes
Qt::GlobalColor  getColor(const std::string&);
Qt::PenStyle     getPenStyle(const std::string&);
Qt::PenCapStyle  getCapStyle(const std::string&);
Qt::PenJoinStyle getPenJoinStyle(const std::string&);
Qt::BrushStyle   getBrushStyle(const std::string&);
QFont::Weight    getWeight(const std::string&);

//text get prototypes
// using namespace Shapes;
// using namespace Vector;
 using namespace Draw;

Vector::vector<shape*> loadFile(std::string file_name){

    std::ifstream fin;
    fin.open(file_name);
    //int counter = 0;
    std::string temp;
    int shapeId;

    //gets the item id
    while(!fin.eof()){
        fin.ignore(numeric_limits<streamsize>::max(), ':');
        fin >> shapeId;

        switch(shapeId){
        case LINE:
            shapesv.push_back(ReadLine(fin, shapeId));
            break;
        case POLYLINE:
            shapesv.push_back(ReadPolyLine(fin, shapeId));
            break;
        case POLYGON:
            shapesv.push_back(ReadPolygon(fin, shapeId));
            break;
        case RECTANGLE:
            shapesv.push_back(ReadRectangle(fin, shapeId));
            break;
        case SQUARE:
            shapesv.push_back(ReadSquare(fin, shapeId));
            break;
        case ELLIPSE:
            shapesv.push_back(ReadEllipse(fin, shapeId));
            break;
        case CIRCLE:
            shapesv.push_back(ReadCircle(fin, shapeId));
            break;
        case TEXT:
            shapesv.push_back(ReadText(fin, shapeId));
            break;
        default:
            throw std::runtime_error("invalid shape id detected\n");
        }
    }
}

//===================================================
//these functons read from the file and obtain all
//necessary information for the object and the
//returns a base class pointer to be stored in the
//items vector.
shape* ReadLine     (std::ifstream& fin, int shapeId){
    //create temp variables
    int startX, startY, endX, endY, width;
    std::string color, style, cap, join, temp;

    getline(fin, temp); //get rid of shapetype

    //get coords
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin >> startX;
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> startY;
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> endX;
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> endY;

    //get pen color
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, color);
    QColor lineColor(getColor(color));

    //get pen width
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin >> width;

    //get pen style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, style);


    //get pen cap style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, cap);

    //get pen join style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, join);

    QBrush brush(lineColor);
    QPen pen(brush, width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    //create line object and assign values
    Shapes::line* line = new Shapes::line;
    line->setEnd(endX, endY);
    line->setStart(startX, startY);
    //line->setLine(brush, pen, shapeId);

    return line;
}

shape* ReadPolyLine (std::ifstream& fin, int shapeId){
    int width, xpos, ypos;
    std::string color, style, cap, join, temp;

    Shapes::polyline* polyline = new Shapes::polyline;

    getline(fin, temp); //get rid of shapetype

    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin.ignore();
    while (fin >> xpos) {
        fin.ignore(numeric_limits<streamsize>::max(), ',');
        fin >> ypos;

        QPoint getPoint(xpos, ypos);
        polyline->set_point(getPoint);

        if (fin.peek() == ',')
            fin.ignore(numeric_limits<streamsize>::max(), ',');
        else
            break;
    }


    //get pen color
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, color);
    QColor lineColor(getColor(color));

    //get pen width
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin >> width;

    //get pen style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, style);


    //get pen cap style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, cap);

    //get pen join style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, join);

    //create brush and pen objects
    QBrush brush(lineColor);
    QPen pen(brush, width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    //set the polyline object
    //polyline->setPolyline(brush, pen, shapeId);

    //return created polyline
    return polyline;

}

shape* ReadPolygon  (std::ifstream& fin, int shapeId){
    int width, xpos, ypos;
    std::string color, style, cap, join, temp, bColor, bStyle;

    Shapes::polygon* polygon = new Shapes::polygon;

    getline(fin, temp); //get rid of shapetype

    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin.ignore();
    while (fin >> xpos) {
        fin.ignore(numeric_limits<streamsize>::max(), ',');
        fin >> ypos;

        QPoint getPoint(xpos, ypos);
        polygon->set_point(getPoint);

        if (fin.peek() == ',')
            fin.ignore(numeric_limits<streamsize>::max(), ',');
        else
            break;
    }


    //get pen color
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, color);
    QColor lineColor(getColor(color));

    //get pen width
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin >> width;

    //get pen style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, style);

    //get pen cap style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, cap);

    //get pen join style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, join);

    //get brush color
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, bColor);

    //get brush style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, bStyle);

    QColor brushColor(getColor(bColor));
    Qt::BrushStyle brushStyle(getBrushStyle(bStyle));

    //create brush and pen objects
    QBrush brush(brushColor, brushStyle);
    QPen pen(getColor(color), width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    //polygon->setPolygon(brush, pen, shapeId);

    return polygon;
}

shape* ReadRectangle(std::ifstream& fin, int shapeId){

    int penWidth, xpos, ypos, recLength, recWidth;
    std::string color, style, cap, join, temp, bColor, bStyle;

    getline(fin, temp);  //clear shapetype line

    //get x position
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin >> xpos;

    //get y position
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> ypos;

    //get rectangle length
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> recLength;

    //get rectangle width
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> recWidth;

    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, color);
    QColor lineColor(getColor(color));

    //get pen width
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin >> penWidth;

    //get pen style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, style);

    //get pen cap style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, cap);

    //get pen join style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, join);

    //get brush color
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, bColor);

    //get brush style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, bStyle);

    QColor brushColor(getColor(bColor));
    Qt::BrushStyle brushStyle(getBrushStyle(bStyle));

    //create brush and pen objects
    QBrush brush(brushColor, brushStyle);
    QPen pen(getColor(color), penWidth, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    QRect rect(xpos, ypos, recLength, recWidth);

    Shapes::rectangle* rectangle = new Shapes::rectangle;
    rectangle->set_rect(rect);

    return rectangle;


}

shape* ReadSquare   (std::ifstream& fin, int shapeId){
    return 0;
}
shape* ReadEllipse  (std::ifstream& fin, int shapeId){
    return 0;

}

shape* ReadCircle   (std::ifstream& fin, int shapeId){
    return 0;

}

shape* ReadText     (std::ifstream& fin, int shapeId){
    return 0;

}

//===================================================
//get qt items functions

Qt::GlobalColor  getColor(const std::string& color){
    if(color == " white"){
        return Qt::white;
    }
    else if(color == " black"){
        return Qt::black;
    }
    else if(color == " red"){
        return Qt::red;
    }
    else if(color == " green"){
        return Qt::green;
    }
    else if(color == " blue"){
        return Qt::blue;
    }
    else if(color == " cyan"){
        return Qt::cyan;
    }
    else if(color == " magenta"){
        return Qt::magenta;
    }
    else if(color == " yellow"){
        return Qt::yellow;
    }
    else if(color == " gray"){
        return Qt::gray;
    }
    else{
        throw std::runtime_error("invalid color detected\n");
    }
}

Qt::PenStyle     getPenStyle(const std::string& style){
    if(style == " SolidLine"){
        return Qt::SolidLine;
    }
    else if(style == " DashLine"){
        return Qt::DashLine;
    }
    else if(style == " DotLine"){
        return Qt::DotLine;
    }
    else if(style == " DashDotLine"){
        return Qt::DashDotLine;
    }
    else if(style == " DashDotDotLine"){
        return Qt::DashDotDotLine;
    }
    else if(style == " CustomDashLine"){
        return Qt::CustomDashLine;
    }
    else if (style == " SolidLine"){
        return Qt::SolidLine;
    }
    else{
        throw std::runtime_error("invalid pen style detected\n");
    }
}

Qt::PenCapStyle  getCapStyle(const std::string& cap){
    switch(cap[1]){
    case 'F':
        return Qt::FlatCap;
        break;
    case 'S':
        return Qt::SquareCap;
        break;
    case 'R':
        return Qt::RoundCap;
        break;
    default:
        throw std::runtime_error("invalid cap style detected\n");
    }
}

Qt::PenJoinStyle getPenJoinStyle(const std::string& join){
    switch(join[1]){
    case 'M':
        return Qt::MiterJoin;
        break;
    case 'B':
        return Qt::BevelJoin;
        break;
    case 'R':
        return Qt::RoundJoin;
        break;
    default:
        throw std::runtime_error("invalid join style detected\n");
    }
}

Qt::BrushStyle   getBrushStyle(const std::string& brush){
    switch(brush[1]){
    case 'S':
        return Qt::SolidPattern;
        break;
    case 'H':
        return Qt::HorPattern;
        break;
    case 'V':
        return Qt::VerPattern;
        break;
    case 'N':
        return Qt::NoBrush;
        break;
    default:
        throw std::runtime_error("invalid brush style detected\n");
    }
}

//QFont::Weight    getWeight(const std::string&){

//}
*/
