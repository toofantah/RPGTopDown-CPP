#include "Character.h"
#include "raymath.h"

Character::Character(/* args */)
{
}

void Character::Tick(float deltaTime)
{
    worldPosLastFrame = GetWorldPosition();
    // Update Animation Frames
    runningTime += deltaTime;
    if (runningTime >= frameRate)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }
    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos + velocity

        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? dirX = -1.f : dirX = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // Draw player
    Rectangle source{frame * width, 0.f, dirX * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

Vector2 Character::GetWorldPosition()
{
    return worldPos;
}

void Character::UndoMovements()
{
    worldPos = worldPosLastFrame;
}

Rectangle Character::GetCollisionRec()
{
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,

        width * scale,
        height * scale};
}
