#version 330
out vec4 frag_colour;
uniform samplerCube cubeID;
in vec3 uv_tmp;
void main () {
     //frag_colour = vec4(uv,1.0,1.0); //test na funkcnost uv souradnic
     frag_colour = texture(cubeID, uv_tmp);
}