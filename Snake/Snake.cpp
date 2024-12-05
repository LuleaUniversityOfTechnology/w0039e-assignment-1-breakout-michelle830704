#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Snake.h"
#include "Play.h" 
#include "Point2D.h"




Snake::Snake() : heading(MyMath::Direction::North) {
    // Initialize the snake with two parts
    parts.push_back(new SnakePart(MyMath::Point2D(40, 40),Play::Colour(0, 100, 0)));
    parts.push_back(new SnakePart(MyMath::Point2D(30, 10),Play::Colour(0, 100, 0)));
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
        heading = MyMath::Direction::North;
    }
    else if (Play::KeyPressed(Play::KEY_DOWN)) {
        heading = MyMath::Direction::South;
    }
    else if (Play::KeyPressed(Play::KEY_LEFT)) {
        heading = MyMath::Direction::West;
    }
    else if (Play::KeyPressed(Play::KEY_RIGHT)) {
        heading = MyMath::Direction::East;
    }
}

void Snake::Move() {

    for (int i = parts.size() - 1; i > 0; --i) {
        parts[i]->position = parts[i - 1]->position;
    }

 
    switch (heading) {
    case MyMath::Direction::North:
        parts[0]->position.y += 1;
        break;
    case MyMath::Direction::South:
        parts[0]->position.y -= 1;
        break;
    case MyMath::Direction::West:
        parts[0]->position.x -= 1;
        break;
    case MyMath::Direction::East:
        parts[0]->position.x += 1;
        break;
    }
}

void Snake::AddPart() {
     MyMath::Point2D newPartPosition = (parts.empty()) ? MyMath::Point2D(0, 0) : parts[parts.size() - 1]->position;
     parts.push_back(new SnakePart(newPartPosition, Play::Colour(255, 0, 0)));
}

bool Snake::Collide(const Apple& apple) {

    float dx = apple.position.x - parts[0]->position.x;
    float dy = apple.position.y - parts[0]->position.y;

    float distance = sqrt(dx * dx + dy * dy);


    if (distance < 2.0f) {

        AddPart();
        return true;
    }
}

