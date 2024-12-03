
#ifndef APPLE_H
#define APPLE_H

#include "Point2D.h"
#include "Play.h" 


class Apple {
public:
    Point2D position;

    Apple();  // Constructor to randomize the apple's position
    void Draw() const;  // Draws the apple on screen
};

#endif // APPLE_H
