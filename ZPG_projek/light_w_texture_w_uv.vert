#version 330
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 uv;

out vec3 FragPos;
out vec3 Normal;
out vec2 uvc;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
    FragPos = vec3(modelMatrix * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(modelMatrix))) * aNormal;  
    
    gl_Position = projectionMatrix * viewMatrix * vec4(FragPos, 1.0);

    
    uvc = uv;
    
}