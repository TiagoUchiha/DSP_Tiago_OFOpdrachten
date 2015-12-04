#include "Ball.h"
#include "MultiObject.h"


// constructor
Ball::Ball()
{
    //ctor
}

Ball::~Ball()
{
    //dtor
}


void Ball::draw(){
    ofSetCircleResolution(20);
    ofSetColor(color);
    ofCircle(x, y, radius);
}
