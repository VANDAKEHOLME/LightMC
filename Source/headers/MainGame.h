#ifndef MAINGAME_H_
#define MAINGAME_H_
#include "windowHanlder.h"
namespace LightMC
{
    class MainGame
    {
    private:
        WindowHandler *windowHandler;
        static inline void WindowLoopCallback(void*);

    public:
        GLenum shaderProgram;
        void StartGame();
        void TerminateGame();
    };
}

#endif