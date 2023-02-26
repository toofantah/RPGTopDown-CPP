#include "raylib.h"

class Character
{
public:
    Character(int winWidth, int winHeight);
    void Tick(float deltaTime);
    // Getting Character's World Position
    Vector2 GetWorldPosition();
    void UndoMovements();

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
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
};