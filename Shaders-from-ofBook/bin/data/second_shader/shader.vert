// vertex shader
#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

uniform float mouseRange;
uniform vec2 mousePos;
uniform vec4 mouseColor;

void main(){
    vec4 pos = position;
    // getting the distance, therefore the direction that the mouse have moved from said pixel.
    vec2 dir = pos.xy - mousePos;
    float dist = distance(pos.xy, mousePos);

    if (dist > 0.0 && dist < mouseRange) {
        // normalise distance between 0 and 1.
        float distNorm = dist / mouseRange;

        // flip it so the closer we are the greater the repulsion.
        distNorm = 1.0 - distNorm;

        // make the direction vector magnitude fade out the further it gets from mouse position.
        dir *= distNorm;

        // add the direction vector to the vertex position.
        pos.x += dir.x;
        pos.y += dir.y;
    }
        // finally set the pos to be that actual position rendered
    gl_Position = modelViewProjectionMatrix * pos;
}