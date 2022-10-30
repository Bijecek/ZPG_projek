#pragma once
#include "Rotate.h"
#include "Translate.h"
#include "Scale.h"
class CompleteTransformation
{
public:
	Rotate* rotate = new Rotate();
	Translate* translate = new Translate();
	Scale* scale = new Scale();

public:
	glm::mat4 getMatrix();

};

