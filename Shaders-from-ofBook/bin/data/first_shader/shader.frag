// fragment shader

#version 150

out vec4 outputColor;
uniform float time;

void main()
{
    float windowWidth = 1080.0;
    float windowHeight = 1920.0;
    float zHeight = windowHeight/2;

    float r = sin(time + (gl_FragCoord.x / windowWidth));
    float g = sin(time + (gl_FragCoord.y / windowHeight));
    float b = sin(time + (gl_FragCoord.y / windowHeight));
    float a = sin(time + (gl_FragCoord.x / windowWidth));
    outputColor = vec4(r, g, b, a);
}