#include "windowHanlder.h"
#include "DebugTools.h"
#include "MainGame.h"
float LightMC::WindowHandler::sensitivity = 0.05f;
int LightMC::WindowHandler::lastX = 2;
int LightMC::WindowHandler::lastY = 2;
/// @brief A callback function to change the viewport with the change of window.
/// @param window
/// @param width
/// @param height
void LightMC::WindowHandler::WindowSizeChangedCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
bool LightMC::WindowHandler::firstRotate = true;
/// @brief To construct a windowhandler class, initialize the GLFW and GLAD.
/// @param width
/// @param height
/// @param title
LightMC::WindowHandler::WindowHandler(int width, int height, const char *title, float _mouseSensitivity)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr)
    {
        DebugTools::DebugOutput("Failed to create the GLFW window", LightMC::DebugTools::MsgType::Error);
        glfwTerminate();
    }
    glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, WindowSizeChangedCallback);
    glfwSetCursorPosCallback(window, this->CursorPosCallback);
    glfwSetScrollCallback(window, this->ScrollCallback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LightMC::DebugTools::DebugOutput("Failed to load the GLAD", LightMC::DebugTools::MsgType::Normal);
        this->CloseWindow();
    }
}
/// @brief To terminate the GLFW window.
void LightMC::WindowHandler::CloseWindow()
{
    glfwTerminate();
}
/// @brief The main loop of window.
/// @param WindowLoopCallbackFunc
void LightMC::WindowHandler::WindowLoop(void (*WindowLoopCallbackFunc)(void *), void *p)
{
    while (!glfwWindowShouldClose(this->window))
    {
        WindowLoopCallbackFunc(p);
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}
/// @brief To return the window pointer.
/// @return window pointer.
GLFWwindow *LightMC::WindowHandler::GetWindow()
{
    return this->window;
}
/// @brief A callback function to get camera rotate by moving the cursor(mouse).
/// @param _window
/// @param _xPos
/// @param _yPos
void LightMC::WindowHandler::CursorPosCallback(GLFWwindow *_window, double _xPos, double _yPos)
{
    if (LightMC::WindowHandler::firstRotate)
    {
        lastX = _xPos;
        lastY = _yPos;
        LightMC::WindowHandler::firstRotate = false;
    }
    LightMC::MainGame::camera->RotateCamera((_xPos - lastX) * LightMC::WindowHandler::sensitivity, (lastY - _yPos) * LightMC::WindowHandler::sensitivity);
    // DebugTools::DebugOutput("1", DebugTools::Error);
    lastX = _xPos;
    lastY = _yPos;
}
/// @brief To control the scroll event.
/// @param _window
/// @param _xOffset
/// @param _yOffset
void LightMC::WindowHandler::ScrollCallback(GLFWwindow *_window, double _xOffset, double _yOffset)
{
    if (LightMC::MainGame::FOV >= 1.0f && LightMC::MainGame::FOV <= 45.0f)
        LightMC::MainGame::FOV -= _yOffset;
    if (LightMC::MainGame::FOV <= 1.0f)
        LightMC::MainGame::FOV = 1.0f;
    if (LightMC::MainGame::FOV >= 45.0f)
        LightMC::MainGame::FOV = 45.0f;
}
