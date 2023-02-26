#include "Character.h"

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

    // Draw player
    Rectangle source{frame * width, 0.f, dirX * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
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
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale
    };
}
