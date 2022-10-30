#pragma once
#include "Camera.h"
class CameraMovement {
private:
	Camera* camera;
	float floating_height = 1.0f;
	bool firstMouse = true;
	float lastX;
	float lastY;
	float sensitivity = 0.1f;
	float yaw = 0.0f;
	float pitch = 0.0f;

public:
	CameraMovement(Camera* camera, int width, int height);
	void handleMouse(GLFWwindow* window, double xpos, double ypos);
	void handleKeys(GLFWwindow* window);
};