//
//  particle.cpp
//  daily6
//
//  Created by Gustav Bodin on 11/9/19.
//

#include "particle.hpp"

void Particle::setup(){
    location.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(0, ofGetHeight()/2));
    velocity.set(.5, .5, .5);
    acceleration.set(.5, .5, .5);
    gravity.set(.1, .1, .1);
}

//------------------------- -------------------------------------
void Particle::update(){
    acceleration += gravity;
    velocity += acceleration;
    location += velocity;
    acceleration.set(0, 0, 0);
    
    if (location.x > ofGetHeight()) {
        location.x = ofGetHeight();
        velocity.x *= -1;
        gravity.x *= -1;
    }
    if (location.x < 0) {
        location.x = 0;
        velocity.x *= -1;
        gravity.x *= 1;
    }
    if (location.y > ofGetHeight()) {
        location.y = ofGetHeight();
        velocity.y *= -1;
        gravity.y *= -1;
    }
    if (location.y < 0) {
        location.y = 0;
        velocity.y *= -1;
        gravity.y *= 1;
    }
    if (location.z > ofGetHeight()/2) {
        location.z = ofGetHeight()/2;
        velocity.z *= -1;
        gravity.z *= -1;
    }
    if (location.z < 0) {
        location.z = 0;
        velocity.z *= -1;
        gravity.z *= 1;
    }
    
}

////--------------------------------------------------------------
//void Particle::draw(float red, float green, float blue, float rad){
//    ofPushMatrix();
//        ofSetColor(red, green, blue);
//        ofNoFill();
//        ofDrawEllipse(location, rad, rad);
//    ofPopMatrix();
//}

//--------------------------------------------------------------
void Particle::draw(float red, float green, float blue){
    ofPushMatrix();
    ofSetColor(red, green, blue);
    float rad = 5.0 - (location.z/10);
    ofDrawEllipse(location, rad, rad);
    ofPopMatrix();
}
