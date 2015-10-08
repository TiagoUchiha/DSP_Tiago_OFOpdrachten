#include "ofApp.h"
#include "Ball.h"
#include "Square.h"
#include "Triangle.h"
#include "ofxGui.h"

Ball ball;
Square square;
Triangle triangle;

//--------------------------------------------------------------
void ofApp::setup() {
    ball.setup();
    //square.setup();
   // triangle.setup();

    gui.setup("Intellingen","settings.xml");
    gui.add(count.setup("count",50,0,200));
    gui.add("speedX",20,0,200);
    gui.add("speedY",20,0 200);

    gui.loadFormFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update() {
    ball.update();
    //square.update();
    //triangle.update();
    for(int i = 0; i<mySquare.size(); i++){
        mySquare[i].update();
    }
    float newBallSpeedX = speedX;
}

//--------------------------------------------------------------
void ofApp::draw() {
    ball.draw();
    //square.draw();
   // triangle.draw();
       for(int i = 0; i<mySquare.size(); i++){
        mySquare[i].draw();
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == ' ' ){
        Square tempSquare;
        tempSquare.setup();
        mySquare.push_back(tempSquare);
    }
    gui.saveToFile("settings.xml");
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
