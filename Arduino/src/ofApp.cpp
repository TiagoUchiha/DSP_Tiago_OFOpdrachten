#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofAddListener(arduino.EInitalized,this, &ofApp::setupArduino);
    isArduinoInitialized = false;
    arduino.connect("COM4",57600);
}

//--------------------------------------------------------------
void ofApp::update(){
    arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

}


void ofApp::setupArduino(const int& version){


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
