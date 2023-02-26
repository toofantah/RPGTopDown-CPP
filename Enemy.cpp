#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idleTex, Texture2D runText)
{

    worldPos = pos;
    texture = idleTex;
    idle = idleTex;
    run = runText;

    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
}

void Enemy::Tick(float deltaTime)
{
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    Character::Tick(deltaTime);
}

void Enemy::SetTarget(Player *newTarget)
{
    target = newTarget;
}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->GetWorldPosition());
}
