#include "MainGame.h"
#include <iostream>
int main()
{
    LightMC::MainGame *game = new LightMC::MainGame();
    game->StartGame();
    game->TerminateGame();
    return 0;
}