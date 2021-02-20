/**
* Copyright 2021 Goblin HQ ©
* Title: Em
* Date: 2/20/2021
* File: Em UBackground.h
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#pragma once
#include "ULib.h"
#include "UTexture.h"
#include "UVector3.h"
#include <vector>




class GBackground {
    // Initialize the GBackgrounds member variables
    GBackground();

    // Initialize the background object
    bool init(SDL_Renderer*);

    // Update the background
    void update(const double&);

    // Draw the default background
    void renderPlay(const UVector3&);

    // Draw the menu background
    void renderMenu(const UVector3&);

    // Draw the settings menu
    void renderSettings(const UVector3&);

    // Free the resources allocated for this texture
    void free();

private:

    UTexture* mBackground, * mForeground, * mMenuScreen, * mSettingsMenu;// need more 


    // Position of the title image
    UVector3 mTitlePos;






};






