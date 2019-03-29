//
// Created by 54367 on 2019/3/26.
//

#ifndef WATERSIM_BASICSHADER_H
#define WATERSIM_BASICSHADER_H

#include <glm/glm.hpp>
#include "../Camera/light.h"
#include "../shader/shader.h"

class BasicShader: public Shader {

public:
    BasicShader(std::string path);

    void setProjection(glm::mat4 projection);

    void setView(glm::mat4 view);

    void setModel(glm::mat4 model);

    void setMoveFactor(float factor);

    void setCameraPos(glm::vec3 pos);

    void setLight(Light &light);

};


#endif //WATERSIM_BASICSHADER_H
