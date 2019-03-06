//
// Created by 54367 on 2019/2/28.
//

#ifndef OPENGL_DISPLAYMANAGER_H
#define OPENGL_DISPLAYMANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../camera/camera.h"

class DisplayManager {
public:

    static int createWindow(std::string);

    static void update();

    static void close();

    static GLFWwindow *window();

private:
    //窗口
    static const int WIDTH = 1280;
    static const int HEIGHT = 720;

    static std::string name;
    static GLFWwindow *wwindow;

    //鼠标移动和滚轮回调函数

};


#endif //OPENGL_DISPLAYMANAGER_H
