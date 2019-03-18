//
// Created by 54367 on 2019/3/1.
//

#ifndef OPENGL_LOADER_H
#define OPENGL_LOADER_H

#include <vector>
#include "../Entities/object.h"
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../tool/stb_image.h"
#include <iostream>

class Loader {
public:
    Object loadVAO(std::vector<float> vertices, unsigned int stride, std::initializer_list<int> pos);

    unsigned int loadCubeMap(std::vector<std::string> faces);

private:

};


#endif //OPENGL_LOADER_H
