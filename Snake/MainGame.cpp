#define PLAY_USING_GAMEOBJECT_MANAGER
#define PLAY_IMPLEMENTATION
#include "Play.h"
#include "Snake.h"
#include "Apple.h"
#include "constant.h"


Snake* snake;
Apple* apple;
int myFrameCount = 0;

void MainGameEntry(PLAY_IGNORE_COMMAND_LINE) {
    Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
    Play::CentreAllSpriteOrigins();
    snake = new Snake();
    apple = new Apple();
}


bool StepFrame(float elapsedTime) {
    if (myFrameCount % 6 == 0) {
        snake->HandleInput();
        snake->Move();

        if (snake->Collide(*apple)) {
            snake->AddPart();
            delete apple;
            apple = new Apple();
        }
    }

    myFrameCount++;

    snake->Draw();
    apple->Draw();

    return Play::KeyDown(Play::KEY_ESCAPE);

}

bool MainGameUpdate(float elapsedTime) {

    Play::ClearDrawingBuffer(Play::cBlack);
    StepFrame(elapsedTime);
    Play::PresentDrawingBuffer(); 
    return Play::KeyDown(Play::KEY_ESCAPE);
}





int MainGameExit() {
    delete snake;
    delete apple;
    Play::DestroyManager();
    return PLAY_OK;
}
