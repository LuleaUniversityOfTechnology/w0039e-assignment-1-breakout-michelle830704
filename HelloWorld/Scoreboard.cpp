#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Scoreboard.h"
#include "Play.h" 
#include <vector>
#include <algorithm>
#include "game.h"
#include "paddle.h"
#include <iostream>

Scoreboard::Scoreboard() : currentScore(0) {
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        highScores[i] = 0;
    }
}

void Scoreboard::drawHighScores(int screenWidth, int screenHeight) {
    int x = screenWidth - 200; 
    int y = screenHeight - 150;

    Play::Point2D bottom_right = Play::Point2D(screenWidth*0.75f, screenHeight*0.15f);
    Play::DrawDebugText(bottom_right, ("Score: " + std::to_string(currentScore)).c_str());

    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        Play::DrawDebugText({ x, y + i * 20 }, std::to_string(highScores[i]).c_str());
      
    }
}

void Scoreboard::drawCurrentScore(int screenWidth, int screenHeight) {
    Play::Vector2f position(40.0f, static_cast<float>(50));
    Play::DrawDebugText(position, ("Score: " + std::to_string(currentScore)).c_str());
}

void Scoreboard::updateHighScores() {
    std::vector<unsigned int> scores(highScores, highScores + MAX_HIGH_SCORES);
    scores.push_back(currentScore);
    std::sort(scores.rbegin(), scores.rend());
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        highScores[i] = scores[i];
    }
}

void Scoreboard::reset(unsigned int screenWidth, unsigned int screenHeight) {
    updateHighScores();
    currentScore = 0;
   
}

void Scoreboard::incrementScore() {

    currentScore++;

}

unsigned int Scoreboard::getCurrentScore() const {
    return currentScore;
}