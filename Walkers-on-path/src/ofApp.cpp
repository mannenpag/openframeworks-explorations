#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(200);
    ofSetWindowTitle("Daily 9, Walker");
    ofSetWindowShape(1560, 1560);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
    //N = 15;
    for (int i = 0; i < N; i++) {
        walkers[i].setup();
    }
    //cam.setup();
}

void Walker::setup(){
    pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    vel.set(.5, .5, .5);
    acc.set(.5, .5, .5);
}

//--------------------------------------------------------------
void ofApp::update(){
    //cam.update();

    
    for (int i = 0; i < N; i++) {
        float newX = ofMap( ofNoise( ofGetElapsedTimef()/i, -1000), 0, 1, 0, ofGetWidth());
        float newY = ofMap( ofNoise( ofGetElapsedTimef()/i, 1000), 0, 1, 0, ofGetHeight());
        
        walkers[i].update(newX,newY);
    }
}

void Walker::update(float x, float y){
    pos.x = x;
    pos.y = y;
    
    pos = pos + vel;
    //vel = vel + acc;
    
    int choice = ofRandom(4);
    if (choice == 0) {
        x++;
    }
    else if (choice == 1) {
        x--;
    }
    else if (choice == 2) {
        y++;
    }
    else if (choice == 3) {
        y--;
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
//cam.begin();
    ofPushMatrix();
        ofSetColor(0, 0, 0, 5);
        ofNoFill();
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopMatrix();
    for (int i = 0; i < N; i++) {
        walkers[i].draw(255-i, 255-i, 255-i, i);
    }
//cam.end();
}

void Walker::draw(float red, float green, float blue, float r){
    ofPushMatrix();
        ofSetColor(red, green, blue);
        //ofNoFill();
        float rad = r + 5.0;
        ofDrawEllipse(pos, rad, rad);
    ofPopMatrix();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
