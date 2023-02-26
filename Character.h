
#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
class Character
{

public:
    Character(/* args */);
    virtual void Tick(float deltaTime);
    Vector2 GetWorldPosition();
    void UndoMovements();
    Rectangle GetCollisionRec();
    virtual Vector2 getScreenPos() = 0;
    bool getAlive() { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }

protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 worldPos{};
    float dirX{1.f};
    float width{};
    float height{};
    // anim vars
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float frameRate{1.f / 12.f};

    float speed{4.f};
    float scale{4.f};
    Vector2 worldPosLastFrame{};
    Vector2 velocity{};

private:
    /* data */
     bool alive{true};
};
#endif
