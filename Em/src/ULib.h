/**
* Copyright 2021 Goblin HQ �
* Title: Em
* Date: 2/20/2021
* File: Em ULib.h
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#pragma once
#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include "UVector3.h"
#include <vector>
#include <ctime>



struct ULib
{
    // Window information
    const static std::string TITLE;
    const static UVector3 SCREEN_DIMENSIONS;

    // Game states
    const static int INITIAL_LEVEL = 0;
    const static int TUTORIAL_LEVEL = 1;
    const static int ANGER_LEVEL = 2;
    const static int BREATH_LEVEL = 3;
};