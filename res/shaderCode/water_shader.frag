#version 420 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D reflectionTexture;
uniform sampler2D refractionTexture;

void main() {
    vec4 reflectColor = texture(reflectionTexture, TexCoords);
    vec4 refractColor = texture(refractionTexture, TexCoords);
    FragColor = mix(reflectColor, refractColor, 0.5);

}