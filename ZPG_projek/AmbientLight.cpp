#include "AmbientLight.h"
AmbientLight::AmbientLight(float ambientStrength, glm::vec3 lightColor) {
	this->ambientStrength = ambientStrength;
	this->lightColor = lightColor;
}
glm::vec3 AmbientLight::getAmbientLight() {
	return this->lightColor;
}
float AmbientLight::getAmbientStrength() {
	return this->ambientStrength;
}
