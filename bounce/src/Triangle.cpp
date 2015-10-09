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
    ofSetCircleResolution(3);
    ofSetColor(color);
    ofCircle(x,y,radius);
}
