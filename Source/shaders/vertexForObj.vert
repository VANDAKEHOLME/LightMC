#version 330 core
layout(location = 12) in vec3 aPos;
layout(location = 2) in vec2 aTexCoord;

out vec2 TexCoord;
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
void main() {
    gl_Position = projection * view * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    //vertexColor = ;
    TexCoord = aTexCoord;
}