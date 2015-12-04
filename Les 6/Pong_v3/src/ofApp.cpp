#include "ofApp.h"
#include "Ball.h"
#include "Square.h"
#include "MultiObject.h"
#include "ofSoundPlayer.h"


//--------------------------------------------------------------
void ofApp::setup(){
//    gui.setup("Settings","settings.xml");
//    gui.add(count.setup("1 == 3 objecten:", 0,0,20));
//    gui.add(speedX.setup("speedX",1,1,20));
//    gui.add(speedY.setup("speedY",1,1,20));
//    gui.loadFromFile("setting.xml");
    makeSpace = false;
    scoreboard.loadFont("arial.ttf",32);
    enemyPoint = 0;
    playerPoint = 0;
    ofSetFrameRate(120);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (makeSpace == true && myBall){
        checkOutBallX = myBall->x;
        checkOutBallY = myBall->y;
        if (checkOutBallX < 5 ){
            enemyPoint++;
            ofLog(OF_LOG_NOTICE,"Score: " + ofToString(playerPoint) + "/" + ofToString(enemyPoint));
            myBall = NULL;
            delete myBall;
        }
        else if (checkOutBallX > (ofGetWidth() - 10) ){
            playerPoint++;
            ofLog(OF_LOG_NOTICE,"Score: " + ofToString(playerPoint) + "/" + ofToString(enemyPoint));
            myBall = NULL;
            delete myBall;

        }
        else {
            checkPlayerY = mySquare->y;
            checkEnemyY = enemySquare->y;
            myBall->update(checkPlayerY,checkEnemyY);
            enemySquare->update(checkOutBallY);
            mySquare->update(0);
        }
    }
    else if (makeSpace == true){
        mySquare->update(0);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    gui.draw();
    if (makeSpace == true){
        if(myBall){
            myBall->draw();
            mySquare->draw();
            enemySquare->draw();

        }
        else if (mySquare){
            mySquare->draw();
            enemySquare->draw();
        }
    }
    scoreboard_final = "Score:"+ ofToString(playerPoint) + "/" + ofToString(enemyPoint);
    scoreboard.drawString(scoreboard_final, ((ofGetWidth()/ 2) - 100), 50);
}

//--------------------------------------------------------------
void ofApp::exit(){
//    gui.saveToFile("setting.xml");
    makeSpace = false;
    myBall = NULL;
    mySquare = NULL;
    enemySquare = NULL;
    delete myBall;
    delete mySquare;
    delete enemySquare;
    //ofExit();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        makeSpace = true;
        mySquare = new Square();
        mySquare->setup();
        myBall = new Ball();
        myBall->setup();
        enemySquare = new MultiObject();
        enemySquare->setup();
//        myBall->updateSpeed(speedX,speedY);
    }
    if (makeSpace == true){
        if (key == 'w'){
            mySquare->update(1);
        }
        else if (key == 's'){
            mySquare->update(2);
        }
    }

    if (key == 'e'){
        exit();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'w'){
         mySquare->update(0);

    }
    else if (key == 's'){
        mySquare->update(0);
    }
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
