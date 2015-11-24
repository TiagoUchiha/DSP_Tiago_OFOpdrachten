//http://forum.openframeworks.cc/t/windows-7-quicktime-error-loading-videos/2882/2
//http://www.slideshare.net/roxlu/openframeworks-007-video

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video1.loadMovie("video001.mov");
    //video1.play();
    totalFrames = video1.getTotalNumFrames();
    currentFrame = 0;

    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    isArduinoInitialized = false;

    arduino.connect("COM4",57600);
    arduino.sendFirmwareVersionRequest();
}

//--------------------------------------------------------------
void ofApp::update(){

    if (lightValue < 50){
        video1.play();
        arduino.sendDigital(12, ARD_HIGH);
    }
    else{
        video1.stop();
        arduino.sendDigital(12, ARD_LOW);
    }
    arduino.update();
    video1.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    video1.draw(0,0,1920,1080);
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
    arduino.sendAnalogPinReporting(0,ARD_ANALOG);

    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);

}
void ofApp::digitalPinChanged(const int& pinNum) {
    // get value with arduino.getDigital(pinNum)
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
    lightValue = arduino.getAnalog(pinNum);

    ofLog(OF_LOG_NOTICE,"Lightsensor works: "+ ofToString(lightValue));
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (arduino.isInitialized()){
        if (key == 'p'){
            if(videoPause == true){
                video1.setPaused(false);
                videoPause = false;
            }
            else{
                video1.setPaused(true);
                videoPause = true;
            }
        }
        if (key == 'n'){
            video1.nextFrame();
            currentFrame = video1.getCurrentFrame();
        }
        if (key == 'b'){
            video1.previousFrame();
            currentFrame = video1.getCurrentFrame();
        }
        if (key == 'f'){
            if (currentFrame < totalFrames){
                video1.setFrame((currentFrame+10));
                currentFrame = video1.getCurrentFrame();
            }
        }
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
