//
// Created by 54367 on 2019/2/11.
//

#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H


#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "../Shader/shader.h"
#include <assimp/Importer.hpp>

using namespace std;
struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};
struct Texture {
    unsigned int id;
    std::string type;
    aiString path; // 判断是否被加载
};


class Mesh {
public:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;

    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

    void Draw(Shader shader);

private:
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};



#endif //OPENGL_MESH_H
