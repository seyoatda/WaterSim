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


    static int createWindow(int width, int height, std::string);

    static void update();

    static void close();

    static GLFWwindow *window();

    static float getRatio();

    static double getDeltaTime();

    static double calcFrame();

    static int getWidth();

    static int getHeight();

private:
    //窗口

    static float aspectRatio;
    static std::string name;
    static GLFWwindow *wwindow;

    static double currentFrame;
    static double lastFrame;
    static double deltaTime;

    static int WIDTH;
    static int HEIGHT;
    //鼠标移动和滚轮回调函数

};


#endif //OPENGL_DISPLAYMANAGER_H
