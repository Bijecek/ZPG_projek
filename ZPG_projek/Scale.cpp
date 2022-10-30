#include "Scale.h"

void Scale::scaling(glm::vec3 size)
{
	this->M = glm::scale(this->M, size);
}
Scale::Scale(){}
