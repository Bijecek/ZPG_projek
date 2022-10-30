#include "Application.h"
//#include "Basic_test_scene.h"
#include "Scene.h"

Application::Application()
{
	createWindow(1280, 720, "ZPG");
}


void Application::createWindow(int width, int height, const char* title)
{
    this->width = width;
    this->height = height;
    glfwSetErrorCallback(this->errorCallback);
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(width, height, title, NULL/*glfwGetPrimaryMonitor()*/, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    glfwGetFramebufferSize(window, &width, &height);
    float ratio = width / (float)height;
    glViewport(0, 0, width, height);
}

void Application::printVersionInfo()
{
    // get version info
    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("Vendor %s\n", glGetString(GL_VENDOR));
    printf("Renderer %s\n", glGetString(GL_RENDERER));
    printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}




void Application::run(int choice)
{
    Scene* scene = new Scene();
    if (choice == 1) {
        scene->drawFourSpheresScene(window, this->width, this->height);
    }
    else if (choice == 2) {
        scene->drawOneSphereLight(window, this->width, this->height);
    }
    else if (choice == 3) {
        scene->drawMultipleObjects(window, this->width, this->height);
    }
}

void Application::errorCallback(int error, const char* description)
{
    fputs(description, stderr);
}

