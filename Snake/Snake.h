
#ifndef SNAKE_H
#define SNAKE_H

#include "Point2D.h"
#include "Apple.h"
#include "SnakePart.h"
#include <vector>

enum class Direction {
    North,
    South,
    East,
    West
};

class Snake {
public:
    Direction heading;
    std::vector<SnakePart*> parts;

    Snake();  
    ~Snake();  
    void Draw() const;  
    void HandleInput();  
    void Move();  
    void AddPart();  
    bool Collide(const Apple& apple) const; 
};

#endif 