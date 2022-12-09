#ifndef MAINGAME_H_
#define MAINGAME_H_
#include "windowHanlder.h"
namespace LightMC
{
    class MainGame
    {
    private:
        WindowHandler *windowHandler;
        static void WindowLoopCallback(void*);

    public:
        void StartGame();
        void TerminateGame();
    };
}

#endif