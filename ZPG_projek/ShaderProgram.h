#pragma once
#include "Shader.h"
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
#include "PointLight.h"
#include "DirectionalLight.h"
#include "Model.h"

using namespace std;

class ShaderProgram : public Observer
{
public:
	vector<Shader*> shader_Array;
	GLuint shaderProgram;
	vector<string> shader_code;
	
	PointLight* point_light;
	DirectionalLight* directional_light;


	vector<glm::vec3> lightPositions;
	vector<glm::vec3> lightDirections;

	//try
	GLuint vbovao_previous;
	GLuint saveTextureId;
	const char* texture_name;
public:
	Camera* camera;
	ShaderProgram();
	ShaderProgram(Camera* camera);
	void addShader(std::string path);
	void createShaderProgram();
	void checkStatus();
	void attachShaders();
	void useCamera(Camera* camera);
	


	void useShaderProgram(GLuint shader_program);
	void setUniform_objectColor(glm::vec3 color);
	void setUniform_ambientStrength(float ambientStrength);
	void setUniform_lightColor(glm::vec3 lightColor);
	void setUniform_lightPos(glm::vec3 lightPos);
	void setUniform_viewPos(glm::vec3 viewPos);
	void setUniform_modelMatrix(glm::mat4 modelMatrix);
	void setUniform_viewMatrix(glm::mat4 viewMatrix);
	void setUniform_projectionMatrix(glm::mat4 projectionMatrix);

	void addPointLight(float ambientStrength, glm::vec3 lightColor, glm::vec3 lightPos, glm::vec3 viewPos);
	void useAvailableLights(float value);

	void addDirectionalLight(glm::vec3 direction);

	void setTexture(const char* texture_name);
	const char* getTexture();
	void update(Subject* sub);
	// Inherited via Observer
	//virtual void notify() override;
};

