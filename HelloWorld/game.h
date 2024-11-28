#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "paddle.h"
#include "constant.h"
#include "Scoreboard.h"
#include <iostream>

void SpawnBall();
void StepFrame(float elapsedTime);
void SetupScene();
void drawHighScores();
void InitializeGame();
void UpdateGame();
void ResetGame();
void ExitGame();

