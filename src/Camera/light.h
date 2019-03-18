//
// Created by 54367 on 2019/3/12.
//

#ifndef OPENGL_LIGHT_H
#define OPENGL_LIGHT_H

#include <glm/glm.hpp>
class Light {
public:
    Light(glm::vec3 pos,glm::vec3 color);

    const glm::vec3 &getPos() const;

    void setPos(const glm::vec3 &pos);

    const glm::vec3 &getColor() const;

    void setColor(const glm::vec3 &color);

private:
    glm::vec3 pos;
    glm::vec3 color;
};


#endif //OPENGL_LIGHT_H
