#include "MultiObject.h"

MultiObject::MultiObject()
{
    //ctor
}

MultiObject::~MultiObject()
{
    //dtor
}

void MultiObject::setup(){
    x = ofGetWidth() - 50;
    y = (0.5 * ofGetHeight());
    speedY = 1000;

    color.set(255,255,255);
}


void MultiObject::draw(){
    ofSetColor(color);
    ofRect(x, y, 25, 100);
}


void MultiObject::update(int ballY){
    if (y < 0 ){
        y = 0;
    }
    else if (ballY > (ofGetHeight() - 100)){
        y = ofGetHeight() - 100;
    }
    else{
        y = ballY - 20;
    }
}
