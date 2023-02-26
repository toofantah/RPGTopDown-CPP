#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "player.h"
#include "Enemy.h"

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
        Vector2{0,0},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")
        };
    gobline.SetTarget(&player);
    Prop props[2]{
        {Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        {Vector2{450.f, 580.f}, LoadTexture("nature_tileset/Log.png")}};
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
        gobline.Tick(GetFrameTime());
        
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