
#ifndef SNAKE_H
#define SNAKE_H
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Point2D.h"
#include "Apple.h"
#include "SnakePart.h"
#include <vector>
#include "Play.h"



class Snake {
public:
    MyMath::Direction heading;
    std::vector<SnakePart*> parts;

    Snake();  
    ~Snake();  
    void Draw() const;  
    //bool StepFrame(float elapsedTime);
    void HandleInput();  
    void Move();  
    void AddPart();  
    bool Collide(const Apple& apple) const; 

};

#endif 