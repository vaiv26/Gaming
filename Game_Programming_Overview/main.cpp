//
//  main.cpp
//  Game_Programming_Overview
//
//  Created by vaibhav kumar on 7/20/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//
#include <iostream>
#include "Game.h"

int main(int argc, char** argv)
{
    Game game;   // object of game class
    bool success = game.Initialize();
    if (success)
    {
        game.RunLoop();
    }
    game.Shutdown();
    return 0;
}
