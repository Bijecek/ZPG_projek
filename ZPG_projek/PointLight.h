#include <GL/glew.h>
//Include GLFW
#include <glfw3.h> 
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <malloc.h>
#include <cstdio>
#include <iostream>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
class PointLight
{
private:
	float ambientStrength;
	glm::vec3 lightColor;
	glm::vec3 lightPos;
	glm::vec3 viewPos;
public:
	PointLight(float ambientStrength, glm::vec3 lightColor, glm::vec3 lightPos, glm::vec3 viewPos);
	float getAmbientStrength();
	glm::vec3 getLightColor();
	glm::vec3 getLightPos();
	glm::vec3 getViewPos();
};

