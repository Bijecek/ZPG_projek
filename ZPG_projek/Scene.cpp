#include "Scene.h"
#include "Camera.h"
#include "Pyramid_coords.h"
#include "suzi_smooth.h"
#include "sphere.h"
#include "tree.h"
#include "base_rectangle.h"
#include "bushes.h"
Scene::Scene() {
   
};
Camera* Scene::camera_movement = nullptr;
void Scene::mouseCallbackWrapper(GLFWwindow* window, double xpos, double ypos) {
    Scene::camera_movement->handleMouse(window, xpos, ypos);
}
void Scene::drawFourSpheresScene(GLFWwindow* window, int width, int height)
{
    cout << "aaba" << endl;
    ShaderProgram* sm1_light = new ShaderProgram();
    sm1_light->addShader("lighting_first_task.vert");
    sm1_light->addShader("lighting_first_task.frag");
    sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm1_light->addDiffuseLight(glm::vec3(0, 0, 0));


    Camera* camera = new Camera(glm::vec3(0.0f, 0.5f, 3.0f), 45.0f, width / (float)height, 0.1f, 100.0f);
    camera->setMovement(width, height);
    Scene::camera_movement = camera;
    sm1_light->useCamera(camera);
    sm1_light->addSpecularLight(camera->getPosition());

    glfwSetCursorPosCallback(window, mouseCallbackWrapper);


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;
    //DrawableObject* draw_Object = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm, sm1_light, 0, 3, 6, 3);

    DrawableObject* draw_Object1 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object2 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object3 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object4 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
    draw_Object1->transformation->scale->scaling(glm::vec3(0.1f));
    draw_Object1->transformation->translate->translation(glm::vec3(-0.3f, 0, 0));

    draw_Object2->transformation->scale->scaling(glm::vec3(0.1f));
    draw_Object2->transformation->translate->translation(glm::vec3(0.3f, 0, 0));

    draw_Object3->transformation->scale->scaling(glm::vec3(0.1f));
    draw_Object3->transformation->translate->translation(glm::vec3(0, -0.3f, 0));

    draw_Object4->transformation->scale->scaling(glm::vec3(0.1f));
    draw_Object4->transformation->translate->translation(glm::vec3(0, 0.3f, 0));


    while (!glfwWindowShouldClose(window)) {
        i += 0;
        camera->handleKeys(window);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Tohle pošli do modelu
        // Abstraktni trida Model
        // 
        // 
        //Funguje
        //    DrawableObject* draw_Object = new DrawableObject(points, size, sm, 0, 4, 8*sizeof(float));
             //DrawableObject* draw_Object = new DrawableObject(cube_data, size_cube, sm, 0, 3,7);




//            draw_Object->transformation->rotate->rotation(20.f+i, glm::vec3(0.2f,0,0.5f));

 //           draw_Object->draw(window, "GL_TRIANGLES_QUADS");
        //draw_Object->draw(window, "GL_MONKEY");


        //            draw_Object1->transformation->translate->translation(glm::vec3(1.0f, 2.0f, 0));
        //            draw_Object1->transformation->rotate->rotation(20.f + i, glm::vec3(0.2f, 0, 0.5f));
        draw_Object1->draw(window, "GL_TRIANGLES_QUADS");
        draw_Object2->draw(window, "GL_TRIANGLES_QUADS");
        draw_Object3->draw(window, "GL_TRIANGLES_QUADS");
        draw_Object4->draw(window, "GL_TRIANGLES_QUADS");

        //            std::cin.ignore();

                // update other events like input handling
        glfwPollEvents();
        // put the stuff we’ve been drawing onto the display
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);


}
void Scene::drawOneSphereLight(GLFWwindow* window, int width, int height)
{

    ShaderProgram* sm1_light = new ShaderProgram();
//correct output of 2nd task
//    sm1_light->addShader("lighting_second_task_right.vert");
//    sm1_light->addShader("lighting_second_task_right.frag");

//wrong output of 2nd task
    sm1_light->addShader("lighting_second_task_wrong.vert");
    sm1_light->addShader("lighting_second_task_wrong.frag");
    sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm1_light->addDiffuseLight(glm::vec3(0, 0, -1));


    Camera* camera = new Camera(glm::vec3(0,0,1),45.0f, width / (float)height, 0.1f, 100.0f);
    camera->setMovement(width, height);
    Scene::camera_movement = camera;
    sm1_light->useCamera(camera);
    sm1_light->addSpecularLight(camera->getPosition());

    glfwSetCursorPosCallback(window, mouseCallbackWrapper);


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;

    DrawableObject* draw_Object1 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
  
    draw_Object1->transformation->scale->scaling(glm::vec3(0.1f));
    //draw_Object1->transformation->translate->translation(glm::vec3(-0.3f, 0, 0));


    while (!glfwWindowShouldClose(window)) {
        i += 0;
        camera->handleKeys(window);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        

        draw_Object1->draw(window, "GL_TRIANGLES_QUADS");
                // update other events like input handling
        glfwPollEvents();
        // put the stuff we’ve been drawing onto the display
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);


}
void Scene::drawMultipleObjects(GLFWwindow* window, int width, int height) 
{
    ShaderProgram* sm_base_rectangle = new ShaderProgram();
    sm_base_rectangle->addShader("pyramid.vert");
    sm_base_rectangle->addShader("pyramid.frag");
    sm_base_rectangle->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm_base_rectangle->addDiffuseLight(glm::vec3(-3, 0, 0));
    

    ShaderProgram* sm1_light = new ShaderProgram();
    sm1_light->addShader("lighting_first_task.vert");
    sm1_light->addShader("lighting_first_task.frag");
    sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm1_light->addDiffuseLight(glm::vec3(-3, 0, 0));

    ShaderProgram* sm2_light = new ShaderProgram();
    sm2_light->addShader("lighting_third_task_blue.vert");
    sm2_light->addShader("lighting_third_task_blue.frag");
    sm2_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));
    sm2_light->addDiffuseLight(glm::vec3(-3, 0, 0));

    //0.0f, 0.5f, 3.0f
    Camera* camera = new Camera(glm::vec3(0, 0, 1), 45.0f, width / (float)height, 0.1f, 100.0f);
    camera->setMovement(width, height);
    Scene::camera_movement = camera;
    sm_base_rectangle->useCamera(camera);
    sm_base_rectangle->addSpecularLight(camera->getPosition());

    sm1_light->useCamera(camera);
    sm1_light->addSpecularLight(camera->getPosition());

    sm2_light->useCamera(camera);
    sm2_light->addSpecularLight(camera->getPosition());

    glfwSetCursorPosCallback(window, mouseCallbackWrapper);


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;
    srand((unsigned)time(NULL));
    //DrawableObject* draw_Object = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm, sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object_rectangle = new DrawableObject(base_rectangle, sizeof(base_rectangle) / sizeof(base_rectangle[0]), sm_base_rectangle, 0, 4, 8, 4);
    draw_Object_rectangle->transformation->translate->translation(glm::vec3(-3, -0.5f, 0));
    draw_Object_rectangle->transformation->rotate->rotation(glm::radians(90.f),glm::vec3(1, 0, 0));
    draw_Object_rectangle->transformation->scale->scaling(glm::vec3(50.f,10.f,10.f));

    vector<DrawableObject*> entities_cube;
    for (int i = 0; i < 20; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1_light, 0, 3, 6, 3);
        draw_Object1->transformation->scale->scaling(glm::vec3(0.1f));
        draw_Object1->transformation->translate->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, 0, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_cube.push_back(draw_Object1);
    }

    vector<DrawableObject*> entities_monkey;
    for (int i = 0; i < 20; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(suziSmooth, sizeof(suziSmooth) / sizeof(suziSmooth[0]), sm2_light, 0, 3, 6, 3);
        draw_Object1->transformation->scale->scaling(glm::vec3(0.1f));
        draw_Object1->transformation->translate->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, 0, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_monkey.push_back(draw_Object1);
    }

    vector<DrawableObject*> entities_trees;
    for (int i = 0; i < 20; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(tree, sizeof(tree) / sizeof(tree[0]), sm2_light, 0, 3, 6, 3);
        draw_Object1->transformation->scale->scaling(glm::vec3(0.1f));
        draw_Object1->transformation->translate->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, 0, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_trees.push_back(draw_Object1);
    }

    vector<DrawableObject*> entities_bushes;
    for (int i = 0; i < 40; i++) {
        DrawableObject* draw_Object1 = new DrawableObject(bushes, sizeof(bushes) / sizeof(bushes[0]), sm2_light, 0, 3, 6, 3);
        draw_Object1->transformation->scale->scaling(glm::vec3(0.5f));
        draw_Object1->transformation->translate->translation(glm::vec3(-5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX, 0, -5 + static_cast<float>(rand()) * static_cast<float>(5 + 5) / RAND_MAX));
        entities_bushes.push_back(draw_Object1);
    }


    while (!glfwWindowShouldClose(window)) {
        i += 0;
        camera->handleKeys(window);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Tohle pošli do modelu
        // Abstraktni trida Model
        // 
        // 
        //Funguje
        //    DrawableObject* draw_Object = new DrawableObject(points, size, sm, 0, 4, 8*sizeof(float));
             //DrawableObject* draw_Object = new DrawableObject(cube_data, size_cube, sm, 0, 3,7);




//            draw_Object->transformation->rotate->rotation(20.f+i, glm::vec3(0.2f,0,0.5f));

 //           draw_Object->draw(window, "GL_TRIANGLES_QUADS");
        //draw_Object->draw(window, "GL_MONKEY");


        //            draw_Object1->transformation->translate->translation(glm::vec3(1.0f, 2.0f, 0));
        //            draw_Object1->transformation->rotate->rotation(20.f + i, glm::vec3(0.2f, 0, 0.5f));
        draw_Object_rectangle->draw(window, "GL_QUADS");
        for (DrawableObject* object : entities_cube) {
            object->draw(window, "GL_TRIANGLES_QUADS");
        }
        for (DrawableObject* object1 : entities_monkey) {
            object1->draw(window, "GL_MONKEY");
        }
        for (DrawableObject* object2 : entities_trees) {
            object2->draw(window, "GL_TREE");
        }
        for (DrawableObject* object3 : entities_bushes) {
            object3->draw(window, "GL_BUSH");
        }

        //            std::cin.ignore();

                // update other events like input handling
        glfwPollEvents();
        // put the stuff we’ve been drawing onto the display
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}