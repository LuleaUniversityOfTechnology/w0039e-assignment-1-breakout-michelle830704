
#include "Scoreboard.h"
#include "Play.h" 
#include <vector>
#include <algorithm>
#include "game.h"
#include "paddle.h"
#include <iostream>
#include <fstream>

Scoreboard::Scoreboard() : currentScore(0){
  
}

void Scoreboard::drawHighScores(int screenWidth, int screenHeight, HighScores& highScore) {
    int x = screenWidth * 0.9; 
    int y = screenHeight*0.9;

    Play::Point2D bottom_right = Play::Point2D(screenWidth*0.9f, screenHeight*0.15f);
    Play::DrawDebugText(bottom_right, ("Score: " + std::to_string(currentScore)).c_str());

    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        Play::DrawDebugText({ x, y - i * 20 }, std::to_string(highScore.getScores()[i]).c_str());
      
    }
}




void Scoreboard::resetScore(HighScores& highScore) {
    highScore.AddScore(currentScore);
    currentScore = 0;
   
}

void Scoreboard::incrementScore() {

    currentScore++;

}

unsigned int Scoreboard::getCurrentScore() const {
    return currentScore;
}