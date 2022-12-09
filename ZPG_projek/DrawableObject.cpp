#include "DrawableObject.h"
int DrawableObject::getObjectId()
{
    return this->object_id;
}
void DrawableObject::setObjectId(int object_id)
{
    this->object_id = object_id;
}
DrawableObject::DrawableObject(bool moreObjects, bool isSkybox, bool hasUvCoords, float* points, int size, ShaderProgram* sp_light, int index, int size_index, int count, int color_count) {
    Model *temp = new Model();
    if (sp_light->vbovao_previous == NULL) {
        temp = new Model(points, size);
        this->lighting_model = temp;
        this->lighting_VAO = lighting_model->setVBOVAO(sp_light->getTexture(), isSkybox, hasUvCoords, index, size_index, count, color_count);
        this->lighting_sp = sp_light;
        this->texture_id = lighting_model->getTextureId();
    }
    else {
        temp = new Model(points, size);
        this->lighting_model = temp;
        this->lighting_VAO = sp_light->vbovao_previous;
        this->lighting_sp = sp_light;
        this->texture_id = sp_light->saveTextureId;
    }
    if (moreObjects) {
        sp_light->vbovao_previous = this->lighting_VAO;
        sp_light->saveTextureId = this->texture_id;
    }
    //this->lighting_sp->createShaderProgram();

}

void DrawableObject::draw(GLFWwindow *window,int size) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->getTextureId());


    this->lighting_sp->useShaderProgram(this->lighting_sp->shaderProgram);
    
    this->lighting_sp->setUniform_objectColor(glm::vec3(1, 1, 1));

    if (this->lighting_sp->point_light != NULL) {
        this->lighting_sp->setUniform_ambientStrength(this->lighting_sp->point_light->getAmbientStrength());

        //this->lighting_sp->setUniform_lightColor(this->lighting_sp->point_light->getLightColor());
    }
    else {
        this->lighting_sp->setUniform_ambientStrength(0.1);
    }
    this->lighting_sp->setUniform_lightColor(glm::vec3(1,1,1));
    //not sure
    //this->lighting_sp->setUniform_lightPos(glm::vec3(1, 2, 1));
    //zakomentovane
    //this->lighting_sp->setUniform_lightPos(this->lighting_sp->dif_light->getLightPosition());
    this->lighting_sp->setUniform_modelMatrix(this->transformation->getMatrix());

    //glm::mat4 temp = this->transformation->getMatrix();

    //glm::vec3 tmp2 = glm::vec3(this->transformation->getMatrix() * glm::vec4(1,0,1, 1.0));
    //odkomentovat
    //glm::mat4 tmp_fin = glm::transpose(glm::inverse(temp));
    
    this->lighting_sp->setUniform_viewPos(this->lighting_sp->camera->getPosition());



    //odkomentovat
    this->lighting_sp->setUniform_viewMatrix(this->lighting_sp->camera->getView());

    //odkomentovat
    this->lighting_sp->setUniform_projectionMatrix(this->lighting_sp->camera->getProjection());
    
    
    GLint uniformID = glGetUniformLocation(this->lighting_sp->shaderProgram, "textureUnitID");
    glUniform1i(uniformID, 0);

    GLint uniformID1 = glGetUniformLocation(this->lighting_sp->shaderProgram, "cubeID");
    glUniform1i(uniformID1, 0);
    GLint uniformID2 = glGetUniformLocation(this->lighting_sp->shaderProgram, "texture_Sphere");
    glUniform1i(uniformID2,0);
    GLint uniformID3 = glGetUniformLocation(this->lighting_sp->shaderProgram, "houseID");
    glUniform1i(uniformID3, 0);
    
    

    //this->lighting_sp->useAllPointLights();

    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        this->lighting_sp->useAvailableLights(5.5);
    }
    else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
       this->lighting_sp->useAvailableLights(0.0);
    }
    else {
        this->lighting_sp->useAvailableLights(-1.0);
    }


    this->lighting_sp->checkStatus();

    glBindVertexArray(this->lighting_VAO);

    
    
    glDrawArrays(GL_TRIANGLES, 0, size);
    
    /*
    else {
        if (size % 6 == 0) {
            //glDrawArrays(GL_TRIANGLES, 0, size);
            glDrawArrays(GL_TRIANGLES, 0, size );

        }
        else if (size % 8 == 0) {
            //glDrawArrays(GL_QUADS, 0, size / 8);
        }
    }
    */
   
}

GLuint DrawableObject::getTextureId()
{
    return this->texture_id;
}

void DrawableObject::rotateAroundParentX(glm::vec3 parent_coords, float speed, float radius)
{
    
    glm::vec3 new_position;
    new_position = this->transformation->getMatrix()[3];
    this->transformation->setTranslate()->translation(glm::vec3(-new_position.x, -new_position.y, -new_position.z));
    new_position.x = parent_coords.x;
    new_position.y = parent_coords.y + cos(glm::radians(angle)) * radius;
    new_position.z = parent_coords.z + sin(glm::radians(angle)) * radius;
    //this->transformation->setRotate()->rotation(glm::radians(angle), glm::vec3(1,0,0));

    angle += speed;
    if (angle >= 360) {
        angle = 0;
    }

    this->transformation->setTranslate()->translation(glm::vec3(new_position.x, new_position.y, new_position.z));
    

}
void DrawableObject::rotateAroundParentY(glm::vec3 parent_coords, float speed, float radius)
{

    glm::vec3 new_position;
    new_position = this->transformation->getMatrix()[3];
    this->transformation->setTranslate()->translation(glm::vec3(-new_position.x, -new_position.y, -new_position.z));
    new_position.x = parent_coords.x + cos(glm::radians(angle)) * radius;
    new_position.y = parent_coords.y;
    new_position.z = parent_coords.z + sin(glm::radians(angle)) * radius;



    angle += speed;
    if (angle >= 360) {
        angle = 0;
    }

    this->transformation->setTranslate()->translation(glm::vec3(new_position.x, new_position.y, new_position.z));


}
void DrawableObject::rotateAroundParentZ(glm::vec3 parent_coords, float speed, float radius)
{

    glm::vec3 new_position;
    new_position = this->transformation->getMatrix()[3];
    this->transformation->setTranslate()->translation(glm::vec3(-new_position.x, -new_position.y, -new_position.z));
    new_position.x = parent_coords.x + cos(glm::radians(angle)) * radius;
    new_position.y = parent_coords.y + sin(glm::radians(angle)) * radius;
    new_position.z = parent_coords.z;

    angle += speed;
    if (angle >= 360) {
        angle = 0;
    }

    this->transformation->setTranslate()->translation(glm::vec3(new_position.x, new_position.y, new_position.z));


}

void DrawableObject::motionLineSegment(glm::vec3 from, glm::vec3 to)
{
    glm::vec3 point = (to-from) * t;
    this->transformation->setTranslate()->translation(point);
    delta += t;
    if (delta >= 1.0f || delta <= 0.0f) {
        t *= -1;
        glm::mat4 tmp = this->transformation->getMatrix();
        cout << tmp[3].x <<" "<< tmp[3].y <<" "<< tmp[3].z << endl;
    }
}
