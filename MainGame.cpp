#include "Play.h"
#include "Apple.h"
#include "Snake.h"

void MainGameEntry()
{
    Play::CreateManager(800, 600, 60);
}

void MainGameUpdate()
{
    Play::ClearDrawingBuffer();
    static Snake snake;
    static Apple apple;

    snake.HandleInput();
    static int frameCount = 0;
    if (frameCount % 6 == 0) 
    {
        snake.Move();
        if (snake.Collide(&apple))
        {
            apple.Respawn();
        }
    }
    frameCount++;

    apple.Draw();
    snake.Draw();

    Play::PresentDrawingBuffer();
}

void MainGameExit()
{
    Play::DestroyManager();
}
