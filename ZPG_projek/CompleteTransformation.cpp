#include "CompleteTransformation.h"

glm::mat4 CompleteTransformation::getMatrix()
{
    glm::mat4 matrix = translate->getMatrix() * rotate->getMatrix()  * scale->getMatrix();
    return matrix;
}
