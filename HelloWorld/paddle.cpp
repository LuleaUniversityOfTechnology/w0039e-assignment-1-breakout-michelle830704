#include "constant.h"
#include "paddle.h"
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "game.h"
#include <iostream>


Paddle paddle;

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

bool isCollidingWithPaddle(const Play::GameObject& ball) {

    Play::Point2D top_left(paddle.position.x - paddle.width / 2, paddle.position.y + paddle.height / 2);
    Play::Point2D bottom_right(paddle.position.x + paddle.width / 2, paddle.position.y - paddle.height / 2);

    float closestX = std::max(top_left.x, std::min(ball.pos.x, bottom_right.x));
    float closestY = std::max(top_left.y, std::min(ball.pos.y, bottom_right.y));

    float dx = ball.pos.x - closestX;
    float dy = ball.pos.y - closestY;

    return (dx * dx + dy * dy) < (ball.radius * ball.radius);
}



