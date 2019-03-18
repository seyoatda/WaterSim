//
// Created by 54367 on 2019/3/3.
//

#ifndef OPENGL_OBJECT_H
#define OPENGL_OBJECT_H


class Object {
public:
    Object(unsigned int vao, unsigned int count);
    unsigned int getVao();
    unsigned int getCount();
private:
    unsigned int vao;
    unsigned int count;
};


#endif //OPENGL_OBJECT_H
