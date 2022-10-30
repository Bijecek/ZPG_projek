#include "Rotate.h"

void Rotate::rotation(GLfloat angle, glm::vec3 ax)
{
	this->M = glm::rotate(this->M, angle, ax);
}
Rotate::Rotate() {

}
