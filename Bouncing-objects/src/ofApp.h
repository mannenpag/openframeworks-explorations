#pragma once

#include "ofMain.h"
#include "particle.hpp"

#define NPARTICLES 40

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
    
    Particle particles[NPARTICLES];
    float radius;
};
