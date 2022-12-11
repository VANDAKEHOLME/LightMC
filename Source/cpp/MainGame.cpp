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
    glEnable(GL_DEPTH_TEST);
#pragma region Test

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

    vertexShader = new Shader("..\\shaders\\vertex.vert", GL_VERTEX_SHADER, shaderProgram);
    fragmentShader = new Shader("..\\shaders\\fragment.frag", GL_FRAGMENT_SHADER, shaderProgram);
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STREAM_DRAW);
    glVertexAttribPointer(12, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(12);
    glVertexAttribPointer(2, 2, GL_FLOAT, false, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
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
#pragma region Input precess
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(maingame->windowHandler->GetWindow(), true);
    }

    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_F) == GLFW_PRESS)
    {
        int monitornum;
        GLFWmonitor **monitor = glfwGetMonitors(&monitornum);
        const GLFWvidmode *mode = glfwGetVideoMode(monitor[0]);
        glfwSetWindowMonitor(maingame->windowHandler->GetWindow(), monitor[0], 0, 0, mode->width, mode->height, mode->refreshRate);
    }
#pragma endregion

    static float framesPerSecond = 0.0f;
    static int fps;
    static float lastTime = 0.0f;
    float currentTime = GetTickCount() * 0.001f;
    ++framesPerSecond;
    DebugTools::DebugOutput(std::to_string(framesPerSecond), DebugTools::Normal);
    if (currentTime - lastTime > 1.0f)
    {
        lastTime = currentTime;
        fps = (int)framesPerSecond;
        framesPerSecond = 0;
    }
#pragma region Render
    glm::mat4 trans = glm::mat4(1.0f);
    // trans = glm::translate(trans, glm::vec3(1.f, 1.f, 1.0f));
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(.5f, 0.3f, 1.0f));
    // trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection = glm::mat4(1.f);
    projection = glm::perspective((float)glm::radians(45.f), (float)(maingame->windowHandler->width / maingame->windowHandler->height), 0.1f, 100.f);
    glClearColor(.2f, .3f, .3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    maingame->vertexShader->EnableShader();
    maingame->fragmentShader->EnableShader();
    maingame->vertexShader->SetFloatUniform("dx", std::sin(glfwGetTime()));
    maingame->vertexShader->SetIntUniform("Texture", 0);
    maingame->vertexShader->SetIntUniform("Face", 1);
    maingame->vertexShader->SetMat4Uniform("transform", trans);
    maingame->vertexShader->SetMat4Uniform("projection", projection);
    maingame->vertexShader->SetMat4Uniform("view", view);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

#pragma endregion
}