#pragma once
#include "Rotate.h"
#include "Translate.h"
#include "Scale.h"
class CompleteTransformation
{
private:
	Rotate* rotate = new Rotate();
	Translate* translate = new Translate();
	Scale* scale = new Scale();

public:
	Scale* setScale();
	Rotate* setRotate();
	Translate* setTranslate();
	glm::mat4 getMatrix();
	glm::vec3 getPosition();

};

