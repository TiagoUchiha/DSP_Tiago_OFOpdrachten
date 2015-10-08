#include "Ball.h"
#include "MultiObject.h"

//MultiObject multiobject;


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
    for(int i; i < ArrayBalls;i++){
    ofSetColor(color[i]);
    ofCircle(x[i], y[i], radius[i]);
    }
}
