#version 420 core
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

layout(std140, binding = 2) uniform uboTrans{
    mat4 projection;
    mat4 view;
};
layout(std140, binding = 1) uniform uboPlane{
    vec4 plane;
};
void main(){
    TexCoords = aPos;
    vec4 worldPos = vec4(aPos, 1.0);
    gl_ClipDistance[0] = dot(worldPos, plane);
    vec4 pos = projection * view * worldPos;
    gl_Position = pos.xyww;
}