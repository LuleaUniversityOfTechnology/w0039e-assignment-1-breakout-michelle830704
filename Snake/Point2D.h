
#ifndef POINT2D_H
#define POINT2D_H


namespace MyMath
{

    struct Point2D {
        float x;
        float y;

        Point2D(float x = 0, float y = 0) : x(x), y(y) {}
    };

    enum class Direction {
        North,
        South,
        West,
        East,
    };

}


#endif 
