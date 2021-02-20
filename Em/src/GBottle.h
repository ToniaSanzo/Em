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
#pragma once
#include "ULib.h"
#include "UTexture.h"



class GBottle {


public: 

		const static int FRAME_WIDTH;
		const static int FRAME_HEIGHT;
        const static int WALK_STATE;
        const static int STAND_STATE;
        const static int OPEN_STATE;
        const static int ATTACHED_STATE;

        enum class FRAMES
        {
            RIGHT_STEP,
            LEFT_STEP,
            STANDING,
            SMASHED,
            ATTACHED
        };


        // Initializes Bottle
        GBottle();


        // Initilaize the Bottle object
        bool init(SDL_Renderer*, const std::string&);

        // Updates the bottle
        void update(const float&);

        // handles event
        void handleEvent(SDL_Event&);

        // Draw the Bottle
        void render();

        // Free the resources
        void free();

        //set overlap flag
        void setOverlapFlag(bool aVal) { overlap = aVal; }

        // Set's the bottles attach
        void setAttachedFlag(bool aVal) { attachedFlag = aVal; }
        // Set's the bottles openedflag
        void setAttachedFlag(bool aVal) { openedflag = aVal; }
private:
    // collision with player flag
    bool aliveflag,attachedFlag,overlapflag,openedflag;
    int overlaptime;
    //Bottle state var

    char mCurrState;

    //bottle pos

    UVector3 mPosition;


    //Bottles Sprite sheet , Number of frames ,and current position on sprite sheet

    UTexture mSpriteSheet;
    SDL_Rect mAnimationFrames[6];
    //TODO CHANGE THIS WHEN WE GET TOTAL NUMBER OF ANIMATIONS 
    int mCurrFrame;



};