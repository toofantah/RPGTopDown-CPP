#include "Character.h"
#include "raymath.h"


Character::Character()
{
    width = texture.width / maxFrames;
    height = texture.height;
}

void Character::Tick(float deltaTime)
{
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
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * width, 4.f * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

Vector2 Character::GetWorldPosition() { return worldPos; }

void Character::SetScreenPos(int winWidth, int winHeight)
{
    screenPos =
        {
            (float)winWidth / 2 - 4.0f * (0.5f * (float)width / 6.0f),
            (float)winHeight / 2 - 4.0f * (0.5f * (float)height / 6.0f),
        };
}

