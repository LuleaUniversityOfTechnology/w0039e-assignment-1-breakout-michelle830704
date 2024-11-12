#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "game.h"
#include "constant.h"






// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE) {
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	
}

bool MainGameUpdate(float elapsedTime) {
	Play::ClearDrawingBuffer(Play::cBlack);
	Play::PresentDrawingBuffer();

	Play::GameObject& ball = Play::GetGameObjectByType(TYPE_BALL);
	Play::UpdateGameObject(ball);
	Play::DrawObject(ball);
	return Play::KeyDown(Play::KEY_ESCAPE);
}



int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}
