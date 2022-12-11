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
    LightMC::Texture texture1("../../Resources/Image/container.jpg");
    LightMC::Texture texture2("../../Resources/Image/awesomeface.png", {0, (10497), (10497), (9728), (9984), (GL_TEXTURE1)});
    Block block(-0.75f, -0.75f, -0.75f, 1.f, 1.f, 1.f);
    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    vertexShaderForObj = new Shader("..\\shaders\\vertexForObj.vert", GL_VERTEX_SHADER, shaderProgram);
    fragmentShaderForObj = new Shader("..\\shaders\\fragmentForObj.frag", GL_FRAGMENT_SHADER, shaderProgram);
    glGenVertexArrays(1, &targetVAO);
    glGenVertexArrays(1, &lightVAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(targetVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STREAM_DRAW);
    glVertexAttribPointer(12, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(12);
    glVertexAttribPointer(2, 2, GL_FLOAT, false, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(lightVAO);
    glVertexAttribPointer(11, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
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
    glm::mat4 trans = glm::mat4(1.0f);
    // trans = glm::translate(trans, glm::vec3(1.f, 1.f, 1.0f));
    // trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(.5f, 0.3f, 1.0f));
    // trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    glm::mat4 projection = glm::mat4(1.f);
    projection = glm::perspective(glm::radians(LightMC::MainGame::FOV), (float)(maingame->windowHandler->width / maingame->windowHandler->height), 0.1f, 100.f);
    glClearColor(.2f, .3f, .3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // maingame->camera->RotateCamera(LightMC::WindowHandler::xOffset, LightMC::WindowHandler::yOffset);
    maingame->vertexShaderForObj->EnableShader();
    maingame->fragmentShaderForObj->EnableShader();
    maingame->vertexShaderForObj->SetVec3Uniform("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
    maingame->vertexShaderForObj->SetVec3Uniform("lightColor", glm::vec3(1.0f, 1.f, 1.f));
    maingame->vertexShaderForObj->SetIntUniform("Texture", 0);
    maingame->vertexShaderForObj->SetIntUniform("Face", 1);
    maingame->vertexShaderForObj->SetMat4Uniform("transform", trans);
    maingame->vertexShaderForObj->SetMat4Uniform("projection", projection);
    mat4 view = maingame->camera->GetViewMatrix();
    maingame->vertexShaderForObj->SetMat4Uniform("view", view);
    glBindVertexArray(maingame->targetVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    trans = glm::translate(trans, glm::vec3(1.5f, 0.2f, -1.5f));
    maingame->vertexShaderForObj->SetMat4Uniform("transform", trans);
    glBindVertexArray(maingame->lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

#pragma endregion
}