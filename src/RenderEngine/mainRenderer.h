//
// Created by 54367 on 2019/3/12.
//

#ifndef OPENGL_MAINRENDERER_H
#define OPENGL_MAINRENDERER_H

#include "../camera/light.h"
#include "../camera/camera.h"

class MainRenderer {
    void Render(Light& light,Camera camera,glm::vec4 const& clipPlane);
};


#endif //OPENGL_MAINRENDERER_H
