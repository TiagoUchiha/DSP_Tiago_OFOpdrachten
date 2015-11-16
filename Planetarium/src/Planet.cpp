#include "Planet.h"

Planet::Planet()
{
    //ctor
    rotation = 0.0;
}

Planet::~Planet()
{
    //dtor
}


void Planet::setup(string name){
    planetParamGroup.setName(name);
    planetParamGroup.add(rotateSpeed.set("speed",0,0,9.0));
    planetParamGroup.add(distance.set("distance",0,0,900));
    planetParamGroup.add(red.set("R",255,0,255));;
    planetParamGroup.add(green.set("G",255,0,255));
    planetParamGroup.add(blue.set("B",255,0,255));


}

void Planet::update(){
    rotation++;
}

void Planet::draw(){
    ofSetColor(red,green,blue);
    ofRotate(rotation* rotateSpeed);
    ofSphere(distance,0,0,30);

}
