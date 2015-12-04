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
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());

    // random snelheid
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);

    radius = ofRandom(10, 20);
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}

void MultiObject::update(){
    // links/ rechts tegen de rand aan? keer om!

    if(x < 0 ) {
        x = 0;
        speedX = -speedX;
    } else if(x > ofGetWidth()) {
        x = ofGetWidth();
        speedX = -speedX;
    }

    // boven/onder tegen de rand aan? keer om!
    if(y < 0 ) {
        y = 0;
        speedY = -speedY;
    } else if(y > ofGetHeight()) {
        y = ofGetHeight();
        speedY = -speedY;
    }


    // bereken nieuwe coordinaten
    x+=speedX;
    y+=speedY;
}


void MultiObject::updateSpeed(float speedXS, float speedYS){
    speedX = speedXS;
    speedY = speedYS;

}
