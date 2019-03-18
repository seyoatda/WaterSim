//
// Created by 54367 on 2019/3/8.
//

#include "gameEngine.h"
glm::vec3 cubePositions[] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 0.0f, 0.0f),
        glm::vec3(-2.0f, 0.0f, 0.0f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f, 2.0f, -2.5f),
        glm::vec3(1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)
};
glm::vec3 pointLightPositions[] = {
        glm::vec3(0.7f, 0.2f, 2.0f),
        glm::vec3(2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f, 2.0f, -12.0f),
        glm::vec3(0.0f, 0.0f, -3.0f)
};
constexpr float SKYSIZE = 500.0;
vector<float> skyboxVertices = {
        // positions
        -SKYSIZE, SKYSIZE, -SKYSIZE,
        -SKYSIZE, -SKYSIZE, -SKYSIZE,
        SKYSIZE, -SKYSIZE, -SKYSIZE,
        SKYSIZE, -SKYSIZE, -SKYSIZE,
        SKYSIZE, SKYSIZE, -SKYSIZE,
        -SKYSIZE, SKYSIZE, -SKYSIZE,

        -SKYSIZE, -SKYSIZE, SKYSIZE,
        -SKYSIZE, -SKYSIZE, -SKYSIZE,
        -SKYSIZE, SKYSIZE, -SKYSIZE,
        -SKYSIZE, SKYSIZE, -SKYSIZE,
        -SKYSIZE, SKYSIZE, SKYSIZE,
        -SKYSIZE, -SKYSIZE, SKYSIZE,

        SKYSIZE, -SKYSIZE, -SKYSIZE,
        SKYSIZE, -SKYSIZE, SKYSIZE,
        SKYSIZE, SKYSIZE, SKYSIZE,
        SKYSIZE, SKYSIZE, SKYSIZE,
        SKYSIZE, SKYSIZE, -SKYSIZE,
        SKYSIZE, -SKYSIZE, -SKYSIZE,

        -SKYSIZE, -SKYSIZE, SKYSIZE,
        -SKYSIZE, SKYSIZE, SKYSIZE,
        SKYSIZE, SKYSIZE, SKYSIZE,
        SKYSIZE, SKYSIZE, SKYSIZE,
        SKYSIZE, -SKYSIZE, SKYSIZE,
        -SKYSIZE, -SKYSIZE, SKYSIZE,

        -SKYSIZE, SKYSIZE, -SKYSIZE,
        SKYSIZE, SKYSIZE, -SKYSIZE,
        SKYSIZE, SKYSIZE, SKYSIZE,
        SKYSIZE, SKYSIZE, SKYSIZE,
        -SKYSIZE, SKYSIZE, SKYSIZE,
        -SKYSIZE, SKYSIZE, -SKYSIZE,

        -SKYSIZE, -SKYSIZE, -SKYSIZE,
        -SKYSIZE, -SKYSIZE, SKYSIZE,
        SKYSIZE, -SKYSIZE, -SKYSIZE,
        SKYSIZE, -SKYSIZE, -SKYSIZE,
        -SKYSIZE, -SKYSIZE, SKYSIZE,
        SKYSIZE, -SKYSIZE, SKYSIZE
};
vector<std::string> faces{
        "../res/pic/right.jpg",
        "../res/pic/left.jpg",
        "../res/pic/top.jpg",
        "../res/pic/bottom.jpg",
        "../res/pic/front.jpg",
        "../res/pic/back.jpg"
};
vector<float> quadVertices = {
        // positions   // texCoords
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
        0.5f, 0.5f,  0.0f, 1.0f, 1.0f,
        0.5f, 0.5f,  0.0f, 1.0f, 1.0f,
        -0.5f, 0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.0f,  0.0f, 0.0f
};
//创建数据
vector<float> vertices = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
};
unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
};

float GameEngine::deltaTime=0.0;
float GameEngine::lastFrame=0.0;
float GameEngine::lastX=640.0;
float GameEngine::lastY=320.0;
bool GameEngine::firstMouse=true;
float GameEngine::ratio=0.5;
Camera GameEngine::camera=Camera(glm::vec3(0.0f,0.0f,3.0f));

GameEngine::GameEngine(){

    DisplayManager::createWindow(1280, 720, "learnOpenGL");
    GLFWwindow *wwindow = DisplayManager::window();
    glfwSetInputMode(wwindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(wwindow, mouse_callback);
    glfwSetScrollCallback(wwindow, scroll_callback);

}

GameEngine::~GameEngine() {

}

void GameEngine::start() {

    //创建一个渲染程序
    Shader ourShader("../res/shaderCode/33shader.vs",
                     "../res/shaderCode/33shader.fs");
    Shader lampShader("../res/shaderCode/light_shader.vs",
                      "../res/shaderCode/light_shader.fs");
    Shader fboShader("../res/shaderCode/fboShader.vs",
                     "../res/shaderCode/fboShader.fs");

    Loader loader;    //将物体加载到vao中

    Object lightObj = loader.loadVAO(vertices, 8, {3});
    Object skyboxObj = loader.loadVAO(skyboxVertices, 3, {3});
    Object fboObj = loader.loadVAO(quadVertices, 5, {3, 2});

    WaterFbo waterFbo;

    Model model1("C:\\Users\\54367\\CLionProjects\\waterSim\\res\\models\\nanosuit\\nanosuit.obj");


    /*加载skybox*/
    unsigned int cubeMapTexture = loader.loadCubeMap(faces);
    Shader skyboxShader("../res/shaderCode/skybox_shader.vs", "../res/shaderCode/skybox_shader.fs");

    glEnable(GL_DEPTH_TEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    double eqn[]={0.0,1.0,0.0,0.0};
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


        //渲染指令
        waterFbo.bindReflectionFbo();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //激活着色器
        ourShader.use();

        //建立模型矩阵
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f));
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
        ourShader.setMat4("model", model);

        //建立观察矩阵
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);

        //建立投影矩阵
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(camera.Zoom), displayManager->getRatio(), 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);


//        //
        ourShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        ourShader.setVec3("dirLight.ambient", 0.2, 0.2f, 0.2f);
        ourShader.setVec3("dirLight.diffuse", 0.5f, 0.5f, 0.5f);
        ourShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//        //
        ourShader.setVec3("spotLight.position", camera.Position);
        ourShader.setVec3("spotLight.direction", camera.Front);
        ourShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        ourShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));
        ourShader.setVec3("spotLight.ambient", 0.0f);
        ourShader.setVec3("spotLight.diffuse", 1.0f);
        ourShader.setVec3("spotLight.specular", 1.0f);
        ourShader.setFloat("spotLight.constant", 1.0f);
        ourShader.setFloat("spotLight.linear", 0.09f);
        ourShader.setFloat("spotLight.quadratic", 0.032f);
//        //
        for (int i = 0; i < 4; ++i) {
            std::string str = "pointLights[" + std::to_string(i) + "].";
            ourShader.setVec3(str + "position", pointLightPositions[i]);
            ourShader.setVec3(str + "ambient", 0.5f, 0.5f, 0.5f);
            ourShader.setVec3(str + "diffuse", 0.8f, 0.8f, 0.8f);
            ourShader.setVec3(str + "specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat(str + "constant", 1.0f);
            ourShader.setFloat(str + "linear", 0.09f);
            ourShader.setFloat(str + "quadratic", 0.032f);
        }
//
        ourShader.setVec3("viewPos", camera.Position);
//        //设置材质
        ourShader.setFloat("material.shininess", 64.0f);
        model1.Draw(ourShader);

        //设置光源
        lampShader.use();
        lampShader.setMat4("view", view);
        lampShader.setMat4("projection", projection);
        glBindVertexArray(lightObj.getVao());
        for (int i = 0; i < 4; i++) {
            model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.2f));
            lampShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, lightObj.getCount());
        }

        // draw skybox as last
        glDepthFunc(
                GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
        skyboxShader.use();
        view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
        skyboxShader.setMat4("view", view);
        skyboxShader.setMat4("projection", projection);
        // skybox cube
        glBindVertexArray(skyboxObj.getVao());
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMapTexture);
        glDrawArrays(GL_TRIANGLES, 0, skyboxObj.getCount());
        glBindVertexArray(0);
        glDepthFunc(GL_LESS); // set depth function back to default


        waterFbo.unbindFbo();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //激活着色器
        ourShader.use();

        //建立模型矩阵
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f));
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
        ourShader.setMat4("model", model);


        //建立观察矩阵
        view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);

        //建立投影矩阵
        projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(camera.Zoom), displayManager->getRatio(), 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);


//        //
        ourShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
        ourShader.setVec3("dirLight.ambient", 0.2, 0.2f, 0.2f);
        ourShader.setVec3("dirLight.diffuse", 0.5f, 0.5f, 0.5f);
        ourShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//        //
        ourShader.setVec3("spotLight.position", camera.Position);
        ourShader.setVec3("spotLight.direction", camera.Front);
        ourShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        ourShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));
        ourShader.setVec3("spotLight.ambient", 0.0f);
        ourShader.setVec3("spotLight.diffuse", 1.0f);
        ourShader.setVec3("spotLight.specular", 1.0f);
        ourShader.setFloat("spotLight.constant", 1.0f);
        ourShader.setFloat("spotLight.linear", 0.09f);
        ourShader.setFloat("spotLight.quadratic", 0.032f);
//        //
        for (int i = 0; i < 4; ++i) {
            std::string str = "pointLights[" + std::to_string(i) + "].";
            ourShader.setVec3(str + "position", pointLightPositions[i]);
            ourShader.setVec3(str + "ambient", 0.5f, 0.5f, 0.5f);
            ourShader.setVec3(str + "diffuse", 0.8f, 0.8f, 0.8f);
            ourShader.setVec3(str + "specular", 1.0f, 1.0f, 1.0f);
            ourShader.setFloat(str + "constant", 1.0f);
            ourShader.setFloat(str + "linear", 0.09f);
            ourShader.setFloat(str + "quadratic", 0.032f);
        }
//
        ourShader.setVec3("viewPos", camera.Position);
//        //设置材质
        ourShader.setFloat("material.shininess", 64.0f);
        model1.Draw(ourShader);

        //设置光源
        lampShader.use();
        lampShader.setMat4("view", view);
        lampShader.setMat4("projection", projection);
        glBindVertexArray(lightObj.getVao());
        for (int i = 0; i < 4; i++) {
            model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.2f));
            lampShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, lightObj.getCount());
        }

        fboShader.use();
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 2.0f));
        model = glm::scale(model,glm::vec3(1.6f, 0.9f, 1.0f));
        fboShader.setMat4("model",model);
        fboShader.setMat4("view",view);
        fboShader.setMat4("projection", projection);

        glBindVertexArray(fboObj.getVao());
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, waterFbo.getReflectionFboColor());
        glDrawArrays(GL_TRIANGLES, 0, fboObj.getCount());



        // draw skybox as last
        glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
        skyboxShader.use();
        view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
        skyboxShader.setMat4("view", view);
        skyboxShader.setMat4("projection", projection);
        // skybox cube
        glBindVertexArray(skyboxObj.getVao());
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMapTexture);
        glDrawArrays(GL_TRIANGLES, 0, skyboxObj.getCount());
        glBindVertexArray(0);
        glDepthFunc(GL_LESS); // set depth function back to default


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













