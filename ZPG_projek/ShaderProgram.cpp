#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
	this->shader_Array = vector<Shader*>(0);
	this->shader_code = {};
	//camera->attachObs(this);
};
//pridano
ShaderProgram::ShaderProgram(Camera *camera) {
	this->shader_Array = vector<Shader*>(0);
	this->shader_code = {};
	//camera->attachObs(this);
	this->camera = camera;
};

void ShaderProgram::addShader(std::string path) {
	ifstream file(path);
	if (!file.is_open())
	{
		cout << "Unable to open file " << path << endl;
		//exit(1);
	}
	std::stringstream fileData;
	fileData << file.rdbuf();
	shader_code.push_back(fileData.str());

	file.close();
	this->shader_Array.push_back(new Shader(shader_code[shader_code.size() - 1].c_str()));
	//Tohle funguje 
	//shader_Array.push_back(Shader("Ahoj jak se"));
}

void ShaderProgram::attachShaders() {
	cout << "Velikost pole : "<< endl;
	cout << shader_Array.size() << endl;
	for (int i = 0; i < shader_Array.size(); i++) {
		if (shader_Array[i]->isVertex()) {
			glAttachShader(shaderProgram, shader_Array[i]->createVertex());
		}
		else {
			glAttachShader(shaderProgram, shader_Array[i]->createFragment());

		}
	}
	glLinkProgram(shaderProgram);

}
void ShaderProgram::checkStatus() {
	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}
void ShaderProgram::createShaderProgram()
{
	this->shaderProgram = glCreateProgram();

	attachShaders();

	//return shaderProgram;


}
void ShaderProgram::useCamera(Camera* camera)
{
	this->camera = camera;
	//this->camera->attachObs(this);
}

//void ShaderProgram::addAmbientLight(float ambientStrength, glm::vec3 lightColor) {
//	this->amb_light = new AmbientLight(ambientStrength, lightColor);
//}

//void ShaderProgram::addDiffuseLight(glm::vec3 lightPos)
//{
//	this->dif_light = new DiffuseLight(lightPos);
//}

//void ShaderProgram::addSpecularLight(glm::vec3 viewPos)
//{
//	this->spe_light = new SpecularLight(viewPos);
//}

void ShaderProgram::useShaderProgram(GLuint shader_program)
{
	glUseProgram(shader_program);
}

void ShaderProgram::setUniform_objectColor(glm::vec3 color)
{
	GLint t_matrix_light = glGetUniformLocation(this->shaderProgram, "objectColor");
	glUniform3fv(t_matrix_light, 1, glm::value_ptr(glm::vec3(1, 1, 1)));
}

void ShaderProgram::setUniform_ambientStrength(float ambientStrength)
{
	GLint ambient_strength = glGetUniformLocation(this->shaderProgram, "ambientStrength");
	glUniform1f(ambient_strength, ambientStrength);
}

void ShaderProgram::setUniform_lightColor(glm::vec3 lightColor)
{
	GLint v_matrix_light = glGetUniformLocation(this->shaderProgram, "lightColor");
	glUniform3fv(v_matrix_light, 1, glm::value_ptr(lightColor));

}

void ShaderProgram::setUniform_lightPos(glm::vec3 lightPos)
{
	//GLint p_matrix_light = glGetUniformLocation(this->shaderProgram, "lightPos");
	//glUniform3fv(p_matrix_light, 1, glm::value_ptr(lightPos));

}

void ShaderProgram::setUniform_viewPos(glm::vec3 viewPos)
{
	GLint cam_matrix_light = glGetUniformLocation(this->shaderProgram, "viewPos");
	//konstantní pozice odlesku od kamery
	//glUniform3fv(cam_matrix_light, 1, glm::value_ptr(this->lighting_sp->spe_light->getViewPosition()));
	//dynamická pozice odlesku od kamery
	glUniform3fv(cam_matrix_light, 1, glm::value_ptr(viewPos));

}

void ShaderProgram::setUniform_modelMatrix(glm::mat4 modelMatrix)
{
	GLint t_matrix_id_light = glGetUniformLocation(this->shaderProgram, "modelMatrix");
	glUniformMatrix4fv(t_matrix_id_light, 1, GL_FALSE, &modelMatrix[0][0]);

}

void ShaderProgram::setUniform_viewMatrix(glm::mat4 viewMatrix)
{
	GLint v_matrix_id_light = glGetUniformLocation(this->shaderProgram, "viewMatrix");
	glUniformMatrix4fv(v_matrix_id_light, 1, GL_FALSE, &viewMatrix[0][0]);

}

void ShaderProgram::setUniform_projectionMatrix(glm::mat4 projectionMatrix)
{
	GLint p_matrix_id_light = glGetUniformLocation(this->shaderProgram, "projectionMatrix");
	glUniformMatrix4fv(p_matrix_id_light, 1, GL_FALSE, &projectionMatrix[0][0]);

}

void ShaderProgram::addPointLight(float ambientStrength, glm::vec3 lightColor, glm::vec3 lightPos, glm::vec3 viewPos)
{
	this->point_light = new PointLight(ambientStrength, lightColor, lightPos, viewPos);
	lightPositions.push_back(point_light->getLightPos());
}

void ShaderProgram::useAvailableLights(float value)
{
	this->useShaderProgram(this->shaderProgram);
	int index = 0;
	if (this->lightPositions.size() != 0) {
		for (glm::vec3 position : lightPositions) {
			std::string convert_toString = "lights[" + std::to_string(index) + "].light_Pos";
			GLint p_matrix_light = glGetUniformLocation(this->shaderProgram, convert_toString.c_str());
			glUniform3fv(p_matrix_light, 1, glm::value_ptr(this->lightPositions[index]));
			index++;
		}
		//GLint p_matrix_light = glGetUniformLocation(this->shaderProgram, "lights[0].light_Pos");
		//glUniform3fv(p_matrix_light, 1, glm::value_ptr(this->lightPositions[0]));
		//GLint p_matrix_light1 = glGetUniformLocation(this->shaderProgram, "lights[1].light_Pos");
		//glUniform3fv(p_matrix_light1, 1, glm::value_ptr(this->lightPositions[1]));
	}
	int index2 = 0;
	if (this->lightDirections.size() != 0) {
		for (glm::vec3 direct: lightDirections) {
			std::string convert_toString = "lights[" + std::to_string(index) + "].direct_Light_Direct";
			GLint direct_light = glGetUniformLocation(this->shaderProgram, convert_toString.c_str());
			glUniform3fv(direct_light, 1, glm::value_ptr(this->lightDirections[index2]));
			index++;
			index2++;
		}
		//GLint direct_light = glGetUniformLocation(this->shaderProgram, "lights[2].direct_Light_Direct");
		//glUniform3fv(direct_light, 1, glm::value_ptr(this->directional_light->getLight_Direction()));
	}
	std::string convert_toString = "lights[" + std::to_string(index) + "].lightPosition_var";
	GLint p_matrix_light12 = glGetUniformLocation(this->shaderProgram, convert_toString.c_str());
	glUniform3fv(p_matrix_light12, 1, glm::value_ptr(this->camera->getPosition()));

	convert_toString = "lights[" + std::to_string(index) + "].lightDirection_var";
	GLint p_matrix_light13 = glGetUniformLocation(this->shaderProgram, convert_toString.c_str());
	glUniform3fv(p_matrix_light13, 1, glm::value_ptr(this->camera->front));
	
	convert_toString = "lights[" + std::to_string(index) + "].cutOff_var";
	GLint p_matrix_light14 = glGetUniformLocation(this->shaderProgram, convert_toString.c_str());
	glUniform1f(p_matrix_light14, glm::cos(glm::radians(12.5f)));

	convert_toString = "lights[" + std::to_string(index) + "].outerCut_var";
	GLint p_matrix_light15 = glGetUniformLocation(this->shaderProgram, convert_toString.c_str());
	glUniform1f(p_matrix_light15, glm::cos(glm::radians(15.0f)));

	if (value >= 0) {
		convert_toString = "lights[" + std::to_string(index) + "].flashlight_Strength";
		GLint p_matrix_light16 = glGetUniformLocation(this->shaderProgram, convert_toString.c_str());
		glUniform1f(p_matrix_light16, value);
	}
}

void ShaderProgram::addDirectionalLight(glm::vec3 direction)
{
	this->directional_light = new DirectionalLight(direction);
	lightDirections.push_back(directional_light->getLight_Direction());
}

void ShaderProgram::setTexture(const char* texture_name)
{
	this->texture_name = texture_name;
}

const char* ShaderProgram::getTexture()
{
	return this->texture_name;
}

/*
void ShaderProgram::notify()
{
	//cout << "Notified in sp" << endl;
	GLint v_matrix_id_light = glGetUniformLocation(this->shaderProgram, "viewMatrix");
	glUniformMatrix4fv(v_matrix_id_light, 1, GL_FALSE, &this->camera->getView()[0][0]);
}
*/
