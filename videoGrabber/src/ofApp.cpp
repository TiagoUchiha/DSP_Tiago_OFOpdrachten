#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gabbie.listDevices();
    gabbie.setDeviceID(0);
    gabbie.setDesiredFrameRate(30);

    gabbie.initGrabber(320,240);


}

//--------------------------------------------------------------
void ofApp::update(){
    gabbie.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    gabbie.draw(0,0);
    ofTranslate(100,100);
    ofRotateX(20);
    gabbie.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
