#include "SpecularLight.h"

SpecularLight::SpecularLight(glm::vec3 viewPos)
{
	this->viewPos = viewPos;
}

glm::vec3 SpecularLight::getViewPosition()
{
	return this->viewPos;
}
