#include "ofApp.h"
#include "Ball.h"
#include "Square.h"
#include "Triangle.h"

//--------------------------------------------------------------
void ofApp::setup() {
}

//--------------------------------------------------------------
void ofApp::update() {

    for(int i = 0; i<myBall.size(); i++){
        myTriangle[i].update();
        mySquare[i].update();
        myBall[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    for(int i = 0; i<myBall.size(); i++){
        myTriangle[i].draw();
        mySquare[i].draw();
        myBall[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == ' ' ){
        Triangle tempTriangle;
        tempTriangle.setup();
        myTriangle.push_back(tempTriangle);
        Square tempSquare;
        tempSquare.setup();
        mySquare.push_back(tempSquare);
        Ball tempBall;
        tempBall.setup();
        myBall.push_back(tempBall);
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
