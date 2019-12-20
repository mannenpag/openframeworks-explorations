#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofSetWindowTitle("Daily 1, Shape and time");
    ofSetWindowShape(1280, 1280);
    ofSetFrameRate(60);
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofHideCursor();

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    float time = ofGetElapsedTimef();
    
    for (int i = 0; i < 1300; i++) {
        ofSetColor(250 * sin(i * 0.01 + time),
                   250 * sin(i * 0.02 + time),
                   250 * sin(i * 0.1 + time));
        ofDrawEllipse(200 + 100 * sin(i * 0.20 + time),
                      50 + i * time,
                      100  + 20 * cos(i * 0.20 + time),
                      100);
    }
    
    for (int i = 0; i < 1300; i++) {
        ofSetColor(250 * sin(i * 0.3 + time),
                   250 * tan(i * 0.01 + time),
                   250 * sin(i * 0.1 + time));
        ofDrawEllipse(
                      (ofGetWidth()-200) + 100 * sin(i * 0.20 + time),
                      20 + i * time,
                      80  + i,
                      100 + 50 * cos(i * 0.30 + time));
    }
    
    for (int i = 0; i < 1300; i++) {
        ofSetColor(250 * sin(i * 0.01 + time),
                   250 * sin(i * 0.1 + time),
                   250 * sin(i * 0.01 + time));
        ofDrawEllipse(
                      (ofGetWidth()/2) + 100 * sin(i * 0.20 + time),
                      20 + i * time,
                      80  + sin(i * 0.30 + time),
                      100 + 50 * sin(i * 0.30 + time));
    }
    
    
//    string showTime = "Here is time:" + ofToString(time);
//    ofSetColor(60);
//    ofDrawBitmapString(showTime, 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f'){
        ofToggleFullscreen();
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
