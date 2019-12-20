//
//  vectorField.cpp
//  daily10
//
//  Created by Gustav Bodin on 11/23/19.
//

#include "vectorField.hpp"

VectorField::VectorField(int _res) {
    resolution = _res;
    
    cols = ofGetWidth() / resolution;
    rows = ofGetHeight() / resolution;

}

VectorField::~VectorField() {
}

void VectorField::setup() {
    zoff = 0;
}

void VectorField::update(){

}

void VectorField::display() {
//    for (int x = 0; x < cols; x++) {
//        for (int y = 0; y < rows; y++) {
//            ofPushMatrix();
//                ofTranslate(x*resolution, y*resolution);
//                ofFill();
//                ofSetColor(255);
//                ofDrawRectangle(0, 0, resolution, resolution);
//            ofPopMatrix();
//
//        }
//    }
    
    xoff = 0;
    for (int x = 0; x < cols; x++) {
        yoff = 0;
        for (int y = 0; y < rows; y++) {
            float theta = ofMap(ofNoise(xoff, yoff, zoff), 0, 1, 0, TWO_PI);
            ofVec2f angle = ofVec2f(cos(theta), sin(theta));
            field[x][y] = angle.normalize();
            yoff += 0.05;
            
            ofPushMatrix();
                ofTranslate(x*resolution, y*resolution);
                ofFill();
                ofSetColor(255);
                ofDrawRectangle(0, 0, resolution, resolution);
            ofPopMatrix();

        }
        xoff += 0.05;
    }
    zoff += 0.01;
}
