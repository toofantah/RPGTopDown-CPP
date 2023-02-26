#include "raylib.h"
#include "Character.h"
#include "Player.h"

class Enemy : public Character
{
public:
    Enemy(Vector2 pos, Texture2D idleTex, Texture2D runText);
    virtual void Tick(float deltaTime) override;
    void SetTarget(Player* newTarget);
private:
    Player* target;
};