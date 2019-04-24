//
// Created by 54367 on 2019/3/12.
//

#include "mainRenderer.h"
#include "windowManager.h"

glm::vec3 pointLightPositions[] = {
        glm::vec3(0.5f, 1.0f, 2.0f),
        glm::vec3(-0.5f, -3.0f, 2.0f),
        glm::vec3(-4.0f, -2.0f, -2.0f),
        glm::vec3(1.0f, 0.0f, -3.0f)
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

MainRenderer::MainRenderer()
        : modelShader("../res/shaderCode/33shader"),
          lampShader("../res/shaderCode/light_shader"),
          nanoModel("../res/models/nanosuit/nanosuit.obj"),
          ditchModel("../res/models/ditch/ditch.obj"),
          lightObj(loader.loadVAO(vertices, 8, {3})) {
    glEnable(GL_CLIP_DISTANCE0);
    uboTrans = initUboTrans();
    uboPlane = initUboPlane();
}

void MainRenderer::render(Camera &camera) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    modelShader.use();
    //建立模型矩阵
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f));
    model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
    modelShader.setMat4("model", model);


    //建立观察矩阵
    glm::mat4 view = camera.getViewMatrix();

    //建立投影矩阵
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(camera.Zoom), WindowManager::getRatio(), 0.1f, 100.0f);
    setUboTrans(projection, view);

//        //
    modelShader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
    modelShader.setVec3("dirLight.ambient", 0.2, 0.2f, 0.2f);
    modelShader.setVec3("dirLight.diffuse", 0.5f, 0.5f, 0.5f);
    modelShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//        //
    modelShader.setVec3("spotLight.position", camera.Position);
    modelShader.setVec3("spotLight.direction", camera.Front);
    modelShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    modelShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));
    modelShader.setVec3("spotLight.ambient", 0.0f);
    modelShader.setVec3("spotLight.diffuse", 1.0f);
    modelShader.setVec3("spotLight.specular", 1.0f);
    modelShader.setFloat("spotLight.constant", 1.0f);
    modelShader.setFloat("spotLight.linear", 0.09f);
    modelShader.setFloat("spotLight.quadratic", 0.032f);
//        //
    for (int i = 0; i < 4; ++i) {
        std::string str = "pointLights[" + std::to_string(i) + "].";
        modelShader.setVec3(str + "position", pointLightPositions[i]);
        modelShader.setVec3(str + "ambient", 0.5f, 0.5f, 0.5f);
        modelShader.setVec3(str + "diffuse", 0.8f, 0.8f, 0.8f);
        modelShader.setVec3(str + "specular", 1.0f, 1.0f, 1.0f);
        modelShader.setFloat(str + "constant", 1.0f);
        modelShader.setFloat(str + "linear", 0.09f);
        modelShader.setFloat(str + "quadratic", 0.032f);
    }
//
    modelShader.setVec3("viewPos", camera.Position);
    //设置材质
    modelShader.setFloat("material.shininess", 64.0f);
    nanoModel.Draw(modelShader);
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-4, 0, 2));
    model = glm::rotate(model,glm::radians(45.0f),glm::vec3(0,1,0));
    model = glm::scale(model, glm::vec3(0.05, 0.05, 0.05));
    modelShader.setMat4("model", model);
    ditchModel.Draw(modelShader);

    //设置光源
    lampShader.use();
    glBindVertexArray(lightObj.getVao());
    for (int i = 0; i < 4; i++) {
        model = glm::mat4(1.0f);
        model = glm::translate(model, pointLightPositions[i]);
        model = glm::scale(model, glm::vec3(0.2f));
        lampShader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, lightObj.getCount());
    }

    // draw skybox as last
    skyboxRenderer.render(camera);

}

unsigned int MainRenderer::initUboTrans() {
    unsigned int uboTrans;
    glGenBuffers(1, &uboTrans);
    glBindBuffer(GL_UNIFORM_BUFFER, uboTrans);
    glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    //绑定在第2个绑定点
    glBindBufferBase(GL_UNIFORM_BUFFER, 2, uboTrans);
    return uboTrans;
}

unsigned int MainRenderer::initUboPlane() {
    unsigned int uboPlane;
    glGenBuffers(1, &uboPlane);
    glBindBuffer(GL_UNIFORM_BUFFER, uboPlane);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::vec4), NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    //绑定在第2个绑定点
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, uboPlane);
    return uboPlane;
}

void MainRenderer::setUboTrans(glm::mat4 proj, glm::mat4 view) {
    glBindBuffer(GL_UNIFORM_BUFFER, uboTrans);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(proj));
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(view));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void MainRenderer::setUboPlane(glm::vec4 clippingPlane) {
    glBindBuffer(GL_UNIFORM_BUFFER, uboPlane);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::vec4), glm::value_ptr(clippingPlane));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
