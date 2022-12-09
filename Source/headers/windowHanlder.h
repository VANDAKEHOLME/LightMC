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
        int width, height;
        char *title;
        static void WindowSizeChangedCallback(GLFWwindow *, int, int);

    public:
        WindowHandler(int, int, const char *);
        void CloseWindow();
        void WindowLoop(void (*)(void *), void *);
        GLFWwindow* GetWindow();
    };
}
#endif