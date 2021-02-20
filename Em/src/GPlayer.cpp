/**
* Copyright 2021 Tonia Sanzo ©
* Title: Em
* Author: Tonia Sanzo
* Date: 2/20/2021
* File: Em GPlayer.cpp
*/
#include "GPlayer.h"




// Initializes the player's member variables
GPlayer::GPlayer()
{
    mCurrFrame = 0;
    // Initialize the animation frames
    for (int i = 0; i < FRAME_COUNT; ++i)
    {
        mAnimationFrames[i] = SDL_Rect();
    }
}




// Initialize the player object
bool GPlayer::init(SDL_Renderer *aRenderer, const std::string &path)
{
    // Initialize the success flag
    bool success = true;

    // Initialize the player sprite sheet
    mSpriteSheet.initUTexture(aRenderer);

    // Load the sprite sheet with the file path
    if (!mSpriteSheet.loadFromFile(path))
    {
        printf("Failed to load player sprite sheet!\n");
        success = false;
    }
    else
    {
        // The position of the player
        mPosition = UVector3(320, 450, 0);

        // Initialize the animation frames
        for (int i = 0; i < FRAME_COUNT; ++i)
        {
            mAnimationFrames[i].x = 0;
            mAnimationFrames[i].y = 0;
            mAnimationFrames[i].w = 100;
            mAnimationFrames[i].h = 100;
        }
    }

    return success;

}




// Updates the player
void GPlayer::update(const float &dt)
{

}




// Handle the events
void GPlayer::handleEvent(SDL_Event &e)
{
    // If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_SPACE:
            printf("Player event space.\n");
            break;

        case SDLK_LEFT:
            printf("Player event left arrow.\n");
            break;

        case SDLK_RIGHT:
            printf("Player event right arrow.\n");
            break;

        }
    }
}




// Draw the player
void GPlayer::render()
{
    mSpriteSheet.render((static_cast<int>(ULib::SCREEN_DIMENSIONS.x) - mSpriteSheet.getWidth()) / 2, (static_cast<int>(ULib::SCREEN_DIMENSIONS.y) - mSpriteSheet.getHeight()) / 2);
}




// Deallocate the hamster's resources
void GPlayer::free()
{
    mSpriteSheet.free();
}