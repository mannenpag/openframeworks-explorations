#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(29);
    ofSetWindowTitle("Ar Room");
    ofEnableDepthTest();
    
    webCam.setup(640, 480);
    color.allocate(webCam.getWidth(), webCam.getHeight());
    gray.allocate(webCam.getWidth(), webCam.getHeight());
    
    haar.setup("haarcascade_frontalface_default.xml");
    haar.setScaleHaar(3);
    this->perspective = ofPoint(0,0);
    this->fontSize = 50;
    this->font.load("MaisonNeue-Medium.ttf", this->fontSize, true, true, true);
    shader.load("shder/shader");
    
    arOne = true;
    arTwo = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    webCam.update();
    
    if (webCam.isFrameNew()) {
        color.setFromPixels(webCam.getPixels());
        gray = color;
        haar.findHaarObjects(gray);
    }
    
    for (int i = 0; i < haar.blobs.size(); i++) {
        auto face = haar.blobs[i];
        if (face.boundingRect.width > 100 ) {
            auto x = face.centroid.x;
            auto y = face.centroid.y;

            this->perspective = ofPoint(ofMap(x, 0, webCam.getWidth(), 30, -30), ofMap(y, 0, webCam.getHeight(), -30, 30));
            
            cout << this->perspective;
            cout << "\n";
            
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (arOne) {
//        vector<string> words = {"Look", "at", "me", "!"};
        string word = "LOOK AT ME";

        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        for (int z = 0; z > -600; z += -20) {
            
            ofFill();
            ofSetColor(239, ofMap(z, 0, -600, 255, 0));
            
            auto textLocation = glm::vec3(-this->font.stringWidth(word)/2,-this->font.stringHeight(word)/2, z );
            int wordIndex = 0;
//
//            if (ofGetFrameNum() % 100 && wordIndex <= 4) {
//                wordIndex += 1;
//            }
//            if (wordIndex == 4) {
//                wordIndex = 0;
//            }
//
//            cout << wordIndex;
//            cout << "\n";
//
//            auto path = this->font.getStringAsPoints(words[wordIndex], true, false);
//            auto outline = path.getOutline();
            ofPushMatrix();
                ofTranslate(textLocation);
                this->font.drawStringAsShapes(word, 0, 0);
            ofPopMatrix();

            
            ofBeginShape();
            ofVertex(ofGetWidth() * 0.5, ofGetHeight() * 0.5, z);
            ofVertex(-ofGetWidth() * 0.5, ofGetHeight() * 0.5, z);
            ofVertex(-ofGetWidth() * 0.5, -ofGetHeight() * 0.5, z);
            ofVertex(ofGetWidth() * 0.5, -ofGetHeight() * 0.5, z);
            
            ofNextContour(true);
            
            ofVertex(ofGetWidth() * 0.47, ofGetHeight() * 0.47, z);
            ofVertex(-ofGetWidth() * 0.47, ofGetHeight() * 0.47, z);
            ofVertex(-ofGetWidth() * 0.47, -ofGetHeight() * 0.47, z);
            ofVertex(ofGetWidth() * 0.47, -ofGetHeight() * 0.47, z);
            
            ofEndShape(true);
            
            ofTranslate( this->perspective.x,  this->perspective.y);
        }
    }
    if (arTwo) {
        shader.begin();
        
            color.draw(0,0);
        shader.end();

    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case '1':
            arOne = true;
            arTwo = false;
            break;
        case '2':
            arOne = false;
            arTwo = true;
            break;
    }
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
