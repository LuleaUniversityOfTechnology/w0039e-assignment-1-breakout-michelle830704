
#ifndef SNAKEPART_H
#define SNAKEPART_H

#include "Point2D.h"
#include "Play.h" // Assuming Play::Colour is part of your library

class SnakePart {
public:
    Point2D position;
    Play::Colour color;

    SnakePart(Point2D pos, Play::Colour col);  // Constructor
    void Draw() const;  // Draws the snake part on the screen
};

#endif // SNAKEPART_H
