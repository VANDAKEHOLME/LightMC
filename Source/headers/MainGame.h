#ifndef MAINGAME_H_
#define MAINGAME_H_
#include "windowHanlder.h"
#include "Shader.h"
namespace LightMC
{
    class MainGame
    {
    private:
        WindowHandler *windowHandler;
        static inline void WindowLoopCallback(void *);
    public:
        Shader* vertexShader;
        Shader* fragmentShader;
        unsigned int shaderProgram = 0;
        void StartGame();
        void TerminateGame();
    };
}

#endif