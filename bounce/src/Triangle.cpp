#include "Triangle.h"
#include "MultiObject.h"

Triangle::Triangle()
{
    //ctor
}

Triangle::~Triangle()
{
    //dtor
}


void Triangle::draw(){
    ofSetColor(color);
    ofSetCircleResolution(3);
    ofCircle(x,y,radius);
}
