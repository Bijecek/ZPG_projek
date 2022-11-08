#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(glm::vec3 light_Direction)
{
	this->light_Direction = light_Direction;
}

glm::vec3 DirectionalLight::getLight_Direction()
{
	return this->light_Direction;
}
