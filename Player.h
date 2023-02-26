#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Character.h"

class Player : public Character
{
public:
    Player(int winWidth, int winHeight);
    virtual void Tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle GetWeaponCollisionRec() { return weaponCollisionRec; }
    float GetHealth() const { return health; }
    void TakeDamage(float damage);

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
    float health{100.f};
};
#endif