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


GLuint Model::setVBOVAO(bool isSkybox, int index, int size, int count, int color_count)
{
    if (!isSkybox) {
        glGenBuffers(1, &VBO); // generate the VBO
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->points_vector.size(), this->points_vector.data(), GL_STATIC_DRAW); //GL_STATIC_DRAW

        glGenVertexArrays(1, &VAO); //generate the VAO
        glBindVertexArray(VAO); //bind the VAO

        glBindBuffer(GL_ARRAY_BUFFER, VBO);


        //glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, count, NULL);
        glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, count * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0); //enable vertex attributes

        glVertexAttribPointer(index + 1, size, GL_FLOAT, GL_FALSE, count * sizeof(float), (void*)(color_count * sizeof(float)));
        //glVertexAttribPointer(index+1, size, GL_FLOAT, GL_FALSE,0, (void*)0);
        glEnableVertexAttribArray(1); //enable vertex attributes

        glVertexAttribPointer(index + 2, size - 1, GL_FLOAT, GL_FALSE, count * sizeof(float), (void*)((color_count * 2) * sizeof(float)));
        glEnableVertexAttribArray(2);




        glActiveTexture(GL_TEXTURE0);
        GLuint textureID = SOIL_load_OGL_texture("grass.png", SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID/*, SOIL_FLAG_TEXTURE_REPEATS*/, NULL);
        if (textureID == NULL) {
            std::cout << "An error occurred while loading image." << std::endl;
            exit(EXIT_FAILURE);
        }

        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, textureID);
        //    glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MINIMAP, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



        return VAO;
    }
    else {
        glGenBuffers(1, &VBO); // generate the VBO
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->points_vector.size(), this->points_vector.data(), GL_STATIC_DRAW); //GL_STATIC_DRAW

        glGenVertexArrays(1, &VAO); //generate the VAO
        glBindVertexArray(VAO); //bind the VAO

        glBindBuffer(GL_ARRAY_BUFFER, VBO);


        //glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, count, NULL);
        glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, count * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0); //enable vertex attributes



        glActiveTexture(GL_TEXTURE0);
        GLuint image = SOIL_load_OGL_cubemap("posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg", SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
        if (image == NULL) {
            std::cout << "An error occurred while loading image." << std::endl;
            exit(EXIT_FAILURE);
        }


        glBindTexture(GL_TEXTURE_CUBE_MAP, image);

        glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

        return VAO;
    }
}
