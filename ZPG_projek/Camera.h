#pragma once
#include "Shader.h"
#include <GL/glew.h>
//Include GLFW
#include <glfw3.h> 
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <cmath>
//#include "Observer.h"
#include "Subject.h"
//class Observer;
using namespace std;

class Camera : public Subject//dedi ze subjectu)
{
private:
	float fov;
	float near;
	float far;
	float aspect;
	const float radius = 10.0f;
	float floating_height = 1.0f;
	bool firstMouse = true;
	float lastX;
	float lastY;
	float sensitivity = 0.05f;
	float yaw = 0.0f;
	float pitch = 0.0f;

public:
	glm::vec3 direction;
	glm::vec3 front;
	glm::vec3 position;
	glm::vec3 up;
	glm::vec3 camera_up;
	glm::mat4 view;
	glm::mat4 projection;
	Camera(glm::vec3 position, float fov, float aspect, float near, float far);
	glm::mat4 getView();
	glm::mat4 getProjection();


	void setMovement(int width, int height);
	void handleMouse(GLFWwindow* window, double xpos, double ypos);
	void handleKeys(GLFWwindow* window);
	glm::vec3 getPosition();

	//vector<Observer*> obs;
	//void update();
	//void attachObs(Observer* obs);

	
};

