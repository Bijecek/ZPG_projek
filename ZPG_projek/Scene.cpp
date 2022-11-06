#include "Scene.h"
#include "Camera.h"
#include "Pyramid_coords.h"
#include "suzi_smooth.h"
#include "sphere.h"
#include "tree.h"
#include "base_rectangle.h"
#include "bushes.h"
#include "Observer.h";
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
    sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm1_light->addDiffuseLight(glm::vec3(0, 0, 0));
    sm1_light->useCamera(camera);
    sm1_light->addSpecularLight(camera->getPosition());
    sm1_light->createShaderProgram();

    glfwSetCursorPosCallback(window, mouseCallbackWrapper);


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;
    DrawableObject* draw_Object1 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object2 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object3 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object4 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
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

        
        draw_Object1->draw(window, sizeof(sphere) / sizeof(sphere[0]));
        draw_Object2->draw(window, sizeof(sphere) / sizeof(sphere[0]));
        draw_Object3->draw(window, sizeof(sphere) / sizeof(sphere[0]));
        draw_Object4->draw(window, sizeof(sphere) / sizeof(sphere[0]));

     
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
    sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm1_light->addDiffuseLight(glm::vec3(0, 0, -1));
    sm1_light->addSpecularLight(camera->getPosition());
    sm1_light->useCamera(camera);
    sm1_light->createShaderProgram();



    glfwSetCursorPosCallback(window, mouseCallbackWrapper);


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;

    DrawableObject* draw_Object1 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
  
    draw_Object1->transformation->setScale()->scaling(glm::vec3(0.1f));


    while (!glfwWindowShouldClose(window)) {
        i += 0;
        camera->handleKeys(window);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        

        draw_Object1->draw(window, sizeof(sphere) / sizeof(sphere[0]));
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

    ShaderProgram* sm_base_rectangle = new ShaderProgram();
    sm_base_rectangle->addShader("pyramid.vert");
    sm_base_rectangle->addShader("pyramid.frag");
    sm_base_rectangle->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm_base_rectangle->addDiffuseLight(glm::vec3(-3, 0, 0));
    sm_base_rectangle->createShaderProgram();
    
    /*
    ShaderProgram* sm1_light = new ShaderProgram();
    sm1_light->addShader("lighting_first_task.vert");
    sm1_light->addShader("lighting_first_task.frag");
    sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm1_light->addDiffuseLight(glm::vec3(-3, 0, 0));
    sm1_light->createShaderProgram();
    */
    ShaderProgram* sm1_light = new ShaderProgram();
    sm1_light->addShader("direct_light.vert");
    sm1_light->addShader("direct_light.frag");
    sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm1_light->addDiffuseLight(glm::vec3(-3, 3, 3));
    sm1_light->createShaderProgram();

    


    ShaderProgram* sm2_light = new ShaderProgram();
    sm2_light->addShader("lighting_third_task_blue.vert");
    sm2_light->addShader("lighting_third_task_blue.frag");
    sm2_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm2_light->addDiffuseLight(glm::vec3(-3, 0, 0));
    sm2_light->createShaderProgram();
   
    //sm_base_rectangle->useCamera(camera);
    sm_base_rectangle->addSpecularLight(camera->getPosition());

    
    //sm1_light->useCamera(camera);
    sm1_light->addSpecularLight(camera->getPosition());

    //sm2_light->useCamera(camera);
    sm2_light->addSpecularLight(camera->getPosition());

    sm_base_rectangle->useCamera(camera);
    sm1_light->useCamera(camera);
    sm2_light->useCamera(camera);
    
    


    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;
    srand((unsigned)time(NULL));
    DrawableObject* draw_Object_rectangle = new DrawableObject(base_rectangle, sizeof(base_rectangle) / sizeof(base_rectangle[0]), sm_base_rectangle, 0, 4, 8, 4);
    draw_Object_rectangle->transformation->setTranslate()->translation(glm::vec3(-3, -0.5f, 0));
    draw_Object_rectangle->transformation->setRotate()->rotation(glm::radians(90.f), glm::vec3(1, 0, 0));
    draw_Object_rectangle->transformation->setScale()->scaling(glm::vec3(50.f, 10.f, 10.f));

    
    vector<DrawableObject*> entities_cube;
    for (int i = 0; i < 20; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
        draw_Object1->transformation->setScale()->scaling(glm::vec3(0.1f));
        draw_Object1->transformation->setTranslate()->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, 0, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_cube.push_back(draw_Object1);
    }
    
    
    vector<DrawableObject*> entities_monkey;
    for (int i = 0; i < 20; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(suziSmooth, sizeof(suziSmooth) / sizeof(suziSmooth[0]), sm2_light, 0, 3, 6, 3);
        draw_Object1->transformation->setScale()->scaling(glm::vec3(0.1f));
        draw_Object1->transformation->setTranslate()->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, 0, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_monkey.push_back(draw_Object1);
    }

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
        
        camera->handleKeys(window);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

       
        draw_Object_rectangle->draw(window, sizeof(base_rectangle) / sizeof(base_rectangle[0]));
        
        for (DrawableObject* object : entities_cube) {
            object->draw(window, sizeof(sphere) / sizeof(sphere[0]));
        }  
        for (DrawableObject* object1 : entities_monkey) {
            object1->draw(window, sizeof(suziSmooth) / sizeof(suziSmooth[0]));
        }
        for (DrawableObject* object2 : entities_trees) {
            object2->draw(window, sizeof(tree) / sizeof(tree[0]));
        }
        for (DrawableObject* object3 : entities_bushes) {
            object3->draw(window, sizeof(bushes) / sizeof(bushes[0]));
        }
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}