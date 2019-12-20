#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Daily 3, Type");
    ofSetWindowShape(1280, 1280);
    ofSetFrameRate(60);
    ofBackground(255);
    //ofSetBackgroundAuto(false);
    ofHideCursor();
    ofToggleFullscreen();
    
    maisonFont.load("MaisonNeue-Medium.ttf", 600);
    std::string textTyped = "";

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
    cam.begin();

    for (int i = 0; i < textTyped.size(); i++) {
        ofPushMatrix();
        ofSetColor(150 * sin(i * 0.3 + time),
                   150 * sin(i * 0.3 + time),
                   150 * sin(i * 0.3 + time));
        ofScale(sin((scale * i) /2.0 + time), sin((scale * i)/2.0 + time), 1);
        //ofScale(scale, scale, 1);
        maisonFont.drawString(textTyped, (1 * i), (ofGetHeight()/2) * i);
        ofPopMatrix();
    }
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
        textTyped += key;
    if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE) {
        textTyped.pop_back();
    } else if(key == OF_KEY_RETURN ){
        textTyped += "\n";
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
