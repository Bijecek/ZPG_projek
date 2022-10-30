#include "DrawableObject.h"
DrawableObject::DrawableObject(float *points, int size, ShaderProgram *sp_light, int index, int size_index, int count, int color_count) {
	Model temp(points, size);
    this->lighting_model = temp;
    this->lighting_VAO = lighting_model.setVBOVAO(index, size_index, count, color_count);
    this->lighting_sp = sp_light;
    this->lighting_sp->createShaderProgram();
}

void DrawableObject::draw(GLFWwindow *window,string draw_something) {
    this->lighting_sp->useShaderProgram(this->lighting_sp->shaderProgram);
    
    this->lighting_sp->setUniform_objectColor(glm::vec3(1, 1, 1));

    this->lighting_sp->setUniform_ambientStrength(this->lighting_sp->amb_light->getAmbientStrength());

    this->lighting_sp->setUniform_lightColor(this->lighting_sp->amb_light->getAmbientLight());


    this->lighting_sp->setUniform_lightPos(this->lighting_sp->dif_light->getLightPosition());
 
    this->lighting_sp->setUniform_viewPos(this->lighting_sp->camera->getPosition());

    this->lighting_sp->setUniform_modelMatrix(this->transformation->getMatrix());


    this->lighting_sp->setUniform_viewMatrix(this->lighting_sp->camera->getView());


    this->lighting_sp->setUniform_projectionMatrix(this->lighting_sp->camera->getProjection());

    this->lighting_sp->checkStatus();

    glBindVertexArray(this->lighting_VAO);

    
    if (draw_something == "GL_TRIANGLES_QUADS") {
        glDrawArrays(GL_TRIANGLES, 0, 2880);
    }
    else if (draw_something == "GL_MONKEY") {
        glDrawArrays(GL_TRIANGLES,0, 2904);
    }
    else if (draw_something == "GL_QUADS") {
        glDrawArrays(GL_QUADS, 0, 4);
    }
    else if (draw_something == "GL_TREE") {
        glDrawArrays(GL_TRIANGLES, 0, 92814);
    }
    else if (draw_something == "GL_BUSH") {
        glDrawArrays(GL_TRIANGLES, 0, 8730);
    }
    else {
        glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
    }
}