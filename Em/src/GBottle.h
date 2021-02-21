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
#include "GPlayer.h"
#include "UTimer.h"

class GBottle {


public: 

    const static int FRAME_WIDTH = 219;
    const static int FRAME_HEIGHT = 327;
        const static int WALK_STATE;
        const static int STAND_STATE;
        const static int OPEN_STATE;
        const static int ATTACHED_STATE;

        enum class FRAMES
        {
            RIGHT_STEP,
            LEFT_STEP,
            STANDING,
            OPENED,
            ATTACHED
        };


        // Initializes Bottle
        GBottle();



        void mvRight();
        void mvLeft();

        // Initilaize the Bottle object
        bool init(SDL_Renderer*, const std::string&);

        // Updates the bottle
        void update(const float&,GPlayer);

        // handles event
        void handleEvent(SDL_Event&);

        // Draw the Bottle
        void render();

        // Free the resources
        void free();

        //set overlap flag
        void setOverlapFlag(bool aVal) { overlapflag = aVal; }

        // Set's the bottles attach
        void setAttachedFlag(bool aVal) { attachedFlag = aVal; }
        // Set's the bottles openedflag
        void setOpenedflag(bool aVal) { openedflag = aVal; }

        bool getAliveflag(){ return aliveflag; }
        void setAliveflag(bool aVal) { aliveflag = aVal; }
        void setPosition(UVector3);




private:
    // collision with player flag
    bool aliveflag,attachedFlag,overlapflag,openedflag;
    float overlaptime;
    //Bottle state var

    char mCurrState;

    //bottle pos
    bool mLeft, mRight;
    float mAcceleration;
    float mFriction;
    float mMaxSpeed;
    UVector3 mVel;
    UVector3 mPosition;

    UTimer timer;
    Uint32 prevTime;


    //Bottles Sprite sheet , Number of frames ,and current position on sprite sheet

    UTexture mSpriteSheet;
    SDL_Rect mAnimationFrames[1];
    //TODO CHANGE THIS WHEN WE GET TOTAL NUMBER OF ANIMATIONS 
    int mCurrFrame;



};