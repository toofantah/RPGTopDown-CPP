#include "Player.h"
#include "raymath.h"

Player::Player(int winWidth, int winHeight) : windowWidth(winWidth),
                                              windowHeight(winHeight)
{
    width = texture.width / maxFrames;
    height = texture.height;
}

void Player::Tick(float deltaTime)
{

    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;
    velocity.x < 0.f ? dirX = -1 : dirX = 1;
    Character::Tick(deltaTime);
}

Vector2 Player::getScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
}
