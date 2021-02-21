/**
* Copyright 2021 Goblin HQ ©
* Title: Em
* Date: 2/20/2021
* File: Em GPlayer.h
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
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
    bool init(SDL_Renderer*, const std::string&);

    // Updates the player
    void update(const float&);

    // Updates the player's current state
    void updateGameState(int);

    // handles event
    void handleEvent(SDL_Event&);

    // Draw the player
    void render();

    // Free the resources
    void free();

    UVector3 getLocation();


private:
    // The current state of the player
    int mCurrState;

    // Number of animation frames
    const static int FRAME_COUNT = 1;

    // The players position, and movement variables
    bool mLeft, mRight;
    float mAcceleration;
    float mFriction;
    float mMaxSpeed;
    UVector3 mVel;
    UVector3 mPosition;

    // The players sprite sheet, animation frame, and current animation frame
    UTexture mSpriteSheet;
    SDL_Rect mAnimationFrames[FRAME_COUNT];
    int mCurrFrame;

};