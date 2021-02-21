/**
* Copyright 2021 Goblin HQ ©
* Title: Em
* Date: 2/20/2021
* File: Em GBottle.h
*
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#include "GBackground.h"


GBackground::GBackground()
{
    mTitlePos = UVector3(0, 0, 0);
    mBackground = nullptr;
    mForeground = nullptr;
    mMenuScreen = nullptr;
    mSettingsMenu = nullptr;
 

}


bool GBackground::init(SDL_Renderer* aRenderer)
{
    // Tracks members initialization status
    bool success = true;

    // Initialize the background texture
    mBackground = new UTexture();
    mBackground->initUTexture(aRenderer);

    if (!mBackground->loadFromFile("assets/background.png"))
    {
        std::printf("Failed to load background texture!\n");
        success = false;
    }

    // Initialize the Foreground texture
    mForeground = new UTexture();
    mForeground->initUTexture(aRenderer);

    if (!mForeground->loadFromFile("assets/foreground.png"))
    {
        std::printf("Failed to load foreground texture!\n");
        success = false;
    }

    // Initialize the settings menu
    mSettingsMenu = new UTexture();
    mSettingsMenu->initUTexture(aRenderer);
    if (!mSettingsMenu->loadFromFile("assets/settings_menu.png"))
    {
        std::printf("Failed to load settings menu texture!\n");
        success = false;
    }


    return success;
}
void GBackground::update(const double& dt)
{
    //music and maybe eyes moving



}


// Free the resources allocated for this texture
void GBackground::free()
{

  

    // Destroy the textures
    mBackground->free();
    delete mBackground;
    mBackground = nullptr;

    mForeground->free();
    delete mForeground;
    mForeground = nullptr;

    mMenuScreen->free();
    delete mMenuScreen;
    mMenuScreen = nullptr;


    mSettingsMenu->free();
    delete mSettingsMenu;
    mSettingsMenu = nullptr;
}



























