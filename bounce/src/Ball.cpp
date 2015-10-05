#include "Ball.h"

Ball::Ball()
{
    //ctor
}

Ball::~Ball()
{
    //dtor
}

void Ball::setup(){
    // kies random start coordinaten
    for (int i; i < ArrayBalls; i++){
    x[i] = ofRandom(0, ofGetWidth());
    y[i] = ofRandom(0, ofGetHeight());

    // random snelheid
    speedX[i] = ofRandom(-10, 10);
    speedY[i] = ofRandom(-10, 10);

    // grootte van cirkel
    radius[i] = 40;
    color[i].set(ofRandom(255),ofRandom(255),ofRandom(255));
    }
}


void Ball::update(){
    for(int i; i < ArrayBalls; i++){
    // links/ rechts tegen de rand aan? keer om!
    if(x[i] < 0 ) {
        x[i] = 0;
        speedX[i] = -speedX[i];
    } else if(x[i] > ofGetWidth()) {
        x[i] = ofGetWidth();
        speedX[i] = -speedX[i];
    }

    // boven/onder tegen de rand aan? keer om!
    if(y[i] < 0 ) {
        y[i] = 0;
        speedY[i] = -speedY[i];
    } else if(y[i] > ofGetHeight()) {
        y[i] = ofGetHeight();
        speedY[i] = -speedY[i];
    }


    // bereken nieuwe coordinaten
    x[i]+=speedX[i];
    y[i]+=speedY[i];
    }
}


void Ball::draw(){
    for(int i; i < ArrayBalls;i++){
    ofSetColor(color[i]);
    ofCircle(x[i], y[i], radius[i]);
    }
}
