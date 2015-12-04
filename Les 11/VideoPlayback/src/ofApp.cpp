#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetFrameRate(60);
    //ofSetVerticalSync(true);  //alternatief voor set framerate
    video.loadMovie("krisis.mp4");
    video.play();
    video.setLoopState(OF_LOOP_NORMAL);
    rotate = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    rotate++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(ofColor::white);
    video.draw(0,0);

    ofSetColor(255,0,0,127);
    //ofSetColor(ofColor::red);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);
    ofDisableAlphaBlending();

    ofSetColor(ofColor::blue);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);

    ofSetColor(ofColor::green);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

