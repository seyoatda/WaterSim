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

const glm::vec3 &Light::getAmbient() const {
    return ambient;
}

void Light::setAmbient(const glm::vec3 &ambient) {
    Light::ambient = ambient;
}

const glm::vec3 &Light::getDiffuse() const {
    return diffuse;
}

void Light::setDiffuse(const glm::vec3 &diffuse) {
    Light::diffuse = diffuse;
}

const glm::vec3 &Light::getSpecular() const {
    return specular;
}

void Light::setSpecular(const glm::vec3 &specular) {
    Light::specular = specular;
}
