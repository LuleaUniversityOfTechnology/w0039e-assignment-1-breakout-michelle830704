#include "Snake.h"
#include <algorithm>

Snake::Snake() : heading(Heading::East), numParts(2)
{
    parts = new SnakePart[numParts]{
        SnakePart({200, 200}),
        SnakePart({190, 200})
    };
}

Snake::~Snake()
{
    delete[] parts;
}

void Snake::Draw() const
{
    for (int i = 0; i < numParts; ++i)
    {
        parts[i].Draw();
    }
}

void Snake::HandleInput()
{
    if (Play::KeyDown(VK_UP) && heading != Heading::South) heading = Heading::North;
    if (Play::KeyDown(VK_DOWN) && heading != Heading::North) heading = Heading::South;
    if (Play::KeyDown(VK_LEFT) && heading != Heading::East) heading = Heading::West;
    if (Play::KeyDown(VK_RIGHT) && heading != Heading::West) heading = Heading::East;
}

void Snake::Move()
{
    for (int i = numParts - 1; i > 0; --i)
    {
        parts[i].SetPosition(parts[i - 1].GetPosition());
    }

    Point2D head = parts[0].GetPosition();
    switch (heading)
    {
    case Heading::North: head.y -= 10; break;
    case Heading::South: head.y += 10; break;
    case Heading::West: head.x -= 10; break;
    case Heading::East: head.x += 10; break;
    }
    parts[0].SetPosition(head);
}

void Snake::AddPart()
{
    SnakePart* newParts = new SnakePart[numParts + 1];
    std::copy(parts, parts + numParts, newParts);
    newParts[numParts] = SnakePart(parts[numParts - 1].GetPosition());
    delete[] parts;
    parts = newParts;
    numParts++;
}

bool Snake::Collide(const Apple* apple)
{
    return Play::IsColliding(parts[0].GetPosition(), 5, apple->GetPosition(), 5);
}
