//
//  vectorField.hpp
//  daily10
//
//  Created by Gustav Bodin on 11/23/19.
//

#ifndef vectorField_hpp
#define vectorField_hpp

#include <stdio.h>
#include "ofMain.h"

class VectorField {
public:
    VectorField (int _res);
    ~VectorField();
    
    void setup();
    void update();
    void display();
    
    int cols, rows;
    int resolution;
    
    float xoff, yoff, zoff;
    //Setting up a 2D vector with ofVectors inside it.
    //Same thing as: array[][] in javacript.
    vector<vector<ofVec2f>> field;
    
    
};

#endif /* vectorField_hpp */
