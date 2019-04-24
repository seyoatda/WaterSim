//
// Created by 54367 on 2019/3/4.
//

#ifndef OPENGL_WATERFRAMEBUFFER_H
#define OPENGL_WATERFRAMEBUFFER_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../RenderEngine/windowManager.h"

class WaterFbo {
public:
    WaterFbo();
    void bindReflectionFbo();
    void bindRefractionFbo();
    unsigned int createFbo();
    void bindFbo(unsigned int fbo,int width,int height);
    void unbindFbo();
    void clear();

    unsigned int getReflectionFboColor() const;

    unsigned int getRefractionFboColor() const;

    unsigned int getRefractionFboDepth() const;

private:
    void initReflectionFbo();
    void initRefractionFbo();
    void initDepthFBO();
    unsigned int createFboColor(int width, int height);
    unsigned int createFboDepth(int width,int height);
    unsigned int createRbo(int width,int height);

    //反射的帧缓冲的id && 颜色纹理 && 深度和模板rbo
    unsigned int reflectionFbo;
    unsigned int reflectionFboColor;
    unsigned int reflectionRbo;

    //折射的帧缓冲的id && 颜色纹理 && 深度纹理
    unsigned int refractionFbo;
    unsigned int refractionFboColor;
    unsigned int refractionFboDepth;
};


#endif //OPENGL_WATERFRAMEBUFFER_H
