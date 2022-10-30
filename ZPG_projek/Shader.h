#pragma once
#include <GL/glew.h>
//Include GLFW
#include <glfw3.h> 
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Shader
{
private:
	const char* shader_in;
	
public:
	Shader(const char* shader_in);
	GLuint createVertex();
	GLuint createFragment();
	bool isVertex();
};

