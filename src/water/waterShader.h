//
// Created by 54367 on 2019/2/23.
//

#ifndef OPENGL_WATER_SHADER_H
#define OPENGL_WATER_SHADER_H

#include "../shader/shader.h"
#include "../Camera/light.h"

class WaterShader: public Shader {
public:
    WaterShader(std::string path);

    void setProjection(glm::mat4 projection);

    void setView(glm::mat4 view);

    void setModel(glm::mat4 model);

    void setTime(float factor);

    void setCameraPos(glm::vec3 pos);

    void setLight(Light& light);

    void setTexture(const std::string &textureName,unsigned int textureId);

    void setNearFar(float nearP, float farP);
};


#endif //OPENGL_WATER_SHADER_H
