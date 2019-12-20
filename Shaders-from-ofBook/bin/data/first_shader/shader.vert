// vertex shader

#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

uniform float time;

void main(){
    float displacementHeight = 100;
    float displacementY = sin(time + (position.x / 100.0)) * displacementHeight;
    float displacementX = sin(time + (position.y / 100.0)) * displacementHeight;
    float displacementZ = sin(time + (position.z / 100.0)) * displacementHeight;

    vec4 modifiedPosition = modelViewProjectionMatrix * position;
    modifiedPosition.y += displacementY;
    modifiedPosition.z += displacementZ;
    modifiedPosition.x += displacementX;

    gl_Position = modifiedPosition;
}