
#include "Apple.h"
#include <cstdlib> 
#include <ctime>   
Apple::Apple() {
    srand(static_cast<unsigned int>(time(0))); 
    position.x = static_cast<float>(rand() % 400);
    position.y = static_cast<float>(rand() % 400); 
}

void Apple::Draw() const {
    Play::DrawCircle({ position.x, position.y }, 5, Play::Colour(255, 0, 0));  
}
