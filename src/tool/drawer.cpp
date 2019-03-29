//
// Created by 54367 on 2019/3/26.
//

#include <glm/glm.hpp>
#include "drawer.h"

std::vector<float> Drawer::drawCircle(int n) {
    std::vector<float> vertice(3 * (n + 1), 0);
    float degree = 0;
    float radius = 0.5;
    for (int i = 0; i < n; i++) {
        //B point
        vertice[i * 3 ] = glm::cos(glm::radians(degree)) * radius;
        vertice[i * 3 + 1] = 0;
        vertice[i * 3 + 2] = glm::sin(glm::radians(degree)) * radius;
        degree += 360.0 / n;
    }
    return vertice;
}
