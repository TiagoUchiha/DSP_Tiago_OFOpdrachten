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
    for(int i; i < ArrayTriangle;i++){
    ofSetColor(color[i]);
    ofSetCircleResolution(10);
    ofCircle(x[i],y[i],radius[i]);
    }
}
