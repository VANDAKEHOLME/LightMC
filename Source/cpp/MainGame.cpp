#include "Texture.h"
#include "MainGame.h"
#include "DebugTools.h"
#include "Block.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <cmath>

/// @brief To start game.
void LightMC::MainGame::StartGame()
{
    LightMC::DebugTools::DebugToolsInitialize();
    windowHandler = new WindowHandler(600, 800, "Light MC");
#pragma region Test
    camera = new LightMC::Camera(glm::vec3(0, 0, -3));
    glEnable(GL_DEPTH_TEST);
    Block block(-0.75f, -0.75f, -0.75f, 1.f, 1.f, 1.f);

    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,

        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f};
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    vertexShaderForObj = new Shader("..\\shaders\\vertexForObj.vert", GL_VERTEX_SHADER, shaderProgram);
    fragmentShaderForObj = new Shader("..\\shaders\\fragmentForObj.frag", GL_FRAGMENT_SHADER, shaderProgram);
    vertexShaderForLight = new Shader("..\\shaders\\vertexForLight.vert", GL_VERTEX_SHADER, shaderProgram);
    fragmentShaderForLight = new Shader("..\\shaders\\fragmentForLight.frag", GL_FRAGMENT_SHADER, shaderProgram);

    glGenVertexArrays(1, &targetVAO);
    glGenVertexArrays(1, &lightVAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(targetVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STREAM_DRAW);
    glVertexAttribPointer(12, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(12);
    glVertexAttribPointer(2, 3, GL_FLOAT, false, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(lightVAO);
    glVertexAttribPointer(11, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(11);
    glBindVertexArray(0);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#pragma endregion
    windowHandler->WindowLoop(WindowLoopCallback, this);
}
/// @brief To terminate all the game.
void LightMC::MainGame::TerminateGame()
{
    this->windowHandler->CloseWindow();
}
/// @brief To handle window events etc..
void LightMC::MainGame::WindowLoopCallback(void *p)
{
    MainGame *maingame = (MainGame *)p;

    float currentFrame = glfwGetTime();
    maingame->deltaTime = currentFrame - maingame->lastFrame;
    maingame->lastFrame = currentFrame;
#pragma region Input precess

    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(maingame->windowHandler->GetWindow(), true);
    }
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        maingame->camera->MoveCamera(maingame->camera->UP, maingame->deltaTime);
    }
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        maingame->camera->MoveCamera(maingame->camera->DOWN, maingame->deltaTime);
    }
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
    {
        maingame->camera->MoveCamera(maingame->camera->BACK, maingame->deltaTime);
    }
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
    {
        maingame->camera->MoveCamera(maingame->camera->FORWARD, maingame->deltaTime);
    }
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
    {
        maingame->camera->MoveCamera(maingame->camera->LEFT, maingame->deltaTime);
    }
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
    {
        maingame->camera->MoveCamera(maingame->camera->RIGHT, maingame->deltaTime);
    }
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_F) == GLFW_PRESS)
    {
        int monitornum;
        GLFWmonitor **monitor = glfwGetMonitors(&monitornum);
        const GLFWvidmode *mode = glfwGetVideoMode(monitor[0]);
        glfwSetWindowMonitor(maingame->windowHandler->GetWindow(), monitor[0], 0, 0, mode->width, mode->height, mode->refreshRate);
    }
#pragma endregion

    // DebugTools::DebugOutput(std::to_string(LightMC::WindowHandler::xOffset), DebugTools::Normal);

#pragma region Render
    glm::vec3 lightPos = glm::vec3(2 * std::sin(glfwGetTime()), 2 * std::cos(glfwGetTime()), 2 * std::sin(glfwGetTime() * 2));
    glm::mat4 trans = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.f);
    projection = glm::perspective(glm::radians(LightMC::MainGame::FOV), (float)(maingame->windowHandler->width / maingame->windowHandler->height), 0.1f, 100.f);
    glClearColor(.1f, .1f, .1f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    maingame->vertexShaderForObj->EnableShader();
    maingame->fragmentShaderForObj->EnableShader();
    maingame->vertexShaderForObj->SetVec3Uniform("cameraPos", camera->GetCameraPosition());
    maingame->vertexShaderForObj->SetVec3Uniform("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
    maingame->vertexShaderForObj->SetVec3Uniform("lightColor", glm::vec3(1.0f, 1.f, 1.f));
    maingame->vertexShaderForObj->SetMat4Uniform("transform", trans);
    maingame->vertexShaderForObj->SetMat4Uniform("projection", projection);
    maingame->vertexShaderForObj->SetVec3Uniform("u_lightPos", lightPos);
    mat4 view = maingame->camera->GetViewMatrix();
    maingame->vertexShaderForObj->SetMat4Uniform("view", view);
    glBindVertexArray(maingame->targetVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    maingame->vertexShaderForLight->EnableShader();
    maingame->fragmentShaderForLight->EnableShader();
    trans = glm::translate(trans, lightPos);
    maingame->vertexShaderForLight->SetMat4Uniform("transform", trans);
    maingame->vertexShaderForLight->SetMat4Uniform("projection", projection);
    maingame->vertexShaderForLight->SetMat4Uniform("view", view);

    glBindVertexArray(maingame->lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

#pragma endregion
}