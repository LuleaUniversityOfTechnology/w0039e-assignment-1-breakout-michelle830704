#include "Apple.h"
#include <cstdlib>

Apple::Apple()
{
    Respawn();
}

void Apple::Respawn()
{
    position = { rand() % 80 * 10, rand() % 60 * 10 }; // Align to grid
}

void Apple::Draw() const
{
    Play::DrawCircle(position, 5, Play::cRed);
}

Point2D Apple::GetPosition() const
{
    return position;
}
