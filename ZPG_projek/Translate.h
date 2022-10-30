#pragma once
#include "Transformation.h"
class Translate : public Transformation
{
public:
	void translation(glm::vec3 ax);
	Translate();
};

