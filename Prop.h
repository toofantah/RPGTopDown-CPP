#include "raylib.h"

class Prop
{
public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 knightPos);
    Rectangle GetCollisionRec(Vector2 playerPos);
private:
    Vector2 worldPos{};
    Texture2D texture{};
    float scale{4.f};
};
