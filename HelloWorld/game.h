#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "paddle.h"
#include "constant.h"
#include <iostream>

void SpawnBall();
void StepFrame(float elapsedTime);
void SetupScene();
void UpdateGame();
void drawHighScores();

