//
//  Game.h
//  Game_Programming_Overview
//
//  Created by vaibhav kumar on 7/20/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//

#ifndef Game_h
#define Game_h

#pragma once
#include <SDL2/SDL.h>

// Vector2 struct just stores x/y coordinates
// (for now)
struct Vector2
{
    float x;
    float y;
};

// Game class
class Game
{
public:
    Game();
    // Initialize the game
    bool Initialize();
    // Runs the game loop until the game is over
    void RunLoop();
    // Shutdown the game
    void Shutdown();
private:
    // Helper functions for the game loop
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    // Window created by SDL
    SDL_Window* mWindow;
    // Renderer for 2D drawing
    SDL_Renderer* mRenderer;
    // Number of ticks since start of game
    Uint32 mTicksCount;
    // Game should continue to run
    bool mIsRunning;
    
    // Pong specific
    // Direction of paddle
    int mPaddleDir;
    int nPaddleDir;
    // Position of paddle
    Vector2 mPaddlePos;
    Vector2 nPaddlePos;
    // Position of ball
    Vector2 mBallPos;
    // Velocity of ball
    Vector2 mBallVel;
};

#endif /* Game_h */
