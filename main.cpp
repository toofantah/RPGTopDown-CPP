#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "player.h"
#include "Enemy.h"
#include <string>

int main()
{
    int windowWidth{384};
    int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "RPG Open World");
    // Worid
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.f};
    // player
    Player player{windowWidth, windowHeight};
    Enemy gobline{
        Vector2{800.f, 300.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy slime{
        Vector2{500.f, 700.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")};
    Enemy *enemies[]{
        &gobline,
        &slime};

    for (auto enemy : enemies)
    {
        enemy->SetTarget(&player);
    }

    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        // Draw World
        mapPos = Vector2Scale(player.GetWorldPosition(), -1);

        DrawTextureEx(map, mapPos, 0, 4, WHITE);
        // Draw props
        for (auto prop : props)
        {
            prop.Render(player.GetWorldPosition());
        }
        player.Tick(GetFrameTime());
        for (auto enemy : enemies)
        {
            enemy->Tick(GetFrameTime());
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (auto enemy : enemies)
            {
                if (CheckCollisionRecs(enemy->GetCollisionRec(), player.GetWeaponCollisionRec()))
                {
                    enemy->setAlive(false);
                }
            }

        }
        if (!player.getAlive()) // Character is not alive
        {
            DrawText("Game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }
        else // Character is alivea
        {
            std::string playerHealth = "Health: ";
            playerHealth.append(std::to_string(player.GetHealth()), 0, 5);
            DrawText(playerHealth.c_str(), 55.f, 45.f, 40, RED);
        }

        // Check Map Bounds
        if (player.GetWorldPosition().x < 0.f || player.GetWorldPosition().y < 0.f || player.GetWorldPosition().x + windowWidth > map.width * mapScale || player.GetWorldPosition().y + windowHeight > map.height * mapScale)
        {
            player.UndoMovements();
        }
        // Check prop Collision
        for (auto prop : props)
        {
            bool collision = CheckCollisionRecs(prop.GetCollisionRec(player.GetWorldPosition()), player.GetCollisionRec());
            if (collision)
                player.UndoMovements();
        }
        EndDrawing();
    }
}