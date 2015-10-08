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
    for(int i; i < 5;i++){
    ofSetColor(color[i]);
    ofRect(x[i], y[i], squaresize, squaresize);
    }
}
