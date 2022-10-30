#pragma once
class Scenes {
public:
	virtual void drawFourSpheresScene(GLFWwindow* window, int width, int height) = 0;
	//virtual void drawScene(GLFWwindow* window, int width, int height) = 0;
	virtual void drawOneSphereLight(GLFWwindow* window, int width, int height) = 0;
	virtual void drawMultipleObjects(GLFWwindow* window, int width, int height) = 0;
};
