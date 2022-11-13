#pragma once
#include <GL/glew.h>
//Include GLFW
#include <glfw3.h> 
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Camera.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
class Light
{
public:
	glm::vec3 light_Pos;
	glm::vec3 direct_Light_Direct;
	glm::vec3 lightPosition_var;
	glm::vec3 lightDirection_var;
	float cutOff_var;
	float outerCut_var;
	float flashlight_Strength;
};

