
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

    Snake();  // Constructor to initialize the snake
    ~Snake();  // Destructor to delete allocated memory
    void Draw() const;  // Draw the snake
    void HandleInput();  // Handle user input to change direction
    void Move();  // Move the snake
    void AddPart();  // Add a new part to the snake
    bool Collide(const Apple& apple) const;  // Check for collision with an apple
};

#endif // SNAKE_H
