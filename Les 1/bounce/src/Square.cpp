#include "Square.h"
#include "MultiObject.h"
//Square  moet eigenlijk rectangle zijn


Square::Square()
{
    //ctor
}

Square::~Square()
{
    //dtor
}

void Square::draw(){
    ofSetColor(color);
    ofRect(x, y, squaresize, squaresize);
}
