
#include "Snake.h"
#include "Play.h" // Assuming Play::IsColliding exists




Snake::Snake() : heading(Direction::East) {
    // Initialize the snake with two parts
    parts.push_back(new SnakePart(Point2D(50, 50),Play::Colour(0, 255, 0)));
    parts.push_back(new SnakePart(Point2D(40, 50),Play::Colour(0, 255, 0)));
}

Snake::~Snake() {
    for (SnakePart* part : parts) {
        delete part;
    }
}

void Snake::Draw() const {
    for (const SnakePart* part : parts) {
        part->Draw();
    }
}

void Snake::HandleInput() {
    if (Play::KeyPressed(Play::KEY_UP)) {
        heading = Direction::North;
    }
    else if (Play::KeyPressed(Play::KEY_DOWN)) {
        heading = Direction::South;
    }
    else if (Play::KeyPressed(Play::KEY_LEFT)) {
        heading = Direction::West;
    }
    else if (Play::KeyPressed(Play::KEY_RIGHT)) {
        heading = Direction::East;
    }
}

void Snake::Move() {

    for (int i = parts.size() - 1; i > 0; --i) {
        parts[i]->position = parts[i - 1]->position;
    }

 
    switch (heading) {
    case Direction::North:
        parts[0]->position.y -= 10;
        break;
    case Direction::South:
        parts[0]->position.y += 10;
        break;
    case Direction::East:
        parts[0]->position.x += 10;
        break;
    case Direction::West:
        parts[0]->position.x -= 10;
        break;
    }
}

void Snake::AddPart() {
    Point2D newPartPosition = parts[parts.size() - 1]->position;
    parts.push_back(new SnakePart(newPartPosition, Play::Colour(255, 0, 0)));
}

bool Snake::Collide(const Apple& apple) const {
    return Play::IsColliding({ parts[0]->position.x, parts[0]->position.y }, { apple.position.x, apple.position.y }, 5, 5); // Check collision
}
