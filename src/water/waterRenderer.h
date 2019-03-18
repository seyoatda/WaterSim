//
// Created by 54367 on 2019/2/28.
//

#ifndef OPENGL_WATER_RENDERER_H
#define OPENGL_WATER_RENDERER_H


#include <vector>
#include "waterShader.h"
#include "waterTile.h"
#include "../camera/camera.h"

class WaterRenderer {
public:
    void render(std::vector<WaterTile> const & water,Camera camera);

private:
    WaterShader shader;
    
};


#endif //OPENGL_WATER_RENDERER_H
