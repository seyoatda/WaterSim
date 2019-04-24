//
// Created by 54367 on 2019/3/12.
//

#ifndef OPENGL_MAINRENDERER_H
#define OPENGL_MAINRENDERER_H

#include "../Camera/light.h"
#include "../Camera/camera.h"
#include "loader.h"
#include "../Shader/shader.h"
#include "../Skybox/skyboxRenderer.h"
#include "../Entities/model.h"
#include <glm/gtc/type_ptr.hpp>

class MainRenderer {
public:
    MainRenderer();

    void render(Camera &camera);



    void setUboTrans(glm::mat4 proj, glm::mat4 view);

    void setUboPlane(glm::vec4 clippingPlane);

    void setRefract();

private:
    //初始化projection & view 的缓冲块
    unsigned int initUboTrans();

    //初始化截面的缓冲块
    unsigned int initUboPlane();


    unsigned int uboTrans;
    unsigned int uboPlane;
    Loader loader;
    Shader modelShader;
    Shader lampShader;
    SkyboxRenderer skyboxRenderer;
    Object lightObj;
    Model nanoModel;
    Model ditchModel;


};


#endif //OPENGL_MAINRENDERER_H
