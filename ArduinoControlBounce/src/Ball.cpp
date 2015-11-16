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
    x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());

    speedX = ofRandom(-10,10);           // and random speed and direction
    speedY = ofRandom(-10,10);

    radius = 20;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}


void Ball::update(ofArduino* arduino){
    if(x < 0 ){
        x = 0;
        speedX *= -1;
        arduino->sendDigital(12,ARD_HIGH);
   } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
        arduino->sendDigital(12,ARD_LOW);

    }

    if(y < 0 ){
        y = 0;
        speedY *= -1;
        arduino->sendDigital(12,ARD_HIGH);
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
        arduino->sendDigital(12,ARD_LOW);
    }

    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
    ofSetColor(color);
    ofCircle(x, y, radius);
}


void Ball::speedChange(float newSpeed){
    //speedY = newSpeed;
    //speedX = newSpeed;
    if(speedX > 0 ){
        speedX = newSpeed;
   } else {
        speedX = -newSpeed;
    }

    if(speedY > 0){
        speedY = newSpeed;
    } else {
        speedY = -newSpeed;
    }
}

