//
// Created by 54367 on 2019/2/28.
//

#ifndef OPENGL_WATER_RENDERER_H
#define OPENGL_WATER_RENDERER_H


#include <vector>
#include "waterShader.h"
#include "waterTile.h"
#include "../camera/camera.h"
#include "waterFbo.h"
#include "../Entities/object.h"
#include "../RenderEngine/loader.h"
#include "../tool/drawer.h"
#include "../Shader/basicShader.h"

class WaterRenderer {
public:
    explicit WaterRenderer(WaterFbo &waterFbo);

    void render(Camera &camera, Light &light);

private:
    Loader loader;

    WaterShader waterShader;
    BasicShader basicShader;
    WaterFbo *waterFbo;
    Object waterObj;
    Object shapeObj;

    unsigned int dudvTexture;
    unsigned int normalTexture;

    float moveFactor;
};


#endif //OPENGL_WATER_RENDERER_H
