#version 420 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 texCoords;
out vec4 clipSpace;
out vec3 cameraVec;
out vec3 lightVec;
uniform mat4 model;
layout(std140, binding = 2) uniform uboTrans{
    mat4 projection;
    mat4 view;
};
uniform vec3 cameraPos;
uniform vec3 lightPos;

void main(){
    vec4 worldPos = model * vec4(aPos, 1.0f);
    clipSpace = projection * view * worldPos;
    gl_Position = clipSpace;
    texCoords = aTexCoords;
    cameraVec = cameraPos - aPos;
    lightVec = worldPos.xyz - lightPos;
}