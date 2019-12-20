#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Daily 2, Type");
    ofSetWindowShape(1280, 1280);
    ofSetFrameRate(60);
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofHideCursor();

    //font
    maisonFont.load("MaisonNeue-Medium.ttf", 120);
    code = "Code";
    typeography = "Typeography";
}

//--------------------------------------------------------------
void ofApp::update(){
    if (isShrinking) {
        scale -= 0.005;
        if (scale < 0.1) {
            isShrinking = false;
        }
    }
    else {
        scale += 0.005;
        if (scale > 1) {
            isShrinking = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    
    for (int i = 0; i < 5; i++) {
            float x = ofMap( ofNoise( time/2.0, -1000), 0, -1, 0, ofGetWidth());
            float y = ofMap( ofNoise( time/2.0, 1000), 0, -1, 0, ofGetHeight());
            float x2 = ofMap( ofNoise( time, -200), 0, 1, 0, ofGetWidth());
            float y2 = ofMap( ofNoise( time, 200), 0, 1, 0, ofGetHeight());
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2 - sin(i*0.5+time), ofGetHeight()/2 - sin(i*0.5+time));

        ofSetColor(150 * cos(i * 0.3 + time),
                   150 * cos(i * 0.3 + time),
                   150 * cos(i * 0.3 + time));
            ofScale(sin(scale/2.0 + time), sin(scale/2.0 + time), 1);
            maisonFont.drawString(code, x, y);
        ofPopMatrix();
        
        ofPushMatrix();
            ofTranslate(ofGetWidth()/2 + sin(i*0.5+time), ofGetHeight()/2 + sin(i*0.5+time));

            ofSetColor(150 * sin(i * 0.03 + time),
                   150 * sin(i * 0.03 + time),
                   150 * sin(i * 0.03 + time));
            ofScale(sin(scale/2.0 + time), sin(scale/2.0 + time), 1);
            maisonFont.drawString(typeography, x2, y2);
        ofPopMatrix();
    }
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
