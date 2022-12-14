#pragma once
#include <GL/glew.h>

//Include GLFW  
#include <glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr


class Transformation
{
protected:
	glm::mat4 M = glm::mat4(1.0f);
	/*
	Rotate* rotate = new Rotate();
	Translate* translate = new Translate();
	Scale* scale = new Scale();
	*/
	glm::mat4 final_matrix;

public:
	Transformation();
	glm::mat4 getMatrix();
};

