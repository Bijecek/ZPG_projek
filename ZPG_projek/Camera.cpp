#include "Camera.h"

Camera::Camera(glm::vec3 position, float fov, float aspect, float near, float far)
{
	this->fov = fov;
	this->aspect = aspect;
	this->near = near;
	this->far = far;

    this->position = position;
    this->front = glm::vec3(0.0f, 0.0f, -1.0f);
	this->direction = glm::normalize(position - glm::vec3(0));
    this->up = glm::vec3(0.0f, 1.0f, 0.0f);
	this->camera_up = glm::cross(direction, glm::normalize(glm::cross(up, direction)));
}

glm::mat4 Camera::getView()
{
	this->view = glm::lookAt(position, position + front, camera_up);

	return this->view;
}

glm::mat4 Camera::getProjection()
{
	this->projection = glm::perspective(glm::radians(fov), aspect, near, far);
	return this->projection;
}

void Camera::setMovement(int width, int height) {
    this->lastX = width;
    this->lastY = height;
    this->yaw = -90.0f;
}
void Camera::handleMouse(GLFWwindow* window, double xpos, double ypos) {
    /*
            if (firstMouse)
            {
                lastX = xpos;
                lastY = ypos;

                firstMouse = false;
            }

            float xoffset = float(xpos - 1024 / 2);
            float yoffset = float(768 / 2 - ypos);
            //lastX = xpos;
            //lastY = ypos;
            xoffset *= sensitivity;
            yoffset *= sensitivity;
            yaw += xoffset;
            pitch += yoffset;

            if (pitch > 89.0f)
                pitch = 89.0f;
            if (pitch < -89.0f)
                pitch = -89.0f;

            glm::vec3 direction;
            direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
            direction.y = sin(glm::radians(pitch));
            direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
            front = glm::normalize(direction);
            glfwSetCursorPos(window, 1024 / 2, 768 / 2);
            //update();
            */
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;

        firstMouse = false;
    }

    float xoffset = float(xpos - lastX);
    float yoffset = float(lastY - ypos);
    lastX = xpos;
    lastY = ypos;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(direction);
}
void Camera::handleKeys(GLFWwindow* window) {
    const float cameraSpeed = 0.02f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        position += cameraSpeed * front;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        position -= cameraSpeed * front;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        position -= glm::normalize(glm::cross(front, camera_up)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        position += glm::normalize(glm::cross(front, camera_up)) * cameraSpeed;
    //update();
}

glm::vec3 Camera::getPosition() {
    return this->position;
}
void Camera::update() {
    printf("Velikost obs\n");
    printf("%d", this->obs.size());
    for (Observer *o : obs) {  
        o->notify();
    }
    //this->obs[0]->notify();
}
void Camera::attachObs(Observer* obs) {
    this->obs.push_back(obs);
}