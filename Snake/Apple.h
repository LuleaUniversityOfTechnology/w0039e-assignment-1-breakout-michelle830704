#ifndef APPLE_H
#define APPLE_H

#include "Play.h"

class Apple
{
private:
    Point2D position;

public:
    Apple();
    void Respawn();
    void Draw() const;
    Point2D GetPosition() const;
};

#endif // APPLE_H
