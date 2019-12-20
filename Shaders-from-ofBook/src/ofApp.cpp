#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Daily 11, Shaders");
    ofSetWindowShape(1080, 1920);
    
    //image
    img.load("images/mini.jpg");
    
    //Load the shaders
    shaderSinePlane.load("first_shader/shader");
    shaderMousePosition.load("second_shader/shader");
    shaderNoise.load("third_shader/shader");

    
    float planeScale = 1;
    int planeWidth = ofGetWidth() * planeScale;
    int planeHeight = ofGetHeight() * planeScale;
    int planeGridSize = 20;
    int planeColumns = planeWidth / planeGridSize;
    int planeRows = planeHeight / planeGridSize;
    plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
    
    firstShader = true;
    secondShader = false;
    thirdShader = false;
}

//--------------------------------------------------------------
void ofApp::updateThirdShader(){
    float noiseScale = ofMap(mouseX, 0, ofGetWidth(), 0, 0.1);
    float noiseVel = ofGetElapsedTimef();
    
    ofPixels & pixels = img.getPixels();
    int w = img.getWidth();
    int h = img.getHeight();
    for(int y = 0; y<h; y++) {
        for(int x = 0; x<w; x++){
            int i = y * w + x;
            float noiseVelue = ofNoise(x * noiseScale, y * noiseScale, noiseVel);
            pixels[i] = 80 * noiseVelue;
        }
    }
    img.update();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (thirdShader) {
        updateThirdShader();
    }
}

//--------------------------------------------------------------
void ofApp::drawFirstShader(){
        float percentX = mouseX / (float)ofGetWidth();
        percentX = ofClamp(percentX, 0, 1);
        
        ofFloatColor colorLeft = ofColor(191, 5, 11);
        ofFloatColor colorRight = ofColor(242, 159, 3);
        ofColor colorMix = colorLeft.getLerped(colorRight, percentX);
        ofSetColor(colorMix);
        
        shaderSinePlane.begin();
        
            shaderSinePlane.setUniform1f("time", ofGetElapsedTimef());
    
            float tx = ofGetWidth() / 2;
            float ty = ofGetHeight() / 2;
            ofTranslate(tx, ty);
    
            float percentY = mouseY / (float)ofGetHeight();
            float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
            ofRotate(rotation, 1, 0, 0);
    
            plane.draw();
        
        shaderSinePlane.end();

}
//--------------------------------------------------------------
void ofApp::drawSecondShader(){
    shaderMousePosition.begin();
    
        float sec = ofGetSeconds();
    
        float cx = ofGetWidth() / 2;
        float cy = ofGetHeight() / 2;
    
        float mx = mouseX - cx;
        float my = mouseY - cy;
    
        // if you want to pass in a float value, use setUniform1f.
        // if you want to pass in a integer value, use setUniform1i.
        shaderMousePosition.setUniform1f("mouseRange", 150); // SET A UNIFORM
    
        // we can pass in two values into the shader at the same time by using the setUniform2 function.
        // inside the shader these two values are set inside a vec2 object.
        shaderMousePosition.setUniform2f("mousePos", mx, my);  // SET A UNIFORM
    
        float percentX = mouseX / (float)ofGetWidth();
        percentX = ofClamp(percentX, 0, 1);
    
        ofFloatColor colorLeft = ofColor(191, 5, 179);
        ofFloatColor colorRight = ofColor(242, 159, 3);
        ofFloatColor colorMix = colorLeft.getLerped(colorRight  * sec, percentX);
    
        float mouseColor[4] ={colorMix.r, colorMix.g, colorMix.b, colorMix.a};
        // we can pass in four values into the shader at the same time as a float array.
        // we do this by passing a pointer reference to the first element in the array.
        // inside the shader these four values are set inside a vec4 object.
        shaderMousePosition.setUniform4fv("mouseColor", &mouseColor[0]);  // SET A UNIFORM
    
        ofTranslate(cx, cy);
    
        plane.draw();

    shaderMousePosition.end();
}

//--------------------------------------------------------------
void ofApp::drawThirdShader(){
    img.getTexture().bind();
    
    shaderNoise.begin();
    ofPushMatrix();
    
    float tx = ofGetWidth() / 2;
    float ty = ofGetHeight() / 2;
    ofTranslate(tx, ty);
    
    float percentY = mouseY / (float)ofGetHeight();
    float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
    ofRotate(rotation, 1, 0, 0);
    
    plane.draw();
    
    ofPopMatrix();
    shaderNoise.end();
    ofSetColor(255);
    img.draw(0, 0);
    img.getTexture().unbind();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(249);
    
    if (firstShader) {
        drawFirstShader();
    }
    if (secondShader) {
        drawSecondShader();
    }
    if (thirdShader) {
        drawThirdShader();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            firstShader = true;
            secondShader = false;
            thirdShader = false;
            break;
        case '2':
            firstShader = false;
            secondShader = true;
            thirdShader = false;
            break;
        case '3':
            firstShader = false;
            secondShader = false;
            thirdShader = true;
            break;
        default:
            firstShader = true;
            secondShader = false;
            thirdShader = false;
    };

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
