#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.loadImage("ezgif-1833955273.jpg");

    plane.set(MESH_WIDTH, MESH_HEIGHT);
    plane.setResolution(MESH_SIZE_X,MESH_SIZE_Y);

    ofMesh& mesh = plane.getMesh();
    plane.mapTexCoordsFromTexture(image.getTextureReference());

}

//--------------------------------------------------------------
void ofApp::update(){

    ofMesh& mesh = plane.getMesh();
    for (int y=0; y<MESH_SIZE_Y; y++){
        for(int x=0; x<MESH_SIZE_X; x++){
            int index =x + MESH_SIZE_X * y;

            ofPoint vertex = mesh.getVertex(index);
            vertex.z = ofNoise(x *0.05, y*0.05, ofGetElapsedTimef()* 0.05) * 100;

            mesh.setVertex(index,vertex);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);

    cam.setVFlip(true);
    cam.begin();
    image.bind();
    plane.drawWireframe();
    image.unbind();

    cam.end();
}
