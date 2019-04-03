//
// Created by 54367 on 2019/2/28.
//

#include "waterRenderer.h"


std::vector<float> quadV = {
        // positions   // texCoords
        -0.5f, 0.0f, -0.5f, 0.0f, 0.0f,
        0.5f, 0.0f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.0f, 0.5f, 0.0f, 1.0f,
        -0.5f, 0.0f, -0.5f, 0.0f, 0.0f
};

WaterRenderer::WaterRenderer(WaterFbo &waterFbo)
        : waterShader("../res/shaderCode/water_shader"),
          basicShader("../res/shaderCode/basicShader"),
          waterObj(loader.loadVAO(quadV, 5, {3, 2})),
          shapeObj(loader.loadVAO(Drawer::drawCircle(360), 3, {3})) {

    //初始化
    this->waterFbo = &waterFbo;
    moveFactor = 0.0f;
    tiling = glm::vec2(2, 4);

    //绑定纹理单元
    waterShader.use();
    waterShader.setTexture("reflectionTexture", 0);
    waterShader.setTexture("refractionTexture", 1);
    waterShader.setTexture("dudvMap", 2);
    waterShader.setTexture("normalMap", 3);
    waterShader.setTexture("depthTexture", 4);
    waterShader.setTexture("flowMap", 5);

    //导入纹理
    dudvMap = loader.loadTexture("../res/pic/waterDUDV.png");
    normalMap = loader.loadTexture("../res/pic/normalMap.png");
    flowMap = loader.loadTexture("../res/pic/flowMap.png");

    waterShader.setNearFar(0.1f, 1000.0f);
    waterShader.setVec2("tiling", tiling);
}

void WaterRenderer::render(Camera &camera, Light &light) {


    //设置model矩阵
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(tiling.x, 0, tiling.y));

    //开启混合模式
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);

    //startMasking();

    waterShader.use();
    waterShader.setCameraPos(camera.getPosition());
    waterShader.setLight(light);
    //绑定纹理单元
    moveFactor += 0.1f * DisplayManager::calcFrame();
    if (moveFactor > 1)moveFactor -= 1;
    waterShader.setTime(moveFactor);
    model = glm::translate(model, glm::vec3(0, -0.0001, 0));
    waterShader.setModel(model);
    glBindVertexArray(waterObj.getVao());

    //绑定反射贴图
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, waterFbo->getReflectionFboColor());
    //绑定折射贴图
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, waterFbo->getRefractionFboColor());
    //绑定dudvMap
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, dudvMap);
    //绑定normalMap
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, normalMap);
    //绑定depthMap
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, waterFbo->getRefractionFboDepth());
    //绑定flowMap
    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, flowMap);
    glDrawArrays(GL_TRIANGLES, 0, waterObj.getCount());

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
    //stopMasking();

}

void WaterRenderer::startMasking() {
    glEnable(GL_STENCIL_TEST);
    glClear(GL_STENCIL_BUFFER_BIT);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilMask(0xFF);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(tiling.x, 0, tiling.y));

    basicShader.use();
    basicShader.setModel(model);
    glBindVertexArray(shapeObj.getVao());
    glDrawArrays(GL_TRIANGLE_FAN, 0, shapeObj.getCount());

    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilMask(0x00);
}

void WaterRenderer::stopMasking() {
    glDisable(GL_STENCIL_TEST);
    glStencilMask(0xFF);
}
