#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "game.h"
#include "Play.h"
#include "constant.h"



void SpawnBall() {
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);

	for (int i = 0; i < 1; i++) {
		const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2 + (i * 1), DISPLAY_HEIGHT - 60 + (i * 1) }, radius, "ball");
		Play::GameObject& ball = Play::GetGameObject(objectId);

		
		ball.velocity = normalize({ 1, -1 }) * ballSpeed;
		
	}

}



void StepFrame(float elapsedTime)  {
	
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(ObjectType::TYPE_BALL);
	
			
		for (int i = 0; i < ballIds.size();i++) {

			Play::GameObject& ball = Play::GetGameObject(ballIds[i]);
			Play::UpdateGameObject(ball);


			Play::DrawObject(ball);
			

			if (ball.pos.x <= radius || ball.pos.x >= DISPLAY_WIDTH - radius) {
				ball.velocity.x *= -1;

			}
			if (ball.pos.y <= radius || ball.pos.y >= DISPLAY_HEIGHT - radius) {
				ball.velocity.y *= -1;  
			}
		
			/*ball.pos.x += ball.velocity.x;
			ball.pos.y += ball.velocity.y;*/
		}



	

}
