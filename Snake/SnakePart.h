
#ifndef SNAKEPART_H
#define SNAKEPART_H

#include "Point2D.h"
#include "Play.h" 

class SnakePart {
public:
    Point2D position;
    Play::Colour color;

    SnakePart(Point2D pos, Play::Colour col);  
    void Draw() const;  
};

#endif 
