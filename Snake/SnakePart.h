#ifndef SNAKEPART_H
#define SNAKEPART_H

#include "Play.h"

class SnakePart
{
private:
    Point2D position;
    Play::Colour colour;

public:
    SnakePart(Point2D pos);
    void Draw() const;
    void SetPosition(Point2D pos);
    Point2D GetPosition() const;
};

#endif // SNAKEPART_H
