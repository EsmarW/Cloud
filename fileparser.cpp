#include "fileparser.h"

#include <Qt>
#include <QPen>
#include <QFont>
#include <QColor>
#include <QMap>
#include <QFile>
#include <QResource>
#include <QTemporaryFile>

using Shapes::shape;
using std::numeric_limits, std::streamsize, std::cout, std::endl;

shape* ReadLine     (std::ifstream&, int shapeId);
shape* ReadPolyLine (std::ifstream&, int shapeId);
shape* ReadPolygon  (std::ifstream&, int shapeId);
shape* ReadRectangle(std::ifstream&, int shapeId);
shape* ReadSquare   (std::ifstream&, int shapeId);
shape* ReadEllipse  (std::ifstream&, int shapeId);
shape* ReadCircle   (std::ifstream&, int shapeId);
shape* ReadText     (std::ifstream&, int shapeId);

//shape get prototypes
Qt::GlobalColor   getColor(const std::string&);
Qt::PenStyle      getPenStyle(const std::string&);
Qt::PenCapStyle   getCapStyle(const std::string&);
Qt::PenJoinStyle  getPenJoinStyle(const std::string&);
Qt::BrushStyle    getBrushStyle(const std::string&);
QFont::Weight     getWeight(const std::string&);
QFont::Style      getFontStyle(const std::string& style);
Qt::AlignmentFlag getAlignment(const std::string& align);

//text get prototypes

Vector::vector<shape*> loadFile(std::string file_name){
    Vector::vector<Shapes::shape*> fileShapes;
    std::ifstream fin(file_name);
    //std::ifstream fin;
    //fin.open("shapes.txt");

    if (!fin.is_open()) {
        throw std::runtime_error("Error opening fstream file...\n");;
    }

    std::string temp;
    int shapeId;

    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, temp);
    //gets the item id
    while(fin >> shapeId){
        getline(fin, temp);

        switch(shapeId){
        case LINE:
            fileShapes.push_back(ReadLine(fin, shapeId));
            break;
        case POLYLINE:
            fileShapes.push_back(ReadPolyLine(fin, shapeId));
            break;
        case POLYGON:
            fileShapes.push_back(ReadPolygon(fin, shapeId));
            break;
        case RECTANGLE:
            fileShapes.push_back(ReadRectangle(fin, shapeId));
            break;
        case SQUARE:
            fileShapes.push_back(ReadSquare(fin, shapeId));
            break;
        case ELLIPSE:
            //fileShapes.push_back(ReadEllipse(fin, shapeId));
            break;
        case CIRCLE:
            //fileShapes.push_back(ReadCircle(fin, shapeId));
            break;
        case TEXT:
            //fileShapes.push_back(ReadText(fin, shapeId));
            break;
        default:
            throw std::runtime_error("invalid shape id detected\n");
        }
        getline(fin, temp);
        fin.ignore(numeric_limits<streamsize>::max(), ':');
    }
    fin.close();
    return fileShapes;
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
    cout << startX << ", ";
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> startY;
    cout << startY << ", ";
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> endX;
    cout << endX << ", ";
    fin.ignore(numeric_limits<streamsize>::max(), ',');
    fin >> endY;
    cout << endY << endl;

    //get pen color
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, color);
    cout << color << endl;
    QColor lineColor(getColor(color));

    //get pen width
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    fin >> width;
    cout << width << endl;

    //get pen style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, style);
    cout << style << endl;

    //get pen cap style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, cap);
    cout << cap << endl;

    //get pen join style
    fin.ignore(numeric_limits<streamsize>::max(), ':');
    getline(fin, join);
    cout << join << endl;

    QBrush brush(lineColor);
    QPen pen(brush, width, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    //create line object and assign values
    Shapes::line* line = new Shapes::line;
    line->setEnd(endX, endY);
    line->setStart(startX, startY);
    line->setPen(pen);
    line->setBrush(brush);
    line->setId(shapeId);

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
    polyline->setBrush(brush);
    polyline->setPen(pen);
    polyline->setId(shapeId);

    //return created polyline
    return polyline;

}

shape* ReadPolygon  (std::ifstream& fin, int shapeId){
    int width, xpos, ypos;
    std::string color, style, cap, join, temp, bColor, bStyle;

    Shapes::polygon* polygon = new Shapes::polygon;

    getline(fin, temp);

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

    polygon->setBrush(brush);
    polygon->setPen(pen);
    polygon->setId(shapeId);

    return polygon;
}

shape* ReadRectangle(std::ifstream& fin, int shapeId)
{

    int penWidth, xpos, ypos, recLength, recWidth;
    std::string color, style, cap, join, temp, bColor, bStyle;

    getline(fin, temp);

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
    rectangle->setBrush(brush);
    rectangle->setPen(pen);
    rectangle->setId(shapeId);

    return rectangle;


}

shape* ReadSquare(std::ifstream& fin, int shapeId) {
    int penWidth, xpos, ypos, sideLength;
    std::string color, style, cap, join, temp, bColor, bStyle;

    getline(fin, temp);

    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    fin >> xpos;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> ypos;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> sideLength;

    // Get pen color
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, color);
    QColor lineColor(getColor(color));

    // Get pen width
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    fin >> penWidth;

    // Get pen style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, style);

    // Get pen cap style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, cap);

    // Get pen join style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, join);

    // Get brush color
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, bColor);

    // Get brush style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, bStyle);

    QColor brushColor(getColor(bColor));
    Qt::BrushStyle brushStyle(getBrushStyle(bStyle));

    // Create brush and pen objects
    QBrush brush(brushColor, brushStyle);
    QPen pen(lineColor, penWidth, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    // Create the square object
    QRect rect(xpos, ypos, sideLength, sideLength);
    Shapes::rectangle* square = new Shapes::rectangle;
    square->setRect(rect);
    square->setBrush(brush);
    square->setPen(pen);
    square->setId(shapeId);

    return square;
}

shape* ReadEllipse(std::ifstream& fin, int shapeId) {
    int penWidth, xpos, ypos, width, height;
    std::string color, style, cap, join, temp, bColor, bStyle;

    getline(fin, temp);

    // Get coordinates and dimensions
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    fin >> xpos;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> ypos;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> width;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> height;

    // Get pen color
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, color);
    QColor lineColor(getColor(color));

    // Get pen width
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    fin >> penWidth;

    // Get pen style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, style);

    // Get pen cap style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, cap);

    // Get pen join style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, join);

    // Get brush color
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, bColor);

    // Get brush style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, bStyle);

    QColor brushColor(getColor(bColor));
    Qt::BrushStyle brushStyle(getBrushStyle(bStyle));

    // Create brush and pen objects
    QBrush brush(brushColor, brushStyle);
    QPen pen(lineColor, penWidth, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));
    QRect rect(xpos, ypos, width, height);

    // Create and configure the ellipse object
    Shapes::ellipse* ellipse = new Shapes::ellipse;
    ellipse->setRect(rect);
    ellipse->setBrush(brush);
    ellipse->setPen(pen);
    ellipse->setId(shapeId);

    return ellipse;
}

/*
shape* ReadCircle(std::ifstream& fin, int shapeId) {
    int penWidth, centerX, centerY, radius;
    std::string color, style, cap, join, temp, bColor, bStyle;

    getline(fin, temp);

    // Get center coordinates and radius
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    fin >> centerX;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> centerY;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> radius;

    // Get pen color
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, color);
    QColor lineColor(getColor(color));

    // Get pen width
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    fin >> penWidth;

    // Get pen style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, style);

    // Get pen cap style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, cap);

    // Get pen join style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, join);

    // Get brush color
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, bColor);

    // Get brush style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, bStyle);

    QColor brushColor(getColor(bColor));
    Qt::BrushStyle brushStyle(getBrushStyle(bStyle));

    // Create brush and pen objects
    QBrush brush(brushColor, brushStyle);
    QPen pen(lineColor, penWidth, getPenStyle(style), getCapStyle(cap), getPenJoinStyle(join));

    // Create  the circle object
    Shapes::circle* circle = new Shapes::circle;
    circle->setCircle(centerX, centerY, radius);
    circle->setShapeProperties(brush, pen, shapeId);

    return circle;
}


shape* ReadText(std::ifstream& fin, int shapeId) {
    int x, y, width, height, pointSize;
    std::string textColor, alignment, fontFamily, fontStyle, fontWeight, temp, textString;

    getline(fin, temp);

    // Get  box dimensions
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    fin >> x;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> y;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> width;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    fin >> height;

    // Get text string
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, textString);

    // Get text color
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, textColor);

    // Get text alignment
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, alignment);

    // Get text point size
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    fin >> pointSize;

    // Get text font family
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, fontFamily);

    // Get text font style
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, fontStyle);

    // Get text font weight
    fin.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    getline(fin, fontWeight);

    QColor color(getColor(textColor));
    QFont font(fontFamily.c_str(), pointSize, getWeight(fontWeight));
    QFont::Style style = getFontStyle(fontStyle);

    font.setStyle(style);

    // Create  the text object
    Shapes::text* text = new Shapes::text;
    text->setText(textString);
    text->setTextColor(color);
    text->setFont(font);
    text->setAlignment(getAlignment(alignment));
    text->setPosition(x, y);
    text->setSize(width, height);
    text->setShapeProperties(shapeId);

    return text;
}
*/
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

Qt::PenStyle getPenStyle(const std::string& style){
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

Qt::PenCapStyle getCapStyle(const std::string& cap){
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

Qt::BrushStyle getBrushStyle(const std::string& brush){
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

QFont::Weight getWeight(const std::string& weight)
{
    if (weight == " Normal"){
        return QFont::Normal;
    }
    else if (weight == " Bold") {
        return QFont::Bold;
    }
    else if (weight == " Thin") {
        return QFont::Thin;
    }
    else if (weight == " Light") {
        return QFont::Light;
    }
    else throw std::runtime_error("invalid font weight detected\n");
}

QFont::Style getFontStyle(const std::string& style)
{
    if (style == " StyleNormal"){
        return QFont::StyleNormal;
    }
    else if (style == " StyleItalic"){
        return QFont::StyleItalic;
    }
    else if (style == " StyleOblique"){
        return QFont::StyleOblique;
    }
    else throw std::runtime_error("invalid font style detected\n");
}
Qt::AlignmentFlag getAlignment(const std::string& align)
{
    if (align == " AlignLeft"){
        return Qt::AlignLeft;
    }
    else if (align == " AlignCenter"){
        return Qt::AlignCenter;
    }
    else if (align == " AlignRight"){
        return Qt::AlignRight;
    }
    else if (align == " AlignTop"){
        return Qt::AlignTop;
    }
    else if (align == " AlignBottom"){
        return Qt::AlignBottom;
    }
    else throw std::runtime_error("invalid alignment detected\n");
}


