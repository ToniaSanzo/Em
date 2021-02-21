/**
* Copyright 2021 Goblin HQ ©
* Title: Em
* Date: 2/21/2021
* File: Em UTimer.h
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#pragma once
#include "ULib.h"

class UTimer {
public:
    // Initializes variables
    UTimer();

    // The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    // Get's the timer's time
    Uint32 getTicks();

    // Checks the status of the timer
    bool isStarted();
    bool isPaused();
private:
    // The clock time when the timer started
    Uint32 mStartTicks;

    // The ticks stored when the timer was paused
    Uint32 mPausedTicks;

    // The timer status
    bool mPaused;
    bool mStarted;
};