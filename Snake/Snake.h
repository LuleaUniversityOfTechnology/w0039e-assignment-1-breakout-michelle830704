
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

    float moveTimer = 0.0f;      // Time since the last move
    const float moveInterval = 8.0f; // The interval between moves (controls the speed)


    Snake();  
    ~Snake();  
    void Draw() const;  

    void HandleInput();  
    void Move();  
    void AddPart();  
    bool Collide(const Apple& apple);  
    bool CollideWithItself();           




};

#endif 