#version 330 core
layout (location = 12) in vec3 aPos;
out vec4 vertexColor;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y + 0.1,aPos.z, 1.0);
    vertexColor = vec4(.5,.0,.0,1.0);
}