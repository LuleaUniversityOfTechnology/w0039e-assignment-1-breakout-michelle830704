#include "SnakePart.h"
#include <cstdlib>

SnakePart::SnakePart(Point2D pos) : position(pos)
{
    colour = Play::Colour(rand() % 256, rand() % 256, rand() % 256);
}

void SnakePart::Draw() const
{
    Play::DrawCircle(position, 5, colour);
}

void SnakePart::SetPosition(Point2D pos)
{
    position = pos;
}

Point2D SnakePart::GetPosition() const
{
    return position;
}
