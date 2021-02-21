/**
* Copyright 2021 Goblin HQ �
* Title: Em
* Date: 2/20/2021
* File: Em UGame.cpp
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#include "UGame.h"




// Default constructor
UGame::UGame()
{
    mRenderer = nullptr;
    mWindow = nullptr;
    buttTexture = nullptr;
    mSounds = nullptr;
    mButton = nullptr;

}




// Initializes and loads all the game objects
bool UGame::init(SDL_Renderer* aRenderer, UWindow* aWindow)
{
    // Initialize success flag
    bool success = true;

    // Set the renderer and window
    mRenderer = aRenderer;
    mWindow = aWindow;

    if (mRenderer == nullptr || mWindow == nullptr)
    {
        printf("Attempted to initialize the UGame object with nullptr! Pass in valid pointers in the UGame.init() function\n");
        success = false;
    }
    else
    {
        // Initialize the player
        if (!mPlayer.init(mRenderer, "assets/em_spritesheet.png"))
        {
            printf("Failed to load player!\n");
            success = false;
        }
    
        // Initialize all the bottles
     

        GBottle* tmpbottle = new GBottle();
        tmpbottle->init(mRenderer, "assets/bottle.png");
        bottles.push_back(tmpbottle);


           /* if (!mBottle.init(mRenderer, "assets/bottle.png"))
            {
                printf("Failed to load bottle!\n");
                success = false;
            }*/
        


        buttTexture = new UTexture();
        buttTexture->initUTexture(mRenderer);
        if (!buttTexture->loadFromFile("assets/volume.png")) {
            std::printf("Failed to load sound icon texture!\n");
            success = false;
        }
     //   mSounds = new USound();
      //  mSounds->init("assets/menu.mp3");
      //  mSounds->playMusic();


        mButton = new GSButton();
        if (!mButton->init(buttTexture, mSounds)) {
            printf("Failed to initialize sound button!\n");
            success = false;
        }
    }

    return success;
}




// Update the game world based on the time since the last update
void UGame::update(const float& dt)
{
    bool killBottle = false;
    
    mPlayer.update(dt);
    for (GBottle* &bottle : bottles) {
        bottle->update(dt,mPlayer);
        if (!bottle->getAliveflag()) {
             bottle->setAliveflag(true);
             killBottle = true;
        }
    }
    // Clean up the dead trees when necessary
    while (killBottle) {
        std::vector<GBottle*>::iterator beg, end;
        for (beg = bottles.begin(), end = bottles.end(); beg != end && (*beg)->getAliveflag(); ++beg);

        // Found a dead ramp
        if (beg != end) {
            (*beg)->free();
            delete(*beg);
            bottles.erase(beg);
        }
        // No dead ramps found
        else {
            killBottle = false;
        }
    }
  
}





// Handle all the events on the queue
bool UGame::handleEvent(SDL_Event& e)
{
    mButton->handleEvent(&e);
    mPlayer.updateGameState(2);
    mPlayer.handleEvent(e);

    if (e.type == SDL_QUIT) { return true; }

    return false;
}

void UGame::spawnBottle() {





}


// Draw the game world to the screen
void UGame::render()
{
    mPlayer.render();
   
    for (GBottle*& bot : bottles) {

        bot->render();

    }

    mButton->render();
}




// Free the game objects
void UGame::close()
{
    if (mRenderer)
    {
        mRenderer = nullptr;
    }

    if (mWindow)
    {
        mWindow = nullptr;
    }

    mPlayer.free();

    for (GBottle*& bot : bottles) {

        bot->free();
        delete bot;
        
    }

    bottles.clear();

    //mBottle.free();
    
}