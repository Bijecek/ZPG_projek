#include "DrawableObject.h"
DrawableObject::DrawableObject(float *points, int size, ShaderProgram *sp_light, int index, int size_index, int count, int color_count) {
	Model temp(points, size);
	//this->m = temp;
    this->lighting_model = temp;
    //this->VAO = m.setVBOVAO(index, size_index, count, color_count);
    this->lighting_VAO = lighting_model.setVBOVAO(index, size_index, count, color_count);
	//this->sp = sp;
    this->lighting_sp = sp_light;
    //this->sp->createShaderProgram();
    this->lighting_sp->createShaderProgram();
}

void DrawableObject::draw(GLFWwindow *window,string draw_something) {
    /*
    
    glm::mat4 view = glm::mat4(0.1f); // make sure to initialize matrix to identity matrix first
    float radius = 10.0f;
    float camX = static_cast<float>(sin(glfwGetTime()) * radius);
    float camZ = static_cast<float>(cos(glfwGetTime()) * radius);
    //view = glm::lookAt(glm::vec3(camX, 0.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));


    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)5000 / (float)3500, 0.1f, 100.0f);
    */
    

    /*
    glm::mat4 M = glm::mat4(1.0f);
    M = glm::rotate(glm::mat4(1.0f), GLfloat(0.5f), glm::vec3(0.0f, 1.0f, 0.0f));

    M = glm::rotate(M, GLfloat(0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
    M = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 1));
    M = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    */
 //   GLuint shaderProgram = this->sp->createShaderProgram();
 //   cout << shaderProgram << endl;
    //Toto by melo byt v shaderProgramu
    /*
    glUseProgram(this->sp->shaderProgram);


    GLint t_matrix_id = glGetUniformLocation(this->sp->shaderProgram, "modelMatrix");
    glUniformMatrix4fv(t_matrix_id, 1, GL_FALSE,&this->transformation->getMatrix()[0][0]);


    GLint v_matrix_id = glGetUniformLocation(this->sp->shaderProgram, "viewMatrix");
    glUniformMatrix4fv(v_matrix_id, 1, GL_FALSE, &this->sp->camera->getView()[0][0]);


    GLint p_matrix_id = glGetUniformLocation(this->sp->shaderProgram, "projectionMatrix");
    glUniformMatrix4fv(p_matrix_id, 1, GL_FALSE, &this->sp->camera->getProjection()[0][0]);

    
    */
    //GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");

    //glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &M[0][0]);
    /*
    this->sp->checkStatus();


    glBindVertexArray(this->VAO);
    */

    // draw triangles
    
    if (draw_something == "GL_TRIANGLES_QUADS") {
        //glDrawArrays(GL_TRIANGLES, 0, 3*12); //mode,first,count //GL_TRIANGLES
//        glDrawArrays(GL_TRIANGLES, 0, 2880);
    }
    else if (draw_something == "GL_QUADS") {
//        glDrawArrays(GL_QUADS, 0, 4);
    }
    else {
//        glDrawArrays(GL_TRIANGLES, 0, 3*12);
    }

//    GLuint shaderProgram_light = this->lighting_sp->createShaderProgram();
    glUseProgram(this->lighting_sp->shaderProgram);

    

    GLint t_matrix_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "objectColor");
    glUniform3fv(t_matrix_light, 1, glm::value_ptr(glm::vec3(1,1,1)));

    GLint ambient_strength = glGetUniformLocation(this->lighting_sp->shaderProgram, "ambientStrength");
    glUniform1f(ambient_strength, this->lighting_sp->amb_light->getAmbientStrength());

    GLint v_matrix_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "lightColor");
    glUniform3fv(v_matrix_light, 1, glm::value_ptr(this->lighting_sp->amb_light->getAmbientLight()));

    GLint p_matrix_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "lightPos");
    glUniform3fv(p_matrix_light, 1, glm::value_ptr(this->lighting_sp->dif_light->getLightPosition()));

    GLint cam_matrix_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "viewPos");
    //konstantní pozice odlesku od kamery
    //glUniform3fv(cam_matrix_light, 1, glm::value_ptr(this->lighting_sp->spe_light->getViewPosition()));
    //dynamická pozice odlesku od kamery
    glUniform3fv(cam_matrix_light, 1, glm::value_ptr(this->lighting_sp->camera->getPosition()));



    
    //this->transformation->translate->translation(glm::vec3(0,1.f,0));

    /*
    GLint t_matrix_id_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "modelMatrix");
    glUniformMatrix4fv(t_matrix_id_light, 1, GL_FALSE, &this->transformation->getMatrix()[0][0]);


    GLint v_matrix_id_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "viewMatrix");
    glUniformMatrix4fv(v_matrix_id_light, 1, GL_FALSE, &this->sp->camera->getView()[0][0]);


    GLint p_matrix_id_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "projectionMatrix");
    glUniformMatrix4fv(p_matrix_id_light, 1, GL_FALSE, &this->sp->camera->getProjection()[0][0]);
    
    */
    GLint t_matrix_id_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "modelMatrix");
    glUniformMatrix4fv(t_matrix_id_light, 1, GL_FALSE, &this->transformation->getMatrix()[0][0]);


    GLint v_matrix_id_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "viewMatrix");
    glUniformMatrix4fv(v_matrix_id_light, 1, GL_FALSE, &this->lighting_sp->camera->getView()[0][0]);


    GLint p_matrix_id_light = glGetUniformLocation(this->lighting_sp->shaderProgram, "projectionMatrix");
    glUniformMatrix4fv(p_matrix_id_light, 1, GL_FALSE, &this->lighting_sp->camera->getProjection()[0][0]);
    this->lighting_sp->checkStatus();

    glBindVertexArray(this->lighting_VAO);

    
    if (draw_something == "GL_TRIANGLES_QUADS") {
        //glDrawArrays(GL_TRIANGLES, 0, 3*12); //mode,first,count //GL_TRIANGLES
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