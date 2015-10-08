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
    ofTriangle(x[i], y[i], y[i], 10, 90, 10);
    }
}
