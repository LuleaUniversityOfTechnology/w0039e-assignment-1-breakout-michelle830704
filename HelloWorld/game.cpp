
#include "game.h"
#include "Play.h"
#include "constant.h"
#include "paddle.h"
#include <vector>
#include <iostream>
#include "Scoreboard.h"
#include "HighScores.h"
#include <fstream>



HighScores highScores;


Paddle paddle;

Scoreboard scoreboard;


const std::string HIGH_SCORE_FILE = "highscores.txt";
//unsigned int currentScore = 0;
bool isGameRunning = true;

void SpawnBall() {

	for (int i = 0; i < 1; i++) {
		const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2 + (i * 1), DISPLAY_HEIGHT - 160 + (i * 1) }, radius, "ball");
		Play::GameObject& ball = Play::GetGameObject(objectId);

		ball.velocity = Play::normalize({ 1, -1 }) * ballSpeed;


	}

}


void SetupScene() {
	const int brickRows = 8;
	const int brickCols = 40;
	const int brickWidth = 16;
	const int brickHeight = 10;
	const int startX = 10;
	const int startY = 353;
	const int spacing = 2;
	for (int row = 0; row < brickRows; ++row) {
		for (int col = 0; col < brickCols; ++col) {
			int x = startX + col * (brickWidth + spacing);
			int y = startY - row * (brickHeight + spacing);
			Play::CreateGameObject(ObjectType::TYPE_BRICK, { x, y }, 8, "brick");

		}
	}
}




void StepFrame(float elapsedTime) {
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(ObjectType::TYPE_BALL);
	const std::vector<int> bricksId = Play::CollectGameObjectIDsByType(ObjectType::TYPE_BRICK);


	for (int i = 0; i < bricksId.size(); i++) {
		Play::GameObject& brick = Play::GetGameObject(bricksId[i]);
		Play::UpdateGameObject(brick);
		Play::DrawObject(brick);

	}

	for (int i = 0; i < ballIds.size(); i++) {
		Play::GameObject& ball = Play::GetGameObject(ballIds[i]);
		Play::UpdateGameObject(ball);
		Play::DrawObject(ball);


		bool hasCollision = isCollidingWithPaddle(ball);
		if (hasCollision)
		{
			ball.velocity.y *= -1;
		}
		

		if (ball.pos.x <= radius || ball.pos.x >= DISPLAY_WIDTH - radius) {
			ball.velocity.x *= -1;

		}
		if (ball.pos.y <= radius || ball.pos.y >= DISPLAY_HEIGHT - radius) {
			ball.velocity.y *= -1;
		}
		for (int brickId : bricksId) {
			Play::GameObject& brick = Play::GetGameObject(brickId);
			if (Play::IsColliding(ball, brick)) {
				Play::DestroyGameObject(brickId);
				scoreboard.incrementScore();
				ball.velocity.y *= -1;
			}
		}

		UpdateGame();
		DrawPaddle(paddle);
		UpdatePaddlePosition(paddle);
		
		//scoreboard.drawCurrentScore(DISPLAY_WIDTH, DISPLAY_HEIGHT);
		scoreboard.drawHighScores(DISPLAY_WIDTH, DISPLAY_HEIGHT, highScores);
		
	}

}


	void InitializeGame() {

		highScores.LoadFromFile(HIGH_SCORE_FILE);
		
		std::cout << "Game initialized." << std::endl;
	}


	void ResetGame() {
		scoreboard.resetScore(highScores);
		SetupScene();
		SpawnBall();
		std::cout << "Game reset." << std::endl;
	}

	void UpdateGame() {

		float x = DISPLAY_WIDTH * 0.9;
		float y = DISPLAY_HEIGHT * 0.95;

		std::string scoreText = "HighScore: ";
		Play::DrawDebugText(Play::Point2D(x, y), scoreText.c_str(), Play::cWhite);
		highScores.Draw();


		const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(ObjectType::TYPE_BALL);
		const std::vector<int> bricksId = Play::CollectGameObjectIDsByType(ObjectType::TYPE_BRICK);

		for (int i = 0; i < ballIds.size(); ++i) {
			Play::GameObject& ball = Play::GetGameObject(ballIds[i]);
			if (ball.pos.y < 10) {
				Play::DestroyGameObject(ballIds[i]);
				ResetGame();
				break;
			}
		}
	}


	void ExitGame() {

		highScores.SaveToFile(HIGH_SCORE_FILE);
		std::cout << "Exiting game. Goodbye!" << std::endl;
	}

	
