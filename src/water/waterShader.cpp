//
// Created by 54367 on 2019/2/23.
//

#include "waterShader.h"
#include <string>
namespace{
    constexpr auto VERTPATH="../res/shaderCode/water_shader.vs";
    constexpr auto FRAGPATH="../res/shaderCode/water_shader.fs";
}

WaterShader::WaterShader() :Shader(VERTPATH,FRAGPATH){

}
void WaterShader::setProjection(glm::mat4 projection) {
    setMat4("projection",projection);
}
void WaterShader::setView(glm::mat4 view) {
    setMat4("view",view);
}
void WaterShader::setModel(glm::mat4 model) {
    setMat4("model",model);
}
void WaterShader::setPlane(glm::vec4 plane) {
    setVec4("plane",plane);
}
