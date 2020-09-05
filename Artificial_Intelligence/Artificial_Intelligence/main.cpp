//
//  main.cpp
//  Artificial_Intelligence
//
//  Created by vaibhav kumar on 8/6/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//
#include "Game.h"

int main(int argc, char** argv)
{
    Game game;
    bool success = game.Initialize();
    if (success)
    {
        game.RunLoop();
    }
    game.Shutdown();
    return 0;
}
