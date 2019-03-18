//
// Created by 54367 on 2019/3/4.
//

#include "waterFbo.h"

namespace {
    constexpr int R_WIDTH = 1280, R_HEIGHT = 720;
    constexpr int A_WIDTH = 1280, A_HEIGHT = 720;
}

WaterFbo::WaterFbo() {
    initReflectionFbo();
    initRefractionFbo();
}

void WaterFbo::clear() {
    glDeleteFramebuffers(1,&reflectionFbo);
    glDeleteTextures(1,&reflectionFboColor);
    glDeleteRenderbuffers(1,&reflectionRbo);

    glDeleteFramebuffers(1,&refractionFbo);
    glDeleteTextures(1,&refractionFboDepth);
    glDeleteTextures(1,&refractionFboColor);
}

void WaterFbo::bindReflectionFbo() {
    bindFbo(reflectionRbo, R_WIDTH, R_HEIGHT);
}

void WaterFbo::bindRefractionFbo() {
    bindFbo(refractionFbo,A_WIDTH,A_HEIGHT);
}

void WaterFbo::bindFbo(unsigned int fbo, int width, int height) {
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    glViewport(0, 0, width, height);
}

void WaterFbo::unbindFbo() {
    int width = 0, height = 0;
    glfwGetFramebufferSize(DisplayManager::window(), &width, &height);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, 1280, 720);
}

unsigned int WaterFbo::createFbo() {
    unsigned int FBO;
    glGenFramebuffers(1, &FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    glDrawBuffer(GL_COLOR_ATTACHMENT0);
    return FBO;
}

unsigned int WaterFbo::createFboColor(int width, int height) {
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    //创建一个空的图像
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture, 0);
    return texture;
}

unsigned int WaterFbo::createFboDepth(int width, int height) {
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    //创建一个空的图像
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, width, height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, texture, 0);
    return texture;
}

unsigned int WaterFbo::createRbo(int width, int height) {
    unsigned int rbo;
    glGenRenderbuffers(1, &rbo);

    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    return rbo;
}

unsigned int WaterFbo::getReflectionFboColor() const {
    return reflectionFboColor;
}

unsigned int WaterFbo::getRefractionFboColor() const {
    return refractionFboColor;
}

unsigned int WaterFbo::getRefractionFboDepth() const {
    return refractionFboDepth;
}


void WaterFbo::initReflectionFbo() {
    reflectionFbo = createFbo();
    reflectionFboColor = createFboColor(R_WIDTH, R_HEIGHT);
    reflectionRbo = createRbo(R_WIDTH, R_HEIGHT);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: reflection fbo is not complete!" << std::endl;
    unbindFbo();
}

void WaterFbo::initRefractionFbo() {
    refractionFbo = createFbo();
    refractionFboColor = createFboColor(A_WIDTH, A_HEIGHT);
    refractionFboDepth = createFboDepth(A_WIDTH, A_HEIGHT);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: refraction fbo is not complete!" << std::endl;
    unbindFbo();
}

void WaterFbo::initDepthFBO() {

}
