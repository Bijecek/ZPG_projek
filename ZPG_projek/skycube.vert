#version 330
layout(location=0) in vec3 uv;

out vec3 uv_tmp;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
        void main () {
             gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4 (uv,1.0);
             uv_tmp = uv;
        }