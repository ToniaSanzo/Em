/**
* Copyright 2021 Goblin HQ ©
* Title: Em
* Date: 2/20/2021
* File: Em UGame.h
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#pragma once
#include "ULib.h"
#include "UTexture.h"
#include "UWindow.h"
#include "GPlayer.h"
#include "GBottle.h"



class UGame
{
public:
    // Initializes internals
    UGame();

    // Initialize the game objects
    bool init(SDL_Renderer *, UWindow *);

    // Updates the game world
    void update(const float &);

    // Handle's events
    bool handleEvent(SDL_Event &);

    // Draw game world
    void render();

    // Free the resources
    void close();

private:
    // Game renderer, and window
    SDL_Renderer *mRenderer;
    UWindow *mWindow;

    // The player
    GPlayer mPlayer;


    //Bottle 
    GBottle mBottle;

};