/**
* Copyright 2021 Tonia Sanzo ©
* Title: Em
* Author: Tonia Sanzo
* Date: 2/20/2021
* File: Em GPlayer.h
*/
#pragma once
#include "ULib.h"
#include "UTexture.h"




// Player object
class GPlayer
{
public:
    // Class constants
    const static int FRAME_WIDTH = 100;
    const static int FRAME_HEIGHT = 100;

    

    // Initializes the player's member variables
    GPlayer();

    // Initilaize the player object
    bool init(SDL_Renderer *, const std::string &);

    // Updates the player
    void update(const float &);

    // handles event
    void handleEvent(SDL_Event &);

    // Draw the player
    void render();

    // Free the resources
    void free();

private:
    // Number of animation frames
    const static int FRAME_COUNT = 1;

    // The players position
    UVector3 mPosition;

    // The players sprite sheet, animation frame, and current animation frame
    UTexture mSpriteSheet;
    SDL_Rect mAnimationFrames[FRAME_COUNT];
    int mCurrFrame;
};