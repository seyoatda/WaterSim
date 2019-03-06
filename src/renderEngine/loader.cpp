//
// Created by 54367 on 2019/3/1.
//

#include "loader.h"
#include <numeric>

/*
 *
 */
Object Loader::loadVAO(std::vector<float> vertices, unsigned int stride, std::initializer_list<int> lens) {
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    //设置顶点属性
    unsigned int step = 0, begin = 0;
    //计算顶点间隔
    for (int len:lens) {
        glVertexAttribPointer(begin, len, GL_FLOAT, GL_FALSE, stride * sizeof(float),
                              (void *) (step * sizeof(float)));
        glEnableVertexAttribArray(begin++);
        step += len;
    }
    return Object(VAO, (unsigned) vertices.size() / stride);
}

unsigned int Loader::loadCubeMap(std::vector<std::string> faces) {
    return 0;
}
