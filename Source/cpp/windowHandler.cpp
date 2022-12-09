#include "windowHanlder.h"
#include "DebugTools.h"
/// @brief To construct a windowhandler class, initialize the GLFW and GLAD.
/// @param width
/// @param height
/// @param title
LightMC::WindowHandler::WindowHandler(int width, int height, const char *title)
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
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, WindowSizeChangedCallback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        LightMC::DebugTools::DebugOutput("Failed to load the GLAD", LightMC::DebugTools::MsgType::Normal);
        this->CloseWindow();
    }
}
/// @brief A callback function to changed the viewport with the change of window.
/// @param window
/// @param width
/// @param height
void LightMC::WindowHandler::WindowSizeChangedCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
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
GLFWwindow* LightMC::WindowHandler::GetWindow()
{
    return this->window;
}
