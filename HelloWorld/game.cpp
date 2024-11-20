#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "game.h"
#include "Play.h"
#include "constant.h"
#include "paddle.h"


static Paddle paddle;


void SpawnBall() {

	for (int i = 0; i < 1; i++) {
		const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2 + (i * 1), DISPLAY_HEIGHT - 80 + (i * 1) }, radius, "ball");
		Play::GameObject& ball = Play::GetGameObject(objectId);


		ball.velocity = normalize({ 1, -1 }) * ballSpeed;

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

		bool hasCollision = IsColliding(paddle, ball);

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
				ball.velocity.y *= -1;
				break;
			}

		}
	}

	DrawPaddle(paddle);
	UpdatePaddlePosition(paddle);
	
	

	

}



