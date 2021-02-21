/**
* CopymRight 2021 Goblin HQ ©
* Title: Em
* Date: 2/20/2021
* File: Em GPlayer.cpp
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#include "GPlayer.h"




// Initializes the player's member variables
GPlayer::GPlayer()
{
    mCurrState = ULib::INITIAL_LEVEL;
    mCurrFrame = 0;
    mLeft = mRight = false;
    mAcceleration = 4000;
    mFriction = 2900;
    mMaxSpeed = 370;
    mVel = UVector3(0, 0, 0);
    mPosition = UVector3(ULib::SCREEN_DIMENSIONS.x / 2, 1070, 0);
    // Initialize the animation frames
    for (int i = 0; i < FRAME_COUNT; ++i)
    {
        mAnimationFrames[i] = SDL_Rect();
    }
}




// Initialize the player object
bool GPlayer::init(SDL_Renderer* aRenderer, const std::string& path)
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
void GPlayer::update(const float& dt)
{
    switch (mCurrState)
    {
    case ULib::TUTORIAL_LEVEL:
    case ULib::ANGER_LEVEL:
        // Apply stopping mFriction only if the player is stopped
        if (!mLeft && !mRight)
        {
            // Apply mFriction
            if (mVel.x > 0)
            {
                mVel.x -= mFriction * dt;

                // Prevent mFriction from pushing the player in the opposite direction
                if (mVel.x < 0) { mVel.x = 0; }
            }
            else if (mVel.x < 0)
            {
                mVel.x += mFriction * dt;

                // Prevent mFriction from pushing the player in the opposite direction
                if (mVel.x > 0) { mVel.x = 0; }
            }
        }
        else
        {
            // Update the player's velocity
            if (mLeft)
            {
                mVel.x -= mAcceleration * dt;
                mLeft = false;
            }

            if (mRight)
            {
                mVel.x += mAcceleration * dt;
                mRight = false;
            }
        }


        // Cap the player's speed
        if (mVel.x > mMaxSpeed)
        {
            mVel.x = mMaxSpeed;
        }
        else if (mVel.x < -mMaxSpeed)
        {
            mVel.x = -mMaxSpeed;
        }

        // Set position
        printf("mVel.x = %f, dt = %f\n", mVel.x, dt);
        mPosition.x += mVel.x * dt;

        break;
    }
}




// Update the current game state
void GPlayer::updateGameState(int aNewState)
{
    mCurrState = aNewState;
}




// Handle the events
void GPlayer::handleEvent(SDL_Event& e)
{
    // If a key was pressed
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_SPACE:
            printf("Player event space.\n");
            break;

        case SDLK_LEFT:
            printf("Player event mLeft arrow.\n");
            mLeft = true;
            break;

        case SDLK_RIGHT:
            printf("Player event mRight arrow.\n");
            mRight = true;
            break;

        }
    }
}




// Draw the player
void GPlayer::render()
{
    mSpriteSheet.render((static_cast<int>(mPosition.x) - mSpriteSheet.getWidth()) / 2, (static_cast<int>(mPosition.y) - mSpriteSheet.getHeight()) / 2);
}

UVector3 GPlayer::getLocation() {

    return mPosition;
}


// Deallocate the hamster's resources
void GPlayer::free()
{
    mSpriteSheet.free();
}