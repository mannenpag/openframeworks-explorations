//
//  particle.hpp
//  daily6
//
//  Created by Gustav Bodin on 11/9/19.
//

#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"

class Particle {
    public:
        void setup();
        void update();
        void draw(float red, float green, float blue);

private:
        ofVec3f location;
        ofVec3f velocity;
        ofVec3f acceleration;
        ofVec3f gravity;
};

#endif /* particle_hpp */
