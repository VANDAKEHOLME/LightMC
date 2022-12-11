#version 400 core
out vec4 FragColor;
in vec3 vertexColor;
in vec2 TexCoord;
uniform sampler2D Texture;
uniform sampler2D Face;
void main() {
    FragColor = mix(texture(Face, TexCoord), texture(Texture, TexCoord), 0.8);
}