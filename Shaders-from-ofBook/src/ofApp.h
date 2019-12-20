#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void drawFirstShader();
        void drawSecondShader();
        void drawThirdShader();
        void updateThirdShader(); 

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
		
    ofShader shaderSinePlane,shaderMousePosition, shaderNoise;
    ofPlanePrimitive plane;
    ofImage img;
    
    bool firstShader, secondShader, thirdShader;
};
