//
// Created by 54367 on 2018/11/7.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:

    Shader(std::string vertexPath, std::string fragmentPath);

    //
    void use();

    void stop();

    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    void setVec3(const std::string &name, glm::vec3 vec) const;

    void setVec3(const std::string &name, float x, float y, float z) const;

    void setVec3(const std::string &name, float x) const;

    void setVec4(const std::string &name, const glm::vec4 &value) const;

private:
    //程序ID
    unsigned int ID;

    //
    void checkCompileErrors(unsigned int shader, std::string type);
};


#endif //OPENGL_SHADER_H
