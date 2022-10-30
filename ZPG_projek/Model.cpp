#include "Model.h"

Model::Model()
{
}

Model::Model(float *points_var, int size) {
    this->VBO = 0;
    this->VAO = 0;
   
    for (int i = 0; i < size; i++) {
        this->points_vector.push_back(points_var[i]);
    }
}


GLuint Model::setVBOVAO(int index, int size, int count, int color_count)
{

    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->points_vector.size(), this->points_vector.data(), GL_STATIC_DRAW); //GL_STATIC_DRAW

    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    
    //glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, count, NULL);
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, count * sizeof(float), NULL);
    glEnableVertexAttribArray(0); //enable vertex attributes

    glVertexAttribPointer(index+1, size, GL_FLOAT, GL_FALSE, count * sizeof(float), (void*)(color_count * sizeof(float)));
    //glVertexAttribPointer(index+1, size, GL_FLOAT, GL_FALSE,0, (void*)0);
    glEnableVertexAttribArray(1); //enable vertex attributes
    

    return VAO;
}
