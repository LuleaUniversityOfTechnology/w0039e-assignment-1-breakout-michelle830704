
#include "Apple.h"
#include <cstdlib> // For rand() function
#include <ctime>   // For time() to seed random number generator

Apple::Apple() {
    srand(static_cast<unsigned int>(time(0))); // Seed for randomization
    position.x = static_cast<float>(rand() % 400); // Randomize x coordinate (assuming screen width 400)
    position.y = static_cast<float>(rand() % 400); // Randomize y coordinate (assuming screen height 400)
}

void Apple::Draw() const {
    Play::DrawCircle({ position.x, position.y }, 5, Play::Colour::Red);  // Assuming Play::Colour::Red exists
}
