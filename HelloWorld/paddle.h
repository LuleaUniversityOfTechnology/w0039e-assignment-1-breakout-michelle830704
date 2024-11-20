#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "constant.h"
#include "paddle.h"



struct Paddle {
    Play::Point2D position{320,8};

    float width = 100.0f;  
    float height = 20.0f;  
};

void DrawPaddle(const Paddle& paddle);

void UpdatePaddlePosition(Paddle & paddle);


struct Point {
    float x;
    float y;
};


struct Ball {
    Point pos;    
    float radius; 
};

