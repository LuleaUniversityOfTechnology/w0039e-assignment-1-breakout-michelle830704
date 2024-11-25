
#include "Scoreboard.h"
#include "Play.h" 
#include <vector>
#include <algorithm>
#include "game.h"
#include "paddle.h"
#include <iostream>
using namespace std;

Scoreboard::Scoreboard() : currentScore(0) {
    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        highScores[i] = 0;
    }
}

void Scoreboard::drawHighScores(int screenWidth, int screenHeight) {
    int x = screenWidth - 200; 
    int y = screenHeight - 150;

    Play::Vector2f position(20, static_cast<float>(screenHeight - 150));
    Play::DrawDebugText(screenHeight - 50, "High Scores:");


    for (int i = 0; i < MAX_HIGH_SCORES; i++) {
        Play::DrawDebugText(x, y + i * 20, std::to_string(highScores[i]).c_str());
      
    }
}

void Scoreboard::drawCurrentScore(int screenWidth, int screenHeight) {
    Play::Vector2f position(20.0f, static_cast<float>(screenHeight - 50));
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
    Play::DestroyAlSprites();
    int ballID = Play::CreateSprite("ball", { screenWidth / 2, screenHeight / 2 }, 1, 1);
    Play::SetSpritePosition(ballID, { screenWidth / 2, screenHeight / 2 });
}

void Scoreboard::incrementScore() {
    currentScore += 1;
}

unsigned int Scoreboard::getCurrentScore() const {
    return currentScore;
}