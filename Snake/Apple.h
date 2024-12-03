
#ifndef APPLE_H
#define APPLE_H
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Point2D.h"
#include "Play.h" 


class Apple {
public:
    MyMath::Point2D position;

    Apple();  
    void Draw() const;  
};

#endif 
