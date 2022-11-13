#pragma once
#include <GL/glew.h>
//Include GLFW
#include <glfw3.h> 
#include <SOIL.h>
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <malloc.h>
#include <cstdio>
#include <iostream>
using namespace std;

class Model
{
private:
	GLuint VBO;
	GLuint VAO;
	vector<float> points_vector;
	GLuint texture_id;
public:
	Model();
	Model(float* points_var, int size);
	GLuint setVBOVAO(const char* texture_name,bool isSkybox, bool isPlain,int index, int size, int count, int color_count);
	GLuint getTextureId();
};

