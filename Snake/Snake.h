#ifndef SNAKE_H
#define SNAKE_H

#include "Play.h"
#include "SnakePart.h"
#include "Apple.h"

enum class Heading { North, South, East, West };

class Snake
{
private:
    Heading heading;
    SnakePart* parts;
    int numParts;

public:
    Snake();
    ~Snake();
    void Draw() const;
    void HandleInput();
    void Move();
    void AddPart();
    bool Collide(const Apple* apple);
};

#endif // SNAKE_H
