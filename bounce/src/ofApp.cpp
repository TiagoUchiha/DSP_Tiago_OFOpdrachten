#include "ofApp.h"
#include "Ball.h"
#include "Square.h"
#include "Triangle.h"

//--------------------------------------------------------------
void ofApp::setup() {
}

//--------------------------------------------------------------
void ofApp::update() {

    for(int i = 0; i<mySquare.size(); i++){
        mySquare[i].update();
        myBall[i].update();
        myTriangle[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

    for(int i = 0; i<mySquare.size(); i++){
        mySquare[i].draw();
        myBall[i].draw();
        myTriangle[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == ' ' ){
        Square tempSquare;
        tempSquare.setup();
        mySquare.push_back(tempSquare);
        Ball tempBall;
        tempBall.setup();
        myBall.push_back(tempBall);
        Triangle tempTriangle;
        tempTriangle.setup();
        myTriangle.push_back(tempTriangle);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
