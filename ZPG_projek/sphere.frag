#version 330
out vec4 frag_colour;
in vec4 ourColor;
void main () {
     frag_colour = ourColor;
}