#pragma once
#include "Transformation.h"
class Rotate : public Transformation
{
public:
	void rotation(GLfloat angle, glm::vec3 ax);
	Rotate();
};

