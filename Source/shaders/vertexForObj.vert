#version 330 core
layout(location = 12) in vec3 aPos;
layout(location = 2) in vec3 aNormal;

out vec3 Normal;
out vec3 lightPos;
out vec3 FragPos;
out vec3 viewPos;
uniform vec3 cameraPos;
uniform vec3 u_lightPos;
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
void main() {
    gl_Position = projection * view * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    lightPos = u_lightPos;
    FragPos = aPos;
    viewPos = cameraPos;
    Normal = aNormal;
}