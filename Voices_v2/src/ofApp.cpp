#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i=0;i<VOICES;i++){
        voicePaused[i] = true;
        ofLogNotice() << "Loading voice" << i << endl;
        voicePlayer[i].loadSound("vox"+ofToString(i+1)+".wav");
        voicePlayer[i].setLoop(true);
        voicePlayer[i].setVolume(1);
        voicePlayer[i].play();
        voicePlayer[i].setPaused(true);
    }
    ofSoundSetVolume(0.2);
    speedBoard.loadFont("arial.ttf",20);
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    float x = time*0.1 + 30;
    for (int i=0;i<VOICES; i++) {
        float y = i * 0.02;
        float volume = ofNoise(x,y);
        voicePlayer[i].setVolume(volume);
    }
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30,30,30);
    currentSpeed1 = voicePlayer[0].getSpeed();
    currentSpeed2 = voicePlayer[1].getSpeed();
    currentSpeed3 = voicePlayer[2].getSpeed();
    currentSpeed4 = voicePlayer[3].getSpeed();
    currentSpeed5 = voicePlayer[4].getSpeed();
    currentSpeed6 = voicePlayer[5].getSpeed();

    string1 ="Speed: 1: " + ofToString(currentSpeed1) + "X / 2: " + ofToString(currentSpeed2) + "X /";
    string2 =" 3: " + ofToString(currentSpeed3) + "X / 4: " + ofToString(currentSpeed4) + "X /";
    string3 =" 5: " + ofToString(currentSpeed5) + "X / 6: " + ofToString(currentSpeed6) + "X";

    speedBoard.drawString(ofToString(string1 + string2 + string3),20,20);


    ofPushMatrix();
    for( int i=0; i<VOICES;i++) {
        if(!voicePaused[i]) {
            ofSetColor(128+i*20, i*80, i*10+60);
            ofRect(100, i*30+200, voicePlayer[i].getVolume()*300, 5);
        }
    }
    ofPopMatrix();
    ofSetColor(255,255,255);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
        if (key == 'h'){
            if (checkKey == 1 && currentSpeed1 < 30){
                voicePlayer[0].setSpeed(currentSpeed1+1);
            }
            else if (checkKey == 2 && currentSpeed2 < 30){
                voicePlayer[1].setSpeed(currentSpeed2+1);
            }
            else if (checkKey == 3 && currentSpeed3 < 30){
                voicePlayer[2].setSpeed(currentSpeed3+1);
            }
            else if (checkKey == 4 && currentSpeed4 < 30){
                voicePlayer[3].setSpeed(currentSpeed4+1);
            }
            else if (checkKey == 5 && currentSpeed5 < 30){
                voicePlayer[4].setSpeed(currentSpeed5+1);
            }
            else if (checkKey == 6 && currentSpeed6 < 30){
                voicePlayer[5].setSpeed(currentSpeed6+1);
            }
        }
        else if (key == 'g'){
            if (checkKey == 1 && currentSpeed1 > -30){
                voicePlayer[0].setSpeed(currentSpeed1-1);
            }
            else if (checkKey == 2 && currentSpeed2 > -30){
                voicePlayer[1].setSpeed(currentSpeed2-1);
            }
            else if (checkKey == 3 && currentSpeed3 > -30){
                voicePlayer[2].setSpeed(currentSpeed3-1);
            }
            else if (checkKey == 4 && currentSpeed4 > -30){
                voicePlayer[3].setSpeed(currentSpeed4-1);
            }
            else if (checkKey == 5 && currentSpeed5 > -30){
                voicePlayer[4].setSpeed(currentSpeed5-1);
            }
            else if (checkKey == 6 && currentSpeed6 > -30){
                voicePlayer[5].setSpeed(currentSpeed6-1);
            }

        }

    if(key=='1'){
        currentSpeed1 = voicePlayer[0].getSpeed();
        voicePaused[0] = !voicePaused[0];
        voicePlayer[0].setPaused(voicePaused[0]);
        checkKey = 1;
    }
    else if(key=='2'){
        currentSpeed2 = voicePlayer[1].getSpeed();
        voicePaused[1] = !voicePaused[1];
        voicePlayer[1].setPaused(voicePaused[1]);
        checkKey = 2;
    }
    else if(key=='3'){
        currentSpeed3 = voicePlayer[2].getSpeed();
        voicePaused[2] = !voicePaused[2];
        voicePlayer[2].setPaused(voicePaused[2]);
        checkKey = 3;
    }
    else if(key=='4'){
        currentSpeed4 = voicePlayer[3].getSpeed();
        voicePaused[3] = !voicePaused[3];
        voicePlayer[3].setPaused(voicePaused[3]);
        checkKey = 4;

    }
    else if(key=='5'){
        currentSpeed5 = voicePlayer[4].getSpeed();
        voicePaused[4] = !voicePaused[4];
        voicePlayer[4].setPaused(voicePaused[4]);
        checkKey = 5;
    }
    else if(key=='6'){
        currentSpeed6 = voicePlayer[5].getSpeed();
        voicePaused[5] = !voicePaused[5];
        voicePlayer[5].setPaused(voicePaused[5]);
        checkKey = 6;

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
