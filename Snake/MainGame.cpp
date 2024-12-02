
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

    if (frameCount % 6 == 0) {  // Limit game speed (moves every 6 frames)
        snake->HandleInput();
        snake->Move();

        if (snake->Collide(*apple)) {
            snake->AddPart();
            delete apple;  // Remove old apple
            apple = new Apple();  // Spawn new apple
        }
    }

    // Draw the game
    snake->Draw();
    apple->Draw();
}

void MainGameExit() {
    delete snake;
    delete apple;
}
