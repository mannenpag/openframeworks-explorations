#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Daily 4, Type");
    ofSetWindowShape(1280, 1280);
    ofSetFrameRate(60);
    ofBackground(255);
    //ofSetBackgroundAuto(false);
    ofHideCursor();
    
    osc.setup(PORT);
    
    
    maisonFont.load("MaisonNeue-Medium.ttf", 600, true, true, true);
    std::string textTyped = "";
    //std::vector<string> letters = {"H","e","l","l","o","\n","I","n","s","t","a","g","r","a","m"};
    std::vector<string> letters;

}

//--------------------------------------------------------------
void ofApp::update(){
    while(osc.hasWaitingMessages()) {
        ofxOscMessage m;
        osc.getNextMessage(&m);
        
        if (m.getAddress() == "/inputEco/x") {
            oscx = m.getArgAsFloat(0);
        }
        if (m.getAddress() == "/inputEco/y") {
            oscy = m.getArgAsFloat(0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    float time = ofGetElapsedTimef();

    for (unsigned i=0; i< textTyped.size(); ++i) {
        float inputY = (ofMap(oscy, 1, 0, 0, ofGetHeight())) * 2;
        float inputX = (oscx * ofGetWidth()) * 2;
        float x = ofMap( ofNoise( i/0.02, -2000), 0, -1, 0, ofGetWidth());
        float y = ofMap( ofNoise( i/0.02, 2000), 0, -1, 0, ofGetHeight());
        ofPushMatrix();
//            letters.push_back("H");
//            letters.push_back("e");
//            letters.push_back("l");
//            letters.push_back("l");
//            letters.push_back("o");
//
//            letters.push_back("I");
//            letters.push_back("n");
//            letters.push_back("s");
//            letters.push_back("t");
//            letters.push_back("a");
//            letters.push_back("g");
//            letters.push_back("r");
//            letters.push_back("a");
//            letters.push_back("m");

            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        
            ofSetColor(150 * cos(i * 0.3 + time),
                       150 * cos(i * 0.3 + time),
                       150 * cos(i * 0.3 + time));
        
//            float scaleVar = sin(scale/0.001 * i);
//            if (scaleVar < 0) {
//                ofScale(scaleVar, scaleVar, 1);
//            } else {
//                ofScale(scale, scale, 1);
//            }
            float scaleVar = sin(scale/0.001 * i);
            ofScale(scaleVar, scaleVar, 1);
            bool vflip = true;
            bool filled = false;
            drawOutline = maisonFont.getCharacterAsPoints(textTyped[i], vflip, filled);
            //maisonFont.drawStringAsShapes(letters[i], x, y);
            drawOutline.draw(x+inputX, y+inputY);
        ofPopMatrix();
        //std::cout << sin(scale/0.001 * i) << '\n';
    }
    //std::cout << textTyped << '\n';

    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    textTyped += key;
    if (key == 'c') {
        textTyped.clear();
    }
    if(key == OF_KEY_RETURN ){
        textTyped += "\n";
    }
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
