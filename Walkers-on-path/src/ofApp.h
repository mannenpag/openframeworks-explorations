#pragma once

#include "ofMain.h"
#define N 255

class Walker {
public:
    void setup();
    void update(float x, float y);
    void draw(float red, float green, float blue, float r);
    
    ofVec2f pos;
    ofVec3f vel;
    ofVec3f acc;

    float time;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //int N;
    Walker walkers[N];
    
    ofEasyCam cam;
};
