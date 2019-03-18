#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main(){
    vec4 worldPos = model * vec4(aPos, 1.0f);

    gl_Position = projection * view * worldPos;
    TexCoords = aTexCoords;
}