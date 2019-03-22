//
// Created by 54367 on 2019/3/12.
//

#include "mainRenderer.h"

MainRenderer::MainRenderer()
        : modelShader("../res/shaderCode/33shader"),
          lampShader("../res/shaderCode/light_shader") {

    uboTrans=initUboTrans();
}

void MainRenderer::render(const Camera &camera) {

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

}
