//
// Created by 54367 on 2019/3/3.
//

#include "object.h"

Object::Object(unsigned int vao, unsigned int count) : vao(vao), count(count) {

}

unsigned int Object::getVao() {
    return vao;
}

unsigned int Object::getCount() {
    return count;
}
