#pragma once

#include "ofMain.h"
//#include "vectorField.hpp"

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
    
        ofTrueTypeFont maison;
        string display;
    
        //The way of setting about of objects to rotate.
        int resolution;
        float angle;
        int cols, rows;
        float xoff, yoff, zoff;
        //Setting up a 2D vector with ofVectors inside it.
        //Same thing as: array[][] in javacript.
        vector<vector<ofVec2f>> field;
};
