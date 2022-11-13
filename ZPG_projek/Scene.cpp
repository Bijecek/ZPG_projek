#include "Scene.h"
#include "Camera.h"
#include "Pyramid_coords.h"
#include "suzi_smooth.h"
#include "sphere.h"
#include "tree.h"
#include "base_rectangle.h"
#include "bushes.h"
#include "Observer.h";
#include "plain.h"
#include "skycube.h"
Scene::Scene() {
   
};
Camera* Scene::camera_movement = nullptr;
void Scene::mouseCallbackWrapper(GLFWwindow* window, double xpos, double ypos) {
    Scene::camera_movement->handleMouse(window, xpos, ypos);
}
void Scene::drawFourSpheresScene(GLFWwindow* window, int width, int height)
{
    

    Camera* camera = new Camera(glm::vec3(0, 0, 1), 45.0f, width / (float)height, 0.1f, 100.0f);
    camera->setMovement(width, height);
    Scene::camera_movement = camera;
    ShaderProgram* sm1_light = new ShaderProgram();
    sm1_light->addShader("lighting_first_task.vert");
    sm1_light->addShader("lighting_first_task.frag");
    //sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    //sm1_light->addDiffuseLight(glm::vec3(0, 0, 0));
    sm1_light->useCamera(camera);
    //sm1_light->addSpecularLight(camera->getPosition());
    sm1_light->createShaderProgram();

    glfwSetCursorPosCallback(window, mouseCallbackWrapper);


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;
    DrawableObject* draw_Object1 = new DrawableObject(false,false,false,sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object2 = new DrawableObject(false, false, false, sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object3 = new DrawableObject(false, false, false, sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object4 = new DrawableObject(false, false, false, sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    draw_Object1->transformation->setScale()->scaling(glm::vec3(0.1f));
    draw_Object1->transformation->setTranslate()->translation(glm::vec3(-0.3f, 0, 0));

    draw_Object2->transformation->setScale()->scaling(glm::vec3(0.1f));
    draw_Object2->transformation->setTranslate()->translation(glm::vec3(0.3f, 0, 0));

    draw_Object3->transformation->setScale()->scaling(glm::vec3(0.1f));
    draw_Object3->transformation->setTranslate()->translation(glm::vec3(0, -0.3f, 0));

    draw_Object4->transformation->setScale()->scaling(glm::vec3(0.1f));
    draw_Object4->transformation->setTranslate()->translation(glm::vec3(0, 0.3f, 0));


    while (!glfwWindowShouldClose(window)) {
        i += 0;
        camera->handleKeys(window);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        
        draw_Object1->draw(false,window, sizeof(sphere) / sizeof(sphere[0]));
        draw_Object2->draw(false, window, sizeof(sphere) / sizeof(sphere[0]));
        draw_Object3->draw(false, window, sizeof(sphere) / sizeof(sphere[0]));
        draw_Object4->draw(false, window, sizeof(sphere) / sizeof(sphere[0]));

     
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);


}
void Scene::drawOneSphereLight(GLFWwindow* window, int width, int height)
{
    Camera* camera = new Camera(glm::vec3(0, 0, 1), 45.0f, width / (float)height, 0.1f, 100.0f);
    camera->setMovement(width, height);
    Scene::camera_movement = camera;
    

    ShaderProgram* sm1_light = new ShaderProgram();
//correct output of 2nd task
    sm1_light->addShader("lighting_second_task_right.vert");
    sm1_light->addShader("lighting_second_task_right.frag");

//wrong output of 2nd task
//    sm1_light->addShader("lighting_second_task_wrong.vert");
//    sm1_light->addShader("lighting_second_task_wrong.frag");
    //sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    //sm1_light->addDiffuseLight(glm::vec3(0, 0, -1));
    //sm1_light->addSpecularLight(camera->getPosition());
    sm1_light->useCamera(camera);
    sm1_light->createShaderProgram();



    glfwSetCursorPosCallback(window, mouseCallbackWrapper);


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;

    DrawableObject* draw_Object1 = new DrawableObject(false, false, false, sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
  
    draw_Object1->transformation->setScale()->scaling(glm::vec3(0.1f));


    while (!glfwWindowShouldClose(window)) {
        i += 0;
        camera->handleKeys(window);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        

        draw_Object1->draw(false, window, sizeof(sphere) / sizeof(sphere[0]));
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);


}
void Scene::drawMultipleObjects(GLFWwindow* window, int width, int height) 
{
    Camera* camera = new Camera(glm::vec3(0, 0, 1), 45.0f, width / (float)height, 0.1f, 100.0f);
    camera->setMovement(width, height);
    Scene::camera_movement = camera;
    
    ShaderProgram* sp_skycube = new ShaderProgram(camera);
    sp_skycube->addShader("skycube.vert");
    sp_skycube->addShader("skycube.frag");

    sp_skycube->createShaderProgram();

    

    ShaderProgram* sp_plain = new ShaderProgram(camera);

    
    sp_plain->addShader("plain.vert");
    sp_plain->addShader("plain.frag");
    

    sp_plain->createShaderProgram();
    

    
    ShaderProgram* sp_Object_w_texture = new ShaderProgram(camera);
    sp_Object_w_texture->addShader("light_w_texture.vert");
    sp_Object_w_texture->addShader("light_w_texture.frag");

    sp_Object_w_texture->addPointLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(2, 0, 0), camera->getPosition());
    sp_Object_w_texture->addPointLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(5,0,0), camera->getPosition());
    sp_Object_w_texture->addDirectionalLight(glm::vec3(2, 5, 0));
    sp_Object_w_texture->createShaderProgram();


    float i = 0;
    srand((unsigned)time(NULL));
    
    DrawableObject* draw_Skycube = new DrawableObject(false,true, false, skycube, sizeof(skycube) / sizeof(skycube[0]), sp_skycube, 0, 3, 3, 0);
    draw_Skycube->transformation->setTranslate()->translation(glm::vec3(0,0,1));
    draw_Skycube->transformation->setScale()->scaling(glm::vec3(0.2f,0.2f,0.2f));



    DrawableObject* draw_Plain = new DrawableObject(false,false,true,plain, sizeof(plain) / sizeof(plain[0]), sp_plain, 0, 3, 8, 3);
    draw_Plain->transformation->setTranslate()->translation(glm::vec3(-3, -5, 0));
    draw_Plain->transformation->setScale()->scaling(glm::vec3(50.f, 10.f, 50.f));
    
    
    sp_Object_w_texture->setTexture("Textures/lava_texture_png.png");
    vector<DrawableObject*> entities_cube;
    for (int i = 0; i < 20; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(true, false, false, sphere, sizeof(sphere) / sizeof(sphere[0]), sp_Object_w_texture, 0, 3, 6, 3);
        draw_Object1->transformation->setScale()->scaling(glm::vec3(0.1f));
        draw_Object1->transformation->setTranslate()->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, -4.9f, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_cube.push_back(draw_Object1);
    }
    sp_Object_w_texture->vbovao_previous = NULL;
    sp_Object_w_texture->setTexture("Textures/ice_texture_png.png");
    vector<DrawableObject*> entities_monkey;
    for (int i = 0; i < 20; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(true, false,false,suziSmooth, sizeof(suziSmooth) / sizeof(suziSmooth[0]), sp_Object_w_texture, 0, 3, 6, 3);
        draw_Object1->transformation->setScale()->scaling(glm::vec3(0.1f));
        draw_Object1->transformation->setTranslate()->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, -4.9f, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_monkey.push_back(draw_Object1);
    }
    sp_Object_w_texture->vbovao_previous = NULL;
    /*
    vector<DrawableObject*> entities_trees;
    for (int i = 0; i < 20; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(tree, sizeof(tree) / sizeof(tree[0]), sm2_light, 0, 3, 6, 3);
        draw_Object1->transformation->setScale()->scaling(glm::vec3(0.1f));
        draw_Object1->transformation->setTranslate()->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, 0, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_trees.push_back(draw_Object1);
    }
    
    vector<DrawableObject*> entities_bushes;
    for (int i = 0; i < 40; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(bushes, sizeof(bushes) / sizeof(bushes[0]), sm1_light, 0, 3, 6, 3);
        draw_Object1->transformation->setScale()->scaling(glm::vec3(0.5f));
        draw_Object1->transformation->setTranslate()->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, 0, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_bushes.push_back(draw_Object1);
    }
    */


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetCursorPosCallback(window, mouseCallbackWrapper);
        }
        else if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            glfwSetCursorPosCallback(window, NULL);
        }


        i += 0;
        glm::vec3 old_pos = camera->getPosition();
        camera->handleKeys(window);
        glm::vec3 new_pos = camera->getPosition();
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        draw_Skycube->transformation->setTranslate()->translation(glm::vec3(new_pos.x - old_pos.x, new_pos.y - old_pos.y, new_pos.z - old_pos.z));
        draw_Skycube->draw(true,window, sizeof(skycube) / sizeof(skycube[0]));
        glClear(GL_DEPTH_BUFFER_BIT);

        draw_Plain->draw(false,window, sizeof(plain) / sizeof(plain[0]));
        
        
        for (DrawableObject* object : entities_cube) {
            object->draw(false,window, sizeof(sphere) / sizeof(sphere[0]));
            
        }
        
        for (DrawableObject* object1 : entities_monkey) {
            object1->draw(false, window, sizeof(suziSmooth) / sizeof(suziSmooth[0]));
        }
        /*
        for (DrawableObject* object2 : entities_trees) {
            object2->draw(window, sizeof(tree) / sizeof(tree[0]));
        }
        
        for (DrawableObject* object3 : entities_bushes) {
            object3->draw(window, sizeof(bushes) / sizeof(bushes[0]));
        }
        */
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}