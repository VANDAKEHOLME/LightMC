#version 400 core
out vec4 FragColor;
// in vec2 TexCoord;
// uniform sampler2D Texture;
// uniform sampler2D Face;
uniform vec3 objectColor;
uniform vec3 lightColor;
void main() {
    FragColor = vec4(objectColor * lightColor, 1.0); //* mix(texture(Face, TexCoord), texture(Texture, TexCoord), 0.8);
}