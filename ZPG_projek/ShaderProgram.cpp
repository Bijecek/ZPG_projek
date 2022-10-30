#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
	this->shader_Array = vector<Shader*>(0);
	this->shader_code = {};
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
}

void ShaderProgram::addAmbientLight(float ambientStrength, glm::vec3 lightColor) {
	this->amb_light = new AmbientLight(ambientStrength, lightColor);
}

void ShaderProgram::addDiffuseLight(glm::vec3 lightPos)
{
	this->dif_light = new DiffuseLight(lightPos);
}

void ShaderProgram::addSpecularLight(glm::vec3 viewPos)
{
	this->spe_light = new SpecularLight(viewPos);
}
