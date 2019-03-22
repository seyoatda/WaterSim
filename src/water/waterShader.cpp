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

