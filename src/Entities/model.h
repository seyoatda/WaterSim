//
// Created by 54367 on 2019/2/11.
//

#ifndef OPENGL_MODEL_H
#define OPENGL_MODEL_H

#include <vector>
#include <string>
#include "mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../tool/stb_image.h"


unsigned int TextureFromFile(const char *path, const string &directory, bool gamma = false);

class Model {
public:
    Model(string path);

    void Draw(Shader shader);

private:
    vector<Texture> textures_loaded;
    vector<Mesh> meshes;
    string directory;

    void loadModel(string path);

    void processNode(aiNode *node, const aiScene *scene);

    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};



#endif //OPENGL_MODEL_H
