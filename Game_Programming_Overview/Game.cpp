//
//  Game.cpp
//  Game_Programming_Overview
//
//  Created by vaibhav kumar on 7/20/20.
//  Copyright © 2020 vaibhav kumar. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Game.h"

const int thickness = 15;
const float paddleH = 100.0f;

Game::Game()
:mWindow(nullptr)
,mRenderer(nullptr)
,mTicksCount(0)
,mIsRunning(true)
,mPaddleDir(0)
,nPaddleDir(0)
{
    
}

bool Game::Initialize()
{
    // Initialize SDL
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    
    // Create an SDL Window
    mWindow = SDL_CreateWindow(
        "Game Programming in C++ (Chapter 1)", // Window title
        100,    // Top left x-coordinate of window
        100,    // Top left y-coordinate of window
        1024,    // Width of window
        768,    // Height of window
        0        // Flags (0 for no flags set)
    );

    if (!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    
    //// Create SDL renderer, mRenderer is s pointer varible.
    mRenderer = SDL_CreateRenderer(
        mWindow, // Window to create renderer for
        -1,         // Usually -1
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!mRenderer) // if null pointer
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }
    //
    mPaddlePos.x = 10.0f;
    mPaddlePos.y = 768.0f/2.0f;
    nPaddlePos.x = 1024.0f - 24.0f;
    nPaddlePos.y = 768.0f/2.0f;
    mBallPos.x = 1024.0f/2.0f;
    mBallPos.y = 768.0f/2.0f;
    mBallVel.x = -200.0f;
    mBallVel.y = 235.0f;
    return true;
}

void Game::RunLoop()
{
    while (mIsRunning) // mIsRunning is bool variable, if true then game will run
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput()
{
    SDL_Event event;  //
    while (SDL_PollEvent(&event)) // The SDL_PollEvent returns true of it finds an event in queue.
    {
        switch (event.type)
        {
            // If we get an SDL_QUIT event, end loop
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }
    
    // Get state of keyboard
    const Uint8* state = SDL_GetKeyboardState(NULL);  // gets keyboard input
    // If escape is pressed, also end loop
    if (state[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
    }
    
    // Update paddle direction based on W/S keys
    mPaddleDir = 0;
    nPaddleDir = 0;
    if (state[SDL_SCANCODE_W])  // top lef corner is (x,y):(0,0)
    {
        mPaddleDir -= 1;
    }
    if (state[SDL_SCANCODE_S])
    {
        mPaddleDir += 1;
    }
    if (state[SDL_SCANCODE_I])  // top lef corner is (x,y):(0,0)
    {
        nPaddleDir -= 1;
    }
    if (state[SDL_SCANCODE_K])
    {
        nPaddleDir += 1;
    }
}

void Game::UpdateGame()
{
    // Wait until 16ms has elapsed since last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
        ;

    // Delta time is the difference in ticks from last frame
    // (converted to seconds)
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    
    // Clamp maximum delta time value
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }

    // Update tick counts (for next frame)
    mTicksCount = SDL_GetTicks();
    
    // Update paddle position based on direction
    if (mPaddleDir != 0)
    {
        mPaddlePos.y += mPaddleDir * 300.0f * deltaTime;
        // Make sure paddle doesn't move off screen!
        if (mPaddlePos.y < (paddleH/2.0f + thickness))
        {
            mPaddlePos.y = paddleH/2.0f + thickness;
        }
        else if (mPaddlePos.y > (768.0f - paddleH/2.0f - thickness))
        {
            mPaddlePos.y = 768.0f - paddleH/2.0f - thickness;
        }
    }
    // Update paddle position based on direction
    if (nPaddleDir != 0)
    {
        nPaddlePos.y += nPaddleDir * 300.0f * deltaTime;
        // Make sure paddle doesn't move off screen!
        if (nPaddlePos.y < (paddleH/2.0f + thickness))
        {
            nPaddlePos.y = paddleH/2.0f + thickness;
        }
        else if (nPaddlePos.y > (768.0f - paddleH/2.0f - thickness))
        {
            nPaddlePos.y = 768.0f - paddleH/2.0f - thickness;
        }
    }
    
    // Update ball position based on ball velocity
    mBallPos.x += mBallVel.x * deltaTime;
    mBallPos.y += mBallVel.y * deltaTime;
    
    // Bounce if needed
    // Did we intersect with the left or right paddle?
    float diff = mPaddlePos.y - mBallPos.y;
    // Take absolute value of difference
    diff = (diff > 0.0f) ? diff : -diff;
    
    float ndiff = nPaddlePos.y - mBallPos.y;
    // Take absolute value of difference
    ndiff = (ndiff > 0.0f) ? ndiff : -ndiff;
    
    if (
        // Our y-difference is small enough
        diff <= paddleH / 2.0f &&
        // We are in the correct x-position
        mBallPos.x <= 25.0f && mBallPos.x >= 20.0f &&
        // The ball is moving to the left
        mBallVel.x < 0.0f)
    {
        mBallVel.x *= -1.0f;
    }
    
    // Did we intersect with the right paddle?
    else if(
        // Our y-difference is small enough
        ndiff <= paddleH / 2.0f &&
        // We are in the correct x-position
        mBallPos.x <= 1005.0f && mBallPos.x >= 1000.0f &&
        // The ball is moving to the right
        mBallVel.x > 0.0f)
    {
        mBallVel.x *= -1.0f;
    }

    
    // Did the ball go off the screen on the left or the right? (if so, end game)
    else if (mBallPos.x <= 0.0f || mBallPos.x >= 1024.0f )
    {
        mIsRunning = false;
    }
    

    /*Did the ball collide with the right wall?
    else if (mBallPos.x >= (1024.0f - thickness) && mBallVel.x > 0.0f)
    {
        mBallVel.x *= -1.0f;
    }*/
    
    // Did the ball collide with the top wall?
    if (mBallPos.y <= thickness && mBallVel.y < 0.0f)
    {
        mBallVel.y *= -1;
    }
    // Did the ball collide with the bottom wall?
    else if (mBallPos.y >= (768 - thickness) &&
        mBallVel.y > 0.0f)
    {
        mBallVel.y *= -1;
    }
}

void Game::GenerateOutput()
{
    // Set draw color to blue
    SDL_SetRenderDrawColor(
        mRenderer,
        0,        // R
        0,        // G
        255,    // B
        255        // A
    );
    
    // Clear back buffer
    SDL_RenderClear(mRenderer);

    // Draw walls
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    
    // Draw top wall
    SDL_Rect wall{
        0,            // Top left x
        0,            // Top left y
        1024,        // Width
        thickness    // Height
    };
    SDL_RenderFillRect(mRenderer, &wall);
    
    // Draw bottom wall
    wall.y = 768 - thickness;
    SDL_RenderFillRect(mRenderer, &wall);
    
    /*Draw right wall
    wall.x = 1024 - thickness;
    wall.y = 0;
    wall.w = thickness;
    wall.h = 1024;
    SDL_RenderFillRect(mRenderer, &wall);*/
    
    // Draw right paddle
    SDL_Rect npaddle{
        static_cast<int>(nPaddlePos.x),
        static_cast<int>(nPaddlePos.y - paddleH/2),
        thickness,
        static_cast<int>(paddleH)
    };
    SDL_RenderFillRect(mRenderer, &npaddle);
    
    // Draw left  paddle
    SDL_Rect paddle{
        static_cast<int>(mPaddlePos.x),
        static_cast<int>(mPaddlePos.y - paddleH/2),
        thickness,
        static_cast<int>(paddleH)
    };
    SDL_RenderFillRect(mRenderer, &paddle);
    
    // Draw ball
    SDL_Rect ball{
        static_cast<int>(mBallPos.x - thickness/2),
        static_cast<int>(mBallPos.y - thickness/2),
        thickness,
        thickness
    };
    SDL_RenderFillRect(mRenderer, &ball);
    
    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}

void Game::Shutdown()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}
