#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(200);
    ofSetWindowTitle("Daily 7, Bouncing particles 3D");
    ofSetWindowShape(1560, 1560);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
    for(int i=0; i<NPARTICLES; i++){
        particles[i].setup();
    }
    
}
 
//------------------------- -------------------------------------
void ofApp::update(){
    for(int i=0; i<NPARTICLES; i++){
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofColor outerColor(8,8,0);
//    ofColor innerColor(64,59,17);
//    ofBackgroundGradient(outerColor, innerColor, OF_GRADIENT_CIRCULAR);
    ofPushMatrix();
        ofSetColor(0, 0, 0, 10);
        ofFill();
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopMatrix();
    for(int i=0; i<NPARTICLES; i++){
        float time = ofGetElapsedTimef();
        radius = 50 + 40 * sin(i * 0.005 + time);
        float red = 222 + 40 * sin(i * 0.01 + time);
        float green = 120 + 40 * sin(i * 0.06 + time);
        float blue = 10 + 40 * sin(i * 0.01 + time);
        particles[i].draw(red, green, blue);
    }
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
