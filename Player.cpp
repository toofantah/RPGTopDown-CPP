#include "Player.h"
#include "raymath.h"

Player::Player(int winWidth, int winHeight)
{
    width = texture.width / maxFrames;
    height = texture.height;
    screenPos =
        {
            static_cast<float>(winWidth) / 2 - scale * (0.5f * width / 6.0f),
            static_cast<float>(winHeight) / 2 - scale * (0.5f * height / 6.0f),
        };
}

void Player::Tick(float deltaTime)
{
    Character::Tick(deltaTime);
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;

    if (Vector2Length(direction) != 0)
    {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? dirX = -1 : dirX = 1;
        texture = run;
    }
    else
    {
        texture = idle;
    }
}


