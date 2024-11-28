#pragma once

#include "game.h"
#include <string>
#include <iostream>
#include "HighScores.h"

const int MAX_HIGH_SCORES = 5;

class Scoreboard {
private:
    unsigned int currentScore;

public:
    Scoreboard();

    void drawHighScores(int screenWidth, int screenHeight, HighScores& highScore);
    void drawCurrentScore(int screenWidth, int screenHeight);
    void updateHighScores();
    void resetScore(HighScores& highScore);
    void incrementScore();

    unsigned int getCurrentScore() const;

    

};
