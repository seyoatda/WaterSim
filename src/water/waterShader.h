//
// Created by 54367 on 2019/2/23.
//

#ifndef OPENGL_WATER_SHADER_H
#define OPENGL_WATER_SHADER_H

#include "../shader/shader.h"

class WaterShader: public Shader {
public:
    WaterShader(std::string path);

    void setProjection(glm::mat4 projection);

    void setView(glm::mat4 view);

    void setModel(glm::mat4 model);



};


#endif //OPENGL_WATER_SHADER_H
