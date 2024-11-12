#include "game.h"
#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

void SpawnBall(int x, int y, float velocityX, float velocityY) {

	int ballid = Play::CreateGameObject(TYPE_BALL, { x,y }, 4, "ball");
	GameObject& ball = Play::GetGameObject(ballid);
	ball.velocity.x = velocityX;
	ball.velocity.y = velocityY;

}
