#include "Basic_test_scene.h"


Basic_test_scene::Basic_test_scene() {};

/*
void Scene::drawScene(GLFWwindow* window, int width, int height)
{
    ShaderProgram* sm = new ShaderProgram();
    sm->addShader("sphere.vert");
    sm->addShader("sphere.frag");

    ShaderProgram* sm1 = new ShaderProgram();
    sm1->addShader("pyramid.vert");
    sm1->addShader("pyramid.frag");

    ShaderProgram* sm1_light = new ShaderProgram();
    sm1_light->addShader("lighting.vert");
    sm1_light->addShader("lighting.frag");
    sm1_light->addAmbientLight(0.1, glm::vec3(1.0f, 1.0f, 1.0f));


    Camera* camera = new Camera(45.0f, width / (float)height, 0.1f, 100.0f);
    camera->setMovement(width, height);
    Scene::camera_movement = camera;
    sm->useCamera(camera);
    sm1->useCamera(camera);
    sm1_light->useCamera(camera);

    glfwSetCursorPosCallback(window, mouseCallbackWrapper);


    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    float i = 0;
    //DrawableObject* draw_Object = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm, sm1_light, 0, 3, 6, 3);
    DrawableObject* draw_Object = new DrawableObject(suziSmooth, sizeof(suziSmooth) / sizeof(suziSmooth[0]), sm, sm1_light, 0, 3, 6, 3);

    DrawableObject* draw_Object1 = new DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), sm1, sm1_light, 0, 3, 6, 3);
    draw_Object->transformation->scale->scaling(glm::vec3(0.1f));
    draw_Object1->transformation->scale->scaling(glm::vec3(0.1f));
    draw_Object1->transformation->translate->translation(glm::vec3(-0.3f, 0, 0));


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
        draw_Object->draw(window, "GL_MONKEY");


        //            draw_Object1->transformation->translate->translation(glm::vec3(1.0f, 2.0f, 0));
        //            draw_Object1->transformation->rotate->rotation(20.f + i, glm::vec3(0.2f, 0, 0.5f));

        draw_Object1->draw(window, "GL_TRIANGLES_QUADS");

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
*/