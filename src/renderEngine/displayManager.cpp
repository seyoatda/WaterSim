//
// Created by 54367 on 2019/2/28.
//


#include "displayManager.h"

//静态变量初始化
GLFWwindow *DisplayManager::wwindow;


int DisplayManager::createWindow(const std::string name) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    wwindow = glfwCreateWindow(800, 600, name.c_str(), NULL, NULL);
    if (wwindow == NULL) {
        std::cout << "failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(wwindow);
    glfwSetFramebufferSizeCallback(wwindow, [](GLFWwindow *window1, int w, int h) { glViewport(0, 0, w, h); });
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSetInputMode(wwindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    return 0;
}

void DisplayManager::update() {

}

void DisplayManager::close() {

}

GLFWwindow *DisplayManager::window() {
    return wwindow;
}
