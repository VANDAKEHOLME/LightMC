#include "MainGame.h"
#include "DebugTools.h"
#include "Block.h"
#include "Shader.h"
/// @brief To start game.
void LightMC::MainGame::StartGame()
{
    LightMC::DebugTools::DebugToolsInitialize();
    windowHandler = new WindowHandler(600, 800, "Light MC");
#pragma region Test
    Shader("..\\shaders\\fragment.frag", GL_FRAGMENT_SHADER, shaderProgram);
    Shader("..\\shaders\\vertex.vert", GL_VERTEX_SHADER, shaderProgram);
    LightMC::Block block(-0.75f, -0.75f, -0.75f, 0.5f, 0.5f, 0.5f);
        float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
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
#pragma endregion
#pragma region Render
    glClearColor(.2f, .3f, .3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
#pragma endregion
}