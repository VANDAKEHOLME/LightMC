#include "MainGame.h"
#include "DebugTools.h"
#include "Shader.h"
#include "Block.h"
/// @brief To start game.
void LightMC::MainGame::StartGame()
{
    LightMC::DebugTools::DebugToolsInitialize();
    windowHandler = new WindowHandler(600, 800, "Light MC");
#pragma region Test
    Shader("..\\shaders\\fragment.frag", GL_FRAGMENT_SHADER, shaderProgram);
    Shader("..\\shaders\\vertex.vert", GL_VERTEX_SHADER, shaderProgram);

    Block block(-0.75f, -0.75f, -0.75f, 1.f, 1.f, 1.f);
    float vertices[] = {
        0.5f, 0.5f, 0.0f,   // 右上角
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, -0.5f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f   // 左上角
    };
    unsigned int indices[] = {
        // 注意索引从0开始!
        // 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
        // 这样可以由下标代表顶点组合成矩形

        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STREAM_DRAW);
    glVertexAttribPointer(12, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(12);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
#pragma endregion
}