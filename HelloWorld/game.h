#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "paddle.h"
#include "constant.h"

void SpawnBall();
void StepFrame(float elapsedTime);
void SetupScene();
void UpdateGame();
void DrawPaddle(const Paddle& paddle);
void UpdatePaddlePosition(Paddle& paddle);
bool isCollidingWithPaddle(const Play::GameObject& ball);

