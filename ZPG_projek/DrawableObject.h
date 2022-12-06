#include <GL/glew.h>
//Include GLFW
#include <glfw3.h> 
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <malloc.h>
#include <cstdio>
#include <iostream>
#include "Model.h"
#include "ShaderProgram.h"
#include "CompleteTransformation.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

class DrawableObject : public CompleteTransformation
{
private:
	int object_id;
	Model *lighting_model;
	ShaderProgram *lighting_sp;
	GLuint lighting_VAO;
	GLuint texture_id;
public:
	CompleteTransformation* transformation = new CompleteTransformation();
	float angle = 0;

public:
	int getObjectId();
	void setObjectId(int object_id);
	DrawableObject(bool moreObjects, bool isSkybox, bool hasUvCoords, float* points, int size, ShaderProgram* sp_light, int index, int size_index, int count, int color_count);
	void draw(GLFWwindow* window, int size);
	GLuint getTextureId();
	void rotateAroundParentX(glm::vec3 parent_coords, float speed, float radius);
	void rotateAroundParentY(glm::vec3 parent_coords, float speed, float radius);
	void rotateAroundParentZ(glm::vec3 parent_coords, float speed, float radius);

	void motionLineSegment(glm::vec3 from, glm::vec3 to);

	//motion
	float t = 0.001;
	float delta = 0;
};

