#include "Translate.h"

void Translate::translation(glm::vec3 ax)
{
	this->M = glm::translate(this->M, ax);
}
Translate::Translate(){}