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

class WaterRenderer {
public:
    WaterRenderer(WaterFbo &waterFbo);
    void render(Camera camera);

private:
    Loader loader;

    WaterShader waterShader;
    WaterFbo* waterFbo;
    Object waterObj;
};


#endif //OPENGL_WATER_RENDERER_H
