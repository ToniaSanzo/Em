/**
* Copyright 2021 Goblin HQ ©
* Title: Em
* Date: 2/20/2021
* File: Em GBottle.cpp
* 
* Engineers: Charles Chiasson, Tonia Sanzo
* Audio:     Ethan Schwabe
* Art:       Bobbierre Heard, Bharati Mahajan, Ngan Nguyen
*/
#include "GBottle.h"







// Class Constraints
const int GBottle::FRAME_WIDTH = 0;//TODO CHANGE THESE WHEN WE GET SPRITE SHEET SPECS
const int GBottle::FRAME_HEIGHT = 0;//TODO CHANGE THESE WHEN WE GET SPRITE SHEET SPECS
const int GBottle::STAND_STATE = 0;
const int GBottle::WALK_STATE = 1;
const int GBottle::OPEN_STATE = 2;
const int GBottle::ATTACHED_STATE = 3;


GBottle::GBottle() {
	mCurrState = STAND_STATE;
	mCurrFrame = static_cast<int>(FRAMES::STANDING);
    overlapflag = attachedFlag = false;
    aliveflag = true;
}

// Initialize the Bottle object
bool GBottle::init(SDL_Renderer* aRenderer, const std::string& path)
{
	// Initialize the success flag
	bool success = true;

	// Initialize the bottle sprite sheet
	mSpriteSheet.initUTexture(aRenderer);

    // Load the sprite sheet with the file path
    if (!mSpriteSheet.loadFromFile(path))
    {
        printf("Failed to load bottle sprite sheet!\n");
        success = false;
    }
    else
    {
        mPosition = UVector3(320, 450, 0);//TODO this position will change 

        // Initialize the animation tiles
        for (int row = 0; row < 3; ++row)// row < 3 will change based on the amount of animations in the spread
        {
            for (int col = 0; col < 2; ++col)// col will be changed upon how evermany columns there are
            {
                mAnimationFrames[(row * 2) + col].x = col * FRAME_WIDTH;
                mAnimationFrames[(row * 2) + col].y = row * FRAME_HEIGHT;
                mAnimationFrames[(row * 2) + col].w = FRAME_WIDTH;
                mAnimationFrames[(row * 2) + col].h = FRAME_HEIGHT;
            }
        }
    }



}


void GBottle::update(const float& dt) {

    if (aliveflag) {


        // If bottle reaches character
        if (overlapflag == true) {

            overlaptime += dt;

            //wait 1.5 seconds
            if (overlaptime == 1.5) {

                attachedFlag = true;
                aliveflag = false;
            }


        }


        // If Bottle was Opened
        if (openedflag) {

            // Bottle Produce Open animation 
            mCurrState = OPEN_STATE;
           
            //change to different animations


        }

  











    }


   
}



// Draw the bottle
void GBottle::render()
{
    mSpriteSheet.render(static_cast<int>(mPosition.x - (FRAME_WIDTH / 2.0)), static_cast<int>(mPosition.y - (FRAME_HEIGHT / 2.0)), &mAnimationFrames[mCurrFrame]);
}





// Deallocate the bottle's resources
void GBottle::free()
{
    mSpriteSheet.free();
}