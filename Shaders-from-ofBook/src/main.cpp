#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    ofGLFWWindowSettings settings;
    settings.setGLVersion(3, 2);
//    settings.width = 1080;
//    settings.height = 1920;
    settings.setSize(1080, 1920);
    ofCreateWindow(settings);
    // this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
