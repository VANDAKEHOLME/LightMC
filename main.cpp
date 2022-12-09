#include "MainGame.h"
int main()
{
    LightMC::MainGame* game = new LightMC::MainGame();
    game->StartGame();
    game->TerminateGame();
    return 0;
}