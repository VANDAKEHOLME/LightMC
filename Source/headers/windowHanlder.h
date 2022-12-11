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
        static void CursorPosCallback(GLFWwindow *, double, double);
        static void ScrollCallback(GLFWwindow *, double, double);
        char *title;

    public:
        static float sensitivity;
        typedef void (*MouseMoveEvent)(int, int);
        static bool firstRotate;
        static int lastX, lastY;
        int width, height;
        WindowHandler(int, int, const char *, float = 0.05f);
        void CloseWindow();
        void WindowLoop(void (*)(void *), void *);
        GLFWwindow *GetWindow();
    };
}
#endif