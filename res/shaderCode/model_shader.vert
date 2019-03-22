#version 420 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 Normal;
out vec3 Pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec4 clipPlane=vec4(0,-1,0,15);

void main()
{

    gl_ClipDistance[0] = -10;
    TexCoords = aTexCoords;
    Normal=aNormal;
    Pos=aPos;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}