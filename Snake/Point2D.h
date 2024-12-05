
#ifndef POINT2D_H
#define POINT2D_H


namespace MyMath
{

    struct Point2D {
        float x;
        float y;

        Point2D(float x = 0, float y = 0) : x(x), y(y) {}
        bool operator==(const Point2D& other) const {
            return (x == other.x && y == other.y);

        }

    };

    enum class Direction {
        North,
        South,
        West,
        East,
    };

}


#endif 
