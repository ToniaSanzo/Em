/**
* Copyright 2021 Goblin HQ �
* Title: Em
* Date: 2/20/2021
* File: Em UGame.cpp
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#include "UGame.h"




// Default constructor
UGame::UGame()
{
    mRenderer = nullptr;
    mWindow = nullptr;
}




// Initializes and loads all the game objects
bool UGame::init(SDL_Renderer* aRenderer, UWindow* aWindow)
{
    // Initialize success flag
    bool success = true;

    // Set the renderer and window
    mRenderer = aRenderer;
    mWindow = aWindow;

    if (mRenderer == nullptr || mWindow == nullptr)
    {
        printf("Attempted to initialize the UGame object with nullptr! Pass in valid pointers in the UGame.init() function\n");
        success = false;
    }
    else
    {
        // Initialize the player
        if (!mPlayer.init(mRenderer, "assets/em_spritesheet.png"))
        {
            printf("Failed to load player!\n");
            success = false;
        }
        if (!mBottle.init(mRenderer, "assets/bottle.png"))
        {
            printf("Failed to load bottle!\n");
            success = false;
        }
        
    }

    return success;
}




// Update the game world based on the time since the last update
void UGame::update(const float& dt)
{
    mPlayer.update(dt);
    mBottle.update(dt);
}





// Handle all the events on the queue
bool UGame::handleEvent(SDL_Event& e)
{
    if (e.type == SDL_QUIT) { return true; }

    return false;
}




// Draw the game world to the screen
void UGame::render()
{
    mPlayer.render();
    mBottle.render();
}




// Free the game objects
void UGame::close()
{
    if (mRenderer)
    {
        mRenderer = nullptr;
    }

    if (mWindow)
    {
        mWindow = nullptr;
    }

    mPlayer.free();
    mBottle.free();
}