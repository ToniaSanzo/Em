/**
* Copyright 2021 Goblin HQ ©
* Title: Em
* Date: 2/20/2021
* File: Em USound.h
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#include "USound.h"

bool USound::globalMute = false;

// Initialize USound member variables
USound::USound() {
    mMusic = nullptr;
    mute = false;

}




// Initialize the USound object
bool USound::init(const char* path) {
    bool success = true;

    // Load the menu music
    mMusic = Mix_LoadMUS(path);
    if (mMusic == nullptr) {
        printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}



void USound::interjectionAbrupt(USound sound1) {

    if (!USound::globalMute) {
        stopMusic();
        sound1.playMusic();
    }
}

void USound::interjectionWithFade(USound sound1, int ms) {

    if (!USound::globalMute) {
        fadeout(ms);

        sound1.playMusic();
    }
}

// Plays the button sound effect
void USound::playSound(){

    if (!USound::globalMute){
        Mix_PlayMusic(mMusic, 1);
    }
}

// Play menu music
void USound::playMusic() {
    // If there is music playing
    

    if (!USound::globalMute) {
        if (Mix_PlayingMusic() != 0) {
            // Stop the music
            Mix_HaltMusic();
        }

        // Play the menu music
        Mix_PlayMusic(mMusic, -1);

        // If it is currently muted
        if (mute) {
            // Pause the music
            Mix_PauseMusic();
        }
    }
    
}

//Gradually fade out the music over ms milliseconds starting from now. The music will be halted after the fade out is completed.
int USound::fadeout(int ms) {


    return Mix_FadeOutMusic(ms);
}


// Toggle the music
void USound::toggleMusic() {
    // If the music is paused


    if (!USound::globalMute) {

        if (Mix_PausedMusic() == 1) {
            // Resume the music
            Mix_ResumeMusic();
        }
        // If the music is playing
        else {
            // Pause the music
            Mix_PauseMusic();
        }
    }
    
}


void USound::stopMusic() {


    if (!USound::globalMute) {
        Mix_HaltMusic();
    }

}

// Mute and unmute the sound
void USound::toggleMute()
{
    if (!USound::globalMute) {
        if (mute)
        {
            mute = false;
        }

        else
        {
            mute = true;
        }

        toggleMusic();
    }
}
void USound::togglemuteAllSounds()
{

   

    if (USound::globalMute) {

        USound::globalMute = false;
        Mix_ResumeMusic();
    }else {
        Mix_PauseMusic();
        USound::globalMute = true;
    }
}





// Deallocate and destroy the sounds
void USound::free() {
    // Music is playing
    if (Mix_PlayingMusic() != 0) {
        // Stop the music
        Mix_HaltMusic();
    }

    // Free menu music
    Mix_FreeMusic(mMusic);
    mMusic = nullptr;
}