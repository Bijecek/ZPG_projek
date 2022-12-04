#pragma once
#include "Transformation.h"
class Translate : public Transformation
{
public:
	glm::vec3 pos = glm::vec3(0);
	void translation(glm::vec3 ax);
	Translate();
};

