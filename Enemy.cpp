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
}

void Enemy::Tick(float deltaTime)
{
    screenPos = Vector2Subtract(worldPos, target->GetWorldPosition());
    Character::Tick(deltaTime);
}

void Enemy::SetTarget(Player *newTarget)
{
    target = newTarget;
}
