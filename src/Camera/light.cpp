//
// Created by 54367 on 2019/3/12.
//

#include "light.h"

Light::Light(glm::vec3 pos, glm::vec3 color):pos(pos),color(color) {

}

const glm::vec3 &Light::getPos() const {
    return pos;
}

void Light::setPos(const glm::vec3 &pos) {
    this->pos = pos;
}

const glm::vec3 &Light::getColor() const {
    return color;
}

void Light::setColor(const glm::vec3 &color) {
   this->color = color;
}
