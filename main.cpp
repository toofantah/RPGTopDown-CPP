#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    int windowWidth{1920};
    int windowHeight{1080};
    InitWindow(windowWidth, windowHeight, "RPG Open World");
    // Worid
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.f};
    // player
    Character player{windowWidth, windowHeight};
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        // Draw World
        mapPos = Vector2Scale(player.GetWorldPosition(), -1);
        DrawTextureEx(map, mapPos, 0, 4, WHITE);
        player.Tick(GetFrameTime());
        //Check Map Bounds
        if (player.GetWorldPosition().x < 0.f || player.GetWorldPosition().y < 0.f 
        || player.GetWorldPosition().x + windowWidth > map.width * mapScale || player.GetWorldPosition().y + windowHeight > map.height * mapScale)
        {
            player.UndoMovements();
        }
        EndDrawing();
    }
}