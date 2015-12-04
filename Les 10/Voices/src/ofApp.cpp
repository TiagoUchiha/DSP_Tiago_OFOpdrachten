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
    for( int i=0; i<VOICES;i++) {
        if(!voicePaused[i]) {
            ofSetColor(128+i*20, i*80, i*10+60);
            ofRect(100, i*30+200, voicePlayer[i].getVolume()*300, 5);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='1'){
        voicePaused[0] = !voicePaused[0];
        voicePlayer[0].setPaused(voicePaused[0]);
    }
    else if(key=='2'){
        voicePaused[1] = !voicePaused[1];
        voicePlayer[1].setPaused(voicePaused[1]);
    }
    else if(key=='3'){
        voicePaused[2] = !voicePaused[2];
        voicePlayer[2].setPaused(voicePaused[2]);
    }
    else if(key=='4'){
        voicePaused[3] = !voicePaused[3];
        voicePlayer[3].setPaused(voicePaused[3]);
    }
    else if(key=='5'){
        voicePaused[4] = !voicePaused[4];
        voicePlayer[4].setPaused(voicePaused[4]);
    }
    else if(key=='6'){
        voicePaused[5] = !voicePaused[5];
        voicePlayer[5].setPaused(voicePaused[5]);
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
