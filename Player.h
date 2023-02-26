#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Character.h"

class Player : public Character
{
public:
    Player(int winWidth, int winHeight);
    virtual void Tick(float deltaTime) override;
private:

};
#endif