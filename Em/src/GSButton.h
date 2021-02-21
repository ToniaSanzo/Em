/*
* Title: Em
* Date : 2 / 20 / 2021
* File : Em GSButton.h
*
*Engineers : Charles Chiasson, Tonia Sanzo
* Audio : Ethan Schwabe
* Art : Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#pragma once
#include "UTexture.h"
#include "USound.h"
#include "UVector3.h"


class GSButton {
    const int TILE_HEIGHT = 130;
    const int TILE_WIDTH = 130;

public:
    // Initialize the GSButton member variables
    GSButton();

    // Initialize the GSButton object
    bool init(UTexture*, USound*);

    // Draw the button
    void render();

    // Play's the button sound when the player clicks the sound button
    void playButton();


    // Play's the menu music
    void playMenu();

    // Play's the game music
    void playGame();

    // Mute the sound and button, used for initializing the sound button
    void muteStartup();

    // Handle events
    void handleEvent(SDL_Event* e);

    // Update the current game state
    void updateGState(int);

    // Free the resources allocated to the GSButton
    void free();

private:
    // The texture, mute status, sound object, and texture clips used by the game sound
    // button
    bool mute;
    USound* mSound;
    UTexture* mTexture;
    SDL_Rect buttClips[2];
    int currState, xPos, yPos;
    UVector3 defaultScreenDimensions;
};