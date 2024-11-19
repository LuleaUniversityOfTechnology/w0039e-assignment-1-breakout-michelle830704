#pragma once
#include "Paddle.h"
#include "game.h"
#include "Play.h"

const int DISPLAY_WIDTH = 640;
const int DISPLAY_HEIGHT = 360;
const int DISPLAY_SCALE = 2;
const float ballSpeed = 2.f;
const float radius = 4.f;


enum ObjectType 
{
	TYPE_BALL,
	TYPE_BRICK,
	TYPE_PADDLE,
	
};
extern Paddle paddle;

