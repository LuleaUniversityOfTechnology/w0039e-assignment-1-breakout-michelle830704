
#include "Play.h"
#include "Snake.h"
#include "Apple.h"

Snake* snake;
Apple* apple;
int frameCount = 0;

void MainGameEntry() {
    snake = new Snake();
    apple = new Apple();
}

void MainGameUpdate() {
    frameCount++;

    if (frameCount % 6 == 0) {  
        snake->HandleInput();
        snake->Move();

        if (snake->Collide(*apple)) {
            snake->AddPart();
            delete apple;  
            apple = new Apple();  
        }
    }

  
    snake->Draw();
    apple->Draw();
}

void MainGameExit() {
    delete snake;
    delete apple;
}
