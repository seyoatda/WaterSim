//
// Created by 54367 on 2019/3/8.
//

#include "gameEngine.h"
#include "../Skybox/skyboxRenderer.h"
#include "mainRenderer.h"

vector<float> quadVertices = {
        // positions   // texCoords
        -0.5f, 0.0f, -0.5f, 0.0f, 0.0f,
        0.5f, 0.0f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.0f, 0.5f, 0.0f, 1.0f,
        -0.5f, 0.0f, -0.5f, 0.0f, 0.0f
};
float GameEngine::deltaTime = 0.0;
float GameEngine::lastFrame = 0.0;
float GameEngine::lastX = 640.0;
float GameEngine::lastY = 320.0;
bool GameEngine::firstMouse = true;
float GameEngine::ratio = 0.5;
Camera GameEngine::camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));

GameEngine::GameEngine() {

    DisplayManager::createWindow(1280, 720, "learnOpenGL");
    GLFWwindow *wwindow = DisplayManager::window();
    glfwSetInputMode(wwindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(wwindow, mouse_callback);
    glfwSetScrollCallback(wwindow, scroll_callback);

}

GameEngine::~GameEngine() {

}

void GameEngine::start() {
    float waterHeight = 1.0f;

    //创建一个渲染程序
    Shader modelShader(R"(../res/shaderCode/33shader)");
    Shader lampShader("../res/shaderCode/light_shader");
    Shader fboShader("../res/shaderCode/fboShader");

    Loader loader;    //将物体加载到vao中

    Object fboObj = loader.loadVAO(quadVertices, 5, {3, 2});

    MainRenderer mainRenderer;

    WaterFbo waterFbo;
    WaterRenderer waterRenderer(waterFbo);
    glEnable(GL_DEPTH_TEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    double eqn[] = {0.0, 1.0, 0.0, 0.0};
    glEnable(GL_CLIP_DISTANCE0);


    while (!glfwWindowShouldClose(DisplayManager::window())) {

        //
        processInput(DisplayManager::window());
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentFrame = (float) glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        //创建一个渲染程序


        //渲染反射缓冲
        float distance = 2 * (camera.getPosition().y- waterHeight);
        camera.getPosition().y -= distance;
        camera.invertPitch();
        waterFbo.bindReflectionFbo();
        mainRenderer.setUboPlane(glm::vec4(0.0, -1.0, 0.0, waterHeight));
        mainRenderer.render(camera);
        mainRenderer.setUboPlane(glm::vec4(0.0, 0.0, 0.0,waterHeight));
        waterFbo.unbindFbo();
        camera.getPosition().y+=distance;
        camera.invertPitch();

        //渲染折射缓冲
        waterFbo.bindRefractionFbo();
        mainRenderer.setUboPlane(glm::vec4(0.0, 1.0, 0.0, 0.0));
        mainRenderer.render(camera);
        mainRenderer.setUboPlane(glm::vec4(0.0, 0.0, 0.0, 0.0));
        waterFbo.unbindFbo();

        //渲染实际画面
        mainRenderer.render(camera);

        waterRenderer.render(camera);
        fboShader.use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-2.0f, 0.0f, 2.0f));
        model = glm::scale(model, glm::vec3(1.6f, 0.9f, 1.0f));
        fboShader.setMat4("model", model);
        glBindVertexArray(fboObj.getVao());
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, waterFbo.getReflectionFboColor());
        glDrawArrays(GL_TRIANGLES, 0, fboObj.getCount());

//        model = glm::mat4(1.0f);
//        model = glm::translate(model, glm::vec3(-2.0f, 0.0f, 2.0f));
//        model = glm::scale(model, glm::vec3(1.6f, 0.9f, 1.0f));
//        fboShader.setMat4("model", model);
//        glBindVertexArray(fboObj.getVao());
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, waterFbo.getRefractionFboColor());
//        glDrawArrays(GL_TRIANGLES, 0, fboObj.getCount());



        //清除缓冲，响应窗口事件
        DisplayManager::update();
    }
    glfwTerminate();
}

void GameEngine::processInput(GLFWwindow *wwindow) {
    if (glfwGetKey(wwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(wwindow, true);
    if (glfwGetKey(wwindow, GLFW_KEY_UP) == GLFW_PRESS)
        ratio = std::min(ratio + 0.001f, 1.0f);
    if (glfwGetKey(wwindow, GLFW_KEY_DOWN) == GLFW_PRESS)
        ratio = std::max(ratio - 0.001f, 0.0f);
    //处理视角移动
    if (glfwGetKey(wwindow, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(wwindow, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(wwindow, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(wwindow, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    if(glfwGetKey(wwindow,GLFW_KEY_Q)==GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
    if (glfwGetKey(wwindow, GLFW_KEY_E) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);

}

void GameEngine::mouse_callback(GLFWwindow *wwindow, double xpos, double ypos) {
    if (firstMouse) {
        lastX = (float) xpos;
        lastY = (float) ypos;
        firstMouse = false;
    }
    float xoffset = (float) xpos - lastX;
    float yoffset = lastY - (float) ypos;
    lastX = (float) xpos;
    lastY = (float) ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void GameEngine::scroll_callback(GLFWwindow *wwindow, double xoffset, double yoffset) {
    camera.ProcessMouseScroll((float) yoffset);
}













