#version 330 core
layout(location = 11) in vec3 lightPos;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
void main() {
    gl_Position = projection * view * transform * vec4(lightPos, 1.0);
}