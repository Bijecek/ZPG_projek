#include "DiffuseLight.h"

DiffuseLight::DiffuseLight(glm::vec3 lightPos)
{
	this->lightPos = lightPos;
}

glm::vec3 DiffuseLight::getLightPosition()
{
	return this->lightPos;
}
