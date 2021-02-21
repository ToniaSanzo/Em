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
#include "ULib.h"

class USound {
public:
    // Initialize the USound member variables
    USound();

    static bool globalMute;
    
    // Initialize the USound object
    bool init(const char*);

    // Play the menu music
    void playMusic();


    //plays a sound does not loop
    void playSound();



    // Mute and unmute the sound
    void toggleMute();
    void toggleMusic();


    //fades out music based on milliseconds handed to it
    int fadeout(int ms);



    void interjectionAbrupt(USound);
    
    void interjectionWithFade(USound,int);

    void stopMusic();

    void togglemuteAllSounds();


    // Mute status
    bool isMuted() { return mute; }

    // Deallocate and destroy the sounds
    void free();
private:
    // Toggle the music
    

    // The music, and sound assets used
    Mix_Music * mMusic;

    bool mute;
};