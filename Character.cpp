#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight)
{
    width = texture.width / maxFrames;
    height = texture.height;
    screenPos =
        {
            static_cast<float>(winWidth) / 2 - scale * (0.5f * width / 6.0f),
            static_cast<float>(winHeight) / 2 - scale * (0.5f * height / 6.0f),
        };
}

void Character::Tick(float deltaTime)
{
    worldPosLastFrame = GetWorldPosition();
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

    // Update Animation Frames
    runningTime += deltaTime;
    if (runningTime >= frameRate)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }

    // Draw player
    Rectangle source{frame * width, 0.f, dirX * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

Vector2 Character::GetWorldPosition() { return worldPos; }
void Character::UndoMovements()
{
    worldPos = worldPosLastFrame;
}
