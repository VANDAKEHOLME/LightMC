#include "MainGame.h"
#include "DebugTools.h"
/// @brief To start game.
void LightMC::MainGame::StartGame()
{
    LightMC::DebugTools::DebugToolsInitialize();
    windowHandler = new WindowHandler(600, 800, "Light MC");
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
    if (!maingame)
    {
        LightMC::DebugTools::DebugOutput("WTF I can't find the maingame instance", LightMC::DebugTools::Error);
    }
#pragma region Input precess
    if (glfwGetKey(maingame->windowHandler->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(maingame->windowHandler->GetWindow(), true);
    }
#pragma endregion
#pragma region Render
    glClearColor(.2f, .3f, .3f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
#pragma endregion
}