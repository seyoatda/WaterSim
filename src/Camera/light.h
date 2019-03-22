//
// Created by 54367 on 2019/3/12.
//

#ifndef OPENGL_LIGHT_H
#define OPENGL_LIGHT_H

#include <glm/glm.hpp>

class Light {
public:
    Light(glm::vec3 pos = glm::vec3(0, 0, 0), glm::vec3 color = glm::vec3(1, 1, 1));

    const glm::vec3 &getPos() const;

    void setPos(const glm::vec3 &pos);

    const glm::vec3 &getColor() const;

    void setColor(const glm::vec3 &color);

    const glm::vec3 &getAmbient() const;

    void setAmbient(const glm::vec3 &ambient);

    const glm::vec3 &getDiffuse() const;

    void setDiffuse(const glm::vec3 &diffuse);

    const glm::vec3 &getSpecular() const;

    void setSpecular(const glm::vec3 &specular);

private:
    glm::vec3 pos;
    glm::vec3 color;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};


#endif //OPENGL_LIGHT_H
