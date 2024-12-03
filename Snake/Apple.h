
#ifndef APPLE_H
#define APPLE_H

#include "Point2D.h"
#include "Play.h" 


class Apple {
public:
    Point2D position;

    Apple();  
    void Draw() const;  
};

#endif 
