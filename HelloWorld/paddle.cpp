#include "constant.h"
#include "paddle.h"
#include "Play.h"
#include "game.h"
#include <iostream>




void DrawPaddle(const Paddle & paddle) {
    Play::Point2D bottom_left(paddle.position.x - paddle.width / 2, paddle.position.y - paddle.height / 2);
    Play::Point2D top_right(paddle.position.x + paddle.width / 2, paddle.position.y + paddle.height/2);
    Play::DrawRect(bottom_left,top_right, Play::cWhite,true);
}


void UpdatePaddlePosition(Paddle& paddle) {

    const float paddleSpeed = 4.0f;

    if (Play::KeyDown(Play::KEY_LEFT)) {
        paddle.position.x -= paddleSpeed;
    }
    if (Play::KeyDown(Play::KEY_RIGHT)) {
        paddle.position.x += paddleSpeed;
    }


    if (paddle.position.x - paddle.width / 2 < 0) {
        paddle.position.x = paddle.width / 2;
    }
    if (paddle.position.x + paddle.width / 2 > DISPLAY_WIDTH) {
        paddle.position.x = DISPLAY_WIDTH - paddle.width / 2;
    }

}

bool isCollidingWithPaddle(const Ball& ball, const Point& paddleTopLeft, const Point& paddleBottomRight) {


    float closestX = std::max(paddleTopLeft.x, std::min(ball.pos.x, paddleBottomRight.x));
    float closestY = std::max(paddleTopLeft.y, std::min(ball.pos.y, paddleBottomRight.y));

    float dx = ball.pos.x - closestX;
    float dy = ball.pos.y - closestY;

    return (dx * dx + dy * dy) < (ball.radius * ball.radius);
}

    int main() {
            Ball ball;
            ball.pos = { 5.0f, 5.0f }; 
            ball.radius = 1.0f;     

          
            Point paddleTopLeft = { 3.0f, 4.0f };       
            Point paddleBottomRight = { 7.0f, 6.0f };   
     }
   
    


