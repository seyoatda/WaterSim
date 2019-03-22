#version 420 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
layout(std140, binding = 2) uniform uboTrans{
    mat4 projection;
    mat4 view;
};
layout(std140, binding = 1) uniform uboPlane{
    vec4 plane;
};
void main()
{
    vec4 worldPos = model * vec4(aPos, 1.0f);
    gl_ClipDistance[0] = dot(worldPos, plane);
    gl_Position = projection * view * worldPos;
}