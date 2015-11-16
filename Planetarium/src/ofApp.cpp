#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(30,30,30);
    drawGrid = false;
    string wordPlanet = "planet";
    for (int i = 0; i < MAXplanet; i++){
        planet[i].setup(wordPlanet + ofToString(i));
        planetParams.add(planet[i].planetParamGroup);
    }
    //planet01.setup("planet 1");
    //planetParams.add(planet01.planetParamGroup);
    //planet02.setup("planet 2");
    //planetParams.add(planet02.planetParamGroup);

    gui.setup(planetParams);
    light.setDirectional();
    light.setPosition(-200,-200,-200);
    light.lookAt(ofVec3f(0,0,0),ofVec3f(0,0,0));
    light.setDiffuseColor(ofColor(255,255,255));
    light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < MAXplanet; i++){
        planet[i].update();
    }
    //planet01.update();
    //planet02.update();
    //if (!drawLight){
    //    light.disable();
    //}
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    ofEnableDepthTest();

    cam.begin();
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    if(drawGrid) ofDrawGrid(200);
    if (drawLight) light.draw();
    planet[0].draw();
    ofTranslate(planet[0].distance,0);
    planet[1].draw();
    ofTranslate(planet[0].distance,1);
    planet[2].draw();
    ofTranslate(planet[0].distance,2);
    planet[3].draw();
    cam.end();
    ofDisableDepthTest();

}


void ofApp::keyPressed(int key){
    if (key=='g'){
        drawGrid = !drawGrid;
        //drawLight = !drawLight;
    }

}
