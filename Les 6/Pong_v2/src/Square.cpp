#include "Square.h"

Square::Square()
{
    //ctor
}

Square::~Square()
{
    //dtor
}
void Square::setup(){
    x = 10;
    y = (0.5 * ofGetHeight());
    speedY = 1000;

    color.set(255,255,255);

}

void Square::update(int movement){
   if (movement == 1 && y > 0){
        y-=speedY * (1.0 / 60.0);

    }
    else if (movement == 2 && y < (ofGetHeight() - 105)){
        y+=speedY * (1.0 / 60.0);

    }
    else{
        y+=0;

    }

}

void Square::draw(){
    ofSetColor(color);
    ofRect(x, y, 25, 100);
}

