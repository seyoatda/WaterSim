//
// Created by 54367 on 2019/3/26.
//

#include "basicShader.h"
BasicShader::BasicShader(std::string path) : Shader(path) {

}

void BasicShader::setProjection(glm::mat4 projection) {
    setMat4("projection", projection);
}

void BasicShader::setView(glm::mat4 view) {
    setMat4("view", view);
}

void BasicShader::setModel(glm::mat4 model) {
    setMat4("model", model);
}

void BasicShader::setMoveFactor(float factor) {
    setFloat("moveFactor", factor);
}

void BasicShader::setCameraPos(glm::vec3 pos) {
    setVec3("cameraPos", pos);
}

void BasicShader::setLight(Light &light) {
    setVec3("lightPos", light.getPos());
    setVec3("lightColor", light.getColor());
}
