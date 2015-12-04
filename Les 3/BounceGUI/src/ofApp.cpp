#include "ofApp.h"
#include "Ball.h"
#include "Square.h"
#include "Triangle.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("Settings","settings.xml");
    gui.add(count.setup("1 == 3 objecten:", 0,0,20));
    gui.add(speedX.setup("speedX",1,1,20));
    gui.add(speedY.setup("speedY",1,1,20));
    gui.loadFromFile("setting.xml");
    tempcount = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    float newBallSpeedX = speedX;
    float newBallSpeedY = speedY;

    for(int i = 0; i<myBall.size(); i++){
        myTriangle[i].update();
        mySquare[i].update();
        myBall[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();

    for(int i = 0; i<myBall.size(); i++){
        myTriangle[i].draw();
        mySquare[i].draw();
        myBall[i].draw();
    }
}
//--------------------------------------------------------------
void ofApp::exit(){
    gui.saveToFile("setting.xml");

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
            if (tempcount > count || count == 0){
                if(!myTriangle.empty() && !mySquare.empty() && !myBall.empty()) {
                    for(int i=tempcount; i > count; i--){
                        myTriangle.pop_back();
                        mySquare.pop_back();
                        myBall.pop_back();
                    }
                }
            }
            else if(tempcount < count && count < 20) {
                for(int i=0; i < count; i++){
                    Triangle tempTriangle;
                    tempTriangle.setup();
                    tempTriangle.updateSpeed(speedX,speedY);
                    myTriangle.push_back(tempTriangle);
                    Square tempSquare;
                    tempSquare.setup();
                    tempSquare.updateSpeed(speedX,speedY);
                    mySquare.push_back(tempSquare);
                    Ball tempBall;
                    tempBall.setup();
                    tempBall.updateSpeed(speedX,speedY);
                    myBall.push_back(tempBall);
                }
            }
            tempcount = count;
    }

    else if (key == 'd' && !count== 0){
        if(!myTriangle.empty() && !mySquare.empty() && !myBall.empty()) {
            myTriangle.pop_back();
            mySquare.pop_back();
            myBall.pop_back();
            count = count - 1;
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
