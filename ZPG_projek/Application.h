#pragma once
#include "Shader.h"
#include <GL/glew.h>
//Include GLFW
#include <glfw3.h> 
//Include the standard C++ headers  
//#include "Model.h"
//#include "ShaderProgram.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <malloc.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
using namespace std;

class Application
{
	GLFWwindow* window;
	int width;
	int height;

public:
//	static Camera* camera_movement;
	Application();
	//static Camera* camera_movement;
	void createWindow(int width, int height, const char* title);
	void printVersionInfo();
	void run();
	static void errorCallback(int error, const char* description);

};

