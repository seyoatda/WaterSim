//
// Created by 54367 on 2019/2/28.
//


#include "windowManager.h"

//静态变量初始化
GLFWwindow *WindowManager::wwindow;
float WindowManager::aspectRatio;
double WindowManager::lastFrame = 0.0;
double WindowManager::currentFrame = 0.0;
double WindowManager::deltaTime = 0.0;
int WindowManager::HEIGHT = 1280;
int WindowManager::WIDTH = 720;

int WindowManager::createWindow(int width, int height, const std::string name) {
    //
    HEIGHT = height;
    WIDTH = width;
    aspectRatio = (float) width / (float) height;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    wwindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
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

void WindowManager::update() {
    //检查事件，交换双重缓存
    glfwPollEvents();
    glfwSwapBuffers(wwindow);
}

void WindowManager::close() {

}

GLFWwindow *WindowManager::window() {
    return wwindow;
}

float WindowManager::getRatio() {
    return aspectRatio;
}

double WindowManager::getDeltaTime() {
    return deltaTime;
}

double WindowManager::calcFrame() {
    currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    return deltaTime;
}

int WindowManager::getWidth() {
    return WIDTH;
}

int WindowManager::getHeight() {
    return HEIGHT;
}
