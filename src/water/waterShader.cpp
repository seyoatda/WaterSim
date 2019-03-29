//
// Created by 54367 on 2019/2/23.
//

#include "waterShader.h"


WaterShader::WaterShader(std::string path) : Shader(path) {

}

void WaterShader::setProjection(glm::mat4 projection) {
    setMat4("projection", projection);
}

void WaterShader::setView(glm::mat4 view) {
    setMat4("view", view);
}

void WaterShader::setModel(glm::mat4 model) {
    setMat4("model", model);
}

void WaterShader::setMoveFactor(float factor) {
    setFloat("moveFactor", factor);
}

void WaterShader::setCameraPos(glm::vec3 pos) {
    setVec3("cameraPos", pos);
}

void WaterShader::setLight(Light &light) {
    setVec3("lightPos", light.getPos());
    setVec3("lightColor", light.getColor());
}

void WaterShader::setTexture(const std::string &textureName, unsigned int textureId) {
    setInt(textureName, textureId);
}

void WaterShader::setNearFar(float nearP, float farP) {
    setFloat("near", nearP);
    setFloat("far", farP);
}
