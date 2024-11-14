
#include "game.h"




// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE) {
	SpawnBall();
	Play::CentreAllSpriteOrigins();


}

bool MainGameUpdate(float elapsedTime) {
	Play::ClearDrawingBuffer(Play::cBlack);
	StepFrame(elapsedTime);
	Play::PresentDrawingBuffer();
	return Play::KeyDown(Play::KEY_ESCAPE);
}



int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}
