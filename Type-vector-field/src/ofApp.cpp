#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    double fps = 30;
    ofSetWindowTitle("Daily 10, Rotating As");
    maison.load("MaisonNeue-Medium.ttf", 25);
    display = "A";
    ofSetWindowShape(1920, 1080);

    ofSetFrameRate(fps);
    
    resolution = 40;
    
    cols = ofGetWidth() / resolution;
    rows = ofGetHeight() / resolution;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(11, 11, 11);
    xoff = 0;
    for (int x = 0; x < cols; x++) {
        yoff = 0;
        for (int y = 0; y < rows; y++) {
            float theta = ofMap(ofNoise(xoff, yoff, zoff), 0, 1, 0, TWO_PI);
            ofVec2f dir = ofVec2f(cos(theta), sin(theta));
            //field[x][y] = angle.normalize();
            ofVec2f org = ofVec2f(1, 0);
            angle = org.angle(dir);

            float r = ofNoise(xoff, yoff, zoff) * 255;
            yoff += 0.05;

            ofPushMatrix();
                ofTranslate(x*resolution, y*resolution);
                ofFill();
                ofSetColor(r);
                ofRotateDeg(angle);
                maison.drawString(display, 0, 0);
                //ofDrawRectangle(0, 0, resolution, resolution);
            ofPopMatrix();

        }
        xoff += 0.05;
    }
    zoff += 0.005;
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
