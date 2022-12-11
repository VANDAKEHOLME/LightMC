#ifndef WINDOWS_HANDLER_H_
#define WINDOWS_HANDLER_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>
namespace LightMC
{
    /// @brief The class used to handle all the stuffs of window.
    class WindowHandler
    {
    private:
        GLFWwindow *window;
        static void WindowSizeChangedCallback(GLFWwindow *, int, int);
        char *title;

    public:
        int width, height;
        WindowHandler(int, int, const char *);
        void CloseWindow();
        void WindowLoop(void (*)(void *), void *);
        GLFWwindow* GetWindow();
    };
}
#endif