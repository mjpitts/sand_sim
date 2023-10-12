#include <iostream>
#include "Game.h"


int main()
{
    Game game;

    while (game.isRunning()) {

        // Update game
        game.update();
        // Render Game
        game.render();
    }

    return EXIT_SUCCESS;
}
