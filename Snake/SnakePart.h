
#ifndef SNAKEPART_H
#define SNAKEPART_H
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Point2D.h"
#include "Play.h" 

class SnakePart {
public:
    MyMath::Point2D position;
    Play::Colour color;

    SnakePart(MyMath::Point2D pos, Play::Colour col);
    void Draw() const;





};

#endif 
