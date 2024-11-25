#pragma once
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "paddle.h"
#include "game.h"
#include <string>
#include <iostream>

const int MAX_HIGH_SCORES = 5;

class Scoreboard {
private:
    unsigned int highScores[MAX_HIGH_SCORES];
    unsigned int currentScore;

public:
    Scoreboard();

    void drawHighScores(int screenWidth, int screenHeight);
    void drawCurrentScore(int screenWidth, int screenHeight);
    void updateHighScores();
    void reset(unsigned int screenWidth, unsigned int screenHeight);
    void incrementScore();
    unsigned int getCurrentScore() const;
}

#endif
