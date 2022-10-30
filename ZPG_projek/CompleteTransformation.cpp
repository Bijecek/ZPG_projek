#include "CompleteTransformation.h"

glm::mat4 CompleteTransformation::getMatrix()
{
    glm::mat4 matrix = translate->getMatrix() * rotate->getMatrix()  * scale->getMatrix();
    return matrix;
}
Scale* CompleteTransformation::setScale() {
    return this->scale;
}
Rotate* CompleteTransformation::setRotate() {
    return this->rotate;
}
Translate* CompleteTransformation::setTranslate() {
    return this->translate;
}
