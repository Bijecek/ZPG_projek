#version 330
out vec4 frag_colour;
uniform sampler2D textureUnitID;
in vec2 uv_tmp;
void main () {
     //frag_colour = vec4(uv,1.0,1.0); //test na funkcnost uv souradnic
     frag_colour = texture(textureUnitID, uv_tmp);
}