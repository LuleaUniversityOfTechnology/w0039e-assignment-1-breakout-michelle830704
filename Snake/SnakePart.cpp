#define PLAY_USING_GAMEOBJECT_MANAGER
#include "SnakePart.h"
#include "Point2D.h"
#include "Play.h"
#include "Snake.h"


SnakePart::SnakePart(MyMath::Point2D pos, Play::Colour col) : position(pos), color(col) {}

void SnakePart::Draw() const {
    Play::DrawCircle({ position.x, position.y }, 5, color);
    }
