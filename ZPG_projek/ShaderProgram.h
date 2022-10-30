#pragma once
#include "Shader.h"
#include "AmbientLight.h"
#include "DiffuseLight.h"
#include "SpecularLight.h"
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

using namespace std;

class ShaderProgram
{
public:
	vector<Shader*> shader_Array;
	GLuint shaderProgram;
	vector<string> shader_code;
	AmbientLight* amb_light;
	DiffuseLight* dif_light;
	SpecularLight* spe_light;
public:
	Camera* camera;
	ShaderProgram();
	void addShader(std::string path);
	void createShaderProgram();
	void checkStatus();
	void attachShaders();
	void useCamera(Camera* camera);
	void addAmbientLight(float ambientStrength, glm::vec3 lightColor);
	void addDiffuseLight(glm::vec3 lightPos);
	void addSpecularLight(glm::vec3 viewPos);


	void useShaderProgram(GLuint shader_program);
	void setUniform_objectColor(glm::vec3 color);
	void setUniform_ambientStrength(float ambientStrength);
	void setUniform_lightColor(glm::vec3 lightColor);
	void setUniform_lightPos(glm::vec3 lightPos);
	void setUniform_viewPos(glm::vec3 viewPos);
	void setUniform_modelMatrix(glm::mat4 modelMatrix);
	void setUniform_viewMatrix(glm::mat4 viewMatrix);
	void setUniform_projectionMatrix(glm::mat4 projectionMatrix);
};

