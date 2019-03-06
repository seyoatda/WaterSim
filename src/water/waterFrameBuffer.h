//
// Created by 54367 on 2019/3/4.
//

#ifndef OPENGL_WATERFRAMEBUFFER_H
#define OPENGL_WATERFRAMEBUFFER_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class WaterFrameBuffer {
public:
    void bindReflectionFBO();
    unsigned int createFBO();

private:
    void initReflectionFBO();
    void initDepthFBO();
    unsigned int createTextureAttachment(int width,int height);
    unsigned int createDepthTextureAttachment(int width,int height);
};


#endif //OPENGL_WATERFRAMEBUFFER_H
