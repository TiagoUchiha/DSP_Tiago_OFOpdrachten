#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.loadMovie("bendershort.mp4");
    video.play();

    plane.set(MESH_WIDTH, MESH_HEIGHT);
    plane.setResolution(MESH_SIZE_X,MESH_SIZE_Y);

    plane.mapTexCoordsFromTexture(video.getTextureReference());


}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();

    if(video.isFrameNew()){
       ofMesh& mesh = plane.getMesh();
       for(int y=0; y<MESH_SIZE_Y;y++){
        for(int x=0;x<MESH_SIZE_X;x++){
            int index = x + MESH_SIZE_X *y;
            ofPoint vertex = mesh.getVertex(index);
            vertex.z = ofNoise(x *0.05, y*0.05, ofGetElapsedTimef()*0.5)*100;
            mesh.setVertex(index,vertex);
        }
       }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    cam.setVFlip(true);

    cam.begin();
    video.getTextureReference().bind();
    //plane.drawWireframe();
    plane.draw();
    video.getTextureReference().unbind();
    cam.end();
}
