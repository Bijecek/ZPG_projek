#include "DrawableObject.h"
DrawableObject::DrawableObject(bool isSkybox, float *points, int size, ShaderProgram *sp_light, int index, int size_index, int count, int color_count) {
	Model temp(points, size);
    this->lighting_model = temp;
    this->lighting_VAO = lighting_model.setVBOVAO(isSkybox,index, size_index, count, color_count);
    this->lighting_sp = sp_light;
    //this->lighting_sp->createShaderProgram();

}

void DrawableObject::draw(bool isSkybox, GLFWwindow *window,int size) {
    this->lighting_sp->useShaderProgram(this->lighting_sp->shaderProgram);
    
    this->lighting_sp->setUniform_objectColor(glm::vec3(1, 1, 1));

    this->lighting_sp->setUniform_ambientStrength(this->lighting_sp->point_light->getAmbientStrength());

    this->lighting_sp->setUniform_lightColor(this->lighting_sp->point_light->getLightColor());

    //zakomentovane
    //this->lighting_sp->setUniform_lightPos(this->lighting_sp->dif_light->getLightPosition());
    

    this->lighting_sp->setUniform_viewPos(this->lighting_sp->camera->getPosition());

    this->lighting_sp->setUniform_modelMatrix(this->transformation->getMatrix());



    this->lighting_sp->setUniform_viewMatrix(this->lighting_sp->camera->getView());


    this->lighting_sp->setUniform_projectionMatrix(this->lighting_sp->camera->getProjection());

    

    GLint uniformID = glGetUniformLocation(this->lighting_sp->shaderProgram, "textureUnitID");
    glUniform1i(uniformID, 0);

    GLint uniformID1 = glGetUniformLocation(this->lighting_sp->shaderProgram, "cubeID");
    glUniform1i(uniformID1, 0);

    //this->lighting_sp->useAllPointLights();

    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        this->lighting_sp->useAvailableLights(0.3);
    }
    else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
        this->lighting_sp->useAvailableLights(0.0);
    }
    else {
        this->lighting_sp->useAvailableLights(-1.0);
    }


    this->lighting_sp->checkStatus();

    glBindVertexArray(this->lighting_VAO);

    
    if (isSkybox) {
        glDrawArrays(GL_TRIANGLES, 0, size);
    }
    else {
        if (size % 6 == 0) {
            //glDrawArrays(GL_TRIANGLES, 0, size);
            glDrawArrays(GL_TRIANGLES, 0, size / 6);

        }
        else if (size % 8 == 0) {
            glDrawArrays(GL_QUADS, 0, size / 8);
        }
    }
   
}