/*
* Title: Em
* Date : 2 / 20 / 2021
* File : Em GSButton.cpp
*
*Engineers : Charles Chiasson, Tonia Sanzo
* Audio : Ethan Schwabe
* Art : Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/


#include "GSButton.h"




// Initialize GSButton member variables
GSButton::GSButton() {
    mute = false;
    mTexture = nullptr;
    mSound = nullptr;
    xPos = yPos = 0;
    currState = 0;
    for (int i = 0; i < 2; ++i) {
        buttClips[i] = SDL_Rect();
    }
}

// Initialize the sound button
bool GSButton::init(UTexture* aText, USound* aSound)
{
    mTexture = aText;
    mSound = aSound;

    for (int i = 0; i < 2; ++i) {
        buttClips[i].x = i * TILE_WIDTH;
        buttClips[i].y = 0;
        buttClips[i].w = TILE_WIDTH;
        buttClips[i].h = TILE_HEIGHT;
    }

    return (mTexture != nullptr && mSound != nullptr);
}

// Render the button to the screen
void GSButton::render() {
   
    mTexture->render(xPos, yPos, &buttClips[mute]);
}


// Play's the button sound when the player clicks the sound button
void GSButton::playButton() {

        mSound->playSound();
    
}
void GSButton::handleEvent(SDL_Event* e) {
    int mosX, mosY;

   
        // The Menu screen 
    
        // If the user pressed the mouse
      
        if (e->type == SDL_MOUSEBUTTONDOWN) {
            // Get mouse position
          
            SDL_GetMouseState(&mosX, &mosY);

            // check if mouse is in the sound button
            bool inside = true;
          
            // Mouse is left of the button
            if (mosX < xPos) {
                inside = false;
            }
            // Mouse is right of the button
            else if (mosX > (xPos + TILE_WIDTH * mTexture->getScale())) {
                inside = false;
            }
            // Mouse is above the button
            else if (mosY < yPos) {
                inside = false;
            }
            // Mouse is below the planet
            else if (mosY > (yPos + TILE_HEIGHT * mTexture->getScale())) {
                inside = false;
            }


            if (inside) {
                mSound->playSound();
                // toggle mute flag
                if (mute) {
                    mute = false;
                }
                else {
                    mute = true;
                }
             mSound->togglemuteAllSounds();
             
            }
        }

      
}


void GSButton::free() {
    mTexture = nullptr;
    mSound = nullptr;
}

