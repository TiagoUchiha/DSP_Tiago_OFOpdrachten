#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gabbie.listDevices();
    gabbie.setDeviceID(0);
    gabbie.setDesiredFrameRate(30);

    gabbie.initGrabber(320,240);
    ofBackground(255,255,255);
    ofSetFrameRate(60);
    //ofSetVerticalSync(true);  //alternatief voor set framerate
    video.loadMovie("krisis.mp4");
    video.play();
    video.setLoopState(OF_LOOP_NORMAL);
    rotate = 0;
    width = (ofGetWidth() *3);
    height = ofGetHeight();

    image1.loadImage("dans1.png");
    image2.loadImage("dans2.png");
    image3.loadImage("glitters.png");
    changeColor = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    gabbie.update();
    video.update();
    rotate++;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofScale(4.0,4.0,4.0);
    gabbie.draw(gabbie.getWidth(),0,-gabbie.getWidth(),gabbie.getHeight());

    ofScale(0.25,0.25,0.25);

    ofEnableAlphaBlending();
    ofSetColor(255,255,255,127);
    //ofSetColor(ofColor::white);
    video.draw(0,0);
    ofDisableAlphaBlending();

    if (changeColor == true){
        ofPushMatrix();
        glTranslated(image1.width,0, 0);
		glScalef(-1, 1, 0);
        ofSetColor(ofColor::red);
        image1.draw(0,height);
        ofPopMatrix();

        ofPushMatrix();
        glTranslated(image2.width, 0, 0);
		glScalef(-1, 1, 0);
        ofSetColor(ofColor::blue);
        image2.draw(-1000,height);
        ofPopMatrix();

        ofPushMatrix();
        ofSetColor(ofColor::green);
        image3.draw(1300,50);
        ofSetColor(ofColor::yellow);
        image3.draw(1300,450);
        ofSetColor(ofColor::pink);
        image3.draw(1300,850);
        ofPopMatrix();
    }
    else{
        image1.draw(0,height);
        image2.draw(1000,height);
        image3.draw(1300,50);
        image3.draw(1300,450);
        image3.draw(1300,850);
    }
    ofSetColor(ofColor::red);

    ofScale(0.5,0.5,0.5);
    ofTranslate((width-600),(height/2));
    //ofRotateX(rotate);
    //ofRotateY(rotate);
    if (changeColor == true){
        ofRotateY(rotate);
    }
    ofRotateZ(rotate);
    video.draw(100,100);

    ofSetColor(ofColor::blue);

    ofScale(0.5,0.5,0.5);
    ofTranslate((width-600),(height/2));
    //ofRotateX(rotate);
    //ofRotateY(rotate);
    if (changeColor == true){
        ofRotateY(rotate);
    }
    ofRotateZ(rotate);
    video.draw(100,100);

    ofSetColor(ofColor::green);

    ofScale(0.5,0.5,0.5);
    ofTranslate((width-600),(height/2));
    //ofRotateX(rotate);
    //ofRotateY(rotate);
    if (changeColor == true){
        ofRotateY(rotate);
    }
    ofRotateZ(rotate);
    video.draw(100,100);

    ofSetColor(ofColor::white);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c'){
       changeColor = true;
    }
    else{
        changeColor = false;
    }
}
