#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "paddle.h"

struct Paddle {
    Play::Point2D position{320,8};

    float width = 100.0f;  
    float height = 20.0f;  
};

void DrawPaddle(const Paddle& paddle);

void UpdatePaddlePosition(Paddle & paddle);

struct Vec2 {
    float x,y;
    
};


bool IsColliding(const Paddle& paddle, Play::GameObject& ball);
