#pragma once
#include "Transformation.h"
class Scale : public Transformation
{
public:
	void scaling(glm::vec3 size);
	Scale();
};

