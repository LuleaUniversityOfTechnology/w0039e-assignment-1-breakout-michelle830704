
#include "SnakePart.h"

SnakePart::SnakePart(Point2D pos, Play::Colour col) : position(pos), color(col) {}

void SnakePart::Draw() const {
    Play::DrawCircle({ position.x, position.y }, 5, color);  
}
