#include "ofApp.h"
#include "Ball.h"

Ball ball;

//--------------------------------------------------------------
void ofApp::setup(){
    ball.setup();
    ofSetFrameRate(30);
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    isArduinoInitialized = false;

    arduino.connect("COM4",57600);
    arduino.sendFirmwareVersionRequest();
}

//--------------------------------------------------------------
void ofApp::update(){
    arduino.update();
    ball.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball.draw();
}


void ofApp::setupArduino(const int& version){
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    // set flag: Arduino now ready for use
    isArduinoInitialized = true;

    // print firmware name and version to the console
  /* ofLogNotice() << "Arduino firmware found: " << arduino.getFirmwareName()
                 << "v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();
*/
    arduino.sendDigitalPinMode(12, ARD_OUTPUT);

    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}

void ofApp::digitalPinChanged(const int& pinNum) {
    // get value with arduino.getDigital(pinNum)
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'w'){
        arduino.sendDigital(12, ARD_HIGH); // this will switch the on-board Arduino LED on
    }
    else{
                arduino.sendDigital(12, ARD_LOW); // this will switch the on-board Arduino LED on

    }
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
        arduino.sendDigital(12, ARD_HIGH); // this will switch the on-board Arduino LED on
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
        arduino.sendDigital(12, ARD_LOW); // this will switch the on-board Arduino LED off
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

