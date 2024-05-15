#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include "shapes.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "ellipse.h"
#include "text.h"
#include "vector.h"
#include "draw.h"

enum ShapeType {LINE = 1, POLYLINE, POLYGON, RECTANGLE,
                 SQUARE, ELLIPSE, CIRCLE , TEXT};


Vector::vector<Shapes::shape*> loadFile(std::string);



#endif // FILEPARSER_H
