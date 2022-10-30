#version 330
layout(location=0) in vec4 vp;
layout(location=1) in vec4 aColor;
out vec4 ourColor;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
        void main () {
             gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4 (vp);
             ourColor = aColor;
        }