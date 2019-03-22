//
// Created by 54367 on 2019/3/8.
//

#ifndef OPENGL_GAMEENGINE_H
#define OPENGL_GAMEENGINE_H

#include "loader.h"
#include "displayManager.h"
#include "../water/waterRenderer.h"
#include "../camera/camera.h"
#include "../Entities/model.h"
#include "../water/waterFbo.h"
#include <glm/gtc/type_ptr.hpp>

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void start();
private:
    DisplayManager* displayManager;
    static Camera camera;

    //计算帧数
    static float deltaTime;
    static float lastFrame;

    static float ratio;
    static float lastX;
    static float lastY;
    static bool firstMouse;

    static void processInput(GLFWwindow *wwindow);
    static void mouse_callback(GLFWwindow *wwindow, double xpos, double ypos);
    static void scroll_callback(GLFWwindow *wwindow, double xoffset, double yoffset);

};


#endif //OPENGL_GAMEENGINE_H
