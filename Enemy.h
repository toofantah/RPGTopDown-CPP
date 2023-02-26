#include "raylib.h"
#include "Character.h"
#include "Player.h"

class Enemy : public Character
{
public:
    Enemy(Vector2 pos, Texture2D idleTex, Texture2D runText);
    virtual void Tick(float deltaTime) override;
    void SetTarget(Player* newTarget);
    virtual Vector2 getScreenPos() override;
private:
    Player* target;
    float damagePerSec{10.f};
    float radius{25.f};
};