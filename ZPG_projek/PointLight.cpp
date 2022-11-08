#include "PointLight.h"

PointLight::PointLight(float ambientStrength, glm::vec3 lightColor, glm::vec3 lightPos, glm::vec3 viewPos)
{
	this->ambientStrength = ambientStrength;
	this->lightColor = lightColor;
	this->lightPos = lightPos;
	this->viewPos = viewPos;
}

float PointLight::getAmbientStrength()
{
	return this->ambientStrength;
}

glm::vec3 PointLight::getLightColor()
{
	return this->lightColor;
}

glm::vec3 PointLight::getLightPos()
{
	return this->lightPos;
}

glm::vec3 PointLight::getViewPos()
{
	return this->viewPos;
}
