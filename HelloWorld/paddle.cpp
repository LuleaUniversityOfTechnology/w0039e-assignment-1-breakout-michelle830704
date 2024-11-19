#include "constant.h"
#include "paddle.h"
#include "Play.h"




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

bool IsColliding(const Paddle& paddle, Play::GameObject& ball) {

    const float dx = ball.pos.x - Max(paddle.position.x-paddle.width/2, Min(ball.position.x-, ball.radius.x));
    const float dy = ball.pos.y - Max(paddle.position.y- paddle.width / 2, Min(ball.position.y - , ball.radius.y);
    return (dx * dx + dy * dy) < (ball.radius * ball.radius);

}
