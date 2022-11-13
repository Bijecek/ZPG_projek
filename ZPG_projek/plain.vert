#version 330
layout(location=0) in vec4 vp;
layout(location=1) in vec4 aColor;
layout(location=2) in vec2 uv;
out vec4 ourColor;
out vec2 uv_tmp;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
        void main () {
             gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4 (vp);
             ourColor = aColor;
             uv_tmp = uv*20;
        }