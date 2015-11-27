//http://forum.openframeworks.cc/t/windows-7-quicktime-error-loading-videos/2882/2
//http://www.slideshare.net/roxlu/openframeworks-007-video

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //totalFrames = video1.getTotalNumFrames();
    //ofLog(OF_LOG_NOTICE,"Potmeter works: "+ ofToString(totalFrames));
    //currentFrame = 0;

    for (int i=0; i < 5; i++){
        string name = "image00" + ofToString(i+1) + ".jpg";
        image[i].loadImage(name);
    }

    for (int i=0; i < 5; i++){
        soundPaused[i] = true;
        string name2 = "track00" + ofToString(i+1) + ".mp3";
        sound[i].loadSound(name2);
        sound[i].setVolume(1);
        sound[i].play();
        sound[i].setPaused(soundPaused[i]);
    }
    ofSoundSetVolume(0.2);
    uiTop.loadImage("front.gif");
    uiDown.loadImage("down.gif");
    uiInfo.loadImage("info.gif");
    width = ofGetWidth();
    height = ofGetHeight();
    totalPlay = 1;
    everythingPause = true;

    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    isArduinoInitialized = false;

    arduino.connect("COM4",57600);
    arduino.sendFirmwareVersionRequest();
}

//--------------------------------------------------------------
void ofApp::update(){
    uiTop.update();
    uiDown.update();
    uiInfo.update();
    ofSoundUpdate();

    if (lightValue < 100){
        everythingPause = false;
        for(int i =0; i < 5; i++){
            playCheck = sound[i].getIsPlaying();
            if (playCheck == false){
                soundPaused[i+1] = false;
                sound[i+1].setPaused(soundPaused[i+1]);
                image[i+1].update();
            }
            else{
            }
        }
    }
    else{
        everythingPause = true;
        for(int i =0; i < 5; i++){
            soundPaused[i] = true;
            sound[i].setPaused(soundPaused[i]);
            image[i].update();
        }
    }
    arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,255);

    if(soundPaused[0] == false){
        image[0].resize(width,height);
        image[0].draw(0,0);
       /* arduino.sendDigital(3, ARD_HIGH);
        arduino.sendDigital(7, ARD_LOW);
        arduino.sendDigital(6, ARD_LOW);
        arduino.sendDigital(5, ARD_LOW);
        arduino.sendDigital(4, ARD_LOW);*/
    }
    if(soundPaused[1] == false){
        image[1].draw(0,0);
        /*arduino.sendDigital(4, ARD_HIGH);
        arduino.sendDigital(3, ARD_LOW);
        arduino.sendDigital(7, ARD_LOW);
        arduino.sendDigital(6, ARD_LOW);
        arduino.sendDigital(5, ARD_LOW);*/

    }
    if(soundPaused[2] == false){
        image[2].draw(0,0);
        /*arduino.sendDigital(5, ARD_HIGH);
        arduino.sendDigital(4, ARD_LOW);
        arduino.sendDigital(3, ARD_LOW);
        arduino.sendDigital(7, ARD_LOW);
        arduino.sendDigital(6, ARD_LOW);*/

    }
    if(soundPaused[3] == false){
        image[3].draw(0,0);
        /*arduino.sendDigital(6, ARD_HIGH);
        arduino.sendDigital(5, ARD_LOW);
        arduino.sendDigital(4, ARD_LOW);
        arduino.sendDigital(3, ARD_LOW);
        arduino.sendDigital(7, ARD_LOW);*/

    }
    if(soundPaused[4] == false){
        image[4].resize(width,height);
        image[4].draw(0,0);
       /* arduino.sendDigital(7, ARD_HIGH);
        arduino.sendDigital(6, ARD_LOW);
        arduino.sendDigital(5, ARD_LOW);
        arduino.sendDigital(4, ARD_LOW);
        arduino.sendDigital(3, ARD_LOW);*/

    }
    ofDisableAlphaBlending;

    ofEnableAlphaBlending();
    ofSetColor(255,255,255,127);
    uiTop.draw(0,0);
    uiDown.draw(0, height-300);
    ofSetColor(255,255,255,255);
    uiInfo.draw(width-530, height-305);
    ofDisableAlphaBlending;



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
    arduino.sendDigitalPinMode(7, ARD_OUTPUT);
    arduino.sendDigitalPinMode(6, ARD_OUTPUT);
    arduino.sendDigitalPinMode(5, ARD_OUTPUT);
    arduino.sendDigitalPinMode(4, ARD_OUTPUT);
    arduino.sendDigitalPinMode(3, ARD_OUTPUT);

    arduino.sendDigitalPinMode(9, ARD_OUTPUT);
    arduino.sendDigitalPinMode(10, ARD_OUTPUT);
    arduino.sendDigitalPinMode(11, ARD_OUTPUT);
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

    if (lightValue < 100){
        arduino.sendDigital(10, ARD_HIGH);
        arduino.sendDigital(11, ARD_LOW);
        arduino.sendDigital(9, ARD_LOW);
        soundPaused[0] = false;
        sound[0].setPaused(soundPaused[0]);
    }
    else if (lightValue < 400 && lightValue > 100){
        arduino.sendDigital(10, ARD_LOW);
        arduino.sendDigital(11, ARD_LOW);
        arduino.sendDigital(9, ARD_HIGH);
    }
    else {
        arduino.sendDigital(10, ARD_LOW);
        arduino.sendDigital(11, ARD_HIGH);
        arduino.sendDigital(9, ARD_LOW);
    }

    if(soundPaused[0] == false){
        for(int i = 3; i < 8; i++){
            arduino.sendDigital(i, ARD_LOW);
        }
        arduino.sendDigital(3, ARD_HIGH);
    }
    if(soundPaused[1] == false){
        for(int i = 3; i < 8; i++){
            arduino.sendDigital(i, ARD_LOW);
        }
        arduino.sendDigital(4, ARD_HIGH);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
 /*   if (arduino.isInitialized()){
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
    */
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
