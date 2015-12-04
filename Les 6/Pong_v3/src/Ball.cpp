#include "Ball.h"
#include "MultiObject.h"
#include "ofSoundPlayer.h"

Ball::Ball()
{
    //ctor
}

Ball::~Ball()
{
    //dtor
}

void Ball::setup(){
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());

    // random snelheid
    speedX = ofRandom(-5, 5);
    speedY = ofRandom(-5, 5);

    radius = ofRandom(10, 20);
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    playerSound.loadSound("playerSound.wav");
    enemySound.loadSound("enemySound.wav");
    pongSound.loadSound("pongSound.wav");
}

void Ball::update(int playerY, int enemyY){
    //http://noobtuts.com/cpp/2d-pong-game
    if(x < 35 && x > 10 && y < (playerY + 100) && y > playerY){
        speedX = -speedX;
        playerSound.play();
    }
    if (x < (ofGetWidth() - 50) && x > (ofGetWidth() - 75) && y < (enemyY + 100) && y > enemyY){
        speedX = -speedX;
        enemySound.play();
    }

    // boven/onder tegen de rand aan? keer om!
    if(y < 0 ) {
        y = 0;
        speedY = -speedY;
        pongSound.play();
    } else if(y > ofGetHeight()) {
        y = ofGetHeight();
        speedY = -speedY;
        pongSound.play();
    }


    // bereken nieuwe coordinaten
    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
    ofSetCircleResolution(20);
    ofSetColor(color);
    ofCircle(x, y, radius);
}

void Ball::updateSpeed(float speedXS, float speedYS){
    speedX = speedXS;
    speedY = speedYS;

}

