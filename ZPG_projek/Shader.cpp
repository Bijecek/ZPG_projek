#include "Shader.h"
Shader::Shader(const char* shader_in) {
	this->shader_in = shader_in;
}
GLuint Shader::createVertex()
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &shader_in, NULL);
	glCompileShader(vertexShader);

	GLint isCompiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &errorLog[0]);

		// Provide the infolog in whatever manor you deem best.
		printf("Error when compiling vertex shader\n");
		for (GLchar c : errorLog) {
			printf("%c", c);
		}
		printf("\n");

		// Exit with failure.
		glDeleteShader(vertexShader); // Don't leak the shader.
		return 0;
	}

	return vertexShader;
}

GLuint Shader::createFragment()
{
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &shader_in, NULL);
	glCompileShader(fragmentShader);

	GLint isCompiled = 0;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &errorLog[0]);

		// Provide the infolog in whatever manor you deem best.
		printf("Error when compiling vertex shader\n");
		for (GLchar c : errorLog) {
			printf("%c", c);
		}
		printf("\n");

		// Exit with failure.
		glDeleteShader(fragmentShader); // Don't leak the shader.
		return 0;
	}

	return fragmentShader;
}
bool Shader::isVertex() {
	if (strstr(shader_in, "gl_Position")) {
		return true;
	}
	return false;
}
