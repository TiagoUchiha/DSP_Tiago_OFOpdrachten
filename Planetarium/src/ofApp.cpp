#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(30,30,30);
    drawGrid = false;
    drawLight = false;
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
    //light.setDirectional();
    //light.setPosition(-200,-200,-200);
    //light.lookAt(ofVec3f(0,0,0),ofVec3f(0,0,0));
    //light.setDiffuseColor(ofColor(255,255,255));
    //light.enable();
    light.setPointLight();
    light.setPosition(200,200,200);

    image.loadImage("blabla1.jpg");
    image2.loadImage("blabla2.jpg");
    image3.loadImage("blabla3.jpg");


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
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    ofScale(image.getWidth(),image.getHeight());
    glMatrixMode(GL_MODELVIEW);


    light.enable();
    gui.draw();
    light.disable();
    ofEnableDepthTest();

    cam.begin();


    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    light.enable();
    if(drawGrid) ofDrawGrid(200);
    //if (drawLight) light.draw();


    image.bind();
    ofDrawSphere(10,10,50);
    image.unbind();
    image2.bind();
    ofDrawSphere(100,100,50);
    image2.unbind();
    image3.bind();
    ofDrawSphere(200,200,50);
    image3.unbind();
    light.disable();

    cam.end();
/*
    cam.begin();

    planet[0].draw();
    ofTranslate(planet[0].distance,0);
    planet[1].draw();
    ofTranslate(planet[0].distance,1);
    planet[2].draw();
    ofTranslate(planet[0].distance,2);
    planet[3].draw();
    cam.end();
    ofDisableDepthTest();
*/
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);



}


void ofApp::keyPressed(int key){
    if (key=='g'){
        drawGrid = !drawGrid;
        //drawLight = !drawLight;
    }

}
