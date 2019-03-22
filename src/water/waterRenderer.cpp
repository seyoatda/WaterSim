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
          waterObj(loader.loadVAO(quadV, 5, {3, 2})) {
    this->waterFbo = &waterFbo;
    waterShader.use();
    waterShader.setInt("reflectionTexture", 0);
    waterShader.setInt("refractionTexture", 1);
}

void WaterRenderer::render(Camera camera) {

    waterShader.use();
    //绑定纹理单元

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(2.0f, 0.0f, 2.0f));
    model = glm::scale(model, glm::vec3(1.6f, 0.9f, 1.0f));
    waterShader.setModel(model);
    glBindVertexArray(waterObj.getVao());
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, waterFbo->getReflectionFboColor());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, waterFbo->getRefractionFboColor());
    glDrawArrays(GL_TRIANGLES, 0, waterObj.getCount());

}

