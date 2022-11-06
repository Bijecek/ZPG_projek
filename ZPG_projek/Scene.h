#pragma once
#include "Shader.h"
#include <GL/glew.h>
//Include GLFW
#include <glfw3.h> 
//Include the standard C++ headers  
#include "Model.h"
#include "ShaderProgram.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <malloc.h>
#include "DrawableObject.h"
#include "CameraMovement.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
//#include "sphere.h"
#include "Scenes.h"
#include "Observer.h"

using namespace std;

class Scene : public Scenes
{
public:
	static Camera* camera_movement;
	Scene();
	void drawScene(GLFWwindow* window, int width, int height);
	void drawFourSpheresScene(GLFWwindow* window, int width, int height);
	void drawOneSphereLight(GLFWwindow* window, int width, int height);
	void drawMultipleObjects(GLFWwindow* window, int width, int height);
	static void mouseCallbackWrapper(GLFWwindow* window, double xpos, double ypos);
};

